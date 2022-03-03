#include <iostream>
#include <ctime>
#include <vector>
#include "hash-table.hpp"

static const char charset[] = 
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyZ";

struct Gen
{
	Gen() {srand(time(nullptr)); maxc = sizeof(charset) / sizeof(charset[0]);}
	size_t len;
	size_t maxc;
	std::string operator()()
	{
		std::string str;
		len = 1 + rand() % 10;
		for (size_t i = 0; i < len; ++i)
			str += charset[rand() % maxc];
		return str;
	}
};

int main()
{
	std::vector<std::string> s(20);
	std::generate(s.begin(), s.end(), Gen());

	HashTable<std::string> htb1(12, [] (std::string s)
	{
		size_t sum = 0;
		for (auto c : s)
			s += c;
		return sum % 12;
	});


	HashTable<std::string> htb(std::move(htb1));

	htb1 = std::move(htb);
	htb = std::move(htb1);
	htb.insert(s.begin(), s.end());

	for (auto &v : s)
	{
		auto item = htb.find(v);
		std::cout << item.first << " " << item.second << "\n";
	}

	auto it = htb.find("zzzzz"); // since z is not charset
	std::cout << "test str that is not in hash table: " << it.first << "\n";
}
