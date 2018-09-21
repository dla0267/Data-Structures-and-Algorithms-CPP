/*
 * TimeSpan.h
 *
 *  Created on: Jan 6, 2018
 *      Author: Yuun
 */

#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class TimeSpan
{
 public:
  // constructors
  TimeSpan();
  TimeSpan(double hours, double minutes, double seconds);
  TimeSpan(double minutes, double seconds);
  TimeSpan(double seconds);
  ~TimeSpan();

  // getters and setters
  int getHours() const;
  int getMinutes() const;
  int getSeconds() const;

  bool setTime(int hours, int minutes, int seconds);
  TimeSpan setTime(const int &totalSeconds);
  int getTotalSeconds(const double &hour, const double &minute,
		  	  	      const double &second);
  int getTotalSeconds() const;

  // operation overloading
  TimeSpan operator+(const TimeSpan &rightHandTimeSpan) const;
  TimeSpan& operator+=(const TimeSpan &rightHandTimeSpan);
  TimeSpan operator-(const TimeSpan &rightHandTimeSpan) const;
  TimeSpan& operator-=(const TimeSpan &rightHandTimeSpan);
  TimeSpan operator-();

  bool operator==(const TimeSpan &rightHandTimeSpan) const;
  bool operator!=(const TimeSpan &rightHandTimeSpan) const;

  friend ostream& operator<<(ostream &outStream, const TimeSpan &duration);
  friend istream& operator>>(istream &inStream, TimeSpan &duration);

private:
  int hours;
  int minutes;
  int seconds;
};
