#include "Grid.h"

Grid::Grid()
{
	hasRobot = false;
};

Grid::Grid(Coordinate* coord, Object* object)
{
    coordinate = coord;
    this->object = object;
    hasRobot = false;
    setRep();
}

Grid::Grid(Coordinate* coord, char rep)
{
    coordinate = coord;
    this->rep = rep;
    hasRobot = false;
    generateObject();
}

Grid::Grid(int y, int x)
{
    this->coordinate = new Coordinate();
    this->coordinate->x = x;
    this->coordinate->y = y;
    hasRobot = false;
}

Grid::~Grid() {
    delete coordinate;
    delete object;
}

Coordinate* Grid::getCoordinate() {
    return coordinate;
}

Object* Grid::getObject() {
    return object;
}

void Grid::setObject(Item item) {
    object->setItem(item);
}


void Grid::generateObject() {
    switch (rep) {
    case ' ': 
        object = new Object(Item::blank);
        break;
    case 'W':
        object = new Object(Item::wall);
        break;
    case '_':
        object = new Object(Item::clean);
        break;
    case 'D':
        object = new Object(Item::dirt);
        break;
    case 'P':
        object = new Object(Item::powerCharge);
        break;
    }
}

void Grid::setRep() {
    if (hasRobot==true)
    {
        if (object->getDirection() == Direction::blank)
        {
            rep = '@';
        }
        else
        {
            rep = 'x';
            switch (object->getDirection())
            {
            case Direction::up:rep = '^'; break;
            case Direction::down:rep = 'v'; break;
            case Direction::left:rep = '<'; break;
            case Direction::right:rep = '>'; break;
            }
        }
    }
    else
    {
        switch (object->getItem())
        {
        case Item::blank: rep = ' '; break;
        case Item::wall: rep = 'W'; break;
        case Item::clean: rep = '_'; break;
        case Item::dirt: rep = 'D'; break;
        case Item::powerCharge:rep = 'P'; break;
        }
    }
}

char Grid::getRep() {
    return rep;
}

void Grid::setVacuum(bool b) {
    hasRobot = b;
    setRep();
}

void Grid::gridInfo() {
    cout << "A " << rep << " at (" << coordinate->x << ", " << coordinate->y << ")." <<endl;
}