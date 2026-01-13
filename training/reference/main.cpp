#include <iostream>

/*
int main(void)
{
	int n = 5;

	int &ref = n;
	int *ptr = &n;


	std::cout << ref << std::endl;
	std::cout << n << std::endl;
	std::cout << *ptr << std::endl;

	ref = 12;
	std::cout << ref << std::endl;
	std::cout << n << std::endl;
	std::cout << *ptr << std::endl;


	*ptr = 44;
	std::cout << ref << std::endl;
	std::cout << n << std::endl;
	std::cout << *ptr << std::endl;

} */

int &getRef(void)
{
	static int num = 5;
	return num;
}

int main(void)
{
	int &num = getRef();
	// std::cout << ref << std::endl;
	std::cout << num << std::endl;

	num = 25;
	// ref = 21;

	// std::cout << ref << std::endl;
	std::cout << num << std::endl;
}