import axios from 'axios';

const baseUrl = process.env.NODE_ENV === 'production' ? '' : 'http://localhost:8080';

export const baseButtonMappings = {
  Up:    { pin: -1, error: null },
  Down:  { pin: -1, error: null },
  Left:  { pin: -1, error: null },
  Right: { pin: -1, error: null },
  A:    { pin: -1, error: null },
  B:    { pin: -1, error: null }

};

async function resetSettings() {
  return axios.get(`${baseUrl}/api/resetSettings`)
	.then((response) => response.data)
	.catch(console.error);
}

async function getGamepadOptions() {
  return axios.get(`${baseUrl}/api/getGamepadOptions`)
	.then((response) => response.data)
	.catch(console.error);
}

async function setGamepadOptions(options) {
  let newOptions = { ...options}; 
  return axios.post(`${baseUrl}/api/setGamepadOptions`, options)
	.then((response) => {
	  console.log(response.data);
	  return true;
	})
	.catch((err) => {
	  console.error(err);
	  return false;
	});
}

async function getLedOptions() {
  return axios.get(`${baseUrl}/api/getLedOptions`)
	.then((response) => response.data)
	.catch(console.error);
}

async function setLedOptions(options) {
  let newOptions = { ...options}; 
  return axios.post(`${baseUrl}/api/setLedOptions`, options)
	.then((response) => {
	  console.log(response.data);
	  return true;
	})
	.catch((err) => {
	  console.error(err);
	  return false;
	});
}

async function getPinMappings() {
  return axios.get(`${baseUrl}/api/getPinMappings`)
	.then((response) => {
	  let mappings = { ...baseButtonMappings };
	  for (let prop of Object.keys(response.data))
		mappings[prop].pin = parseInt(response.data[prop]);

	  return mappings;
	})
	.catch(console.error);
}

async function setPinMappings(mappings) {
  let data = {};
  Object.keys(mappings).map((button, i) => data[button] = mappings[button].pin);
  return axios.post(`${baseUrl}/api/setPinMappings`, data)
	.then((response) => {
	  console.log(response.data);
	  return true;
	})
	.catch((err) => {
	  console.error(err);
	  return false;
	});
}

const WebApi = {
  resetSettings,
  getGamepadOptions,
  setGamepadOptions,
  getLedOptions,
  setLedOptions,
  getPinMappings,
  setPinMappings,
};

export default WebApi;
