#include "MergeSort.hpp"

int MergeSort::mergeSort(std::vector<int>& nums, int& duration)
{
    bool isEven;
    if(nums.size() % 2 == 0)
        isEven = true;

    std::vector<int> temp(nums.size());
    mergeSortHelper(nums, temp, 0, nums.size() - 1);

    if(isEven)
    {
        return nums[(nums.size() / 2) - 1];
    }
    return nums[nums.size() / 2];
}

void MergeSort::mergeSortHelper(std::vector<int>& nums, std::vector<int>& temp, int start, int end)
{
    if (start < end) 
    {
        int mid = start + (end - start) / 2;

        mergeSortHelper(nums, temp, start, mid);
        mergeSortHelper(nums, temp, mid + 1, end);

        std::merge(nums, temp, start, mid, end);
    }
}