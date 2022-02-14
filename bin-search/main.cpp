#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        auto start = 0;
        auto end = nums.size() - 1;
        int mid;
        while (start <= end)
        {
            mid = start + (end - start)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }
};

int main()
{
	std::vector<int> v{5};

	Solution s;

	std::cout << s.search(v, -5) << std::endl;
}
