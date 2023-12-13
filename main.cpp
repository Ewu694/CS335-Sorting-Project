//
//  main.cpp
//  Project 2
//
//  Created by Riyuan Liu on 11/29/23.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"

std::vector<int> readIntegersFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> numbers;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int num;
            while (iss >> num) {
                numbers.push_back(num);
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file " << filename << std::endl;
    }

    return numbers;
}
void writeIntegersToFile(const std::vector<int>& numbers, const std::string& filename) {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (size_t i = 0; i < numbers.size(); ++i) {
            file << numbers[i];
            // Add a space after each number except for the last one
            if (i != numbers.size() - 1) {
                file << " ";
            }
        }
        file.close();
        std::cout << "Numbers written to " << filename << " successfully." << std::endl;
    } else {
        std::cerr << "Unable to create/open file " << filename << std::endl;
    }
}
bool areFilesEqual(const std::string& filename1, const std::string& filename2) {
    std::ifstream file1(filename1);
    std::ifstream file2(filename2);

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Unable to open one or both files." << std::endl;
        return false;
    }

    std::string line1, line2;
    if (std::getline(file1, line1) && std::getline(file2, line2)) {
        if(line1 == line2){
            return true;
        }
    }

    return false;
}


bool isSorted(const std::vector<int>& nums) {
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] > nums[i]) {
            return false;
        }
    }
    return true;
}


int main() {
    std::string filename = "input1.txt"; // Change this to your file's name
    std::vector<int> integers = readIntegersFromFile(filename);
    int timer=0;
    // int medianofhalfselectionsort = halfSelectionSort(integers, timer);
    // writeIntegersToFile(integers, "selectionsort.txt");
    // //std::cout<<isSorted(integers)<<std::endl;
    // std::cout<<areFilesEqual("selectionsort.txt", "selectionsort1.txt")<<std::endl;


    // int medianstandardsort = standardSort(integers, timer);
    // writeIntegersToFile(integers, "standardsort.txt");
    // std::cout<<isSorted(integers)<<std::endl;

//    int mediansmergesort = mergeSort(integers, timer);
//    writeIntegersToFile(integers, "mergesort.txt");
//    std::cout<<isSorted(integers)<<std::endl;

//    int medianinplacemrgesort = inPlaceMergeSort(integers, timer);
//    writeIntegersToFile(integers, "inplacemergesort.txt");
//    std::cout<<isSorted(integers)<<std::endl;

        //HEAP SORT TEST CASE
    // int arr[] = {22, 9, 8, 71, 6, 500, 4, 3, 29, 1};
    // std::vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
    //buildHeap(test);
    int medianhalfheapsort = halfHeapSort(integers, timer);
    writeIntegersToFile(integers, "heapsort.txt");
    //std::cout<<isSorted(test)<<std::endl;
    std::cout<<areFilesEqual("heapsort.txt", "heapsort1.txt")<<std::endl;


//    int medianhalfheapsort = halfHeapSort(integers, timer);
//    std::vector<int> nums{10,9,8,7,6,5,4,3,2,1};
    // std::vector<int> nums{1,2,3,4,5,6,7,8,9,10};
    // int medianhalfheapsort = halfHeapSort(nums,timer);
    // writeIntegersToFile(nums, "heapsort.txt");
    // std::cout<<areFilesEqual("heapsort1.txt", "heapsort.txt")<<std::endl;


    return 0;
}
