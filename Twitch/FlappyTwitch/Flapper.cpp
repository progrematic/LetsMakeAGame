#include "Flapper.h"

#include "../Engine/Engine.h"
#include "../Engine/Math/Rect.h"

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
	boundingRect.SetSize(*sprite.GetSize() * *sprite.GetScale());
	rb.Initialize(0.8f, -10, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize(), boundingRect);
}

void Flapper::Update()
{
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