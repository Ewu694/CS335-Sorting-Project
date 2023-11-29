#ifndef STANDARDSORT_HPP
#define STANDARDSORT_HPP

#include <iostream>
#include <vector>
#include <chrono>

class StandardSort
{
    public:
        int standardSort(std::vector<int>& nums, int& duration)
        {
            auto start = std::chrono::steady_clock::now();

            bool isEven;
            if(nums.size() % 2 == 0)
                isEven = true;

            std::sort(nums.begin(), nums.end());

            auto end = std::chrono::steady_clock::now();
            auto diff = end - start;

            duration = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();

            if(isEven)
                return nums[(nums.size() / 2) - 1];
            return nums[nums.size() / 2];
        }
};
#endif