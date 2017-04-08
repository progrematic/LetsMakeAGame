#ifndef TWITCH_INPUTMANAGER
#define TWITCH_INPUTMANAGER

#include "../Engine/Engine.h"
#include "../Engine/IO/Mouse.h"
#include "../Engine/IO/Keyboard.h"
#include "Flapper.h"
#include "Pipe.h"

class InputManager
{
public:
	InputManager(Flapper* _flapper, Pipe* _pipe);

	void Update();
private:
	Flapper* flapper;
	Pipe* pipe;
};

#endif
