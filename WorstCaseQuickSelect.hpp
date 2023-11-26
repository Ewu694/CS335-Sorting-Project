#ifndef WORSTCASEQUICKSELECT_HPP
#define WORSTCASEQUICKSELECT_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

class WorstCaseQuickSelect
{
    public:
        std::vector<int>& worstCaseQuickSelect(void);  
        // worstCaseQuickSelect generates a worst-case input for a quickselect that uses median-of-3 partitioning. The input it generates must be of length 20,000, and contain each number from 1-20000 once.
};
#endif