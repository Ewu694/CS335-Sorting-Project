#ifndef INPLACEMERGESORT_HPP
#define INPLACEMERGESORT_HPP

#include <iostream>
#include <vector>

class InPlaceMergeSort
{
    int inPlaceMergeSort(std::vector<int>& nums, int& duration);
    void inPlaceMergeSortHelper(std::vector<int>& nums, size_t start, size_t end);//helper for InPlaceMergeSort
};
#endif