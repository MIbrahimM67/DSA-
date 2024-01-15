#pragma once
#include "dnode.h"
template <typename T>
class list {
	denode<T>* Head;
	int n;
public:
	list()
	{
		Head= new denode<T>;
		Head->next = Head;
		Head->prev = Head;
		n = 0;
	}
	/*
	~list()
	{
		while (n != 0)
		{
			pop_front();
			
		}
		delete Head;

    }*/

	void push_front(const T &val)
	{
		denode<T> *temp;
		temp = new denode<T>;
		temp->val = val;
		temp->next = Head->next;
		temp->prev = Head;
		Head->next->prev = temp;
		Head->next = temp;
		n++;
	}
	void push_back(const T &val)
	{
		denode<T> *temp;
		temp = new denode<T>;
		temp->val = val;
		temp->prev = Head->prev;
		temp->next = Head;
		Head->prev->next = temp;
		Head->prev = temp;
		n++;
	}

	void pop_back()
	{

		denode<T> *temp=Head->prev;
		Head->prev->prev->next = Head;
		Head->prev = Head->prev->prev;
		delete temp;
		n--;

	}
	void pop_front()
	{
		denode<T> *temp = Head->next;
		Head->next->next->prev = Head;
		Head->next = Head->next->next;
		delete temp;
		n--;
	}
	void swap(denode<T>*n1, denode<T>*n2)
	{
		
		if (n1->next == n2)
		{
			denode<T>*temp1 = n1->prev;
			/*temp1->next = n1->next; // n2
			temp1->prev = n1->prev; // prev of n1
			*/
			n1->prev = n2;
			n1->next = n2->next;
			n1->next->prev = n1;
			n2->next = n1;
			n2->prev = temp1;
			n2->prev->next = n2;



			
		}

		else
		{
			denode<T>*prev = n1->prev;
			n1->prev->next = n2;
			n1->next->prev = n2;
			n2->prev->next = n1;
			n2->next->prev = n1;
			denode<T>*temp = n1;
			n1->prev = n2->prev;
			n1->next = n2->next;
			n2->next = temp->next;
			n2->prev = temp->prev;


		}



	}
	void sort()
	{
		denode<T>*n1 = Head -> next;
		denode<T>*n2 = Head->next->next;
		bool check = true;
		while (check)
		{
			denode<T>*n1 = Head->next;
			denode<T>*n2 = Head->next->next;
			check = false;
			while (n2 != Head && n1!=Head)
			{
				if (n1->val > n2->val)
				{
					swap(n1, n2);
					check = true;
					denode<T> *temp3 = n1;
					n1 = n2;
					n2 = temp3;

				}
				else
				{
					n1 = n1->next;
					n2 = n2->next;
				}

			}


		}

	}
	void Display()
	{
		denode<T>*temp=Head->next;
		while (temp != Head)
		{
			std::cout << temp->val << "  ";
			temp = temp->next;

		}

	}

	void SwappingEndNodes()
	{
		denode<T> *temp1 = Head->next;
		denode<T> *temp2 = Head->prev;
		swap(temp1, temp2);
	}
	void SwappingFirst_MidNodes()
	{
		denode<T> *temp1 = Head->next;
		denode<T> *temp2 = Head->prev->prev;
		swap(temp1, temp2);
	}


};