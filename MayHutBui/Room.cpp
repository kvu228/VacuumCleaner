#include "Room.h"

Room::Room() 
{
    ifstream inFile;
    bool gotFile = false;
    while (!gotFile) {
        inFile.open("../room.txt");
        if (!inFile.is_open()) 
        {
            cout << "Failed to find room file." << std::endl;
            continue;
        }
        gotFile = true;
        string line;
        int lineCount = 0;
        while (getline(inFile, line)) 
        {
            lineCount++;
            if (lineCount == 1) 
            {
                width = stoi(line);
            }
            else if (lineCount == 2) 
            {
                height = stoi(line);
                roomLayout = vector<vector<Grid*>>(height, vector<Grid*>(width, NULL));
            }
            else 
            {
                for (size_t i = 0; i < line.length(); ++i) 
                {
                    roomLayout[lineCount - 3][i] = new Grid(new Coordinate(lineCount - 3, i), line[i]);
                }
                /*for (int i = line.length(); i < width; ++i)
                {
                    roomLayout[lineCount - 3][i] = new Grid(new Coordinate(lineCount - 3, i), ' ');
                }*/
            }
        }
    }

    inFile.close();
};

Room::~Room() {};

void Room::printRoom()
{
    for (auto row : roomLayout)
    {
        for (auto cell : row)
        {
            cout << cell->getRep();
        }
        cout << endl << flush;
    }

}

int Room::getHeight()
{
    return this->height;
}

int Room::getWidth()
{
    return this->width;
}

