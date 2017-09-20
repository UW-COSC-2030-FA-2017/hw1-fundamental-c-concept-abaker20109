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
	i++;
	cout << "Count ++ : " << i << endl;
	if(i < 10)
	{
		return addOne(i);
	}
	else
	{
		cout << "Count Reached 10" << endl;
		return i;
	}
}

static int minusOne(int i)
{
	i--;
	cout << "Count -- : " << i << endl;
	if(i > 0)
	{
		return minusOne(i);
	}
	else
	{
		cout << "Count Reached 0" << endl;
		return i;
	}
}

int main() {
	int count = 0;

	cout << "Adding One To Count \nVia Recursion\n-------------" << endl;

	cout << "Starting At : " << count << endl;
	count = addOne(count);
	cout << "-------------\n\n" << "-------------" << endl;

	cout << "Minus One From Count \nVia Recursion" << endl;
	cout << "-------------" << endl;
	cout << "Starting At : " << count << endl;
	count = minusOne(count);
	cout << "-------------" << endl;

	return 0;
}


