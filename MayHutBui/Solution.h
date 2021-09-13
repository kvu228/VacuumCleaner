#pragma once
#include"Vacuum.h"

#include <unordered_map>

class Solution
{
private:
	unordered_map<int, unordered_map<int, bool>> visited;


public:
	void cleanRoom(Vacuum* vacuum);
	void cleanRoom(Vacuum* vacuum, Coordinate curCoord);
	Coordinate getNextPos(Vacuum* vacuum, Coordinate curCoord);

	/*
	Coordinate getNextPos(Vacuum* vacuum, Coordinate curCoord);
	void goToPowerCharge(Vacuum* vacuum);
	void goToPowerCharge(Vacuum* vacuum, Coordinate curCoord, Coordinate powerCord);
	*/

};

