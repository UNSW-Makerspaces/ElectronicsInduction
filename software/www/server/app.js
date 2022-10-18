/**
 * Configurator Development Server
 */

const express = require('express');
const cors = require('cors');

const controllers = require('../src/Data/Controllers.json');

const port = process.env.PORT || 8080;
const baseButtonMappings = {
	Up:    { pin: 1, error: null },
	Down:  { pin: 2, error: null },
	Left:  { pin: 3, error: null },
	Right: { pin: 4, error: null },
	A:    { pin: 5, error: null },
	B:    { pin: 6, error: null }

};

const app = express();
app.use(cors());
app.use(express.json());

app.use(function(req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "X-Requested-With");
  next();
  });

app.get('/api/resetSettings', (req, res) => {
	console.log('/api/resetSettings');
	return res.send({ success: true });
});

app.get('/api/getGamepadOptions', (req, res) => {
	console.log('/api/getGamepadOptions');
	return res.send({
		dpadMode: 0,
		inputMode: 1,
		socdMode: 2
	});
});

app.get('/api/getLedOptions', (req, res) => {
	console.log('/api/getLedOptions');
	let usedPins = [];
	for (let prop of Object.keys(controllers['PicoGamePad']))
		if (!isNaN(parseInt(controllers['PicoGamePad'][prop])))
			usedPins.push(parseInt(controllers['PicoGamePad'][prop]));

	return res.send({
		brightnessMaximum: 255,
		brightnessSteps: 5,
		dataPin: 15,
		ledFormat: 0,
		ledLayout: 1,
		ledsPerButton: 2,
		ledButtonMap: {
			Up: 3,
			Down: 1,
			Left: 0,
			Right: 2,
			A: 8,
			B: 9
		},
		usedPins,
	});
});

app.get('/api/getPinMappings', (req, res) => {
	console.log('/api/getPinMappings');
	let mappings = { ...baseButtonMappings };
	for (let prop of Object.keys(controllers['PicoGamePad'])) {
		if (mappings[prop])
			mappings[prop] = parseInt(controllers['PicoGamePad'][prop]);
	}

	return res.send(mappings);
});

app.post('/api/*', (req, res) => {
	console.log(req.url);
	return res.send(req.body);
})

app.listen(port, () => {
  console.log(`Example app listening at http://localhost:${port}`)
});
