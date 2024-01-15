
#include <iostream>
#include "stack.h"
int main()
{
	stack s1, s2;
	// pushing the values into stack 1
	s1.push(5);
	s1.push(8);
	s1.push(9);
	s2 = s1; // assignment operator invokes here
	stack s3 = s2; // copy constuctor  invokes here

	std::cout << "Values of stack 1" << std::endl;
	std::cout << s1.top() << std::endl;
	std::cout << " After poping " << std::endl;
	s1.pop();
	std::cout << s1.top() << std::endl;
	std::cout << " After poping " << std::endl;
	s1.pop();
	std::cout << s1.top() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	if (s1.Full())
	{
		std::cout << "stack 1 is full" << std::endl;
	}
	else
		std::cout << "stack 1 is not full" << std::endl;


	if (s1.Empty())
	{
		std::cout << "stack 1 is Empty" << std::endl;
	}
	else
		std::cout << "stack 1 is not Empty" << std::endl;
	std::cout << "The size of Stack 1 After popping  is " << s1.size() << std::endl;

	std::cout << "Values of stack 2" << std::endl;


	std::cout << s2.top() << std::endl;
	s2.pop();
	std::cout << " After poping " << std::endl;

	std::cout << s2.top() << std::endl;
	s2.pop();
	std::cout << " After poping " << std::endl;

	std::cout << s2.top() << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Values of stack 3" << std::endl;

	std::cout << s3.top() << std::endl;
	s3.pop();
	std::cout << " After poping " << std::endl;

	std::cout << s3.top() << std::endl;
	s3.pop();
	std::cout << " After poping " << std::endl;

	std::cout << s3.top() << std::endl;












}