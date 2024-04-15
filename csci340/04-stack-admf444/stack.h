
#ifndef STACK_H
#define STACK_H
#include <queue>

template<typename T>
class Stack
{
private:
    std::queue<T> q1;	// These queues are where the stack's elements
    std::queue<T> q2;	// are to be saved.

public:
    bool empty() const;
    int size() const;
    const T& top();
    void push(const T &val);
    void pop();
};


// Note that the members of a template go into a .h file since
// they are not compiled directly into a .o file like the members
// of regular/non-template classes.



// Place your Stack class member implementations here.

/**
* Stack empty function
*
* Returns true if the stack has no elements in it
*
* @return true - if stack is empty
* @return false - if stack is not empty
******************************************************************************/
template<typename T>
bool Stack<T>::empty() const
{
	if(q1.empty())
	{
		return true;
	}

	else
	{
		return false;
	}
}

/**
* Stack size function
*
* Returns the number of elements currently in the stack
*
* @return - size (number of elements) in stack
******************************************************************************/
template<typename T>
int Stack<T>::size() const
{
	return q1.size();
}

/**
* Stack top function
*
* Returns reference to the newest element in the stack.
* Will error out before attempting to return the front of an empty queue
*
* @return - reference to the newest element in the stack
******************************************************************************/
template<typename T>
const T& Stack<T>::top()
{
	if(q1.empty())
	{
		exit(1); //didn't know about error checking, so when trying to access the top
			 //element of an empty stack exit with error code 1
	}

	else
	{
		return q1.front();
	}
}

/**
* Stack push function
*
* Adds an element to the stack
* New element gets pushed onto q2, then all of q1 is pushed onto q2, then the name of q2 and q1 switch
*
* @param val - element to be added to the stack
******************************************************************************/
template<typename T>
void Stack<T>::push(const T &val)
{
	q2.push(val);

	while(!q1.empty())
	{
		q2.push(q1.front());
		q1.pop();
	}

	std::queue<T> temp = q1;
	q1 = q2;
	q2 = temp;

}

/**
* Stack pop function
*
* Removes the newest element from the stack
******************************************************************************/
template<typename T>
void Stack<T>::pop()
{
	if(q1.empty())
	{
		return;
	}

	else
	{
		q1.pop();
	}
}

#endif // STACK_H
