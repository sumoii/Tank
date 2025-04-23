#pragma once
#define WINDOW_WIDTH	932						//为窗口宽度定义的宏，以方便在此处修改窗口宽度
#define WINDOW_HEIGHT	932							//为窗口高度定义的宏，以方便在此处修改窗口高度

class Bullet	
{
private:
	float Bullet_Speed =16;
	int Bullet_Direction;
	float Bullet_X;
	float Bullet_Y;
public:
	Bullet(int Direction, float X_coord, float Y_coord);
	bool Bullet_Exist;
	bool Bullet_Shoot(int Direction, float X_coord, float Y_coord);
	bool Bullet_Getcoord(float* X_coord, float* Y_coord);
	bool Bullet_Move();
	bool Bullet_Disapper();
	int Bullet_GetDirection();
};