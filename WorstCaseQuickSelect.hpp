#include <iostream>
#include <vector>

std::vector<int> worstCaseQuickSelect (void)
{
    int min = 1;
    int max = 20000;
    std::vector<int> data;
    for (int i = 20000; i > 0; --i)
        data.push_back(i);
    return data;
}
