#ifndef ASSIGNMENT_2_HALFSELECTIONSORT_HPP
#define ASSIGNMENT_2_HALFSELECTIONSORT_HPP

#include <vector>
#include <iostream>
#include <chrono>

int halfSelectionSort(std::vector<int>& nums, int& duration) {
    // start time calculation from here
    auto start = std::chrono::steady_clock::now();

    std::size_t size = nums.size();

    // input is too big, don't use this method
    if (size > 50000) {
        std::cout << "This input was too large for selection sort. Size: " << size << "\n";
        return -1;
    }


    for (size_t i = 0; i < size / 2 + 1; i++) {
        // initialize minIndex (index of minimum element) and index (general index for nested loop)
        size_t minIndex = i;
        size_t index = i;

        // find minimum for non-sorted portion of array
        for (auto it = nums.begin() + i; it != nums.end(); it++) {
            int num = *it;
            int min = nums[minIndex];

            if (num < min) {
                minIndex = index;
            }

            index++;
        }

        // swap ith element with minimum
        std::swap(nums[i], nums[minIndex]);
    }

    // calculate time elapsed
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    duration = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();

    // print half-sorted vector to console
//    for (int num : nums) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;

    // return median
    if (size % 2 == 0) {
        return nums[size / 2 - 1];
    } else {
        return nums[nums.size() / 2];
    }
}



#endif //ASSIGNMENT_2_HALFSELECTIONSORT_HPP
