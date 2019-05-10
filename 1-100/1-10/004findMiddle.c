//寻找两个有序数组的中位数，要求时间复杂度为log(m+n)(m,n为数组长度)
#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int halfLen = (nums1Size + nums2Size + 1) / 2; 
    if(nums1Size > nums2Size){
        int *temp = nums1; nums1 = nums2; nums2 = temp;
        int tmp = nums1Size^nums2Size; nums1Size = tmp^nums1Size; nums2Size = tmp^nums2Size; 
    }
    int iMin = 0, iMax = nums1Size;
    while(iMin <= iMax){
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        if(i < iMax && nums2[j-1] > nums1[i]){
            iMin = i + 1;
        }
        else if(i > iMin && nums1[i-1] > nums2[j]){
            iMax = i - 1;
        }
        else{
            int maxLeft = 0;
            if (i == 0){
                maxLeft = nums2[j-1];
            }
            else if(j == 0){
                maxLeft = nums1[i-1];
            }
            else{
                maxLeft = (nums1[i-1]>nums2[j-1]?nums1[i-1]:nums2[j-1]);
            }
            if((nums1Size+nums2Size)%2 == 1){
                printf("奇数\n");
                return maxLeft;
            }

            int minRight = 0;
            if(i == nums1Size){
                minRight = nums2[j];
            }
            else if(j == nums2Size){
                minRight = nums1[i];
            }
            else{
                minRight = (nums1[i]<nums2[j]?nums1[i]:nums2[j]);
            }
            printf("偶数\n");
            printf("maxLeft = %.2d, minRight = %.2d\n", maxLeft, minRight);
            return (maxLeft + minRight) / 2.0;
        }
    }
    return 0;
}

int main(int argc, char *argv[]){

    int a[] = {1, 2};
    int b[] = {3, 4};
    double ret = findMedianSortedArrays(a, sizeof(a)/sizeof(a[0]), b, sizeof(b)/sizeof(b[0]));
    printf("ret = %.1lf", ret);

    return 0;
}