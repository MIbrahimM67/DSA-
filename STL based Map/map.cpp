
#include <iostream>
#include<string>
template<typename key_type, typename value_type>
struct tnode {
	tnode<key_type, value_type>* left, * right, * parent;
	bool isnil;
	std::pair<key_type, value_type> p1;

	tnode() {
		left = right = parent = nullptr;
		isnil = false;
	}

};
template<typename key_type, typename value_type>
class map {
	tnode<key_type, value_type>* DummyH;
	int n;
public:
	map()
	{
		DummyH = new tnode<key_type, value_type>;
		DummyH->parent = DummyH->left = DummyH->right = DummyH;
		DummyH->isnil = true;
		n = 0;

	}
	~map()
	{
		clear();
		delete DummyH;
	}
	map(const map& rhs)
	{
		DummyH = new tnode<key_type, value_type>;
		DummyH->parent = DummyH->left = DummyH->right = DummyH;
		DummyH->isnil = true;
		n = 0;

		traversePreorder(rhs.DummyH->parent);
	}
	map& operator=(const map& rhs)
	{
		if (this != &rhs) {
			clear(); // Clear the current BST
			traversePreorder(rhs.DummyH->parent);
		}
		return *this;
	}
	void traversePreorder(const tnode<key_type, value_type>* root)
	{
		if ((root->isnil))
			return;
		insert(root->p1);
		traversePreorder(root->left);
		traversePreorder(root->right);
	}
	// capacity 
	bool empty() const
	{
		if (DummyH->parent == DummyH)
		{
			return true;
		}
		else
			return false;
	}
	int size()
	{
		return n;
	}

