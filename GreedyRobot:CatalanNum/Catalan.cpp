// Catalan.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int Catalan(int number);
int Catalan(int iterator, int number);

int main(int argc, char** argv)
{
  if (argc != 2) {
    cout << "You can only put one integer after command ";
  } else {
	int number = atoi(argv[1]);
	cout << Catalan(number) << endl;
  }
  return 0;
}

int Catalan(int number)
{
  if (number == 0 || number == 1) {
	return 1;
  } else if (number % 2 != 0) { // when the input is odd number
	return (2 * Catalan(0, number - 1))
	    + (Catalan(number / 2) * Catalan(number / 2));
  } else {// when the input is even number
    return 2 * Catalan(0, number - 1);
  }
}

// helper method for computing Catalan number with iterator to keep track
// how far it has computed the number.
int Catalan(int iterator, int number) {
  if (iterator < number) { 
	return Catalan(iterator) * Catalan(number)
	    + Catalan(iterator + 1, number - 1);
  } else {
	return 0;
  }
}
