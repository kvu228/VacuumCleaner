#include "Vacuum.h"
Vacuum::Vacuum(Room* room)
{
	name = "abc";
	brand = "xyz";
	direction = Direction::up;
	vacuumStep = 0;
	vacuumCoord = new Coordinate;
	batteryStep = 500;
	battery = (float) 100;
	this->room = room;
}

Vacuum::~Vacuum() {};

void Vacuum::scanRoom() {
	for (auto row : this->room->roomLayout)
	{
		for (auto cell : row) 
		{
			cout << cell->getRep();
		}
		cout << endl << flush;
	}
	string faceString;
	switch (getDirection()) {
	case Direction::up: faceString = "Len"; break;
	case Direction::down: faceString = "Xuong"; break;
	case Direction::left: faceString = "Trai"; break;
	case Direction::right: faceString = "Phai"; break;
	}
	cout << endl << "May hut bui: " << this->name<< " - "<<this->brand;
	cout << endl << "Toa do Vacuum (" << vacuumCoord->x << ", " << vacuumCoord->y << ") huong " 
		<< faceString << '\r' << endl;

	cout << "Vacuum da di: " << totalStep << " buoc."<<endl
		<<"Pin hien tai: "<<battery <<"%"<< endl
		<<"Toa do Power Charge (" << this->getPowerChargeCoor()->getCoordinate()->x << ", " 
		<< this->getPowerChargeCoor()->getCoordinate()->y << ")" << flush;

}

void Vacuum::turnLeft()
{
	switch (direction)
	{
	case Direction::up:
		direction = Direction::left;
		break;
	case Direction::down:
		direction = Direction::right;
		break;
	case Direction::left:
		direction = Direction::down;
		break;
	case Direction::right:
		direction = Direction::up;
		break;

	}
}

void Vacuum::turnRight()
{
	switch (direction)
	{
	case Direction::up:
		direction = Direction::right;
		break;
	case Direction::down:
		direction = Direction::left;
		break;
	case Direction::left:
		direction = Direction::up;
		break;
	case Direction::right:
		direction = Direction::down;
		break;
	}
}

void Vacuum::turnOver()
{
	switch (direction)
	{
	case Direction::up:
		direction = Direction::down;
		break;
	case Direction::down:
		direction = Direction::up;
		break;
	case Direction::left:
		direction = Direction::right;
		break;
	case Direction::right:
		direction = Direction::left;
		break;
	}
}

Direction Vacuum::getDirection()
{
	return this->direction;
}

void Vacuum::setDirection(Direction newDir)
{
	this->direction = newDir;
}

bool Vacuum::Move()
{
	sleep_until(system_clock::now() + microseconds (sleepTime));
	clearScreen();
	scanRoom();

	switch (this->getDirection()) {
	case Direction::down:
		if (vacuumCoord->y + 1 < this->room->getHeight()
			&& (this->room->roomLayout[vacuumCoord->y + 1][vacuumCoord->x]->getRep() == '_'
				|| this->room->roomLayout[vacuumCoord->y + 1][vacuumCoord->x]->getRep() == 'D'))
		{
			setVacuum(false);
			vacuumCoord->y++;
			setVacuum(true);
			vacuumStep++;
			totalStep++;
			battery = (1.0-vacuumStep*1.0 / batteryStep)*100;
			return true;
		}
		return false;
	case Direction::up:
		if (vacuumCoord->y - 1 >= 0
			&& (this->room->roomLayout[vacuumCoord->y - 1][vacuumCoord->x]->getRep() == '_'
				|| this->room->roomLayout[vacuumCoord->y - 1][vacuumCoord->x]->getRep() == 'D'))
		{
			setVacuum(false);
			vacuumCoord->y--;
			setVacuum(true);
			vacuumStep++;
			totalStep++;
			battery = (1.0-vacuumStep*1.0 / batteryStep)*100;
			return true;
		}
		return false;
	case Direction::left:
		if (vacuumCoord->x - 1 >= 0
			&& (this->room->roomLayout[vacuumCoord->y][vacuumCoord->x - 1]->getRep() == '_'
				|| this->room->roomLayout[vacuumCoord->y][vacuumCoord->x - 1]->getRep() == 'D'))
		{
			setVacuum(false);
			vacuumCoord->x--;
			setVacuum(true);
			vacuumStep++;
			totalStep++;
			battery = (1.0-vacuumStep*1.0 / batteryStep)*100;
			return true;
		}
		return false;
	case Direction::right:
		if (vacuumCoord->x + 1 < this->room->getWidth()
			&& (this->room->roomLayout[vacuumCoord->y][vacuumCoord->x + 1]->getRep() == '_'
				|| this->room->roomLayout[vacuumCoord->y][vacuumCoord->x + 1]->getRep() == 'D'))
		{
			setVacuum(false);
			vacuumCoord->x++;
			setVacuum(true);
			vacuumStep++;
			totalStep++;
			battery = (1.0-vacuumStep*1.0 / batteryStep)*100;
			return true;
		}
		return false;
	}
	return false;
}

void Vacuum::vacuumClean()
{
    if (this->room->roomLayout[vacuumCoord->y][vacuumCoord->x]->getObject()->getItem() == Item::dirt)
    {
        this->room->roomLayout[vacuumCoord->y][vacuumCoord->x]->setObject(Item::clean);
    }
}

void Vacuum::placeVacuum()
{
    bool placed = false;
    while (!placed) {
        //tọa độ x,y là random
        int x = rand()%this->room->getWidth();
        int y = rand() % this->room->getHeight();

		//Đặt máy tại powerCharge
		/*int x = this->getPowerChargeCoor()->getCoordinate()->x;
		int y = this->getPowerChargeCoor()->getCoordinate()->y;*/

        if (this->room->roomLayout[y][x]->getRep() == '_' 
            || this->room->roomLayout[y][x]->getRep() == 'D')
        {
			setVacuumCoord(x, y);
			setVacuum(true);
            placed = true;
        }
    }
}

void Vacuum::setVacuum(bool b)
{
	this->room->roomLayout[vacuumCoord->y][vacuumCoord->x]->getObject()->setDirection(this->getDirection());
	this->room->roomLayout[vacuumCoord->y][vacuumCoord->x]->setVacuum(b);
}

Coordinate* Vacuum::getVacuumCoord()
{
	return vacuumCoord;
}

void Vacuum::setVacuumCoord(int x, int y)
{
	this->vacuumCoord->x = x;
	this->vacuumCoord->y = y;
}

float Vacuum::getBattery()
{
	return this->battery;
}

void Vacuum::setDeath()
{
	this->battery = 0;
	this->vacuumStep = this->batteryStep;
}

void Vacuum::Charged()
{
	/*int x = this->getPowerChargeCoor()->getCoordinate()->x;
	int y = this->getPowerChargeCoor()->getCoordinate()->y;
	this->setVacuumCoord(x, y);*/
	battery = 100;
	vacuumStep = 0;
	
}

Grid* Vacuum::getPowerChargeCoor()
{
	for (int y = 0; y < this->room->getHeight() ; y++)
	{
		for (int x = 0; x < this->room->getWidth(); x++)
		{
			if (this->room->roomLayout[y][x]->getRep()=='P')
			{
				Grid* temp = new Grid(y, x);
				return temp;
			}
		}
	}
}

void Vacuum::clearScreen() {
	cout << "\x1B[2J\x1B[H";
}