	class iterator {
		tnode<key_type, value_type>* ptr;
		friend class map;
	public:
		iterator()
		{
			ptr = nullptr;

		}
		value_type& operator*()
		{
			return ptr->p1.second;
		}
		std::pair<key_type, value_type>* operator->()
		{
			return &(ptr->p1);
		}
		bool operator ==(const iterator& a)
		{
			return ptr == a.ptr;
		}
		iterator& operator --()
		{
			tnode<key_type, value_type>* temp;
			tnode<key_type, value_type>* p;

			iterator it;
			temp = ptr;
			if (!(temp->left->isnil)) // to check if the left node is dummyhead or not, if not we move left once
			{
				temp = temp->left;
				while (!(temp->right->isnil)) // we keep moving right till the dummyhead is reached
				{
					temp = temp->right;
				}
				this->ptr = temp;
				return *this;
			}
			else if ((temp->left->isnil)) // if the left is dummy, we move up
			{
				p = temp;
				temp = temp->parent;
				if (temp->right == p) // if we are moving up from right, we return iterator of that node
				{
					this->ptr = temp;
					return it;
				}
				else if (temp->left == p)
				{
					while (temp->left == p)
					{
						p = temp;
						temp = temp->parent;
					}
					this->ptr = temp;
					if (this->ptr->isnil == true)
					{
						this->ptr = this->ptr->right;
					}
					return *this;


				}

			}
		}
		iterator& operator++() {
			tnode<key_type, value_type>* temp;
			tnode<key_type, value_type>* p;

			iterator it;
			temp = ptr;
			if (!(temp->right->isnil)) // checking if the right node is dummy or not, if not, we move right once
			{
				temp = temp->right;
				while (!(temp->left->isnil)) // we keep moving left till the dummy node is reached;
				{
					temp = temp->left;
				}
				this->ptr = temp;
				return *this;
			}
			else if ((temp->right->isnil)) // to check if the right node is dummy  
			{
				p = temp;
				temp = temp->parent;
				if (temp->left == p) // if we moving up from the left node, we will return the iterator of that node
				{
					this->ptr = temp;
					return it;
				}
				else if (temp->right == p) // if we are coming from the right, we will keep moving up untill the dummy is reached or till we come from left node
				{
					while (temp->right == p)
					{
						p = temp;
						temp = temp->parent;
					}
					this->ptr = temp;
					if (this->ptr->isnil == true)
					{
						this->ptr = this->ptr->left;
					}
					return *this;


				}

			}
		}



	};
	class reverse_iterator {
		tnode<key_type, value_type>* ptr;
		friend class map;
	public:
		reverse_iterator()
		{
			ptr = nullptr;

		}
		value_type& operator*()
		{
			return ptr->p1.second;
		}
		std::pair<key_type, value_type>* operator->()
		{
			return &(ptr->p1);
		}
		bool operator ==(const reverse_iterator& a)
		{
			return ptr == a.ptr;
		}
		reverse_iterator& operator ++()
		{
			tnode<key_type, value_type>* temp;
			tnode<key_type, value_type>* p;

			reverse_iterator it;
			temp = ptr;
			if (!(temp->left->isnil)) // to check if the left node is dummyhead or not, if not we move left once
			{
				temp = temp->left;
				while (!(temp->right->isnil)) // we keep moving right till the dummyhead is reached
				{
					temp = temp->right;
				}
				this->ptr = temp;
				return *this;
			}
			else if ((temp->left->isnil)) // if the left is dummy, we move up
			{
				p = temp;
				temp = temp->parent;
				if (temp->right == p) // if we are moving up from right, we return iterator of that node
				{
					this->ptr = temp;
					return it;
				}
				else if (temp->left == p)
				{
					while (temp->left == p)
					{
						p = temp;
						temp = temp->parent;
					}
					this->ptr = temp;
					if (this->ptr->isnil == true)
					{
						this->ptr = this->ptr->right;
					}
					return *this;


				}

			}
		}
		reverse_iterator& operator--() {
			tnode<key_type, value_type>* temp;
			tnode<key_type, value_type>* p;

			reverse_iterator it;
			temp = ptr;
			if (!(temp->right->isnil)) // checking if the right node is dummy or not, if not, we move right once
			{
				temp = temp->right;
				while (!(temp->left->isnil)) // we keep moving left till the dummy node is reached;
				{
					temp = temp->left;
				}
				this->ptr = temp;
				return *this;
			}
			else if ((temp->right->isnil)) // to check if the right node is dummy  
			{
				p = temp;
				temp = temp->parent;
				if (temp->left == p) // if we moving up from the left node, we will return the iterator of that node
				{
					this->ptr = temp;
					return it;
				}
				else if (temp->right == p) // if we are coming from the right, we will keep moving up untill the dummy is reached or till we come from left node
				{
					while (temp->right == p)
					{
						p = temp;
						temp = temp->parent;
					}
					this->ptr = temp;
					if (this->ptr->isnil == true)
					{
						this->ptr = this->ptr->left;
					}
					return *this;


				}

			}
		}



	};
	class const_iterator {
		tnode<key_type, value_type>* ptr;
		friend class map;
	public:
		const_iterator()
		{
			ptr = nullptr;

		}
		value_type& operator*()
		{
			return ptr->p1.second;
		}
		std::pair<key_type, value_type>* operator->()
		{
			return &(ptr->p1);
		}
		bool operator ==(const iterator& a)
		{
			return ptr == a.ptr;
		}
		const_iterator& operator --()
		{
			tnode<key_type, value_type>* temp;
			tnode<key_type, value_type>* p;

			const_iterator it;
			temp = ptr;
			if (!(temp->left->isnil)) // to check if the left node is dummyhead or not, if not we move left once
			{
				temp = temp->left;
				while (!(temp->right->isnil)) // we keep moving right till the dummyhead is reached
				{
					temp = temp->right;
				}
				this->ptr = temp;
				return *this;
			}
			else if ((temp->left->isnil)) // if the left is dummy, we move up
			{
				p = temp;
				temp = temp->parent;
				if (temp->right == p) // if we are moving up from right, we return iterator of that node
				{
					this->ptr = temp;
					return it;
				}
				else if (temp->left == p)
				{
					while (temp->left == p)
					{
						p = temp;
						temp = temp->parent;
					}
					this->ptr = temp;
					if (this->ptr->isnil == true)
					{
						this->ptr = this->ptr->right;
					}
					return *this;


				}

			}
		}
		const_iterator& operator++() {
			tnode<key_type, value_type>* temp;
			tnode<key_type, value_type>* p;

			const_iterator it;
			temp = ptr;
			if (!(temp->right->isnil)) // checking if the right node is dummy or not, if not, we move right once
			{
				temp = temp->right;
				while (!(temp->left->isnil)) // we keep moving left till the dummy node is reached;
				{
					temp = temp->left;
				}
				this->ptr = temp;
				return *this;
			}
			else if ((temp->right->isnil)) // to check if the right node is dummy  
			{
				p = temp;
				temp = temp->parent;
				if (temp->left == p) // if we moving up from the left node, we will return the iterator of that node
				{
					this->ptr = temp;
					return it;
				}
				else if (temp->right == p) // if we are coming from the right, we will keep moving up untill the dummy is reached or till we come from left node
				{
					while (temp->right == p)
					{
						p = temp;
						temp = temp->parent;
					}
					this->ptr = temp;
					if (this->ptr->isnil == true)
					{
						this->ptr = this->ptr->left;
					}
					return *this;


				}

			}
		}



	};
	class const_reverse_iterator {
		tnode<key_type, value_type>* ptr;
		friend class map;
	public:
		const_reverse_iterator()
		{
			ptr = nullptr;

		}
		value_type& operator*()
		{
			return ptr->p1.second;
		}
		std::pair<key_type, value_type>* operator->()
		{
			return &(ptr->p1);
		}
		bool operator ==(const const_reverse_iterator& a)
		{
			return ptr == a.ptr;
		}
		const_reverse_iterator& operator ++()
		{
			tnode<key_type, value_type>* temp;
			tnode<key_type, value_type>* p;

			const_reverse_iterator it;
			temp = ptr;
			if (!(temp->left->isnil)) // to check if the left node is dummyhead or not, if not we move left once
			{
				temp = temp->left;
				while (!(temp->right->isnil)) // we keep moving right till the dummyhead is reached
				{
					temp = temp->right;
				}
				this->ptr = temp;
				return *this;
			}
			else if ((temp->left->isnil)) // if the left is dummy, we move up
			{
				p = temp;
				temp = temp->parent;
				if (temp->right == p) // if we are moving up from right, we return iterator of that node
				{
					this->ptr = temp;
					return it;
				}
				else if (temp->left == p)
				{
					while (temp->left == p)
					{
						p = temp;
						temp = temp->parent;
					}
					this->ptr = temp;
					if (this->ptr->isnil == true)
					{
						this->ptr = this->ptr->right;
					}
					return *this;


				}

			}
		}
		const_reverse_iterator& operator--() {
			tnode<key_type, value_type>* temp;
			tnode<key_type, value_type>* p;

			const_reverse_iterator it;
			temp = ptr;
			if (!(temp->right->isnil)) // checking if the right node is dummy or not, if not, we move right once
			{
				temp = temp->right;
				while (!(temp->left->isnil)) // we keep moving left till the dummy node is reached;
				{
					temp = temp->left;
				}
				this->ptr = temp;
				return *this;
			}
			else if ((temp->right->isnil)) // to check if the right node is dummy  
			{
				p = temp;
				temp = temp->parent;
				if (temp->left == p) // if we moving up from the left node, we will return the iterator of that node
				{
					this->ptr = temp;
					return it;
				}
				else if (temp->right == p) // if we are coming from the right, we will keep moving up untill the dummy is reached or till we come from left node
				{
					while (temp->right == p)
					{
						p = temp;
						temp = temp->parent;
					}
					this->ptr = temp;
					if (this->ptr->isnil == true)
					{
						this->ptr = this->ptr->left;
					}
					return *this;


				}

			}
		}



	};

