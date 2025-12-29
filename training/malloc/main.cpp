#include <iostream>

int main(void)
{
	int a = 5;

	int *ptr2 = new int[5];
	int *ptr = new int;

	*ptr = 5;

	std::cout << sizeof(ptr2) << std::endl;
	delete ptr;
	delete[] ptr2;
	return 0;
}