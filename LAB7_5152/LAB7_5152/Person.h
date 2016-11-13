#pragma once
#include "Sex.h"
#include <string>
#include <sstream>

class  Person
{
public:
	std::string Name;
	std::string Surname;
	Sex sex;
	Person(std::string firstName = "", std::string lastName = "", int age = 0, Sex seX = Male); //On Create
	Person(Person* person);
	void ReadPerson();
	int GetAge();
	void SetAge(int age);
	void FillRandomPerson();
	std::string GetDescription();
	std::string IntToStr(int x)
	{
		std::stringstream r;
		r << x;
		return r.str();
	};
	friend std::ostream& operator <<(std::ostream & os, Person const & person);
private:

protected:
	int Age = 0;
};

std::istream& operator >> (std::istream& is, Person& person);
std::ostream& operator <<(std::ostream & os, Person const & person);