#include <iostream>

void displayMsg(const std::string &Message)
{
	std::cout << Message << std::endl;
}

int sum(const int& a, const int& b)
{
	return a + b;
}

int main()
{
	// void (*ptr_to_display)(const std::string &Message);
	// ptr_to_display = &displayMsg;
	// ptr_to_display("je suis un message");

	int (*ptr_to_sum)(const int& x , const int& y) = &sum;
	
}