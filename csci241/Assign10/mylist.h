
#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

//node declaration
template <class T>
struct node
{
	T value;
	node<T>* prev;
	node<T>* next;

	node(const T& value = T(), node<T>* next = nullptr, node<T>* prev = nullptr)
	{
		this->value = value;
		this->prev = prev;
		this->next = next;
	}
};

//forward declarations
template <class T>
class mylist;

template <class T>
std::ostream& operator<<(std::ostream&, const mylist<T>&);

//mylist class
template <class T>
class mylist
{
	//friend function declaration for << operator
	friend std::ostream& operator<< <>(std::ostream&, const mylist<T>&);

private:

	node<T>* l_front; //pointer to front of list
	node<T>* l_back;  //pointer to back of list
	size_t l_size = 0;

public:

	//function prototypes
	mylist();
	~mylist();
	mylist(const mylist<T>&);
	mylist& operator=(const mylist<T>&);
	bool operator==(const mylist<T>&) const;
	bool operator<(const mylist<T>&) const;
	void clear();
	size_t size() const;
	bool empty() const;
	const T& front() const;
	T& front();
	const T& back() const;
	T& back();
	void push_front(const T&);
	void push_back(const T&);
	void pop_front();
	void pop_back();
};

//default constructor
template <class T>
mylist<T>::mylist()
{
	l_front = nullptr;
	l_back = nullptr;
	l_size = 0;
}

//destructor
template <class T>
mylist<T>::~mylist()
{
	clear();
}

//copy constructor
//@param const mylist<T>& other - mylist object to be copied
template <class T>
mylist<T>::mylist(const mylist<T>& other)
{
	if(other.l_front == nullptr) //if the other list is empty make the current list empty
	{
		l_front = nullptr;
	}

	else
	{
		node<T>* current1 = other.l_front; //pointer to other list
		l_front = l_back = new node<T>;
		l_front->prev = nullptr;
		l_front->value = current1->value;
		current1 = current1->next;

		if(current1 == nullptr)
		{
			l_front->next = nullptr;
		}

		else
		{
			node<T>* current2 = l_front; //pointer to copied list being created

			while(current1 != nullptr)
			{
				current2->next = new node<T>;
				current2->next->prev = current2;
				current2 = current2->next;

				current2->value = current1->value;
				current1 = current1->next;
			}

			current2->next = nullptr;
			l_back = current2;
		}
	}
}

//copy assignment operator
//@param const mylist<T>& other - mylist object to be copied
template <class T>
mylist<T>& mylist<T>::operator=(const mylist<T>& other)
{
	//this function has the same logic as the copy constructor
	if(&other != this)
	{
		if(l_front != nullptr)
		{
			node<T> *current = l_front;

			while(current != nullptr)
			{
				node<T> *temp = current;
				current = current->next;
				delete temp;
			}

			l_front = l_back = nullptr;
		}

		if(other.l_front == nullptr)
		{
			l_front = nullptr;
		}

		else
		{
			node<T> *current1 = other.l_front;
			l_front = l_back = new node<T>;
			l_front->prev = nullptr;
			l_front->value = current1->value;
			current1 = current1->next;

			if(current1 == nullptr)
			{
				l_front->next = nullptr;
			}

			else
			{
				node<T> *current2 = l_front;

				while(current1 != nullptr)
				{
					current2->next = new node<T>;
					current2->next->prev = current2;
					current2 = current2->next;

					current2->value = current1->value;
					current1 = current1->next;
				}

				current2->next = nullptr;
				l_back = current2;
			}
		}
	}

	return *this;
}

//stream insertion operator
//sends mylist object to stdout
//@return lhs to cascade operator
template <class T>
ostream& operator<<(ostream& lhs, const mylist<T>& rhs)
{
	node<T>* temp = rhs.l_front;

	while(temp)
	{
		lhs << temp->value << " ";
		temp = temp->next;
	}

	return lhs; //cascade operator
}

//clear()
//clears the list
template <class T>
void mylist<T>::clear()
{
	while(!empty())
	{
		pop_front();
	}
}

//size()
//keeping track of l_size by counting the nodes in the current list instead of incrementing and decrementing l_size
//@returns number of nodes in the list
template <class T>
size_t mylist<T>::size() const
{
	node<T> *ptr = l_front;
	int count = 0;

	while(ptr != nullptr)
	{
		count++;
		ptr = ptr->next;
	}

	return count;
}

