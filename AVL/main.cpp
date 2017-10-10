#include "AVLtree.h"
#include <iostream>

int main()
{
	AVLtree<int> myAvl;
	
	myAvl.insert(4);
	myAvl.insert(1);
	myAvl.insert(7);
	myAvl.insert(7);
	myAvl.insert(17);
	myAvl.insert(3);
	myAvl.insert(2);
	myAvl.insert(71);
	myAvl.insert(6);

	myAvl.traversalLcr();
	std::cout << std::endl;
	myAvl.remove(0);
	myAvl.remove(4);
	myAvl.remove(1);
	myAvl.remove(7);

	myAvl.traversalLcr();

	system("pause");
	return 0;
}