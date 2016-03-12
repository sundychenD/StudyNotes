#include <iostream>
#include <sstream>
#include <string>

const int forever = 1;
const int stacksize = 10;
const int bufsize = 20;

class Stack {
	public: 
		int stack[stacksize];	
		Stack();
		void ShowStack();
		void Push(int);
		int Pop();

	private: 
		int stackpointer;
};

int main() {
	char input[bufsize];
	char command[5];
	int number, newnumber;
	Stack s;

	std::cout << "Stack demo\n\n";
	s.ShowStack();

	while (forever) 
	{
		std::cout << "Enter command";

		std::cin.getline(input, bufsize);
		std::stringstream stream(input);
		stream >> command >> number; // >> right shift is been overloaded, here we reading 2 things, one char array one integer and put them into "command" and "number" correspondingly;
		
		if (strcmp(command, "push") == 0) 
		{
			s.Push(number);
		}

		else if (strcmp(command, "pop") == 0)
		{
			newnumber = s.Pop();
		}

		else if (strcmp(command, "quit") == 0)
		{
			break;	
		}
		
		else 
		{
			number = 0;
			std::cout << "Bad command\n\n";
		}

		s.ShowStack();
	}
	s.ShowStack();
}

// ***********************
// Class Stack
// ***********************

Stack::Stack()
{
	int i;
	stackpointer = 0;

	for (i = 0; i < stacksize; i++)
	{
		stack[i] = 0;
	}
}

void Stack::Push(int n)
{
	std::cout << "Pushing" << n << " on the stack\n";

	if (stackpointer >= stacksize)
	{
		std::cerr << "Stack overflow!\n";
		return;
	}

	stack[stackpointer] = n;
	stackpointer++;
}

int Stack::Pop()
{
	if (stackpointer == 0)
	{
		std::cerr << "Stack underflow!\n";
		return 0;
	}
	stackpointer--;
	stack[stackpointer] = 0;
	std::cout << "Popped " << stack[stackpointer] << " from stack\n";

	return (stack[stackpointer]);
}

void Stack::ShowStack()
{
	int i;

	for (i = stacksize - 1; i >= 0; i--)
	{
		std::cout << "Stack[" << i << "] = " << stack[i];

		if (i == stackpointer)
		{
			std::cout << " <<-- Pointer\n";
		}

		else 
		{
			std::cout << std::endl;
		}
	}
}
