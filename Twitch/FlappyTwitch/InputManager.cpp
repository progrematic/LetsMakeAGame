#include "InputManager.h"

InputManager::InputManager(Flapper* _flapper, Pipe* _pipe)
{
	flapper = _flapper;
	pipe = _pipe;
}

void InputManager::Update()
{
	if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
	{
		flapper->Flap();
	}

	pipe->MoveTo(Vector3(Mouse::GetMouseX(), Mouse::GetMouseY(), 0));
}