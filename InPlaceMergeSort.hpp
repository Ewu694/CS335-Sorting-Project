#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

void inPlaceMergeSortHelper(std::vector<int>&nums,std::vector<int>::size_type left, std::vector<int>::size_type right )
{
    if (left < right) 
    {
        std::vector<int>::size_type center = left + (right - left) / 2;
        inPlaceMergeSortHelper(nums, left, center);
        inPlaceMergeSortHelper(nums, center + 1, right);
        std::inplace_merge(nums.begin() + left, nums.begin() + center + 1, nums.begin() + right + 1);
    }
}

int inPlaceMergeSort ( std::vector<int>& nums, int& duration)
{
    auto t1 = std::chrono::high_resolution_clock::now();

    size_t half = (nums.size() - 1) / 2;
    inPlaceMergeSortHelper(nums, 0, nums.size()-1);

    auto t2 = std::chrono::high_resolution_clock::now(); // Update the stop time
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    duration = dur.count();

    return nums[half];
}
