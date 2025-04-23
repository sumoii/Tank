#include "Tank.h"
#define WINDOW_WIDTH	932						//为窗口宽度定义的宏，以方便在此处修改窗口宽度
#define WINDOW_HEIGHT	932							//为窗口高度定义的宏，以方便在此处修改窗口高度

Tank::Tank(int Direction, float X_coord, float Y_coord)
{
	Tank_Direction = Direction;
	Tank_X = X_coord;
	Tank_Y = Y_coord;
}

bool Tank::Tank_Move(int Direction) 
{
	switch (Direction)
	{
	case 0:
		Tank_Y -= Tank_Speed;
		Tank_Direction = 0;
		if (Tank_Y < 0)
			Tank_Y = 0;
		break;
	case 1:
		Tank_X -= Tank_Speed;
		if (Tank_X < 0)
			Tank_X = 0;
		Tank_Direction = 1;
		break;
	case 2:
		Tank_Y += Tank_Speed;
		if (Tank_Y >= (WINDOW_HEIGHT-32))
			Tank_Y = (WINDOW_HEIGHT-32);
		Tank_Direction = 2;
		break;
	case 3:
		Tank_X += Tank_Speed;
		if (Tank_X > (WINDOW_WIDTH-32))
			Tank_X = (WINDOW_WIDTH-32);
		Tank_Direction = 3;
		break;
	default:
		break;
	}
	return 0;
}

bool Tank::Tank_Getcoord(float* X_coord, float* Y_coord)
{
	*X_coord = Tank_X;
	*Y_coord = Tank_Y;
	return 0;
}

int Tank::Tank_Getdirection()
{
	return Tank_Direction;
}

bool Tank::Tank_Shoot(float *X_coord, float *Y_coord)
{
	switch (Tank_Direction)
	{
	case 0:
		*X_coord = Tank_X + 6;
		*Y_coord = Tank_Y - 6;
		break;
	case 1:
		*X_coord = Tank_X;
		*Y_coord = Tank_Y;
		break;
	case 2:
		*X_coord = Tank_X + 6;
		*Y_coord = Tank_Y;
		break;
	case 3:
		*X_coord = Tank_X + 13;
		*Y_coord = Tank_Y;
		break;
	default:
		break;
	}
	return 0;
}

void Tank::Tank_AddShoot(const Bullet& bullet)
{
	bullets.push_back(bullet);
}

void Tank::Tank_DeleteShoot()
{
	for (auto it = bullets.begin(); it != bullets.end(); ++it) {
		if (!it->Bullet_Exist)
			bullets.erase(it);
	}
}