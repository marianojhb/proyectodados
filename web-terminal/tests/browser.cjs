const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const os = require('node:os');
const http = require('node:http');
const { chromium } = require('playwright');

async function main() {
  const root = path.resolve(__dirname, '../build');
  const server = http.createServer((req, res) => {
    const file = path.resolve(root, '.' + new URL(req.url, 'http://localhost').pathname);
    if (!file.startsWith(root + path.sep) || !fs.existsSync(file) || !fs.statSync(file).isFile()) { res.writeHead(404); res.end(); return; }
    const types = { '.wasm': 'application/wasm', '.js': 'text/javascript', '.css': 'text/css', '.html': 'text/html' };
    res.setHeader('Content-Type', types[path.extname(file)] || 'text/plain');
    fs.createReadStream(file).pipe(res);
  });
  await new Promise(resolve => server.listen(0, '127.0.0.1', resolve));
  let browser;
  try {
    const chrome = '/Applications/Google Chrome.app/Contents/MacOS/Google Chrome';
    browser = await chromium.launch({ headless: true, executablePath: process.env.CHROME_PATH || (fs.existsSync(chrome) ? chrome : undefined) });
    const page = await browser.newPage({ viewport: { width: 1100, height: 900 } });
    const errors = [];
    page.on('pageerror', error => errors.push(error.message));
    page.on('console', message => { if (message.type() === 'error') errors.push(message.text()); });
    page.on('dialog', dialog => { errors.push('Unexpected browser dialog'); dialog.dismiss(); });
    const screen = () => {
      const buffer = window.terminal.buffer.active;
      return Array.from({ length: terminal.rows }, (_, i) => buffer.getLine(buffer.baseY + i)?.translateToString()).join('\n');
    };
    const wait = text => page.waitForFunction(({ text, source }) => (0, eval)(`(${source})`)().includes(text), { text, source: screen.toString() });
    const key = name => page.keyboard.press(name);
    const url = `http://127.0.0.1:${server.address().port}/original.html`;
    await page.goto(url);
    await wait('COMENZAR UN JUGADOR');
    const screenshots = fs.mkdtempSync(path.join(os.tmpdir(), 'dados-terminal-'));
    await page.screenshot({ path: path.join(screenshots, 'menu.png'), fullPage: true });

    // Original instructions and left/right paging.
    for (let i = 0; i < 3; i++) await key('ArrowUp');
    await key('Enter');
    await wait('CONTROLES (1/3)');
    await key('ArrowRight');
    await wait('CÓMO JUGAR (2/3)');
    await key('ArrowRight');
    await wait('COMBINACIONES (3/3)');
    await key('Escape');
    await wait('COMENZAR UN JUGADOR');

    // Instructions retained index 5. Go up once to toggle original simulated mode.
    await key('ArrowUp');
    await key('Enter');
    await wait('MODO SIMULADO ON');
    for (let i = 0; i < 4; i++) await key('ArrowUp');
    await key('Enter');
    await wait('INGRESE SU NOMBRE:');
    await page.keyboard.type('quiquex');
    await key('Backspace');
    await wait('quique');
    await key('Enter');
    await wait('RONDA N° 1');
    await key('Space');
    await wait('INGRESE EL DADO N° 1');
    await wait('JUGADOR: quique');
    for (let value = 1; value <= 6; value++) {
      await wait(`INGRESE EL DADO N° ${value}`);
      await page.keyboard.type(String(value));
      await key('Enter');
    }
    await wait('SACO ESCALERA Y GANO EL JUEGO!');
    await wait('┏━━━━━━━━━┓');
    await page.screenshot({ path: path.join(screenshots, 'original-dice-win.png'), fullPage: true });
    await key('Space');
    await wait('COMENZAR UN JUGADOR');
    // Same-session ranking is still the original C++ ranking.
    for (let i = 0; i < 3; i++) await key('ArrowDown');
    await key('Enter');
    await wait('RANKING ULTIMAS 10 PARTIDAS');
    await wait('quique');
    await key('q');
    await page.locator('#restart:visible').waitFor();
    assert((await page.locator('#status').textContent()).includes('Programa finalizado'));

    // Real multiplayer input and an ordinary (non-simulated) pause.
    await page.locator('#restart').click();
    await wait('COMENZAR UN JUGADOR');
    await key('ArrowDown');
    await key('Enter');
    await wait('INGRESE EL NOMBRE DEL JUGADOR  1:');
    await page.keyboard.type('Ana');
    await key('Enter');
    await wait('INGRESE EL NOMBRE DEL JUGADOR  2:');
    await page.keyboard.type('Luis');
    await key('Enter');
    await wait('JUGAR CON RONDAS PREDERMINADAS:');
    await key('Enter');
    await wait('RONDA N° 1');
    await key('Space');
    await wait('TURNO DE Ana');
    await key('Space');
    await wait('LANZAR LOS DADOS');
    await key('Space');
    await page.waitForFunction(source => {
      const text = (0, eval)(`(${source})`)();
      return text.includes('SUMATORIA DE LOS DADOS') || text.includes('SACO ESCALERA');
    }, screen.toString());
    await key('q');
    await page.locator('#restart:visible').waitFor();
    assert.deepEqual(errors, []);
    console.log('PASS: original menus, paging, real keyboard + editing, six manual dice, straight victory, ranking, multiplayer, ordinary roll, q and restart');
    console.log(`Screenshots: ${screenshots}`);
  } finally {
    if (browser) await browser.close();
    await new Promise(resolve => server.close(resolve));
  }
}
main().catch(error => { console.error(error); process.exitCode = 1; });
