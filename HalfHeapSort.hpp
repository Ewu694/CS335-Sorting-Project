
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

    int halfHeapSort(std::vector<int>& nums, int& duration)
    {
        auto start = std::chrono::steady_clock::now();

        std::vector<int>::size_type newSize = nums.size() / 2;
        std::swap(nums[0], nums[nums.size() - 1]); // Move the first element to the end
        nums.resize(newSize); // Reduce the size to half

        buildHeap(nums);

        // Perform half heap sort by removing elements
        for (int i = 0; i < newSize / 2; ++i) {
        std::swap(nums[0], nums[nums.size() - 1]); // Swap root with the last element
        nums.pop_back(); // Delete the last element (smallest)
        percDown(nums, 0); // Adjust the heap
    }
        duration = newSize / 2; // Update the duration

        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;

        duration = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
        return nums[0]; // Return the median at the root
    }
    void percDown(std::vector<int>& heap, std::vector<int>::size_type hole)
    {
        std::vector<int>::size_type child;
        int tmp = std::move(heap[hole]); // Store the value at hole

        while (2 * hole + 1 < heap.size()) 
        {
            child = 2 * hole + 1;
            if (child != heap.size() - 1 && heap[child + 1] < heap[child])
                ++child; // Move to the right child if it exists and is smaller
            if (heap[child] < tmp) 
                heap[hole] = std::move(heap[child]); // Move child up
            else 
                break;
        hole = child;
        }
        heap[hole] = std::move(tmp); // Place the value at the final hole
    }
    // parameter "hole" is the index of the hole.
    // percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
    // percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
    void buildHeap(std::vector<int>& heap)
    {
        for(int i = heap.size() / 2 - 1; i >= 0; --i)
        {
            percDown(heap, i);
        }
    }