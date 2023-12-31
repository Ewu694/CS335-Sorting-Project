#include <vector>
#include <chrono>
#include <iostream>

int leftChild(int i) { return 2 * i; }

void percDown(std::vector<int>& a, int i) 
{
    int child;
    int tmp;

    for(tmp = std::move( a[ i ] ); leftChild( i ) < a.size(); i = child) 
    {
        child = leftChild(i);
        if(child != a.size() - 1 && a[ child ] > a[ child + 1])
            ++child;
        if(tmp > a[ child ])
            a[i] = std::move(a[child]);
        else
            break;
    }

    a[i] = std::move(tmp);
}


void buildHeap (std::vector<int>& heap) {
    for (int i = heap.size() / 2; i > 0; --i) {
        percDown(heap, i);
    }
}

int halfHeapSort (std::vector<int>& nums, int& duration) {
    auto start = std::chrono::steady_clock::now();
    
    nums.push_back(nums[0]);

    buildHeap(nums);

    int halfsize = nums.size() / 2; // Delete min n/2 times
    for (int i = nums.size() - 1; i > halfsize + 1; i--) 
    {
        std::swap(nums[1], nums[i]); // Root starts at 1 and not 0
        nums.pop_back();
        percDown(nums, 1);
    }

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    duration = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();

    return nums[1];
}
