#include <iostream>
#include <string>
// sometimes i need random numbers


int main(int argc, char **argv)
{
	int max, min;
	int size;

	std::cout << "<how many numbers> <max> <min>" << std::endl;
	if (argc > 1)
	{
		srand(time(NULL));
		size = std::stoi(argv[1]);
		max = 201;
		if (argc > 2)
			max = std::stoi(argv[2]);
		else
			std::cout << "default max : 200\n";
		min = 0;
		if (argc > 3)
			min = std::stoi(argv[3]);
		else
			std::cout << "default min: 0\n";

		for (int i = 0; i < size; ++i)
			std::cout << min + (rand() % max) << ", ";
		std::cout << std::endl;
	}
}
