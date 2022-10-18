import { createContext } from 'react';

export const defaultAppData = {
	buttonLabels: 'PicoGamePad',
};

export const AppContext = createContext(defaultAppData);
