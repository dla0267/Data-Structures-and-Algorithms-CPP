/*
 * TimeSpan.cpp
 *
 *  Created on: Jan 6, 2018
 *      Author: Yuun
 */

//#include "stdafx.h"
#include "TimeSpan.h"
using namespace std;

TimeSpan::TimeSpan(): hours(0), minutes(0), seconds(0)
{
}

TimeSpan::TimeSpan(double theHours, double theMinutes, double theSeconds)
				: hours(theHours), minutes(theMinutes), seconds(theSeconds)
{
  int totalSecond = getTotalSeconds(theHours, theMinutes, theSeconds);
  hours =  totalSecond / 3600;
  minutes = (totalSecond - (hours * 3600)) / 60;
  seconds = totalSecond % 60;
}

TimeSpan::TimeSpan(double theMinutes, double theSeconds)
				: hours(0), minutes(theMinutes), seconds(theSeconds)
{
  int totalSecond = getTotalSeconds(0, theMinutes, theSeconds);
  hours =  totalSecond / 3600;
  minutes = (totalSecond - (hours * 3600)) / 60;
  seconds = totalSecond % 60;
}

TimeSpan::TimeSpan(double theSecond): hours(0), minutes(0), seconds(theSecond)
{
  int totalSecond = getTotalSeconds(0, 0, theSecond);
  hours =  totalSecond / 3600;
  minutes = (totalSecond - (hours * 3600)) / 60;
  seconds = totalSecond % 60;
}

TimeSpan::~TimeSpan()
{
}

int TimeSpan::getHours() const
{
  return hours;
}

int TimeSpan::getMinutes() const
{
  return minutes;
}

int TimeSpan::getSeconds() const
{
  return seconds;
}

bool TimeSpan::setTime(int hour, int minute, int second)
{
  *this = setTime(getTotalSeconds(hour, minute, second));
  return true;
}

TimeSpan TimeSpan::setTime(const int &totalSeconds) {
  TimeSpan time;
  time.hours =  totalSeconds / 3600;
  time.minutes = (totalSeconds - (time.hours * 3600)) / 60;
  time.seconds = totalSeconds % 60;
  return time;
}

int TimeSpan::getTotalSeconds(const double &hour, const double &minute,
							 const double &second)
{
	return round(hour * 3600 + minute * 60 + second);
}

int TimeSpan::getTotalSeconds() const
{
  return round(hours * 3600 + minutes * 60 + seconds);
}


TimeSpan TimeSpan::operator+(const TimeSpan &rightHandTimeSpan) const
{
  TimeSpan duration = *this;
  duration += rightHandTimeSpan;
  return duration;
}
TimeSpan TimeSpan::operator-(const TimeSpan &rightHandTimeSpan) const
{
  TimeSpan duration = *this;
  duration -= rightHandTimeSpan;
  return duration;
}

TimeSpan TimeSpan::operator-()
{
  TimeSpan time = *this;
  time.hours = -hours;
  time.minutes = -minutes;
  time.seconds = -seconds;
  return time;
}

TimeSpan& TimeSpan::operator+=(const TimeSpan &rightHandTimeSpan)
{
  int resultInSeconds = (*this).getTotalSeconds() + rightHandTimeSpan.getTotalSeconds();
  *this = setTime(resultInSeconds);
  return *this;
 }

TimeSpan& TimeSpan::operator-=(const TimeSpan &rightHandTimeSpan)
{
  int resultInSeconds = (*this).getTotalSeconds()
						  - rightHandTimeSpan.getTotalSeconds();
  *this = setTime(resultInSeconds);
  return *this;
}

bool TimeSpan::operator==(const TimeSpan &rightHandTimeSpan) const
{
  return (*this).getTotalSeconds() == rightHandTimeSpan.getTotalSeconds();
}

bool TimeSpan::operator!=(const TimeSpan &rightHandTimeSpan) const
{
  return (*this).getTotalSeconds() != rightHandTimeSpan.getTotalSeconds();
}

ostream& operator<<(ostream &outStream, const TimeSpan &duration)
{
  outStream << "Hours: " << duration.getHours() << ", Minutes: "
		  << duration.getMinutes() << ", Seconds: " << duration.getSeconds();
  return outStream;
}

istream& operator>>(istream &inStream, TimeSpan &duration)
{
  inStream >> duration.hours >> duration.minutes >> duration.seconds;
  duration = duration.setTime(duration.getTotalSeconds());
  return inStream;
}

