
#include "inpost.h"
#include "mystack.h"

//function prototypes
bool isOperator(char x);
int precedence(char x);

//convert function converts infix expression to postfix notation
//@param const string& infix - string to be converted
//@returns - converted postfix output string
string convert(const string& infix)
{
	//create the stack and output string
	//declare the length of the infix string
	mystack s;
	string output = "";
	int n = infix.length();

	//iterate through each array entry
	for(int i = 0; i < n; i++)
	{
		//if the char is a space, continue on
		if(infix[i] == ' ')
		{
			continue;
		}

		//if the char is a letter
		else if(infix[i] >= 'a' && infix[i] <= 'z')
		{
			//add the letter and a space to the output string
			output += infix[i];
			output += ' ';
		}

		//if the char is a number
		else if(infix[i] >= '0' && infix[i] <= '9')
		{
			//add the number to the end of the output string
			output += infix[i];
		}

		//if the char is a number and the next char is an operator
		else if((infix[i] >= '0' && infix[i] <= '9') && isOperator(s.top()))
		{
			//add the number and a space to the end of the output string
			output += infix[i];
			output += ' ';
		}

		//if the char is a left parenthesis
		else if(infix[i] == '(')
		{
			s.push(infix[i]);
		}

		//if the char is a right parenthesis
		else if(infix[i] == ')')
		{
			while((s.top() != '(') && (!s.empty()))
			{
				char temp = s.top();
				output += temp;
				output += ' ';
				s.pop();
			}

			if(s.top() == '(')
			{
				s.pop();
			}
		}

		//if the char is an operator
		else if(isOperator(infix[i]))
		{
			if(s.empty())
			{
				s.push(infix[i]);
			}

			//check precedence of the operator
			else
			{
				if(precedence(infix[i]) > precedence(s.top()))
				{
					s.push(infix[i]);
				}

				else if((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^'))
				{
					s.push(infix[i]);
				}

				else
				{
					while((!s.empty()) && (precedence(infix[i]) <= precedence(s.top())))
					{
						output += s.top();
						output += ' ';
						s.pop();
					}

					s.push(infix[i]);
				}
			}
		}
	}

	//while the stack is not empty
	while(!s.empty())
	{
		output += s.top();
		output += ' ';
		s.pop();
	}

	return output;
}

//precedence checks the order of operations for operators
//@param char x - operator to be checked
//@returns a precedence value depending on which operator was entered. Highest returns 3, lowest returns -1
int precedence(char x)
{
	if(x == '^' || x == '~')
	{
		return 3;
	}

	else if(x == '*' || x == '/')
	{
		return 2;
	}

	else if(x == '+' || x == '-')
	{
		return 1;
	}

	else
	{
		return -1;
	}
}

//isOperator checks if the character is an operator
//@param char x - char to be checked
//@returns true if character is an operator
//@returns false if character is not an operator
bool isOperator(char x)
{
	if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '~')
	{
		return true;
	}

	else
	{
		return false;
	}
}
