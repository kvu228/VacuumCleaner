#include"Room.h"
#include"Vacuum.h"
#include"Solution.h"

int main() {
	Room room;
	Room* pRoom = &room;
	
	int selection;
	do
	{
		cout << "\n-----------------\n";
		cout << "\nChon thao thac can nhap: ";
		cout << "\nPhim 1: Hien thi phong";
		cout << "\nPhim 2: Don dep";
		cout << "\nPhim 0: Thoat\n";
		cin >> selection;
		if (selection != 0 && selection != 1 && selection != 2)
		{
			cout << "\nChi nhap gia tri trong day 0,1,2.\nVui long nhap lai: ";
			cin >> selection;
		}
		switch (selection)
		{
		case 1: {
			cout << "\n----------------- Hien thi phong -----------------\n";

			room.printRoom();
			break;
		}
		case 2: {
			cout << "\n----------------- Don phong -----------------\n";
			Vacuum Robot(pRoom);
			Vacuum* pRobot = &Robot;
			Robot.placeVacuum();
			Solution s;
			s.cleanRoom(pRobot);
			cout << "\nDone!";
			selection = 0;
			break;
		}
		
		default:
			break;
		}
	} while (selection != 0);

	return 1;
}
