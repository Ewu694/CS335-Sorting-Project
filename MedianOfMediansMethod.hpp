#ifndef MEDIANOFMEDIANSMETHOD_HPP
#define MEDIANOFMEDIANSMETHOD_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "QuickSelect.hpp"

class MedianOfMediansMethod
{
    public:
        int medianOfMediansMethod(std::vector<int>& nums, int& duration);
        int medianOfMedians(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high);
        int medianOfFive(int a, int b, int c, int d, int e);
        // returns the median of medians of all elements contained between high and low, inclusive.
};
#endif