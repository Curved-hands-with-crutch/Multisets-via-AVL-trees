#pragma once
#include "AVLtree.h"
#include <fstream>
#include <regex>

template<typename T>
class Multiset
{
private:
	AVLtree<T> set;

public:

	Multiset()
	{
		set = AVLtree<T>();
	}

	~Multiset()
	{
	//	set.~AVLtree<T>();
	}

	void insert(T val)
	{
		set.insert(val);
	}

	void remove(T val)
	{
		set.remove(val);
	}

	bool contains(T val)
	{
		return set.contains(val);
	}

	void print()
	{
		std::cout << set.traversalLcr("") << std::endl;
	}

	void saveToFile(char* filename)
	{
		std::ofstream fout(filename);
		fout << set.traversalLcr("");
		fout.close();
	}

	// Только для чисел. Целочисленные типы приводятся к double.
	void loadFromFile(char* filename)
	{
		std::ifstream fin(filename);
		char str[100];

		while (!fin.eof())
		{
			fin.getline(str, 100);
			set.insert(std::atof(str));
		}
		set.remove(0);
		fin.close();
	}

};