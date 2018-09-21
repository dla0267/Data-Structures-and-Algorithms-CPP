/*
 * Point.h
 *
 *  Created on: Jan 24, 2018
 *      Author: Yuun
 */

#pragma once
#include <stdlib.h>


class Point {
public:
  Point();
  Point(int x, int y);
  virtual ~Point();

  int getX() const;
  int getY() const;
  void setX(int x);
  void setY(int y);

  int getDistance(Point other);
  void setPoint(int x, int y);	// do I need it?

  Point PlusX();
  Point PlusY();
  Point MinusX();
  Point MinusY();

private:
  int x;
  int y;
};

