#pragma once
#include "Object.h"

struct Coordinate
{
	int x;
	int y;
	Coordinate() {};
	Coordinate(int y, int x) {
		x = x;
		y = y;
	}
};


class Grid
{
private:
	Coordinate* coordinate; //Tọa độ của grid
	Object* object;//Thuộc tính object của grid
	bool hasRobot;//Grid hiện có máy hút bụi không
	char rep;//Hiển thị trên console
public:
	Grid();
	Grid(Coordinate* coord, Object* object);
	Grid(Coordinate* coord, char rep);
	Grid(int y, int x);
	~Grid();

	Coordinate* getCoordinate();
	Object* getObject();

	void setObject(Item item);
	void generateObject();

	void setRep();
	char getRep();

	void setVacuum(bool b);//Nếu ô đang có máy hút bụi sẽ setRep() theo hướng của máy hút bụi

	void gridInfo();
};

