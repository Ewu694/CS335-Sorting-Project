#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

void mergeSortHelper(std::vector<int>&nums){
    if (nums.size() <= 1)
        return;
    
    std::vector<int>::size_type center = nums.size()/2;
    std::vector<int> left(nums.begin(), nums.begin() + center);
    std::vector<int> right(nums.begin()+center, nums.end());
    mergeSortHelper(left);
    mergeSortHelper(right);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), nums.begin());
}

int mergeSort ( std::vector<int>& nums, int& duration){
    auto t1 = std::chrono::high_resolution_clock::now();
    
    int half = nums.size()/2;
    mergeSortHelper(nums);
    
    auto t2 = std::chrono::high_resolution_clock::now(); // Update the stop time
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    duration = dur.count();

    return nums[nums.size() % 2 == 0 ? nums.size() / 2 - 1 : nums.size() / 2]; //Returns the lesser of the two medians
}
