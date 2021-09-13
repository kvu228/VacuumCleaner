#pragma once
#include <iostream>;
using namespace std;


/*
Thuộc tính các ô gạch.
Khởi tạo là blank, wall là tường , clean là sạch, dirt là có bụi, powerCharge là sạc
*/

enum class Item
{
	blank,
	wall,
	clean,
	dirt,
	powerCharge
};

enum class Direction
{
	up,
	down,
	left,
	right,
	blank
};


class Object
{
private:
	Item item;
	Direction direction;
public:
	Object();
	Object(Item item);
	~Object();

	Item getItem();
	void setItem(Item newItem) ;
	void itemInfo();

	Direction getDirection();
	void setDirection(Direction newDir);

};

