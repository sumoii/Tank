#include "Bullet.h"

bool Bullet::Bullet_Move()
{
	switch (Bullet_Direction)
	{
	case 0:
		Bullet_Y -= Bullet_Speed;
		break;
	case 1:
		Bullet_X -= Bullet_Speed;
		break;
	case 2:
		Bullet_Y += Bullet_Speed;
		break;
	case 3:
		Bullet_X += Bullet_Speed;
		break;
	default:
		break;
	}
	return 0;
}

bool Bullet::Bullet_Shoot(int Direction, float X_coord, float Y_coord)
{
	Bullet_Direction = Direction;
	Bullet_X = X_coord;
	Bullet_Y = Y_coord;
	return 0;
}

int Bullet::Bullet_GetDirection()
{
	return Bullet_Direction;
}

bool Bullet::Bullet_Getcoord(float* X_coord, float* Y_coord)
{
	*X_coord = Bullet_X;
	*Y_coord = Bullet_Y;
	return 0;
}

bool Bullet::Bullet_Disapper()
{
	return 0;
}