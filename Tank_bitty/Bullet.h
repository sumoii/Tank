#pragma once
#define WINDOW_WIDTH	932						//Ϊ���ڿ�ȶ���ĺ꣬�Է����ڴ˴��޸Ĵ��ڿ��
#define WINDOW_HEIGHT	932							//Ϊ���ڸ߶ȶ���ĺ꣬�Է����ڴ˴��޸Ĵ��ڸ߶�

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