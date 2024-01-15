#pragma once
struct Node {
	int Value;
	Node *Next;

};

class stack{

private:
	Node *Top;
	int Size = 0;
public:
	stack()   // default constructor 
	{
		Top = nullptr;
	}
	~stack()  // Destructor 
	{
		Node *Temp;
		while (Top != nullptr)
		{
			Temp = Top->Next;
			delete Top;
			Top = Temp;
			Size--;
		}
	}
	stack& operator =(const stack& rhs)  // Assignment Operator , it is bonus task
	{
		if (rhs.Top == nullptr)
		{
			return *this;
		}
		Top = new Node;
		Node *Temp = Top;
		Node* rhstemp = rhs.Top;
		Temp->Value = rhstemp->Value;
		rhstemp = rhstemp->Next;
		while (rhstemp != nullptr)
		{
			Temp->Next = new Node;
			Temp = Temp->Next;
			Temp->Value = rhstemp->Value;
			rhstemp = rhstemp->Next;
		}
		Temp->Next = nullptr;
		Size = rhs.Size;
		return *this;


	}
	stack(const stack & rhs) // Copy constructor , it is bonus task
	{
		
		*this = rhs;


	}
	



	void push(const int &val)
	{ 
		if (!(Full()))
		{
			Node *temp = Top;
			Top = new Node;
			Top->Next = temp;
			Top->Value = val;
			Size++;
		}
		else
			throw "Stack overflow";
	}
	int top() const
	{
		return Top->Value; 
  	}
	void pop()
	{
		if (Size != 0)
		{
			Node *Temp = Top->Next;
			delete Top;
			Top = Temp;
			Size--;
		}
		else
			throw"Stack is already empty";
	}
	int size() const
	{
		return Size;
	}
	bool Empty()const
	{
		if (Size == 0)
		{
			return true;
		}
		return false;
	}
	bool Full() const
	{
		Node *Temp;
		if ((Temp = new Node)!=nullptr ) // checks if new memory can be allocated or not, if not then the stack is full
		{
			return false;
		}
		delete Temp;
		return true;
	}

};
