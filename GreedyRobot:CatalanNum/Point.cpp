/*
 * Point.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: Yuun
 */

#include "stdafx.h"
#include "Point.h" d
#include <iostream>
using namespace std;

Point::Point() : x(0), y(0)
{
}

Point::Point(int theX, int theY) : x(theX), y(theY)
{
}

Point::~Point() {
}

int Point::getX() const
{
  return x;
}

int Point::getY() const
{
  return y;
}

void Point::setX(int newX)
{
  x = newX;
}

void Point::setY(int newY)
{
  y = newY;
}

int Point::getDistance(Point other)
{
  return abs(x - other.x) + abs(y - other.y);
}

void Point::setPoint(int theX, int theY)
{
  x = theX;
  y = theY;
}

Point Point::PlusX() {
  Point result = *this;
  result.x++;
  return result;
}

Point Point::MinusX()
{
  Point result = *this;
  result.x--;
  return result;
}

Point Point::PlusY() {
  Point result = *this;
  result.y++;
  return result;
}

Point Point::MinusY() {
  Point result = *this;
  result.y--;
  return result;
}




