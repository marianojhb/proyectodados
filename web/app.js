/* The browser handles presentation; all dice and turn rules live in C++. */
(() => {
  'use strict';
  const $ = id => document.getElementById(id);
  const screens = ['menu', 'play', 'instructions', 'exit'];
  let current = 'menu';
  let previous = 'menu';
  let helpTrigger;
  let ready = false;
  let player = '';
  let phase = 0;
  const api = (name, ...args) => Module.ccall(`game_${name}`, 'number', args.map(() => 'number'), args);

  function show(screen, focus = true) {
    screens.forEach(id => { $(id).hidden = id !== screen; });
    current = screen;
    $('help').hidden = screen === 'instructions' || screen === 'exit';
    if (focus) $({ menu: 'menu-title', play: 'play-title', instructions: 'instructions-title', exit: 'exit-title' }[screen]).focus();
  }

  function resizeDice() {
    if (ready) api('columns', window.matchMedia('(max-width: 640px)').matches ? 3 : 6);
  }

  function refresh() {
    phase = api('phase');
    const rolls = api('rolls');
    const total = api('total');
    const combination = api('combination');
    $('round').textContent = String(api('round')).padStart(2, '0');
    $('rolls').textContent = rolls;
    $('total').textContent = total;
    $('best').textContent = api('best');
    $('player-label').textContent = `JUEGA ${player}`;
    const dice = Array.from({ length: 6 }, (_, i) => api('die', i));
    $('canvas').setAttribute('aria-label', rolls ? `Dados: ${dice.join(', ')}` : 'Seis dados listos para lanzar');
    $('dice-caption').textContent = rolls ? dice.join(' · ') : 'Tu próxima jugada está en estos seis dados.';
    $('play-title').textContent = phase === 2 ? '¡La partida es tuya!' : phase === 1 ? 'Una ronda más cerca.' : 'Vamos con esa tirada.';
    const messages = [
      `${api('points')} puntos en los dados.`,
      `¡Generala! ${api('points')} puntos.`,
      'Seis seis: tu total vuelve a cero.',
      '¡Escalera! Ganaste al instante.'
    ];
    $('result').textContent = rolls ? messages[combination] : 'Todavía no lanzaste.';
    if (phase === 1) $('result').textContent += ` Sumaste ${api('best')} esta ronda.`;
    if (phase === 2 && combination !== 3) $('result').textContent = `¡Llegaste a ${total} puntos en ${api('round')} rondas!`;
    $('roll').innerHTML = `${phase === 2 ? 'Jugar otra partida' : phase === 1 ? 'Siguiente ronda' : 'Lanzar dados'} <span aria-hidden="true">${phase === 2 ? '↩' : '↗'}</span>`;
  }

  function start() {
    api('reset');
    show('play');
    resizeDice();
    refresh();
  }

  function act() {
    if (!ready || current !== 'play') return;
    if (phase === 2) { start(); return; }
    if (phase === 1) api('next_round');
    else api('roll');
    refresh();
  }

  function quit() {
    if (!ready) return;
    api('reset');
    show('exit');
  }

  function back() {
    show(previous, false);
    if (previous === 'play') resizeDice();
    if (helpTrigger && !helpTrigger.hidden) helpTrigger.focus();
  }

  function initialized() {
    if (ready) return;
    ready = true;
    $('start').disabled = false;
    $('help').disabled = false;
    $('loading').textContent = 'Todo listo. Los dados están de tu lado.';
  }

  $('start-form').addEventListener('submit', event => {
    event.preventDefault();
    if (!ready) return;
    const input = $('player-name');
    player = input.value.trim();
    if (!player) { input.setCustomValidity('Ingresá tu nombre para jugar.'); input.reportValidity(); return; }
    input.setCustomValidity('');
    start();
  });
  $('player-name').addEventListener('input', () => $('player-name').setCustomValidity(''));
  $('roll').addEventListener('click', act);
  $('leave').addEventListener('click', quit);
  $('help').addEventListener('click', event => { previous = current; helpTrigger = event.currentTarget; show('instructions'); });
  $('back').addEventListener('click', back);
  $('return-menu').addEventListener('click', () => show('menu'));
  $('brand').addEventListener('click', event => { event.preventDefault(); if (ready) { api('reset'); show('menu'); } });
  window.addEventListener('resize', resizeDice);
  window.addEventListener('keydown', event => {
    if (event.target.matches('input, textarea, select, [contenteditable]') || event.ctrlKey || event.metaKey || event.altKey) return;
    if (event.key === 'q') { event.preventDefault(); quit(); return; }
    if (event.key === 'Escape' && current === 'instructions') { event.preventDefault(); back(); return; }
    if ((event.key === ' ' || event.key === 'Enter') && current === 'play' && !event.target.closest('button, a')) {
      event.preventDefault();
      if (!event.repeat) act();
    }
  });
  window.addEventListener('dados-ready', initialized);
  function failed() {
    $('loading').textContent = 'No pudimos cargar el juego. Recargá la página para reintentar.';
    $('loading').setAttribute('role', 'alert');
    $('start').disabled = true;
    $('help').disabled = true;
    ready = false;
  }
  window.addEventListener('dados-error', failed);
  if (window.dadosFailed) failed();
  else if (window.dadosReady) initialized();
})();
