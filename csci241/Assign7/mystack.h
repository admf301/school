
#ifndef MYSTACK_H
#define MYSTACK_H

#include <cstdlib>
#include <cstddef>

class mystack
{

//private data members:
//*stk - pointer to a char to dynamically allocate a char array
//stack_capacity - number of elements in the stack array
//stack_size - number of values currently in the stack array
private:
	char *stk;
	size_t stack_capacity;
	size_t stack_size;

//function prototypes for member functions
public:
	mystack();
	mystack(const mystack& x);
	~mystack();
	mystack& operator=(const mystack& x);
	size_t capacity() const;
	size_t size() const;
	bool empty() const;
	void clear();
	void reserve(size_t n);
	const char& top() const;
	void push(char value);
	void pop();
};

#endif
