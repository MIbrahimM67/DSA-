#include <iostream>

struct node {

	int val;
	node *next;
};


class queue
{
private:
	node *Front, *Back;
	int Size;
public:

	//MEMBERS
	queue()
	{
		Front = Back = nullptr;
		Size = 0;

	}

	queue(const queue & rhs) // copy constructor 
	{
		if (rhs.Front != nullptr)
		{
			Size = 0;
			*this = rhs;  // invoking assignment operator here

		}

	}
	queue &operator=(const queue&rhs) // assignment operator
	{
		
		if (this != &rhs)
		{
			node *temp = rhs.Front;	
			clear();
			while (temp != nullptr)
			{
				this->push(temp->val);
				temp = temp->next;
			}

		}

		return *this;

	}
	 // MODIFIERS

	void push(const int &val)
	{    
		if (this->Front!=nullptr && this->full()) // to check whether the queue is full or not before adding new nodes
		{
			throw" queue overflow";
		}
		else
		{
			if (Front == nullptr)
			{
				Front = new node;
				Back = Front;

			}
			else
			{
				Back->next = new node;
				Back = Back->next;

			}
			Back->val = val;
			Back->next = nullptr;
			Size++;
		}

	}
	void pop()
	{
		if (Front == nullptr)
		{
			throw"queue underflow";
		}
		node *temp;
		temp = Front->next;
		delete Front;
		Front = temp;
		Size--;
	}
	void clear()
	{
		while (Front != nullptr)
		{
			pop();
		}
		Front = Back = nullptr;
	}

	
	// Element ACCESSORS
	int front()const
	{
		return Front->val;
	}

	int back() const
	{
		return Back->val;

	}
	// Capacity 

	bool empty()const
	{
		if (Front == nullptr)
		{
			return true;
		}
		else 
		return false;
	}
	bool full()const
	{
		node *temp = new node;
		if (temp == nullptr)
		{ 
			return true;
		}
		else
		{
			delete temp;
			return false;
		}
	}
	int size() const
	{
		return Size;
	}
	// OPERATORS
	bool operator==(const queue &rhs)
	{
		if (size() != rhs.size())
		{
			return false;

		}
		else
		{
			node *temp = this->Front;
			node *Rhstemp = rhs.Front;
			while (Rhstemp != nullptr)
			{
				if (Rhstemp->val != temp->val)
				{
					return false;
				}
				Rhstemp = Rhstemp->next;
				temp = temp->next;
			}
			return true;
		}

	}

	bool operator!=(const queue &rhs)
	{
		if (*this == rhs)
		{
			return false;
		}
		return true;
	}

	bool operator<(const queue &rhs)
	{
		//if (size < rhs.size)
	//	{
	//		return true;
	//	}
	//	else
	//	{
			node *temp = this->Front;
			node *Rhstemp = rhs.Front;
			while (Rhstemp != nullptr && temp!=nullptr)     // doing the comparison by member by member, it terminates if either of them is nullptr
			{
				if (temp->val>Rhstemp->val)
				{
					return false;
				}
				Rhstemp = Rhstemp->next;
				temp = temp->next;
			}
			return true;
	//	}
	}
	bool operator>(const queue &rhs)
	{
		if (*this < rhs)
		{
			return false;
		}
		return true;
	}
	bool operator >=(const queue &rhs)
	{
		if (*this < rhs)
		{
			return false;
		}
		return true;
	}
	bool operator <=(const queue &rhs)
	{
		if (*this > rhs)
		{
			return false;
		}
		return true;
	}




	~queue()
	{ 
		while (Front != nullptr)
		{
			node *temp;
			temp = Front->next;
			delete Front;
			Front = temp;
		}
	}


};



int main()
{
	try {
		queue q1, q2;
		q1.push(1);   
		q1.push(2);
		
		q2 = q1;  //invoking assignment operator here
		queue q3 = q2;  // invking copy  constructor
		q3.push(9); // making q3 greater than q2  by adding another value 9 so we can now test our comparison operators

		if (q3 != q2)
		{
			std::cout << "q3 and q2 are not equal" << std::endl;
		}
		else
			std::cout << "q3 and q2 are equal" << std::endl;


		if (q3 == q2)
		{
			std::cout << "q3 and q2 are equal" << std::endl;
		}
		else
			std::cout << "q3 and q2 are not equal" << std::endl;

		if (q3 > q2)
		{
			std::cout << "q3 is greater than q2" << std::endl;

		}
		if (q2 < q3)
		{
			std::cout << "q2 is smaller than q3" << std::endl;

		}
		if(q2<=q3)
		{
		     std::cout << "q2 is smaller  than or equal to q3" << std::endl;
	    }
		if (q2 >= q3)
		{
			std::cout << "q2 is greater  than or equal to q3" << std::endl;
		}




		
		std::cout<< "the  front and back values of q3 are "<<std::endl << q3.front() << std::endl << q3.back() << std::endl;

	}
	catch (const char *str) {
		std::cout << str << std::endl;
	}

}

