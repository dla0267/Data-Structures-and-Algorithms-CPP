/*
 * Robot.h
 *
 *  Created on: Jan 22, 2018
 *      Author: Yuun
 */

#pragma once
#include "Point.h"
#include <iostream>
using namespace std;

class Robot {
public:
  Robot();
  Robot(Point position, Point treasure);
  virtual ~Robot();

  Point getCurrentPosition() const;
  Point getTreasure() const;
  void setRobot(int x, int y);
  void setTreasure(int x, int y);

  int ShortestPath();
  int xLimit() const;
  int yLimit() const;

  int NumOfPath(Point robot, Point treasure, string path, int xLimit, int yLimit);
  bool solutionOrNot(const string& path) const;

  friend ostream& operator<<(ostream &outStream, const Robot& robot);
  friend istream& operator>>(istream &inStream, Robot &robot);

private:
  Point currentPosition;
  Point treasure;
  int count;
};
