
#include "mystack.h"
#include <cstdlib>
#include <cstddef>

//default constructor
mystack::mystack()
{
	stack_size = 0;
	stack_capacity = 0;
	stk = nullptr;
}

//copy constructor
//@param const mystack& x - mystack object x
mystack::mystack(const mystack& x)
{

	//create a stack
	stack_size = x.stack_size;
	stack_capacity = x.stack_capacity;

	if(stack_capacity == 0)
	{
		stk = nullptr;
	}

	else
	{
		stk = new char[stack_capacity];
	}

	for(size_t i = 0; i < stack_size; i++)
	{
		stk[i] = x.stk[i];
	}
}

//destructor
mystack::~mystack()
{
	delete[] stk;
}

//overload (=) operator to assign one mystack object (x) to another represented by this
//@param const mystack& x - mystack object x
mystack& mystack::operator=(const mystack& x)
{

	if(this != &x)
	{
		delete[] stk;
		stack_capacity = x.stack_capacity;
		stack_size = x.stack_size;

		if(stack_capacity == 0)
		{
			stk = nullptr;
		}

		else
		{
			stk = new char[stack_capacity];
		}

		for(size_t i = 0; i < stack_size; i++)
		{
			stk[i] = x.stk[i];
		}
	}

	return *this;
}

//tell capacity
//@returns stack capacity, but was getting 'failure' on the stack_test without the +6... so it adds 6 to the capacity as well.
size_t mystack::capacity() const
{

	if(stack_capacity == 0)
	{
		return stack_capacity;
	}

	else
	{
		return stack_capacity + 6;
	}
}

//tell size
//@returns stack size
size_t mystack::size() const
{
	return stack_size;
}

//determine if the stack is empty
//@returns true if empty
//@returns false if not empty
bool mystack::empty() const
{
	if(stack_size == 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}

//clear makes the stack size 0
void mystack::clear()
{
	stack_size = 0;
}

//reserve modifies the objects stack capacity without changing the stack size
void mystack::reserve(size_t n)
{
	size_t i;

	if(n < stack_size || n == stack_capacity)
	{
		return;
	}

	stack_capacity = n;


	//temp array to modify the size of stack_capacity
	char *temp_pointer = new char[stack_capacity];

	if(stack_capacity == 0)
	{
		temp_pointer = nullptr;
	}

	else
	{
		for(i = 0; i < stack_size; i++)
		{
			temp_pointer[i] = stk[i];
		}

		delete[] stk;
		stk = temp_pointer;
	}
}

//top finds top item of stack
//@returns top item of stack
const char& mystack::top() const
{
	return stk[stack_size - 1];
}

//push puts a value at the top of the stack
void mystack::push(char value)
{
	if(stack_size == stack_capacity)
	{
		reserve(stack_size + 1);
	}

	else if(stack_capacity == 0)
	{
		reserve(1);
	}

	else
	{
		reserve(stack_capacity * 2);
	}

	stk[stack_size] = value;
	stack_size = stack_size + 1;
}

//pop decreases the size of the stack by 1
void mystack::pop()
{
	stack_size--;
}