	// Modifiers 
	std::pair<iterator, bool> insert(const std::pair<key_type, value_type>& p2) 
	{
		iterator it;
		tnode<key_type, value_type>* temp = new tnode<key_type, value_type>;
		temp->p1 = p2;
		tnode<key_type, value_type>* Tree = DummyH->parent;
		temp->right = temp->left = DummyH;
		while (true)
		{
			if (DummyH->parent == DummyH)
			{
				DummyH->parent = temp;
				DummyH->left = temp;
				DummyH->right = temp;
				temp->parent = DummyH;
				n++;
				break;

			}
			else if (temp->p1.first > Tree->p1.first)
			{
				if (Tree->right == DummyH)
				{
					Tree->right = temp;
					temp->left = temp->right = DummyH;
					temp->parent = Tree;
					it.ptr = temp;
					if (temp->p1.first > DummyH->right->p1.first)
					{
						DummyH->right = temp;
					}
					n++;
					return(std::pair<iterator, bool>(it, true));

				}
				else
				{
					Tree = Tree->right;
				}

			}
			else if (temp->p1.first < Tree->p1.first)
			{
				if (Tree->left == DummyH)
				{
					Tree->left = temp;
					temp->left = temp->right = DummyH;
					temp->parent = Tree;
					it.ptr = temp;
					if (temp->p1.first < DummyH->left->p1.first)
					{
						DummyH->left = temp;
					}
					n++;
					return(std::pair<iterator, bool>(it, true));
				}
				else
				{
					Tree = Tree->left;
				}
			}
			else
			{
				delete temp;
				it.ptr = Tree;
				return(std::pair<iterator, bool>(it, false));
			}
		}
	}

