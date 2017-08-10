#include "InputManager.h"

InputManager::InputManager()
{
	flapper = nullptr;
}

InputManager::InputManager(Flapper* _flapper)
{
	flapper = _flapper;
}

void InputManager::Update()
{
	if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
	{
		flapper->Flap();
	}
}