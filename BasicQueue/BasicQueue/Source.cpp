#include "Queue.h"
#include <iostream>

void view(Queue z)
{
	int data;

	while (z.peek(data))
	{
		std::cout << data << ", ";
		z.pop();
	}

	std::cout << std::endl;
}

int main()
{
	Queue z;

	z.push(5);
	z.push(10);
	z.push(8);
	z.push(11);
	z.push(22);

	view(z);
	z.pop();
	view(z);

	return 0;
}