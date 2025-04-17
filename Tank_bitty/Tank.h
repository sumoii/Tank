#include<string>
#pragma once
class Tank
{
private:
	int Tank_Ip = 1;
	int Tank_Speed = 16;
	int Tank_X = 416;
	int Tank_Y = 800;
	int Tank_Level = 1;
	int Tank_Living = 0;
	int Tank_Direction = 0;
	int Tank_Bullet = 0;
public:
	bool Tank_Getcoord(int &X_coord, int &Y_coord);
	bool Tank_move(int Direction);
	bool Tank_deal();
	bool Tank_Uplevel();
};
