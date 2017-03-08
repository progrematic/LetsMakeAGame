#include "InputManager.h"

InputManager::InputManager(Flapper* _flapper)
{
	flapper = _flapper;
}

void InputManager::Update()
{
	if (Keyboard::Key(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
	{
		flapper->Flap();
	}
}