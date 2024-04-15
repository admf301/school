#ifndef MYSTACK_H
#define MYSTACK_H

#include <cstddef>

using namespace std;

struct node
{
	int value;
	node* next;

	node(int value, node* next = nullptr)
	{
		this->value = value;
		this->next = next;
	}
};

class mystack
{

private:

	node *stack_top;
	size_t stack_size;

public:
	mystack();
	mystack(const mystack& x);
	~mystack();
	mystack& operator=(const mystack& x);
	size_t size() const;
	bool empty() const;
	void clear();
	const int& top() const;
	void push(int value);
	void pop();
	void clone(const mystack& x);
};

#endif
