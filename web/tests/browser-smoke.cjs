// Optional end-to-end checks against the actual compiled WASM, not a JS mock.
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const os = require('node:os');
const http = require('node:http');
const { chromium } = require('playwright');

async function main() {
  const root = path.resolve(__dirname, '../build');
  const types = { '.html': 'text/html', '.css': 'text/css', '.js': 'text/javascript', '.wasm': 'application/wasm' };
  const server = http.createServer((req, res) => {
    const file = path.resolve(root, '.' + new URL(req.url, 'http://localhost').pathname);
    if (!file.startsWith(root + path.sep) || !fs.existsSync(file) || !fs.statSync(file).isFile()) {
      res.writeHead(404); res.end(); return;
    }
    res.setHeader('Content-Type', types[path.extname(file)] || 'application/octet-stream');
    fs.createReadStream(file).pipe(res);
  });
  await new Promise(resolve => server.listen(0, '127.0.0.1', resolve));
  const chrome = '/Applications/Google Chrome.app/Contents/MacOS/Google Chrome';
  let browser;
  try {
    browser = await chromium.launch({
      headless: true,
      executablePath: process.env.CHROME_PATH || (fs.existsSync(chrome) ? chrome : undefined)
    });
    const screenshots = process.env.DADOS_SCREENSHOTS || fs.mkdtempSync(path.join(os.tmpdir(), 'dados-web-'));
    fs.mkdirSync(screenshots, { recursive: true });
    for (const width of [1280, 375]) {
      const page = await browser.newPage({ viewport: { width, height: 900 } });
      const errors = [];
      page.on('pageerror', error => errors.push(error.message));
      page.on('console', message => { if (message.type() === 'error') errors.push(message.text()); });
      await page.goto(`http://127.0.0.1:${server.address().port}/dados.html`);
      await page.locator('#start:enabled').waitFor();
      await page.screenshot({ path: path.join(screenshots, `menu-${width}.png`), fullPage: true });
      await page.locator('#player-name').fill('quique');
      // q in text entry must not exit the game.
      await page.locator('#player-name').press('q');
      assert(await page.locator('#menu').isVisible());
      await page.locator('#player-name').fill('quique');
      await page.locator('#start').click();
      assert(await page.locator('#play').isVisible());
      assert.equal(await page.locator('#total').textContent(), '0');
      const canvas = await page.locator('#canvas').boundingBox();
      assert(canvas.width > 250 && canvas.height > 50, 'dice canvas must be visible');
      // Actual SDL pixels: a pip must differ from the cream table background.
      assert(await page.locator('#canvas').evaluate(c => {
        const pixels = c.getContext('2d').getImageData(0, 0, c.width, c.height).data;
        let dark = 0;
        for (let i = 0; i < pixels.length; i += 4) if (pixels[i] < 100 && pixels[i + 1] < 100) dark++;
        return dark > 500;
      }), 'SDL must draw the dice pips');
      await page.keyboard.press('Space');
      assert.equal(await page.locator('#rolls').textContent(), '1');
      const before = await page.locator('#rolls').textContent();
      await page.locator('#help').click();
      assert(await page.locator('#instructions').isVisible());
      await page.keyboard.press('Escape');
      assert(await page.locator('#play').isVisible());
      assert.equal(await page.locator('#rolls').textContent(), before);
      for (let i = 1; i < 3; i++) {
        const phase = await page.evaluate(() => Module._game_phase());
        if (phase !== 0) break;
        await page.locator('#roll').click();
      }
      assert.notEqual(await page.evaluate(() => Module._game_phase()), 0, 'round must finish after three rolls');
      await page.screenshot({ path: path.join(screenshots, `game-${width}.png`), fullPage: true });
      assert(await page.evaluate(() => document.documentElement.scrollWidth <= window.innerWidth), 'no horizontal overflow');
      await page.locator('#help').click();
      await page.keyboard.press('q');
      assert(await page.locator('#exit').isVisible(), 'q must exit even from instructions');
      await page.locator('#return-menu').click();
      await page.locator('#start').click();
      assert.equal(await page.locator('#total').textContent(), '0');
      assert.equal(await page.locator('#rolls').textContent(), '0');
      await page.keyboard.press('q');
      assert(await page.locator('#exit').isVisible(), 'q must exit from gameplay');
      assert.deepEqual(errors, [], 'no browser errors');
      await page.close();
      console.log(`PASS: ${width}px — WASM, SDL dice, turns, help, q, restart, layout`);
    }
    console.log(`Screenshots: ${screenshots}`);
  } finally {
    if (browser) await browser.close();
    await new Promise(resolve => server.close(resolve));
  }
}
main().catch(error => { console.error(error); process.exitCode = 1; });
