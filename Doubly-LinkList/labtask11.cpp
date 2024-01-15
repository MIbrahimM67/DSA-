#include <iostream>
#include"DoublyLinkList.h"

int main()
{
	list<int> l1;
	l1.push_front(1);
	l1.push_front(2);
	l1.push_front(3);
	l1.push_front(4);
	l1.push_front(5);



//	l1.push_back(4);
	l1.Display();
	l1.sort();
	std::cout << std::endl;
	std::cout<<" after sorting " << std::endl;
	l1.Display();
	std::cout << std::endl;
	

	std::cout << "before swapping first and last nodes";
	l1.Display();
	std::cout << std::endl;

	l1.SwappingEndNodes();
	std::cout << "After swapping first and last nodes";
	l1.Display();
	std::cout << std::endl;

	std::cout << "before swapping first and mid nodes";
	l1.Display();
	std::cout << std::endl;

	l1.SwappingFirst_MidNodes();
	std::cout << "After swapping first and last nodes";
	l1.Display();
	std::cout << std::endl;



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
