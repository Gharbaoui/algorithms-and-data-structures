#include <ostream>

template <typename T>
std::ostream&	operator<<(std::ostream &os, const std::vector<T> &vect)
{
	for (auto val : vect)
		os << val << " ";
	return os;
}


template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &vects)
{
	for (auto &vct : vects)
		os << vct << "\n";
	return os;
}
