#pragma once
#define WINDOW_WIDTH	932						//为窗口宽度定义的宏，以方便在此处修改窗口宽度
#define WINDOW_HEIGHT	932							//为窗口高度定义的宏，以方便在此处修改窗口高度

class Bullet
{
private:
	float Bullet_Speed = 4.5;
	int Bullet_Direction;
	float Bullet_X;
	float Bullet_Y;
	bool exit;

public:
	bool Bullet_Getcoord(int* X_coord, int* Y_coord);
	bool Bullet_Move();
	bool Bullet_Disapper();
	bool Bullet_Shoot(int Direction,int X_coord,int Y_coord);
	int Bullet_GetDirection();
};