#ifndef QUICKSELECT_HPP
#define QUICKSELECT_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

class QuickSelect
{
    public:
        int quickSelect(std::vector<int>& nums, int& duration)
        {
            auto start = std::chrono::steady_clock::now();

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
            int median = nums[left + (right - left) / 2];

            duration = right - left + 1;

            auto end = std::chrono::steady_clock::now();
            auto diff = end - start;

            duration = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
            
            return median;
        }
        std::vector<int>::iterator hoarePartition( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
        {
            int pivot = *high;
            auto i = low - 1;
            auto j = high;

            while (true) 
            {
                do 
                    ++i;
                while (*i < pivot);

                do 
                    --j;
                while (*j > pivot);

                if (i >= j)
                    break;
                std::swap(*i, *j);
            }
            std::swap(*i, *high);
            return i;
        }
        // hoarePartition precondition: low points to the first element in the subarray to be partitioned. The pivot is the last element in the subarray to be partitioned, and is pointed to by high.
        // hoarePartition returns an iterator to the pivot after it's placed.

        void insertionSort(std::vector<int>& nums, int left, int right) //insertion sort helper
        {
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
        int medianOfThree(std::vector<int>& nums, int left, int right) //partitioning method used as helper
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
};
#endif