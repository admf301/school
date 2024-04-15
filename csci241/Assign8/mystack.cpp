#include "mystack.h"
#include <cstdlib>

mystack::mystack()
{
	stack_size = 0;
	stack_top = nullptr;
}

mystack::mystack(const mystack& x)
{
	stack_top = nullptr;
	clone(x);
	stack_size = x.stack_size;
}

mystack::~mystack()
{
	clear();
}

mystack& mystack::operator=(const mystack& x)
{
	if(this != &x)
	{
		clear();
		clone(x);
		stack_size = x.stack_size;
	}

	return *this;
}

size_t mystack::size() const
{
	return stack_size;
}

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

void mystack::clear()
{
	while(!empty())
	{
		pop();
	}
}

const int& mystack::top() const
{
	return stack_top->value;
}

void mystack::push(int value)
{
	node *temp = new node();
	temp->value = value;
	temp->next = stack_top;
	stack_top = temp;

	stack_size++;
}

void mystack::pop()
{
	node *temp;
	temp = stack_top;

	if(stack_top == nullptr)
	{
		return;
	}

	else
	{
		temp = stack_top;
		stack_top = stack_top->next;
		delete temp;
	}

	stack_size--;
}

void clone(const mystack& x)
{
	node *current = x.stack_top;
	node *prev = nullptr;
	node *new_node;

	while(current != nullptr)
	{

		new_node->value = ptr->value;

		if(prev == nullptr)
		{
			stack_top = new_node;
		}

		else
		{
			prev->next = new_node;
		}

		prev = new_node;
		current = current->next;
	}
}
