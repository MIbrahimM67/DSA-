#include <iostream>
#include "forward_list.h"
int main()
{
	forward_list f1,f2;	
	f1.push_front(5);
	f1.push_front(5);
	f1.push_front(5);
	f1.push_front(3);
	f1.push_front(3);
	f1.push_front(3);
	f1.push_front(1);
	f2.push_front(6);
	f2.push_front(4);
	f2.push_front(2);


	
	f1.unique();
	f1.reset();
	while (!(f1.is_last()))
	{
		std::cout << f1.get_next();
	}

	f1.merge(f2);
	std::cout << std::endl;

	f1.reset();
	while (!(f1.is_last()))
	{
		std::cout << f1.get_next();
	}




}

