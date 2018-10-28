#ifndef _SYNTH_CONTROLLER_H
#define _SYNTH_CONTROLLER_H

#include <SDL2/SDL_events.h>
#include <functional>
#include <unordered_map>
#include <unordered_set>

class SynthController
{
	SDL_Event e;
	std::unordered_map<SDL_Keycode, std::function<void()>> keymap;
	std::unordered_set<std::function<void()>&> contRunning;
public:
	SynthController();
	int addKey(SDL_Keycode key, std::function<void> handler);
	void tick();
};

#endif // _SYNTH_CONTROLLER_H
