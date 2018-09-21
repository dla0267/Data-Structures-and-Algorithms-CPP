/*
 * TimeMachine.cpp
 *
 *  Created on: Jan 6, 2018
 *      Author: Yuun
 */
//#include "stdafx.h"
#include "TimeSpan.h"

using namespace std;

int main()
{
  TimeSpan time1(1, 45, 600), time2(1.5, 400.5, 700);
  TimeSpan time3(-1, -23.8, 40), time4(-1.8, 43, 77);
  TimeSpan time5(0, 0, 0), time6(20, 80, 88);
  TimeSpan time7(21, 21, 28.4), time8(21, 21, 28.6);
  TimeSpan time9(32, 50), time10(66);
  TimeSpan time11;
  TimeSpan time13(67.3), time14(-84), time15(1500);
  TimeSpan time16(-58, 88), time17(-89, 99.3);
  TimeSpan time18(66, -77.3);
  TimeSpan time19(-33, -444, -44), time20(-1, -12.5, 69.4);
  TimeSpan time21(-33.5, -10.4, 70);
  time11 = time9 + time10;

  
  cout << "time1  : " << time1 << endl;
  cout << "time2  : " << time2 << endl;
  cout << "time3  : " << time3 << endl;
  cout << "time4  : " << time4 << endl;
  cout << "time5  : " << time5 << endl;
  cout << "time6  : " << time6 << endl;
  cout << "time7  : " << time7 << endl;
  cout << "time8  : " << time8 << endl;
  cout << "time9  : " << time9 << endl;
  cout << "time10 : " << time10 << endl;
  cout << "time11 : " << time11 << endl;
  cout << "time13 : " << time13 << endl;
  cout << "time14 : " << time14 << endl;
  cout << "time15 : " << time15 << endl;
  cout << "time16 : " << time16 << endl;
  cout << "time17 : " << time17 << endl;
  cout << "time18 : " << time18 << endl;
  cout << "time19 : " << time19 << endl;
  cout << "time20 : " << time20 << endl;
  cout << "time21 : " << time21 << endl;
  cout << endl;

  cout << "time1: " << time1 << endl;
  cout << "time2: " << time2 << endl;
  time1 += time2;
  cout << "updated time1 after adding time2: " << time1 << endl;
  cout << "time1 + time2 = " << time1 + time2 << endl;

  cout << "time1 is still " << time1 << endl;
  time1 -= time2;
  cout << "updated time1 after subtracting time2: " << time1 << endl;
  cout << time1 << endl;

  cout << "time1 - time2 = " << time1 - time2 << endl;
  cout << time1 << endl;
  cout << time3 << endl;
  cout << "time1 + time3 = " << time1 + time3 << endl;
  cout << endl;

  cout << "time 4 : " << time4 << endl;
  time4= -time4;
  cout << time4 << endl;
  cout << endl;
  cout << endl;
  cout << "time6 : " << time6 << endl;
  cout << "time7 : " << time7 << endl;
  cout << "time8 : " << time8 << endl;

  if (time6 == time7)
  {
    cout << "time6 and time7 are same" << endl;
  }
  else
  {
    cout << "nope" << endl;
  }
  if (time6 != time8)
  {
    cout << "time6 and time8 are different" << endl;
  }
  else
  {
    	cout << "they are same" << endl;
  }

  TimeSpan time12;
  cout << "cin : ";
  cin >> time12;
  cout << "time12 : " << time12 << endl;

  if (time12.setTime(111, 423 , 56)) {
    cout << time12 << endl;
  }
  return 0;
}


