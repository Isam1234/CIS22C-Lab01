/*
 * Tien Nguyen
 * CIS 22C
 * StackTest.cpp
 */

#include "Stack.h"
#include <iostream>
#include <cstddef>

 //#include "List.h"
using namespace std;
int main()
{
	Stack s1;
	s1.push(1);
	cout << " The Stack_1 should contain 1: " << s1.get_top() << endl;
	s1.push(25);
	s1.push(6);
	cout << " The Stack_1 should contain 1 25 6: ";
	s1.print();
	Stack s2(s1);
	cout << " The Stack_2 should contain 1 25 6: ";
	s2.print();
	s1.pop();
	cout << " The Stack_1 should contain 1 25  : ";
	s1.print();
	cout << " The length of Stack_1 should be 2: " << s1.get_size() << endl;
	cout << " The length of Stack_2 should be 3: " << s2.get_size() << endl;
	if (s1 == s2)
		cout << "Stacks are equal !";
	else
		cout << " Stacks aren't equal !";

	return 0;
}
/*
 *
The Stack_1 should contain 1: 1
The Stack_1 should contain 1 25 6: 1 25 6
The Stack_2 should contain 1 25 6: 1 25 6
The Stack_1 should contain 1 25  : 1 25
The length of Stack_1 should be 2: 2
The length of Stack_2 should be 3: 3
Stacks aren't equal !

 */


