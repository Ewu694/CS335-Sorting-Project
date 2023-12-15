#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

std::vector<int>::iterator median3(std::vector<int>::iterator& low, std::vector<int>::iterator& high) 
{
    auto center = low + std::distance(low, high) / 2;

    if ((*low < *center && *center < *high) || (*high < *center && *center < *low))
        std::swap(*center, *high);
    else if ((*center < *low && *low < *high) || (*high < *low && *low < *center))
        std::swap(*low, *high);
    return high;
}


std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) 
{
    auto pivot = median3(low, high);
    int pivotValue = *pivot;

    std::iter_swap(pivot, high);
    auto i = low;
    auto j = high;

    while (true) {
        while (i < j && *i < pivotValue) {
            i++;
        }
        while (j > i && *j >= pivotValue) {
            j--;
        }
        if (i >= j) {
            break;
        }
        std::swap(*i, *j);
    }

    std::swap(*i, *high);
    return i;
}

// Helper function for quickSelect
int quickSelectHelper(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, int k) 
{
    if (high - low < 10) {
        std::sort(low, high + 1);  // Sorts to get correct range
        return *(low + k);
    }
    auto partition = hoarePartition(nums, low, high);
    int pivotDist = std::distance(low, partition);

    if (pivotDist == k) {
        return *partition;
    } else if (pivotDist > k) {
        return quickSelectHelper(nums, low, partition - 1, k);
    } else {
        return quickSelectHelper(nums, partition + 1, high, k - pivotDist - 1);
    }
}

int quickSelect(std::vector<int>& nums, int& duration) 
{
    auto t1 = std::chrono::high_resolution_clock::now();
    
    int median = (nums.size()-1)/2;

    quickSelectHelper(nums,nums.begin(),nums.end()-1, median);

    auto t2 = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    duration = dur.count();

    return nums[median];
}
