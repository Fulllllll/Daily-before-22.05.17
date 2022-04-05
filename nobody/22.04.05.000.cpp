#include<stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = 0, j = 0;
    int len = 0;
    int* nums = (int*)malloc(sizeof(int) * (m + n));
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
            nums[len++] = nums1[i];
        else
            nums[len++] = nums2[j];
        i++;
        j++;
    }
    while (i < m)
    {
        nums[len++] = nums1[i++];
    }
    while (j < n)
    {
        nums[len++] = nums2[j++];
    }

    for (int i = 0; i < len; i++)
    {
        nums1[i] = nums[i];
    }
}
int main()
{
    int a[] = { 1,2,3,0,0,0 };
    int b[] = { 2,5,6 };
    merge(a, 6, 3, b, 3, 3);




    return 0;
}