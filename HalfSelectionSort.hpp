#include <vector>
#include <chrono>
#include <iostream>

int leftChild(int i) { return 2 * i; }

// parameter "hole" is the index of the hole.
// percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
// percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
//void percDown ( std::vector<int>& heap, std::vector<int>::size_type hole ) {
//    int child;   // used for the index of the child of the hole to switch with
//    int tmp;     // used for the value at the hole
//
//    // perc down pseudocode:
//    /*
//     * while hole is not a leaf
//     *      check if it's in the right place (for min heap, so less than both children)
//     *      if so, continue
//     *      if not, swap it with its child
//     */
//    for (tmp = heap[hole]; leftChild(hole) < heap.size(); hole = child) {
//        child = leftChild(hole);
//        // find smaller child
//        if (child != heap.size() - 1 && heap[child] > heap[child + 1]) {
//            child++;
//        }
//
//        // move hole down
//        if (tmp > heap[child]) {
//            heap[hole] = heap[child];
//        }
//        // stop perc down
//        else {
//            break;
//        }
//    }
//
//    // maintain complete tree structure
//    heap[hole] = tmp;
//}

void percDown( std::vector<int>& a, int i ) {
    int child;
    int tmp;

    for( tmp = std::move( a[ i ] ); leftChild( i ) < a.size(); i = child ) {
        child = leftChild( i );
        if( child != a.size() - 1 && a[ child ] > a[ child + 1])
            ++child;
        if( tmp > a[ child ] )
            a[ i ] = std::move( a[ child ] );
        else
            break;
    }

    a[ i ] = std::move( tmp );
}


void buildHeap ( std::vector<int>& heap) {
    for (int i = heap.size() / 2; i > 0; --i) {
        percDown(heap, i);
    }
}


int halfHeapSort ( std::vector<int>& nums, int& duration ) {
    auto start = std::chrono::steady_clock::now();

    // move first item to back to leave open for buildHeap
    nums.push_back(nums[0]);

    buildHeap(nums);

    // delete min n/2 times - the "Half" in "HalfHeapSort"
    int halfsize = nums.size() / 2;
    for (int i = nums.size() - 1; i > halfsize + 1; i--) {
        // our root is starting at 1, so i changed it from 0 to 1
        std::swap(nums[1], nums[i]);
        nums.pop_back();
        percDown(nums, 1);
    }

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    duration = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();

    return nums[1];
}
