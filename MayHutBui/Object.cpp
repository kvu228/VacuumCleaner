#include "Object.h"

Object::Object()
{
	item = Item::blank;
	direction = Direction::blank;
}

Object::Object(Item item)
{
	direction = Direction::blank;
	this->item = item;
}

Object::~Object() { };

Item Object::getItem()
{
	return item;
}

void Object::setItem(Item newItem)
{
	this->item = newItem;
}


void Object::itemInfo()
{
	switch (item)
	{
	case Item::blank:
		cout << "Blank";
		break;
	case Item::wall:
		cout << "Wall";
		break;
	case Item::clean:
		cout << "Clean";
		break;
	case Item::dirt:
		cout << "Dirt";
		break;
	case Item::powerCharge:
		cout << "Power Charge";
		break;
	}
}

Direction Object::getDirection()
{
	return this->direction;
}

void Object::setDirection(Direction newDir)
{
	this->direction = newDir;
}