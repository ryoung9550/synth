#include "SynthController.h"
#include <SDL2/SDL.h>

SynthController::SynthController()
{
	SDL_Init(SDL_INIT_VIDEO);
}

void SynthController::tick()
{
	while(SDL_PollEvent(&e)) {
		if(e.key.type == SDL_KEYDOWN) {
			if(keymap.find(e.key.keysym.sym) == keymap.end()) {
				keymap.at(e.key.keysym.sym)();
			}
		}
	}
}
