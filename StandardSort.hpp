#ifndef STANDARDSORT_HPP
#define STANDARDSORT_HPP

#include <iostream>
#include <vector>

class StandardSort
{
    public:
        int standardSort(std::vector<int>& nums, int& duration)
        {
            bool isEven;
            if(nums.size() % 2 == 0)
            isEven = true;

            std::sort(nums.begin(), nums.end());

        if(isEven)
            return nums[(nums.size() / 2) - 1];
        return nums[nums.size() / 2];
        }
};
#endif