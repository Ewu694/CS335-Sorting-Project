#ifndef MEDIANOFMEDIANSMETHOD_HPP
#define MEDIANOFMEDIANSMETHOD_HPP

#include <chrono>
#include "QuickSelect.hpp"

class MedianOfMediansMethod
{
    public:
        int medianOfMediansMethod(std::vector<int>& nums, int& duration)
        {
            auto start = std::chrono::steady_clock::now();

            int median = medianOfMedians(nums, nums.begin(), nums.end());

            auto end = std::chrono::steady_clock::now();
            auto diff = end - start;

            duration = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
            
            return median;
        }
        int medianOfMedians(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
        {
            bool isEven;
            if(nums.size() % 2 == 0)
                isEven = true;

            int numElements = std::distance(low, high);

            if (numElements <= 5) 
            {
                std::sort(low, high);
                return *(low + numElements / 2);
            }

            int numGroups = (numElements + 4) / 5;
            std::vector<int> medians(numGroups);

            for (int i = 0; i < numGroups; ++i) 
            {
                auto groupStart = low + i * 5;
                auto groupEnd = std::min(groupStart + 5, high);
                medians[i] = quickSelect(nums, groupStart, groupEnd, (groupEnd - groupStart) / 2);
            }

            int result = quickSelect(medians, medians.begin(), medians.end(), medians.size() / 2);
            return result;
        }
        int medianOfFive(int a, int b, int c, int d, int e)
        {
            if (a > b) 
                std::swap(a, b);
            if (c > d) 
                std::swap(c, d);
            if (a > c) 
                std::swap(a, c);
            if (b > d) 
                std::swap(b, d);
            if (b > e) 
                std::swap(b, e);
            if (a > b) 
                std::swap(a, b);
            if (c > e) 
                std::swap(c, e);
            if (c > d) 
                std::swap(c, d);
            if (d > e) 
                std::swap(d, e);
            if (c > d) 
                std::swap(c, d);
            return d;
        }
        // returns the median of medians of all elements contained between high and low, inclusive.
};
#endif