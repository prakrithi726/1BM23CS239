#include <stdio.h>

int majorityElement(int* nums, int n) {
    int candidate = nums[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}




    
    
