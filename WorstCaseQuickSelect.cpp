#include "WorstCaseQuickSelect.hpp"

std::vector<int>& WorstCaseQuickSelect::worstCaseQuickSelect() {
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