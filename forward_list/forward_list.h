#pragma once
#include"node.h"
#include <stack>
class forward_list {

private:
	node *Front, *Itr;
	int Size;
public:
	forward_list()
	{
		Front = nullptr;
		Itr = nullptr;
		Size = 0;
	}

	~forward_list()
	{
		while(Front!=nullptr)
		{
			pop_front();
		}
	}
	int size()const
	{
		return Size;

	}
	void push_front(const int& val)
	{
		node *temp;
		temp = new node;
		if (temp == nullptr)
		{
			throw"Forward list overflow";
		}
		temp->val = val;
		temp->next=Front;
		Front = temp;
		Size++;


	}

	void  pop_front()
	{
		if (Front == nullptr)
		{
			throw"Forward list underflow";
	}
		node *temp;
		temp = Front->next;
		delete Front;
		Front = temp;
		Size--;
	}

	int front()const
	{
		return Front->val;
	}

	void reset() {

		Itr = Front;
	}

	bool is_last()const
	{
		if (Itr == nullptr)
		{
			return true;
		}
		else
			return false;
	}
	int get_next()
	{
		if (Itr != nullptr)
		{
			node *temp = Itr;
			Itr = Itr->next;
			return temp->val;
		}

	}

	void unique()
	{
		node *temp,*tempnext;
		{  temp = Front;
		tempnext = Front->next;
			while (tempnext != nullptr)
			{
				if (temp->val == tempnext->val)
				{
					node *to_del;
					to_del = tempnext;
					temp->next = to_del->next;
					delete to_del;
					tempnext = temp->next;
					
				}
				else {
					temp = temp->next;
					tempnext = tempnext->next;
				}
			}
		}

	}
	T front()const
	{
		return Front->val;
	}
	void reverse()
	{

		std::stack<node*> s1;
		node *temp,*temp2;
		temp = Front;
		while (temp != nullptr)
		{
			s1.push(temp);
			temp = temp->next;
		}
		temp2 = s1.top();
		temp = s1.top();
		s1.pop();

		while (s1.size()>0)
		{
			temp->next = s1.top();
			temp = temp->next;
			s1.pop();
		}
		temp->next = nullptr;
		Front = temp2;
	}

	void merge( forward_list& other)
	{

		node *temp,*tempother,*tempmid,*anothertemp;
		temp = Front;
		tempother = other.Front;
		while (tempother!=nullptr)
		{
			temp = Front;
			for (int i = 0; i <= Size-1; i++)
			{

				if (Front->val > other.Front->val)
				{
					tempmid = tempother->next;
					tempother->next = temp;
					other.Front = tempmid;
					Front = tempother;
					tempother = other.Front;
					Size++;
				}

				while (temp != nullptr && tempother!=nullptr)
				{
					if ((temp->next==nullptr) || (temp->val < tempother->val && temp->next->val>tempother->val))
					{
						if (temp->next != nullptr)
						{
							tempmid = temp->next;
						}
						else
							tempmid = nullptr;
						temp->next = tempother;
						anothertemp = tempother->next;			
						tempother->next = tempmid;
				
						tempother = anothertemp;
						Size++;

					}
					temp = temp->next;

				}				
			}
			if (tempother == nullptr)
			{
				other.Front = nullptr;
				return;

			}

			tempother = tempother->next;

				
			}
		}

	

};