//empty()
//@returns true if the current list is empty(pointing to nullptr) or false if not
template <class T>
bool mylist<T>::empty() const
{
	return l_front == nullptr;
}

//front()
//@returns first node value in the list
template <class T>
const T& mylist<T>::front() const
{
	if(empty())
	{
		throw std::underflow_error("underflow exception on call to front()");
	}

	return l_front->value;
}

//front()
//@returns first node value in the list
template <class T>
T& mylist<T>::front()
{
	if(empty())
	{
		throw std::underflow_error("underflow exception on call to front()");
	}

	return l_front->value;
}

//back()
//@returns the last node value in the list
template <class T>
const T& mylist<T>::back() const
{
	if(empty())
	{
		throw std::underflow_error("underflow exception on call to back()");
	}

	return l_back->value;
}

//back()
//@returns the last node value in the list
template <class T>
T& mylist<T>::back()
{
	if(empty())
	{
		throw std::underflow_error("underflow exception on call to back()");
	}

	return l_back->value;
}

//push_back()
//@param const T& value - item to be inserted at the back of the list
template <class T>
void mylist<T>::push_back(const T& value)
{
	node<T>* new_node;
	new_node = new node<T>(value);

	if(!empty())
	{
		new_node->prev = l_back;
		l_back->next = new_node;
		l_back = new_node;
	}

	else
	{
		new_node->prev = l_back;
		l_front = new_node;
		l_back = new_node;
	}
}

//push_front()
//@param const T& value - item to be inserte at the front of the list
template <class T>
void mylist<T>::push_front(const T& value)
{
	node<T>* new_node;
	new_node = new node<T>(value);

	if(!empty())
	{
		new_node->next = l_front;
		l_front->prev = new_node;
		l_front = new_node;
	}

	else
	{
		new_node->next = l_front;
		l_back = new_node;
		l_front = new_node;
	}
}

//pop_front
//removes item at the front of the list
template <class T>
void mylist<T>::pop_front()
{
	if(size() == 0)
	{
		throw std::underflow_error("underflow exception on call to pop_front()");
	}

	else if(size() == 1)
	{
		node<T>* del_node = l_front;
		l_front = del_node->next;
		l_back = nullptr;
		delete del_node;
	}

	else if(size() > 1)
	{
		node<T>* del_node = l_front;
		l_front = del_node->next;
		l_front->prev = nullptr;
		delete del_node;
	}
}

//pop_back()
//removes item at the back of the list
template <class T>
void mylist<T>::pop_back()
{
	if(size() == 0)
	{
		throw std::underflow_error("underflow exception on call to pop_back()");
	}

	else if(size() == 1)
	{
		node<T>* del_node = l_back;
		l_back = del_node->prev;
		l_front = nullptr;
		delete del_node;
	}

	else if(size() > 1)
	{
		node<T>* del_node = l_back;
		l_back = del_node->prev;
		l_back->next = nullptr;
		delete del_node;
	}
}

//equality operator
//@param const mylist<T>& rhs - right hand side operand
//lhs represented by this
//compares two mylist objects
//@returns true if lists contain same amount of nodes and if each element of lhs is equal to each element of rhs
//else @returns false
template <class T>
bool mylist<T>::operator==(const mylist<T>& rhs) const
{
	node<T> *p1;
	node<T> *p2;

	p1 = this->l_front;
	p2 = rhs.l_front;
	bool flag;

	while(p1 != nullptr && p2 != nullptr)
	{
		if(p1->value == p2->value)
		{
			flag = true;
		}

		else
		{
			flag = false;
		}

		p1 = p1->next;
		p2 = p2->next;
	}

	return flag;
}

//less than operator
//@param const mylist<T>& rhs - right hand side operand
//lhs represented by this
//@returns true if element in lhs is less than element in rhs
//else @returns false
template <class T>
bool mylist<T>::operator<(const mylist<T>& rhs) const
{
	node<T> *p1;
	node<T> *p2;

	p1 = this->l_front;
	p2 = rhs.l_front;

	while(p1 != nullptr && p2 != nullptr)
	{
		if(p1->value < p2->value)
		{
			return true;
		}

		if(p1->value > p2->value)
		{
			return false;
		}

		p1 = p1->next;
		p2 = p2->next;
	}

	if(p2 == nullptr)
	{
		return false;
	}

	else
	{
		return true;
	}
}

#endif
