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
		std::cout << "***********double[5]List Test\n";
		double a = 5.7;
		List <double> doubleArrList(new double[5]);

		doubleArrList.Add(new double[5]);
		doubleArrList.Add(new double[5]);

		for (int i = 1; i < 6; i++)
		{
			doubleArrList.Find(0)[i - 1] = i * 1;
			doubleArrList.Find(1)[i - 1] = i * 2;
			doubleArrList.Find(2)[i - 1] = i * 3;
		}
		for (int i = 0; i < doubleArrList.GetCount(); i++)
			std::cout << std::endl << doubleArrList.Find(i)[0]<< doubleArrList.Find(2)[1] << std::endl;
		std::cout << "\nFind itemIndex 2:";
		std::cout << std::endl << doubleArrList.Find(2)[0]<< doubleArrList.Find(2)[1] << std::endl;
		doubleArrList.RemoveAt(1);
		std::cout << "\nFirst item removed. New first item: " << doubleArrList.Find(1)[0]<< doubleArrList.Find(1)[1] << std::endl;
		std::cout << "\ndoubleList: \n";
		for (int i = 0; i < doubleArrList.GetCount(); i++)
			std::cout << std::endl << doubleArrList.Find(i)[0]<< doubleArrList.Find(i)[1] << std::endl;
		for (int i = 0; i < doubleArrList.GetCount(); i++)
		{
			double* pTmpDouble = doubleArrList.Find(i);
			doubleArrList.RemoveAt(i);
			delete pTmpDouble;
		}
	}
	{
		std::cout << "***********List of doubleList Test\n";
		double a = 5.7;
		List <List<double>> doubleList(new List<double>(new double(2.5)));

		doubleList.Add(new List<double>(new double(3.5)));
		doubleList.Add(new List<double>(new double(4.5)));
		std::cout << "List(2.5) List(3.5) List(4.5) Added to list\n";
		for (int i = 0; i < doubleList.GetCount(); i++)
			std::cout << std::endl << *doubleList.Find(i)->Find(0) << std::endl;
		std::cout << "\nFind itemIndex 2:";
		std::cout << std::endl << *doubleList.Find(2)->Find(0) << std::endl;
		delete doubleList.Find(1);
		doubleList.RemoveAt(1);
		std::cout << "\nFirst item removed. New first item: " << *doubleList.Find(1)->Find(0)<< std::endl;
		std::cout << "\ndoubleList: \n";
		for (int i = 0; i < doubleList.GetCount(); i++)
			std::cout << std::endl << *doubleList.Find(i)->Find(0) << std::endl;
		for (int i = 0; i < doubleList.GetCount(); i++)
			delete doubleList.Find(i);
		doubleList.Clear();
	}

    return 0;
}

