#include <vector>
#include <iostream>
#include <chrono>

int halfSelectionSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::steady_clock::now();

    std::size_t size = nums.size();
    if (size > 50000) //If Input is too large, exit
    {
        std::cout << "Input was too large for selection sort. Size: " << size << "\n";
        return -1;
    }
    
    for (size_t i = 0; i < size / 2 + 1; i++) 
    {
        size_t minIndex = i;
        size_t index = i;
        for (auto it = nums.begin() + i; it != nums.end(); it++) // Finds minimum for non-sorted portion of array
        {  
            int num = *it;
            int min = nums[minIndex];
            if (num < min) 
                minIndex = index;
            index++;
        }

        std::swap(nums[i], nums[minIndex]); //swap ith element with minimum
    }
    
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    duration = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();

    if (size % 2 == 0) 
        return nums[size / 2 - 1];
    else 
        return nums[nums.size() / 2];
}
