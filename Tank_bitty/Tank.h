#include"Bullet.h"
#include<vector>
#include <list>
#pragma once

class Tank
{
private:
	int Tank_Ip = 1;
	float Tank_Speed = 4.5;
	float Tank_X;
	float Tank_Y;
	int Tank_Level = 1;
	int Tank_Direction;
	int Tank_Bullet = 1;
public:
	Tank(int Direction, float X_coord, float Y_coord);
	bool Tank_Getcoord(float *X_coord, float *Y_coord);
	bool Tank_Move(int Direction);
	bool Tank_Deal();
	bool Tank_Uplevel();
	int Tank_Getdirection();
	bool Tank_Shoot(float* X_coord, float* Y_coord);
	void Tank_AddShoot(const Bullet &bullet);
	void Tank_DeleteShoot();
	std::list<Bullet> bullets;
};
