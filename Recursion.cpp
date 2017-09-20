//============================================================================
// Name        : Recursion.cpp
// Author      : Aaron Baker
// Class		   : Computer Science 2 : Homework 1
// Description : Recursion with adding and subtracting numbers
//============================================================================

#include <iostream>
using namespace std;

static int addOne(int i)
{
	i++; // Adding 1 to the current count
	cout << "Count ++ : " << i << endl; // showing user new count
	if(i < 10)
	{
		return addOne(i); // recall addOne method if count is less than 10
	}
	else
	{
		cout << "Count Reached 10" << endl;
		return i; // if count is equal to 10 return the value of count
	}
}

static int minusOne(int i)
{
	i--; // Minus 1 from current count
	cout << "Count -- : " << i << endl; // showing user new count
	if(i > 0)
	{
		return minusOne(i); // recall minusOne method if count is more than 0
	}
	else
	{
		cout << "Count Reached 0" << endl;
		return i; // if count is 0 return the value of count
	}
}

int main() {
	int count = 0;

	cout << "Adding One To Count \nVia Recursion\n-------------" << endl;

	cout << "Starting At : " << count << endl;
	count = addOne(count); // call addOne() method with int of count and setting the new value of count
	cout << "-------------\n\n" << "-------------" << endl;

	cout << "Minus One From Count \nVia Recursion" << endl;
	cout << "-------------" << endl;
	cout << "Starting At : " << count << endl;
	count = minusOne(count); // calling minusOne() method with int of count and setting the new value of count
	cout << "-------------" << endl;

	return 0;
}


