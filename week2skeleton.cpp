#include <string>
#include <iostream>
#include <cassert>

int getMax(int a[], int n) {
    return 0;
}

int sumOverThreshold(int x[], int length, int threshold) {
    return 0;
}

std::string endX(std::string str) {
    return "";
}

bool isSolvable(int x, int y, int c) {
    return true;
}

// Change QUESTION to test a different question
const int QUESTION = 4;

int main() {
    int arr1[4] = {0, 3, 5, 10};
    int arr2[6] = {10, 4, 2, 4, 2, 10};
    int arr3[5] = {-5, -2, -100, -1, -3};
    int arr4[1] = {1000};

    switch(QUESTION) {
        case 1:
            assert(getMax(arr1, 4) == 10);
            assert(getMax(arr2, 6) == 10);
            assert(getMax(arr3, 5) == -1);
            assert(getMax(arr4, 1) == 1000);
            break;
        case 2:
            assert(sumOverThreshold(arr1, 4, -1) == 0);
            assert(sumOverThreshold(arr2, 6, 14) == 16);
            assert(sumOverThreshold(arr4, 1, 10000) == -1);
            break;
        case 3:
            assert(endX("xrxe") == "rexx");
            assert(endX("xcxsx3x2xixsxcxoxoxlx") == "cs32iscoolxxxxxxxxxxx");
            assert(endX("xxxaaa") == "aaaxxx");
            break;
        case 4:
            assert(isSolvable(7, 5, 45) == true);
            assert(isSolvable(100, 100, 0) == true);
            assert(isSolvable(9, 23, 112) == false);
            break;
    }
    
    std::cout << "Passed all test cases." << std::endl;
}