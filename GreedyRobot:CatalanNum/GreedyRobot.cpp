/*
 * GreedyRobot.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: Yuun
 */

#include "stdafx.h"
#include "Point.h"
#include "Robot.h"
#include <string>
using namespace std;


int main()
{
  Point robot1(1, 1);
  Point treasure(4, 4);
  Point treasure2(1, 4);
  Point treasure3(3, -1);
  Point treasure4(-1, 3);

  Robot robot1234;
  cout << "input coordinates of robot and treasure: ";
  cin >> robot1234;
  cout << robot1234 << endl;

  Robot robo11(robot1, treasure);
  cout << robo11 << endl;
  cout << endl;

  Robot robo12(robot1, treasure2);
  cout << robo12 << endl;
  cout << endl;

  Robot robo13(robot1, treasure3);
  cout << robo13 << endl;
  cout << endl;

  Robot robo14(robot1, treasure4);
  cout << robo14 << endl;
  cout << endl;

  Robot robo15(treasure, robot1);
  cout << robo15 << endl;
  cout << endl;

  return 0;
}
