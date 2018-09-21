/*
* Robot.cpp
*
*  Created on: Jan 22, 2018
*      Author: Yuun
*/

#include "stdafx.h"
#include "Robot.h"
#include <string>
#include <iostream>


Robot::Robot() : currentPosition(0, 0), treasure(0, 0), count(0)
{
}


Robot::Robot(Point givenPosition, Point theTreasure) :
    currentPosition(givenPosition), treasure(theTreasure)
{
  count = NumOfPath(currentPosition, treasure, "", xLimit(), yLimit());
}

Robot::~Robot()
{
}

Point Robot::getCurrentPosition() const
{
  return currentPosition;
}

Point Robot::getTreasure() const
{
  return treasure;
}

void Robot::setRobot(int x, int y)
{
  currentPosition.setPoint(x, y);
}

void Robot::setTreasure(int x, int y)
{
  treasure.setPoint(x, y);
}

int Robot::ShortestPath()
{
  return currentPosition.getDistance(treasure);
}

int Robot::xLimit() const
{
  return abs(treasure.getX() - currentPosition.getX());
}

int Robot::yLimit() const
{
  return abs(treasure.getY() - currentPosition.getY());
}

int Robot::NumOfPath(Point robot, Point treasure, string path,
  int xLimit, int yLimit)
{
  if (path.length() == ShortestPath()) {
    // Check if robot found a treasure or not
    if (xLimit == 0 && yLimit == 0 && solutionOrNot(path)) {
	  cout << path << endl;
	  return 1;
	} else {
	  return 0;
	}
  } else {
	if ((robot.getX() <= treasure.getX()) && // when the treasure locates in NorthEast
		(robot.getY() <= treasure.getY())) {
      return NumOfPath(robot.PlusX(), treasure, path + "E",
	                   xLimit - 1, yLimit)
	      + NumOfPath(robot.PlusY(), treasure,
					  path + "N", xLimit, yLimit - 1);
	} else if ((robot.getX() <= treasure.getX()) && // when the treasure locates in SouthEast
			   (robot.getY() >= treasure.getY())) {
	  return NumOfPath(robot.PlusX(), treasure, path + "E",
				       xLimit - 1, yLimit)
	      + NumOfPath(robot.MinusY(), treasure, path + "S",
					  xLimit, yLimit - 1);
	} else if ((robot.getX() >= treasure.getX()) && // when the treasure locates in NorthWest
	           (robot.getY() <= treasure.getY())) {
	  return NumOfPath(robot.MinusX(), treasure,
	           		   path + "W", xLimit - 1, yLimit)
	      + NumOfPath(robot.PlusY(), treasure,
					  path + "N", xLimit, yLimit - 1);
	} else {   // When the treasure locates in SouthWest
	  return NumOfPath(robot.MinusX(), treasure,
		      		   path + "W", xLimit - 1, yLimit)
	      + NumOfPath(robot.MinusY(), treasure,
					  path + "S", xLimit, yLimit - 1);
	}
  }
}

// it returns true if the path doesn't consist of more than 3 consecutive moves
bool Robot::solutionOrNot(const string& path) const
{
  bool movedRight;
  int move = 1; // tracking number of movements toward same direction
  int length = path.length() - 1;
  for (int i = 0; i < length; i++) {
    if (path.at(i) == path.at(i + 1)) {
	  move++;
	  if (move > 2) { // made more than three moves toward same direction
        return false;
      }
	} else {
	  move = 1;
	}
  }
  if (move <= 2) {
    movedRight = true;
  } else {
    movedRight = false;
  } 
  return movedRight;
}

ostream& operator<<(ostream &outStream, const Robot &robot) {
  return outStream << "Number of paths: " << robot.count << endl;
}

istream& operator>>(istream &inStream, Robot &robot)
{
  int a, b, c, d;
  inStream >> a >> b >> c >> d;
  robot.currentPosition.setPoint(a, b);
  robot.treasure.setPoint(c, d);
  robot.count = robot.NumOfPath(
      robot.currentPosition, robot.treasure,
      "", robot.xLimit(), robot.yLimit());
  return inStream;
}
