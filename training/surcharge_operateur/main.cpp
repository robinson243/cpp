#include <iostream>

class Number
{
	public:
		int n;
		Number(int set_n) : n(set_n) {};
		Number operator+(const Number &numA)
		{
			return (Number(this->n + numA.n));
		}
		int get()
		{
			return n;
		}
};

int main(void)
{
	// Number a(5);
	// Number b(10);
	// Number c = a + b;

	// std::cout << "a = " << a.get() << std::endl;
	// std::cout << "b = " << b.get() << std::endl;
	// std::cout << "c = " << c.get() << std::endl;

	std::cout << 960 * 256 << std::endl;
}