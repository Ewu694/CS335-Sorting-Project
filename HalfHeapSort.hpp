#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>

void percDown(std::vector<int> &heap, std::vector<int>::size_type hole)
{
   int temp = heap[0];/temp hold on first element 

   // Iterate through the heap starting from the root
   for (int child; hole * 2 < heap.size(); hole = child) // Iterate through the heap starting from the root
   {
      child = hole * 2;
      if (child + 1 < heap.size() && heap[child + 1] < heap[child])
         child++;
      if (temp > heap[child])
         heap[hole] = heap[child];
      else
         break;
   }
   heap[hole] = temp; // Place temp back in the right place
}

void buildHeap(std::vector<int> &heap)
{
   for (int i = (heap.size() - 1) / 2; i > 0; --i)// Iterate through the non-leaf elements of the heap
   {
      heap[0] = heap[i];
      percDown(heap, i);
   }
}

// Implementation of HalfHeapSort
int halfHeapSort(std::vector<int> &nums, int &duration)
{
   auto start_time = std::chrono::high_resolution_clock::now();

   nums.push_back(nums[0]);
   buildHeap(nums);
   int middle = (nums.size() - 2) / 2;
   for (int j = 0; j < middle; ++j)
   {
      nums[0] = nums[nums.size() - 1];
      nums.pop_back();
      percDown(nums, 1);
   }

   nums.erase(nums.begin());
    
   auto end_time = std::chrono::high_resolution_clock::now();
   duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

   return nums[0];
}
