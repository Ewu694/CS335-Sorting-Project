#include "QuickSelect.hpp"

std::vector<int>::iterator QuickSelect::hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) 
{
    int pivot = *high;
    auto i = low - 1;
    auto j = high;

    while (true) 
    {
        do 
        {
            ++i;
        } while (*i < pivot);

        do 
        {
            --j;
        } while (*j > pivot);

        if (i >= j)
            break;
        std::swap(*i, *j);
    }
    std::swap(*i, *high);
    return i;
}

void QuickSelect::insertionSort(std::vector<int>& nums, int left, int right) {
    for (int i = left + 1; i <= right; ++i) 
    {
        int key = nums[i];
        int j = i - 1;

        while (j >= left && nums[j] > key) 
        {
            nums[j + 1] = nums[j];
            --j;
        }

        nums[j + 1] = key;
    }
}

int QuickSelect::medianOfThree(std::vector<int>& nums, int left, int right) 
{
    int mid = left + (right - left) / 2;
    if (nums[left] > nums[mid])
        std::swap(nums[left], nums[mid]);
    if (nums[left] > nums[right]) 
        std::swap(nums[left], nums[right]);
    if (nums[mid] > nums[right])
        std::swap(nums[mid], nums[right]);
    return mid;
}

int QuickSelect::quickSelect(std::vector<int>& nums, int& duration)
{
    int left = 0;
    int right = nums.size() - 1;

    while (right - left > 10) 
    {
        int pivotIndex = medianOfThree(nums, left, right);
        std::swap(nums[pivotIndex], nums[right - 1]); // Move pivot to second-to-last position
        auto pivotIter = hoarePartition(nums, nums.begin() + left, nums.begin() + right);

        if (std::distance(nums.begin(), pivotIter) > (left + right) / 2)
            right = std::distance(nums.begin(), pivotIter) - 1;
        else
            left = std::distance(nums.begin(), pivotIter) + 1;
    }

    insertionSort(nums, left, right); // Sort the remaining elements using insertion sort

    duration = right - left + 1;
    return nums[left + (right - left) / 2]; // Return the median
}