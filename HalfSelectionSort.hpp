#include <iostream>
#include <vector>
#include <chrono>

int halfSelectionSort ( std::vector<int>& nums, int& duration)
{
    auto t1 = std::chrono::high_resolution_clock::now();
    
    if (nums.size() > 50000)
    {
        std::cout << "Input is too big for selection sort" << std::endl;
        return -1;
    }

    int middle = (nums.size() - 1) / 2;
    for (int i = 0; i <= middle; ++i)
    {
        int min_index = i;
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[j] < nums[min_index]){
                min_index = j;
            }
        }
        std::swap(nums[i], nums[min_index]);
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    duration = dur.count();
    
    return nums[(nums.size() - 1) / 2];
}

#endif
