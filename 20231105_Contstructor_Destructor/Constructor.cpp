#include <iostream>

using namespace std;

class ExConstructor
{
public:
	ExConstructor()
	{
		cout << "ExConstructor() called!" << endl;
	}

	ExConstructor(int a)
	{
		cout << "ExConstructor(int a) called!" << endl;
	}

	ExConstructor(int a, int b)
	{
		cout << "ExConstructor(int a, int b) called!" << endl;
	}
};

int main()
{
	ExConstructor ec1;
	ExConstructor ec2(10);
	ExConstructor ec3(20, 10);

	return 0;
}