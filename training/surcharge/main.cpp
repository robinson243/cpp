#include "time.hpp"

int main(void)
{
	jc::time t1(14, 25, 56);
	jc::time t2(3, 11, 5);

	std::cout << t1 << std::endl;
	std::cout << t2 << std::endl;
	std::cout << t1 + t2 << std::endl;
	return 0;
}