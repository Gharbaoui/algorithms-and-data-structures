#include "course-schedule.cpp"

int main()
{
	std::vector<std::vector<int>> v 
{{0,10},{3,18},{5,5},{6,11},{11,14},{13,1},{15,1},{17,4}};
	Solution s;

	std::cout << s.canFinish(20, v) << std::endl;
}