	void clear()
	{
		tnode<key_type, value_type>* Temp = DummyH->parent;
		tnode<key_type, value_type>* p = DummyH->parent;

		if (n == 0)
		{
			return;
		}
		while (Temp != DummyH)
		{
			p = Temp;
			if (Temp->left != DummyH)
			{
				Temp = Temp->left;
			}
			else if (Temp->right != DummyH)
			{
				Temp = Temp->right;
			}
			else
			{
				Temp = p->parent;
				if (Temp->left == p)
				{
					Temp->left = DummyH;
				}
				else if (Temp->right == p)
				{
					Temp->right = DummyH;

				}
				delete p;
				n--;
				p = Temp;

			}

		}
		DummyH->left = DummyH->right = DummyH->parent = DummyH;

	}
	iterator erase(iterator pos)
	{
		tnode < key_type, value_type>* ToReplace;
		tnode < key_type, value_type>* PToReplace;
		tnode < key_type, value_type>* ToReplaceRight;

		tnode < key_type, value_type>* ToReplaceLeft;


		map<int, std::string>::iterator Movementit = begin();
		tnode<key_type, value_type>* nodeTodel = pos.ptr; // node to delete
		tnode<key_type, value_type>* Pnode = nodeTodel->parent; // parent to the node being deleted
		if (nodeTodel->left == DummyH && nodeTodel->right == DummyH) // in case of leaf node
		{
			//delete nodeTodel;
			if (Pnode->left == nodeTodel) 
			{
				if (DummyH->left == nodeTodel)
				{
					++Movementit;
					DummyH->left = Movementit.ptr;
				}
				delete nodeTodel;
				n--;

				Pnode->left = DummyH;
				return Movementit;
			}
			else
			{
				if (DummyH->right == nodeTodel)
				{
					--Movementit;
					DummyH->left = Movementit.ptr;
				}
				delete nodeTodel;
				n--;
				Pnode->left = DummyH;
				return Movementit;
			}
		}

		else if (nodeTodel->left != DummyH && nodeTodel->right == DummyH) // if it has one child
		{
			Pnode = nodeTodel->parent;
			Pnode->left = nodeTodel->left;
			nodeTodel->left->parent = Pnode;
			delete nodeTodel;
			n--;
			Movementit.ptr = Pnode;
			return Movementit;
		}
		else if (nodeTodel->left == DummyH && nodeTodel->right != DummyH)
		{

			Pnode = nodeTodel->parent;
			Pnode->right = nodeTodel->right;
			nodeTodel->right->parent = Pnode;
			delete nodeTodel;
			n--;
			Movementit.ptr = Pnode;
			return Movementit;
		}
		else if (nodeTodel->left != DummyH && nodeTodel->right != DummyH) // if it has two childs
		{
			Pnode = nodeTodel->parent;
			Movementit.ptr = nodeTodel;
			++Movementit;
			ToReplace = Movementit.ptr;
			PToReplace = ToReplace->parent;
			ToReplaceLeft = ToReplace->left;
			ToReplaceRight = ToReplace->right;

			if (Pnode->left == nodeTodel)
			{
				if (ToReplace->left == DummyH && ToReplace->right == DummyH)
				{
					Pnode->left = ToReplace;
					ToReplace->parent = Pnode;
					ToReplace->left = nodeTodel->left;
					ToReplace->right = nodeTodel->right;


				}
				else if (ToReplace->left != DummyH && ToReplace->right == DummyH)
				{
					PToReplace->right = ToReplace->left;
					ToReplace->right->parent = PToReplace;

					Pnode->left = ToReplace;
					ToReplace->parent = Pnode;
					ToReplace->left = nodeTodel->left;
					ToReplace->right = nodeTodel->right;
				}
				else if (ToReplace->left == DummyH && ToReplace->right != DummyH)
				{
					PToReplace->left = ToReplace->right;
					ToReplace->right->parent = PToReplace;

					Pnode->left = ToReplace;
					ToReplace->parent = Pnode;
					ToReplace->left = nodeTodel->left;
					ToReplace->right = nodeTodel->right;

				}

				ToReplace->left->parent = ToReplace;
				ToReplace->right->parent = ToReplace;

				delete nodeTodel;
				n--;
				Movementit.ptr = Pnode;
				return Movementit;

			}
			else if (Pnode->right == nodeTodel)
			{
				if (ToReplace->left == DummyH && ToReplace->right == DummyH)
				{
					Pnode->right = ToReplace;
					ToReplace->parent = Pnode;
					ToReplace->left = nodeTodel->left;
					ToReplace->right = nodeTodel->right;
					if (ToReplace->left = ToReplace)
					{
						ToReplace->left = DummyH;
					}
					else if (ToReplace->right = ToReplace)
					{
						ToReplace->right = DummyH;

					}

				}
				else if (ToReplace->left != DummyH && ToReplace->right == DummyH)
				{
					PToReplace->left = ToReplace->right;
					ToReplace->right->parent = PToReplace;


					Pnode->right = ToReplace;
					ToReplace->parent = Pnode;
					ToReplace->left = nodeTodel->left;
					ToReplace->right = nodeTodel->right;
				}
				else if (ToReplace->left == DummyH && ToReplace->right != DummyH)
				{
					PToReplace->left = ToReplace->right;
					ToReplace->right->parent = PToReplace;

					Pnode->right = ToReplace;
					ToReplace->parent = Pnode;
					ToReplace->left = nodeTodel->left;
					ToReplace->right = nodeTodel->right;

				}

				ToReplace->left->parent = ToReplace;
				ToReplace->right->parent = ToReplace;
				delete nodeTodel;
				n--;
				Movementit.ptr = Pnode;
				return Movementit;

			}



		}

	}


