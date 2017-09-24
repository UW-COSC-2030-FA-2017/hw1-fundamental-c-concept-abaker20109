#include <iostream>

using namespace std;


template<class T>
class Collection
{
private:
	int size;
	T* col;
	int arySize;
public:
	Collection()
	{
		size = 0;
		arySize = 5;
		col = new T[arySize];
	}
	~Collection()
	{
		delete col;
	}

	void print()
	{
		for(int i=0;i<size;i++)
		{
			cout << col[i] << endl;
		}
	}


	void insert(T i)
	{
		if(size == arySize)
		{
			arySize = arySize * 2;
			T* tempAry = new T[arySize];
			for(int i=0;i<arySize;i++)
			{
				tempAry[i] = col[i];
			}
			delete[] col;
			col = tempAry;
		}
		col[size] = i;
		size++;
	}

	void remove(T i)
	{
		if(!isEmpty() && !notContained(i))
		{
			//cout << "Removing Item: " << i << endl;
			bool removed = false;
			int c = 0;
			while(c < size && !removed)
			{
				if(col[c] == i)
				{
					while(c < (size - 1))
					{
						col[c] = col[c + 1];
						c++;
					}
					removed = true;
				}
				c++;
			}
			size -= 1;
			cout << "Item " << i << " Removed" << endl;
		}
		else
		{
			cout << "ERROR DELETING ITEM" << endl;
		}
	}

	void removeRandom()
	{
		if(!isEmpty())
		{
			int r = rand() % (4 - size);
			cout << "Removing Random Item: " << col[r] << endl;
			while(r < (size - 1))
			{
				col[r] = col[r + 1];
				r++;
			}
			size -= 1;
		}
	}

	void makeEmpty()
	{
		if(!isEmpty())
		{
			delete[] col;
			size = 0;
			arySize = 5;
			col = new T[arySize];
		}
	}

	//bool notContained();

	bool isEmpty()
	{
		if(size == 0)
		{
			return true;

		}
		else
		{
			return false;
		}
	}

	bool notContained(int i)
	{
		bool contained = true;
		if(!isEmpty())
		{
			int c = 0;
			while(c < (size) && contained)
			{
				if(col[c] == i)
				{
					contained = false;

				}
				c++;
			}
		}
		return contained;
	}
};

int main()
{
	cout << "Creating Object<int>\n-----" << endl;
	Collection<int> intObject;
	cout << "Created Object\nObject Empty?: " << (intObject.isEmpty() == 1 ? "1 : True" : " 0 : False") << endl;
	cout << "\n-----\nInserting Items Into Object" << endl;
	intObject.insert(1);
	intObject.insert(45);
	intObject.insert(88);
	intObject.insert(23);
	intObject.insert(232);
	intObject.insert(2);
	intObject.insert(98);
	intObject.insert(42);

	cout << "\n-----\nObject Empty?: " << (intObject.isEmpty() == 1 ? "1 : True" : " 0 : False") << endl;

	cout << "\n-----\nItems In Object\n-----" << endl;
	intObject.print();
	cout << "-----" << endl;
	cout << "Object Not Contain?(34): " << (intObject.notContained(34) == 1 ? "1 : True" : " 0 : False")<< endl;
	cout << "Object Not Contain?(88): " << (intObject.notContained(88) == 1 ? "1 : True" : " 0 : False" )<< endl;

	cout << "\n-----\nRemoving Item\n-----" << endl;
	intObject.remove(88);
	cout << "-----" << endl;

	cout << "\n-----\nRemoving Random Item\n-----" << endl;
	intObject.removeRandom();
	cout << "-----" << endl;

	cout << "\n-----\nItems In Object\n-----" << endl;
	intObject.print();
	cout << "-----" << endl;
	intObject.makeEmpty();
	cout << "Object Empty?: " << (intObject.isEmpty() == 1 ? "1 : True" : " 0 : False") << endl;
	cout << endl;
}

