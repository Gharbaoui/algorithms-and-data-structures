#include <iostream>
#include <string>

std::string	string_match(const std::string &str, const std::string &sub)
{
	for (int i = 0; i < str.size() - sub.size(); ++i)
	{
		int j;
		for (j = 0; j < sub.size(); ++j)
			if (sub[j] != str[i + j])
				break ;
		if (j == sub.size())
			return std::string(str.c_str() + i);
	}
	return std::string();
}


int main(int argc, char **argv)
{

	if (argc > 2)
		std::cout << string_match(argv[1], argv[2]) << std::endl;
	else
		std::cout << "enter a string and substr\n";
}
