#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size) {
    
    int size = nums1Size + nums2Size;
    int merge[size];
    int i, j;

    for (i = 0; i < nums1Size; i++) {
        merge[i] = nums1[i];
    }

    for (i = 0; i < nums2Size; i++) {
        merge[nums1Size + i] = nums2[i];
    }

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            
            if (merge[j] > merge[j + 1]) {
                int temp = merge[j];
                merge[j] = merge[j + 1];
                merge[j + 1] = temp;
            }
        }
    }

    if (size % 2 == 1) {
        return merge[size / 2];
    } 
    else {
        return (merge[size / 2 - 1] + merge[size / 2]) / 2.0;
    }
}

int main() {

    int nums1[] = {1, 3};
    int nums2[] = {2};

    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    double median = findMedianSortedArrays(nums1,nums1Size,nums2,nums2Size);

    printf("Median = %.2f\n", median);

    return 0;
}
