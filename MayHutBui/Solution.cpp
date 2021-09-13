#include "Solution.h"
void Solution::cleanRoom(Vacuum* vacuum)
{
    cleanRoom(vacuum, Coordinate(0, 0));
}


void Solution::cleanRoom(Vacuum* vacuum, Coordinate curCoord)
{
    curCoord.x = vacuum->getVacuumCoord()->x;
    curCoord.y = vacuum->getVacuumCoord()->y;
    vacuum->vacuumClean();

    //set giá trị Viền là true
    /*for (int x = 0; x < vacuum->getRoomInfo()->getWidth(); x++)
    {
        visited[x][0] = true;
        visited[x][vacuum->getRoomInfo()->getWidth()] = true;
    }
    for (int y = 0; y < vacuum->getRoomInfo()->getHeight(); y++)
    {
        visited[0][y] = true;
        visited[vacuum->getRoomInfo()->getWidth()][0] = true;
    }*/
    
    for (int i = 0; i < 4; i++) // quay phải tối đa 4 lần, nếu thấy vị trí khả dụng và chưa visit thì move() 
    {
        cout << "\ncurCoord = (" << curCoord.x << "," << curCoord.y << ")";
        cout << visited[curCoord.x][curCoord.y]<<endl;

        Coordinate newPos = getNextPos(vacuum, curCoord);
        cout << "\nnextCoord = (" << newPos.x << "," << newPos.y << ")";
        cout << visited[newPos.x][newPos.y]<<endl;
        if (visited[newPos.x][newPos.y] == 0)
        {
            if (vacuum->Move())
            {
                visited[curCoord.x][curCoord.y]=true;
                cleanRoom(vacuum, newPos);
                
                if (vacuum->getBattery()<0)
                {
                    break;
                }

                if (vacuum->getBattery() < 1 )
                {
                    cout << "\nHet pin.";
                    char isCharge;
                    cout << "\nBan muon sac pin khong ('y' de  sac): ";
                    cin >> isCharge;
                    if (isCharge == 'y')
                    {
                        vacuum->Charged();
                    }
                    else
                    {
                        vacuum->setDeath();
                    }
                }
                if (vacuum->getBattery() < 20)
                {
                    cout << "\nSap het pin.";

                }
                
            }
            
        }
        vacuum->turnRight(); //Nếu đụng tường hoặc đi rồi thì quay phải
    }
    vacuum->turnRight(); //quay đầu
    vacuum->turnRight();
    vacuum->Move(); //lùi về 1 bước
    vacuum->turnRight();
    vacuum->turnRight();//quay đầu để tìm tiếp hướng tiếp theo
    
    /*if (vacuum->getBattery() < 1)
    {
        char isCharge;
        cout << "\nBan muon sac pin khong ('y' de  sac): ";
        cin >> isCharge;
        if (isCharge == 'y')
        {
            vacuum->Charged();
        }
    }*/
    
}

Coordinate Solution::getNextPos(Vacuum* vacuum, Coordinate curCoord)
{
    switch (vacuum->getDirection()) {
    case Direction::up: curCoord.y--; break;
    case Direction::down: curCoord.y++; break;
    case Direction::left: curCoord.x--; break;
    case Direction::right: curCoord.x++; break;
    }
    return curCoord;
}


//
//void Solution::cleanRoom(Vacuum* vacuum, Coordinate curCoord)
//{
//    curCoord.x = vacuum->getVacuumCoord()->x;
//    curCoord.y = vacuum->getVacuumCoord()->y;
//    visited[curCoord.x][curCoord.y] = true;
//    vacuum->vacuumClean();
//    while (vacuum->getBattery() >= 0)
//    {
//        if (vacuum->getBattery() > 20)
//        {
//            for (int i = 0; i < 4; i++) // quay 4 lần vẫn không đi tiếp được thì ngừng
//            {
//                Coordinate newPos = getNextPos(vacuum, curCoord);
//                if (visited[newPos.x][newPos.y] == false)
//                {
//                    cout << "\nx = (" << curCoord.x << "," << curCoord.y << ")";
//                    if (vacuum->Move()) {
//                        cleanRoom(vacuum, newPos);
//                    }
//                }
//                vacuum->turnRight(); //Nếu đụng tường hoặc đi rồi thì quay phải
//            }
//            vacuum->turnRight(); //quay đầu
//            vacuum->turnRight();
//            vacuum->Move(); //lùi về 1 bước
//            vacuum->turnRight();
//            vacuum->turnRight();//quay đầu để tìm tiếp hướng tiếp theo
//            break;
//        }
//        else
//        {
//            cout << "\nSap het pin";
//            char isContinue;
//            cout << "\nNhap 'y' de sac pin: ";
//            cin >> isContinue;
//            if (isContinue == 'y')
//            {
//                vacuum->Charged();
//            }
//            else
//            {
//
//            }
//
//            break;
//        }
//    }
//}


//void Solution::cleanRoom(Vacuum* vacuum, Coordinate curCoord)
//{
//
//    curCoord.x = vacuum->getVacuumCoord()->x;
//    curCoord.y = vacuum->getVacuumCoord()->y;
//    vacuum->vacuumClean();
//
//    //set giá trị Viền là 9 
//    for (int x = 0; x < vacuum->getRoomInfo()->getWidth(); x++)
//    {
//        visited[x][0] = 9;
//        visited[x][vacuum->getRoomInfo()->getWidth()] = 9;
//    }
//    for (int y = 0; y < vacuum->getRoomInfo()->getHeight(); y++)
//    {
//        visited[0][y] = 9;
//        visited[vacuum->getRoomInfo()->getWidth()][0] = 9;
//    }
//
//    for (int i = 0; i < 4; i++) // quay phải tối đa 4 lần, nếu thấy vị trí khả dụng và chưa visit thì move() 
//    {
//        cout << "\ncurCoord = (" << curCoord.x << "," << curCoord.y << ")";
//        cout << visited[curCoord.x][curCoord.y];
//
//        Coordinate newPos = getNextPos(vacuum, curCoord);
//        cout << "\nnextCoord = (" << newPos.x << "," << newPos.y << ")";
//        cout << visited[newPos.x][newPos.y];
//        if (visited[newPos.x][newPos.y] == 0)
//        {
//            if (vacuum->Move())
//            {
//                visited[curCoord.x][curCoord.y]++;
//                cleanRoom(vacuum);
//                if (vacuum->getBattery() < 20)
//                {
//                    cout << "\nSap het pin " << vacuum->getBattery();
//                    int x;
//                    cout << "Nhap 'Y' de sac: ";
//                    cin >> x;
//                    vacuum->Charged();
//                    visited.erase(1);
//                    cleanRoom(vacuum);
//
//                }
//            }
//
//        }
//        vacuum->turnRight(); //Nếu đụng tường hoặc đi rồi thì quay phải
//    }
//    vacuum->turnRight(); //quay đầu
//    vacuum->turnRight();
//    vacuum->Move(); //lùi về 1 bước
//    vacuum->turnRight();
//    vacuum->turnRight();//quay đầu để tìm tiếp hướng tiếp theo