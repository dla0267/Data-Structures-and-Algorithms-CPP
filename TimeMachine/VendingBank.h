/*
 * VendingBank.h
 *
 *  Created on: Jan 6, 2018
 *      Author: Yuun
 */

#ifndef SRC_VENDINGBANK_H_
#define SRC_VENDINGBANK_H_

#pragma once
#include "Snack.h"  //assume that there is a class for snack in vending machine
#include <string>
#include <iostream>

class VendingBank
{
public:
  VendingBank();
  VendingBank(int id);
  VendingBank(int id, double balance);
  ~VendingBank();

  // getters and setters
  int getVendingBankId() const;

  int getNumOfQuarter() const;
  int setNumOfQuarter(const int &theQuarter);

  int getNumOfDime() const;
  int setNumOfDime(const int &theDime);

  int getNumOfNickel() const;
  int setNumOfNickel(const int &theNickel);

  int getNumOfPenny() const;
  int setNumOfPenny(const int &thePenny);

  double getBalance() const;
  bool setBalance(const int &id, const int &quaters, const int &dimes,
		  	  	  const int &nickels, const int &pennys);

  // Action
  double DepositPayment(Snack snackType, int numOfQuater, int numOfDime, //
		  	  	  	    int NumOfNickel, int NumOfPenny);
  bool ReturnChange(const double &amount);
  bool isEmpty() const;
  bool availableChange(const Snack &snackType);

  // operator overloading
  VendingBank operator-(const VendingBank &rat) const;
  VendingBank& operator-=(const VendingBank &rat);
  VendingBank operator+(const VendingBank &rat) const;
  VendingBank& operator+=(const VendingBank &rat);

  bool operator==(const VendingBank &rat) const;
  bool operator!=(const VendingBank &rat) const;

private:
	int id;
	int numOfQuarter;
	int numOfDime;
	int numOfNickel;
	int numOfPenny;
	double balance;
};

#endif /* SRC_VENDINGBANK_H_ */
