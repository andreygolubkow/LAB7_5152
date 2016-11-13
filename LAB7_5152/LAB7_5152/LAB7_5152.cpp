#include <iostream>
#include "List.h"
#include "Person.h"
#include "Sex.h"

int main()
{
	{
		std::cout << "***********doubleList Test\n";
		double a = 5.7;
		List <double> doubleList(new double(5.6));

		doubleList.Add(new double(7.8));
		doubleList.Add(new double(2.3));
		std::cout << "5.6 Added to list, 7.8 Added to list, 2.3 Added to list\n";
		for (int i = 0; i < doubleList.GetCount(); i++)
			std::cout << std::endl << *doubleList.Find(i) << std::endl;
		std::cout << "\nFind itemIndex 2:";
		std::cout << std::endl << *doubleList.Find(2) << std::endl;
		delete doubleList.Find(1);
		doubleList.RemoveAt(1);
		std::cout << "\nFirst item removed. New first item: " << *doubleList.Find(1) << std::endl;
		std::cout << "\ndoubleList: \n";
		for (int i = 0; i < doubleList.GetCount(); i++)
			std::cout << std::endl << *doubleList.Find(i) << std::endl;
		for (int i = 0; i < doubleList.GetCount(); i++)
			delete doubleList.Find(i);
		doubleList.Clear();
	}

	{
		std::cout << "***********personList Test\n";
		double a = 5.7;
		List <Person> personList(new Person("Andrey", "Golubkow", 19, Male));

		personList.Add(new Person("Ivan", "Ivanov", 23, Male));
		personList.Add(new Person("Mary", "Jane", 20, Female));
		std::cout << "Andrey Added to list, Ivan Added to list, Mary Added to list\n";
		for (int i = 0; i < personList.GetCount(); i++)
			std::cout << std::endl << *personList.Find(i) << std::endl;
		std::cout << "\nFind itemIndex 2:";
		std::cout << std::endl << *personList.Find(2) << std::endl;
		personList.RemoveAt(1);
		std::cout << "\nFirst item removed. New first item: " << *personList.Find(1) << std::endl;
		std::cout << "\npersonList: \n";
		for (int i = 0; i < personList.GetCount(); i++)
			std::cout << std::endl << *personList.Find(i) << std::endl;
		for (int i = 0; i < personList.GetCount(); i++)
		{
			Person* pTmpPerson = personList.Find(i);
			personList.RemoveAt(i);
			delete pTmpPerson;
		}
	}
	{
		std::cout << "***********personList Test\n";
		double a = 5.7;
		List <double[5]> doubleArrList(new[5] double);

		personList.Add(new Person("Ivan", "Ivanov", 23, Male));
		personList.Add(new Person("Mary", "Jane", 20, Female));
		std::cout << "Andrey Added to list, Ivan Added to list, Mary Added to list\n";
		for (int i = 0; i < personList.GetCount(); i++)
			std::cout << std::endl << *personList.Find(i) << std::endl;
		std::cout << "\nFind itemIndex 2:";
		std::cout << std::endl << *personList.Find(2) << std::endl;
		personList.RemoveAt(1);
		std::cout << "\nFirst item removed. New first item: " << *personList.Find(1) << std::endl;
		std::cout << "\ndoubleList: \n";
		for (int i = 0; i < personList.GetCount(); i++)
			std::cout << std::endl << *personList.Find(i) << std::endl;
		for (int i = 0; i < personList.GetCount(); i++)
		{
			Person* pTmpPerson = personList.Find(i);
			personList.RemoveAt(i);
			delete pTmpPerson;
		}
	}


    return 0;
}

