# include <iostream>
# include <unistd.h>
// "extern" keyword would refer sleep() to a function already defined in other files
// "extern C" would make a function-name in C++ to have C linkage, here we are using 
// disable C++ name mangling and directly access the C function.
//extern "C" void sleep();
//extern "C" int fork();
//extern "C" int getpid();
//extern "C" void wait();
//extern "C" void exit();

void ChildProcess();

int main()
{
	int pid, cid;
	pid = getpid();

	std::cout << "Fork demo, I am the parent (pid = )" << pid << ")\n";

	if (!fork())
	{
		cid = getpid();
		std::cout << "I am the child (cid=" << cid << ") of (pid = )" << pid << ")\n";
		ChildProcess();
		exit(0);
	}

	std::cout << "Parent waiting here for the child...\n";
	wait(NULL); // Wait for child to terminate

	std::cout << "Child finished, parent quitting too";
}

void ChildProcess()
{
	int i;
	for (i = 0; i < 10; i++) 
	{
		std::cout << i << "..\n";
		sleep(1);
	}
}


