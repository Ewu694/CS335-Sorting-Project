#ifndef HALFSELECTIONSORT_HPP
#define HALFSELECTIONSORT_HPP

#include <iostream>
#include <vector>
#include <chrono>

class HalfSelectionSort
{
    public:
        int halfSelectionSort(std::vector<int>& nums, int& duration)
        {
            auto start = std::chrono::steady_clock::now();

            bool isEven;
            if(nums.size() % 2 == 0)
                isEven = true;

            if(nums.size() >= 50000)
                std::cout << "Input is too big for Selection Sort";

            int minIndex = 0;
            for(int i = 0; i < nums.size() / 2; ++i)
            {
                minIndex = i;
                for(int j = i + 1; j < nums.size(); j++)
                {   
                    if(nums[j] < nums[minIndex])
                    minIndex = j;
                    std::swap(nums[j], nums[minIndex]);
                }
            }   
            auto end = std::chrono::steady_clock::now();
            auto diff = end - start;

            duration = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
    
            if(isEven)
                return nums[(nums.size() / 2) - 1];
            return nums[nums.size() / 2];
        }
};
#endif

