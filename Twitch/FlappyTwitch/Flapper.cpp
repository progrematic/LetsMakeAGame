#include "Flapper.h"

#include "../Engine/Engine.h"
#include "../Engine/Math/Rect.h"
#include "../Engine/IO/Keyboard.h"
#include "../Engine/IO/Mouse.h"

Flapper::Flapper()
{
	flapForce = 750;
	maxRot = 30;
	minRot = -maxRot;
}

Flapper::Flapper(Sprite _sprite) : Flapper()
{
	sprite = _sprite;

	Rect boundingRect = Rect();
	Vector3 sizeOffset(0.8, 0.3, 1);
	boundingRect.SetSize(*sprite.GetSize() * *sprite.GetScale() * sizeOffset);
	rb.Initialize(0.8f, -10, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize(), boundingRect);
}

void Flapper::Update()
{
	HandleInput();

	sprite.Update();
	rb.Update();

	float yVel = rb.GetVel().y;
	if (flapForce == 0)
	{
		cout << "Error! Flapping will do you no good! Setting to 750" << endl;
		flapForce = 750;
	}
	float newRot = (maxRot / flapForce) * yVel;
	sprite.RotateTo(newRot);
}

void Flapper::Render()
{
	sprite.Render();
	rb.Render(Vector3(0, 0, 0));
}

void Flapper::Flap()
{
	rb.SetVel(Vector3(0, flapForce, 0));
	sprite.RotateTo(maxRot);
}

Sprite& Flapper::GetSprite()
{
	return sprite;
}

Rigidbody& Flapper::GetRB()
{
	return rb;
}

void Flapper::Reset()
{
	sprite.MoveTo(Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	sprite.RotateTo(0);
	rb.SetVel(Vector3(0, 0, 0));
}

// Private

void Flapper::HandleInput()
{
	if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
	{
		Flap();
	}
}