#include <iostream>
#include <vector>
#include <algorithm>

int Brute_Force(std::vector<int> &val);
bool	isAlternate(int a, int b);


struct Gen
{
	int operator()()
	{
		return rand() % 100;
	}
};


int COUNTER;

int main()
{
	
	COUNTER = 0;
	std::vector <int> values{1, 2, 10, 5, 4, 6 ,3};
	//std::generate(values.begin(), values.end(), Gen{});
	std::cout << Brute_Force(values) << std::endl;

	std::cout << "steps: " << COUNTER << std::endl;
}

int Brute_Force(std::vector<int> &val)
{
	size_t	N(val.size());
	int curdiff;
	std::vector<int> maxV, curV;
	maxV.reserve(N);
	curV.reserve(N);

	for (size_t i = 0; i < N - 1; ++i)
	{
		++COUNTER;
		curV.push_back(val[i + 1] - val[i]);
		for (size_t j = i + 2; j < N; ++j)
		{
			++COUNTER;
			curdiff = val[j] - val[j - 1];
			if (isAlternate(curV.back(), curdiff))
				curV.push_back(curdiff);
		}
		if (curV.size() > maxV.size())
			curV.swap(maxV);
		curV.clear();
	}
	for (auto v: maxV)
		std::cout << v << ", ";
	std::cout << std::endl;
	return maxV.size() + 1;
}

bool	isAlternate(int a, int b)
{
	if (a < 0 && b > 0)
		return true;
	else if (a > 0 && b < 0)
		return true;
	return false;
}