	//Look-up
	int count(const key_type& key)
	{
		iterator it = find(key);
		if (it == end())
		{
			return 0;
		}
		else
			return 1;


	}

	iterator find(const key_type& val)  // overload of this function is done after this
	{
		tnode<key_type, value_type>* Tree = DummyH->parent;
		iterator it;
		while (Tree != DummyH)
		{
			if (Tree->p1.first == val)
			{
				it.ptr = Tree;
				return it;

			}
			else if (val > Tree->p1.first)
			{
				Tree = Tree->right;
			}
			else if (val < Tree->p1.first)
			{
				Tree = Tree->left;
			}

		}
		it.ptr = DummyH;
		return it;

	}
	const_iterator find(const key_type& val) const // overload of find function
	{
		tnode<key_type, value_type>* Tree = DummyH->parent;
		const_iterator it;
		while (Tree != DummyH)
		{
			if (Tree->p1.first == val)
			{
				it.ptr = Tree;
				return it;

			}
			else if (val > Tree->p1.first)
			{
				Tree = Tree->right;
			}
			else if (val < Tree->p1.first)
			{
				Tree = Tree->left;
			}

		}
		it.ptr = DummyH;
		return it;

	}
	 //iterator functions
	iterator& begin() {
		iterator it;
		it.ptr = DummyH->left;
		return it;
	}
	iterator& end()
	{
		iterator it;
		it.ptr = DummyH;
		return it;
	}
	//reverse iterator functions

	reverse_iterator& rbegin() {
		reverse_iterator it;
		it.ptr = DummyH->right;
		return it;
	}
	
	reverse_iterator& rend()
	{
		reverse_iterator it;
		it.ptr = DummyH;
		return it;
	}
	// const interator functions
	const_iterator& cbegin()const {
		const_iterator it;
		it.ptr = DummyH->left;
		return it;
	}
	const_iterator& cend()const
	{
		const_iterator it;
		it.ptr = DummyH;
		return it;
	}
	// const reverse interator functions

	const_reverse_iterator& crbegin()const {
		const_reverse_iterator it;
		it.ptr = DummyH->right;
		return it;
	}
	
	const_reverse_iterator& crend()const
	{
		const_reverse_iterator it;
		it.ptr = DummyH;
		return it;
	}

