#pragma once
#include<string>
#include <Windows.h>
#include <chrono>
#include <thread>
#include "Room.h";

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;




class Vacuum
{
private:
	string name;
	string brand;
	Direction direction;
	Coordinate* vacuumCoord;
	Room* room;
	int vacuumStep;
	int totalStep;
	const int sleepTime = 20;
	float battery;
	int batteryStep;


public:
	Vacuum() {};
	Vacuum(Room* room);
	~Vacuum();

	void scanRoom();

	//Điều hướng thiết bị
	void turnLeft();
	void turnRight();
	void turnOver();

	Direction getDirection();
	void setDirection(Direction newDir);


	bool Move();
	void vacuumClean();

	void placeVacuum();
	void setVacuum(bool b);

	Coordinate* getVacuumCoord();
	void setVacuumCoord(int x, int y);

	float getBattery();
	void setDeath();

	void Charged();

	Grid* getPowerChargeCoor();

	static void clearScreen();

	Room* getRoomInfo() { return this->room; };

};

