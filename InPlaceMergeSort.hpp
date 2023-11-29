#ifndef INPLACEMERGESORT_HPP
#define INPLACEMERGESORT_HPP

#include <iostream>
#include <vector>
#include <chrono>

class InPlaceMergeSort
{
    int inPlaceMergeSort(std::vector<int>& nums, int& duration)
    {
        auto start = std::chrono::steady_clock::now();

        bool isEven;
        if(nums.size() % 2 == 0)
            isEven = true;

        inPlaceMergeSortHelper(nums, 0, nums.size() - 1);

        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;

        duration = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();

        if(isEven)
            return nums[(nums.size() / 2) - 1];
        return nums[nums.size() / 2];
    }
    void inPlaceMergeSortHelper(std::vector<int>& nums, size_t start, size_t end)//helper for InPlaceMergeSort
    {
        if (start < end)
        {
            size_t mid = start + (end - start) / 2;

            inPlaceMergeSortHelper(nums, start, mid);
            inPlaceMergeSortHelper(nums, mid + 1, end);

            std::inplace_merge(nums.begin() + start, nums.begin() + mid + 1, nums.begin() + end + 1);
        }
    }
};
#endif