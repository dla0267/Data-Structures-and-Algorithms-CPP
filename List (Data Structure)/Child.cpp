#include "stdafx.h"
#include "Child.h"
#include <iostream>

Child::Child() : firstName(""), lastName(""), age(0)
{
}

Child::Child(string theFirstName, string theLastName, int theAge) :
	firstName(theFirstName), lastName(theLastName), age(theAge)
{
}

Child::~Child() {
}

string Child::getLastName() const
{
	return lastName;
}

string Child::getFirstName() const
{
	return firstName;
}

int Child::getAge() const
{
	return age;
}

void Child::setLastName(const string &lastName)
{
	this->lastName = lastName;
}

void Child::setFirstName(const string &firstName)
{
	this->firstName = firstName;
}

void Child::setAge(const int &age)
{
	this->age = age;
}
bool Child::operator==(const Child &child2) const
{
	if ((this->lastName == child2.lastName) && (this->firstName == child2.firstName) && (this->age == child2.age)) {
		return true;
	}
	else
	{
		return false;
	}
}

bool Child::operator!=(const Child &child2) const
{
	return !(*this == child2);
}

bool Child::operator>(const Child &child2) const
{
	if (lastName > child2.lastName)
	{
		return true;
	}
	if (lastName == child2.lastName && firstName > child2.firstName)
	{
		return true;
	}
	if (lastName == child2.lastName && firstName == child2.firstName &&
		age > child2.age)
	{
		return true;
	}
	return false;
}
bool Child::operator>=(const Child &child2) const
{
	return (*this > child2 || *this == child2);
}
bool Child::operator<(const Child &child2) const
{
	if (lastName < child2.lastName)
	{
		return true;
	}
	if (lastName == child2.lastName && firstName < child2.firstName)
	{
		return true;
	}
	if (lastName == child2.lastName && firstName == child2.firstName && age < child2.age)
	{
		return true;
	}
	return false;
}

bool Child::operator<=(const Child &child2) const
{
	return (*this < child2 || *this == child2);
}

Child& Child::operator=(const Child &child2)
{
	lastName = child2.lastName;
	firstName = child2.firstName;
	age = child2.age;
	return *this;
}

ostream& operator<<(ostream &outStream, const Child &child)
{
	outStream << child.getFirstName() << child.getLastName() << child.getAge();
	return outStream;
}

istream& operator>>(istream &inStream, Child &child)
{
	int age;
	string firstName, lastName;
	inStream >> firstName >> lastName >> age;

	child.setFirstName(firstName);
	child.setLastName(lastName);
	child.setAge(age);
	return inStream;
}
