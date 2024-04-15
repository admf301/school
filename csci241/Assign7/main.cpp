
#include <iostream>
#include <string>
#include "inpost.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main()
{
    string infix;
    string postfix;

    while (getline(cin, infix))
    {
        cout << "  infix: " << infix << endl;
        postfix = convert(infix);
        cout << "postfix: " << postfix << endl << endl;
    }

    return 0;
}
