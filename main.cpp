/***************************************************************************
* AUTHOR			: TALON BAKER
* ASSIGNMENT # 4	: QUEUE DEQUE & VECTOR
* CLASS				: CS1D
* SECTION			: TTH - 5:30PM
* DUE DATE			: 2/17/15
**************************************************************************/

#include "header.h"
int main()
{
    string string1 = "A man, a plan, a canal, Panama";
    string string2 = "Was it a car or a cat I saw?";
    string string3 = "Sit on a potato pan, Otis";
    string string4 = "Isn’t this class cool?";

	MyDeque<string> dequeTest;

	cout << "Part 1) Using wrappers! Pushing the strings\n\n";

	dequeTest.enqueue(string1);
	dequeTest.enqueue(string2);
	dequeTest.enqueue(string3);
	dequeTest.enqueue(string4);

	cout << "Contents: ";

	dequeTest.print();
	cout << endl << endl;

	cout << "empty: ";

	if(dequeTest.empty())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	cout << "Size: " << dequeTest.size() << endl;
	cout << "Front: " << dequeTest.front() << endl;

	cout << "Popping: " << dequeTest.front() << endl;
	dequeTest.dequeue();

	cout << "Contents: ";
	dequeTest.print();
	cout << endl << endl;

	cout << "Popping: " << dequeTest.front() << endl;
	dequeTest.dequeue();


	cout << "Contents: ";
	dequeTest.print();
	cout << endl << endl;

	cout << "Popping: " << dequeTest.front() << endl;
	dequeTest.dequeue();


	cout << "Contents: ";
	dequeTest.print();
	cout << endl << endl;


	cout << "Popping: " << dequeTest.front() << endl;
	dequeTest.dequeue();


	cout << "Contents: ";
	dequeTest.print();
	cout << endl << endl;

	cout << "empty: ";

	if(dequeTest.empty())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	cout << "Size: " << dequeTest.size() << endl;
	cout << "Front: " << dequeTest.front() << endl;

	cout << "Part 2, option 2: Implementing a vector ADT using doubly linked "
			"list" << endl << endl;

	cout << "Using the previous doubly linked list class to make my "
			"vector ADT" << endl;

	MyDeque<int> myVector;

	cout << "Pushing 50, 60, 40, 10, 90, 30" << endl;
	myVector.push_back(50);
	cout << "Contents: \n";
	myVector.print();
	myVector.push_back(60);
	cout << "Contents: \n";
	myVector.print();
	myVector.push_back(40);
	cout << "Contents: \n";
	myVector.print();
	myVector.push_back(10);
	cout << "Contents: \n";
	myVector.print();
	myVector.push_back(90);
	cout << "Contents: \n";
	myVector.print();
	myVector.push_back(30);
	cout << "Contents: \n";
	myVector.print();


	cout << endl << "Popping the list of all it's elements" << endl << endl;

	myVector.pop_back();
	cout << "Contents: \n";
	myVector.print();

	myVector.pop_back();
	cout << "Contents: \n";
	myVector.print();

	myVector.pop_back();
	cout << "Contents: \n";
	myVector.print();

	myVector.pop_back();
	cout << "Contents: \n";
	myVector.print();

	myVector.pop_back();
	cout << "Contents: \n";
	myVector.print();

	myVector.pop_back();
	cout << "Contents: \n";
	myVector.print();

	return 0;
}
