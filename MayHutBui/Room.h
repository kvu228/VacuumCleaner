#pragma once
#include "Grid.h";

#include <vector>;
#include<string>;
#include<fstream>;

class Room
{
private:
	int height;
	int width;
	
protected:
	

public:
	Room();
	~Room();
	vector <vector<Grid*>> roomLayout;

	void printRoom();

	//void printRoom();

	int getHeight();
	int getWidth();
};

