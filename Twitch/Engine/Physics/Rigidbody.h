#ifndef TWITCH_RIGIDBODY
#define TWITCH_RIGIDBODY

#include "../Math/Vector3.h"

class Rigidbody
{
public:

	Rigidbody();

	void Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size);

	void Update();
	void Render(Vector3 c);

	void AddForce(Vector3 f);

	Vector3 GetVel();
	void SetVel(Vector3 _vel);

private:
	Vector3* pos;
	float* rot;
	Vector3* scale;
	Vector3* size;

	float gravity;
	float friction;
	Vector3 vel;
};

#endif
