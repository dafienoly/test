#include <iostream>
#include <stack>
using namespace std;


class MyClass
{
public:
	MyClass();
	~MyClass();
	void push(int elem);
	int pop();
	int getMin();
private:
	stack<int> stackData;
	stack<int> stackMin;
};

void MyClass::push(int elem)
{
	stackData.push(elem);
	if (!stackMin.empty())
	{
		if (elem <= stackMin.top())
		{
			stackMin.push(elem);
		}
	}
	else
	{
		stackMin.push(elem);
	}
}

int MyClass::pop()
{
	if (stackData.empty())
		return 0;
	int elem = stackData.top();
	stackData.pop();
	if (elem == stackMin.top())
	{
		stackMin.pop();
	}
}

int MyClass::getMin()
{
	return stackMin.top();
}

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int main()
{
	MyClass myStack = MyClass();
	myStack.push(2);
	cout << myStack.getMin() << endl;
	myStack.push(3);
	cout << myStack.getMin() << endl;
	myStack.push(1);
	cout << myStack.getMin() << endl;
	myStack.push(4);
	cout << myStack.getMin() << endl;
	myStack.push(5);
	cout << myStack.getMin() << endl;
	for (int i = 0; i <= 4; i++)
	{
		cout << myStack.getMin() << endl;
		myStack.pop();
	}
	getchar();
}