#include <iostream>
#include <vector>

void displayVec(const std::vector<int> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
}

int main()
{
	std::vector<int> my_vec;
	// std::cout << my_vec.empty() << std::endl;
	my_vec.push_back(4);
	displayVec(my_vec);
}