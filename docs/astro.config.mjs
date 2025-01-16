// @ts-check
import { defineConfig } from 'astro/config';
import starlight from '@astrojs/starlight';

// https://astro.build/config
export default defineConfig({
	integrations: [
		starlight({
			title: 'ATmega328P',
			social: {
				github: 'https://github.com/kevinzunigacuellar/atmega328p',
			},
			customCss: [
				"./src/styles/custom.css"
			],
			sidebar: [
				{
					label: 'Start here',
					items: [
						"getting-started"
					],
				},
				{
					label: 'Exercises',
					autogenerate: { directory: 'exercises' },
				},
			],
		}),
	],
});
