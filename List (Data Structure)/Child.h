#pragma once
#include <string>
using namespace std;

class Child {
public:
	Child();
	Child(string firstName, string lastName, int age);
	virtual ~Child();

	string getLastName() const;
	string getFirstName() const;
	int getAge() const;
	void setLastName(const string &lastName);
	void setFirstName(const string &firstName);
	void setAge(const int &age);

	bool operator==(const Child &child2) const;
	bool operator!=(const Child &child2) const;
	bool operator>(const Child &child2) const;
	bool operator>=(const Child &child2) const;
	bool operator<(const Child &child2) const;
	bool operator<=(const Child &child2) const;
	Child& operator=(const Child &child2);

	friend ostream& operator<<(ostream &outStream, const Child &child);
	friend istream& operator>>(istream &inStream, const Child &child);
private:
	string firstName;
	string lastName;
	int age;
};