	// Element Access
	value_type& at(const key_type& key)
	{
		iterator it;
		it = find(key);
		if (it == this->end())
		{
			throw"out of bounds";
		}
		else
			return it->second;
	}
	value_type& operator [](const key_type& key)
	{

		insert({ key, value_type() });
		return at(key);
	}

}; 
//**************************************************************************************************************************

// Client code 
int main()
{
	try {
		// inserting values using insert function
		map<int, std::string> b1;
		b1.insert({ 10,"ali" });
		b1.insert(std::pair<int, std::string>(5, "b"));
		b1.insert(std::pair<int, std::string>(2, "c"));
		b1.insert(std::pair<int, std::string>(1, "d"));
		b1.insert(std::pair<int, std::string>(4, "e"));
		b1.insert(std::pair<int, std::string>(8, "f"));
		b1.insert(std::pair<int, std::string>(6, "g"));
		b1.insert(std::pair<int, std::string>(7, "h"));
		b1.insert(std::pair<int, std::string>(15, "i"));

		map<int, std::string>::iterator EraserIT;
		EraserIT = b1.begin();


		b1.erase(EraserIT); // Triggering Erase function , in this case it will remove the smallest value


		// using iterator 
		map<int, std::string>::iterator it;

		// testing find function 
		it = b1.find(126);
		if (it == b1.end())
		{
			std::cout << " key 126 doesnt exist so value not found" << std::endl;
		}
		else
		{
			std::cout << it->second;
		}

		// testing operator ++ 
		it = b1.begin();
		int counter = 0;
		std::cout << "Values of b1  in accending order Are " << std::endl;
		while (counter < b1.size())
		{
			std::cout << it->first << " ";
			++it;
			counter++;
		}
		std::cout << std::endl;

		--it;
		--it;
		// testing operator --

		std::cout << "Values of b1  in deccending order Are " << std::endl;

		counter = 0;
		while (counter < b1.size())
		{
			std::cout << it->first << " ";
			--it;
			counter++;
		}
		// using reverse iterator now
		// testing ++ operator
		std::cout << "using reverse iterator,Values of b1  in deccending order Are " << std::endl;
		counter = 0;
		map<int, std::string>::reverse_iterator r_it;
		r_it = b1.rbegin();
		while (counter < b1.size())
		{
			std::cout << r_it->first << " ";
			++r_it;
			counter++;
		}
		std::cout << std::endl;
		// testing --operator
		std::cout << "using reverse iterator,Values of b1  in aeccending order Are " << std::endl;
		counter = 0;
		r_it = b1.rbegin(); // rbegin takes us to the largest value in the map
		--r_it; // taking it to the first smallest value;
		while (counter < b1.size())
		{
			std::cout << r_it->first << " ";
			--r_it;
			counter++;
		}


		std::cout << std::endl;
		std::cout << "Values of map b1 at key 15 is  ";

		std::cout << b1.at(15) << std::endl;
		// testing overloaded opeartor [] function
		b1[32] = "uh";
		std::cout << "Values of map b1 at key 32 after  using [] operator  is  ";

		std::cout << b1.at(32);


		std::cout << std::endl;
		map<int, std::string> b2;
		// trigering assignment operator 
		b2 = b1;
		std::cout << std::endl;
		it = b2.begin();
		counter = 0;
		std::cout << "Values of b2  Are " << std::endl;

		while (counter < b2.size())
		{
			std::cout << it->first << " ";  // printing b2 values to see if they match b1 or not

			++it;
			counter++;
		}

		map<int, std::string> b3 = b2; // trigering copy constructor 
		std::cout << std::endl;

		it = b3.begin();
		counter = 0;
		std::cout << "Values of b2  Are " << std::endl;

		while (counter < b3.size())
		{
			std::cout << it->first << " ";  // printing b3 values to see if they match b2 or not
			counter++;
			++it;
		}
		std::cout << std::endl;

		if (b1.empty()) // triggering empty function
		{
			std::cout << "map b1 is empty! " << std::endl;

		}
		else
		{
			std::cout << "map b1 is Not Empty! " << std::endl;

		}
		std::cout << "size  of b1  is  " << b1.size() << std::endl; // triggering size function

		// trigering clear function 
		b1.clear();
		b2.clear();
		b3.clear();

	}
	catch (const char* st) {
		std::cout << st << std::endl;
	}


   
}



