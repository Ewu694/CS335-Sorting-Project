#ifndef WORSTCASEQUICKSELECT_HPP
#define WORSTCASEQUICKSELECT_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

class WorstCaseQuickSelect
{
    public:
        std::vector<int>& worstCaseQuickSelect(void)
        // worstCaseQuickSelect generates a worst-case input for a quickselect that uses median-of-3 partitioning. The input it generates must be of length 20,000, and contain each number from 1-20000 once.
        {
            static std::vector<int> worstCaseInput(20000);
    
            // Generating the worst-case input
            for (int i = 0; i < 20000; ++i) {
                worstCaseInput[i] = i + 1;
            }
    
            // Shuffle the elements to avoid a sorted input (for worst-case)
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(worstCaseInput.begin(), worstCaseInput.end(), g);
    
            return worstCaseInput;
        }
};
#endif