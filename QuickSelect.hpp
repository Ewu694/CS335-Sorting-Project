#ifndef QUICKSELECT_HPP
#define QUICKSELECT_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class QuickSelect
{
    public:
        int quickSelect(std::vector<int>& nums, int& duration);
        std::vector<int>::iterator hoarePartition( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high);
        // hoarePartition precondition: low points to the first element in the subarray to be partitioned. The pivot is the last element in the subarray to be partitioned, and is pointed to by high.
        // hoarePartition returns an iterator to the pivot after it's placed.

        void insertionSort(std::vector<int>& nums, int left, int right); //insertion sort helper
        int medianOfThree(std::vector<int>& nums, int left, int right); //partitioning method used as helper
};
#endif