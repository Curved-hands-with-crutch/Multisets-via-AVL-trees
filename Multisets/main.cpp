#include <iostream>
#include "Multisets.h"
#include <ctime>
#include "AVLtree.h"
#include <string>
#include <set>
#include <ctime>

int main()
{

	srand(time(NULL));
	Multiset<int> mySet;

	for (size_t i = 0; i < 14; i++)
	{
		size_t dummy = rand() % 100;
		std::cout << dummy << " ";
		mySet.insert(dummy);
	}
	
	for (size_t i = 0; i < 20; i++)
	{
		size_t dummy = rand() % 100;
		std::cout << mySet.contains(dummy) << " " << dummy << "\n";
	}

	mySet.saveToFile("here.txt");

	Multiset<double> mySet1;
	mySet1.loadFromFile("here.txt");
	mySet1.print();

	//mySet1.loadFromFile("here.txt");
	//mySet1.print();
	//mySet.insert(5);
	//mySet.insert(4);
	//mySet.insert(1);
	//mySet.insert(55);
	//mySet.insert(52);
	//mySet.insert(25);
	//mySet.insert(15);
	//mySet.insert(555);
	//mySet.insert(1);
	//mySet.insert(67);
	//mySet.insert(22);
	//std::cout << mySet.contains(4);
	//std::cout << mySet.contains(5);
	//std::cout << mySet.contains(1);
	//std::cout << mySet.contains(55);
	//std::cout << mySet.contains(52);
	//std::cout << mySet.contains(25);
	//std::cout << mySet.contains(15);
	//std::cout << mySet.contains(555);
	//std::cout << mySet.contains(1);
	//std::cout << mySet.contains(67);
	//std::cout << mySet.contains(22);

	

//	std::set<int> goodSet;
	std::multiset<int> goodSet;
	Multiset<int> badSet;
//-------------------------------Insert-comparison-------------------------------
	std::cout.precision(8);
	time_t start = clock(),
		finish;

	for (size_t i = 0; i < 100000; i++)
		goodSet.insert(rand() % 10000);
	finish = clock() - start;

	start = clock();
	for (size_t i = 0; i < 100000; i++)
		badSet.insert(rand() % 10000);
	
	std::cout << "For 100000 inserts operations:\nMy multiset time required: "
		<< double(clock() - start) / CLOCKS_PER_SEC << " seconds\nAnd for STL multiset: "
		<< double(finish) / CLOCKS_PER_SEC << std::endl;

//-------------------------------Remove-comparison-------------------------------
	start = clock();
	for (size_t i = 0; i < 100000; i++)
		goodSet.erase(rand() % 10000);
	finish = clock() - start;

	start = clock();
	for (size_t i = 0; i < 100000; i++)
		badSet.remove(rand() % 10000);

	std::cout << "For 100000 removals operations:\nMy multiset time required: "
		<< double(clock() - start) / CLOCKS_PER_SEC << " seconds\nAnd for STL multiset: "
		<< double(finish) / CLOCKS_PER_SEC << std::endl;



	system("pause");
	return 0;
}
