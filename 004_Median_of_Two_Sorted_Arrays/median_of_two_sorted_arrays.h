/*
 Author:            cuckoo
 Date:              2017/03/02 22:50:48
 Update:
 Problem:           Median of Two Sorted Arrays
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/median-of-two-sorted-arrays

 */

int min(int a, int b)
{
    return a < b ? a : b;
}
// find the Kth small number
double FindKthNumber(int a[], int m, int b[], int n, int k)
{
    // assume m <= n
    if(m > n)
        return FindKthNumber(b, n, a, m, k);
    if(m == 0)
        return b[k-1];
    if(k == 1)
        return min(a[0], b[0]);

    // divide k into two parts, and delete smaller numbers
    int pa = min(m, k/2), pb = k - pa;
    if(a[pa-1] < b[pb-1])
        return FindKthNumber(a+pa, m-pa, b, n, k-pa);
    else if(a[pa-1] > b[pb-1])
        return FindKthNumber(a, m, b+pb, n-pb, k-pb);
    else
        return a[pa-1];
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    if(total & 0x01)
        return FindKthNumber(nums1, nums1Size, nums2, nums2Size, total/2 + 1);
    else
        return (FindKthNumber(nums1, nums1Size, nums2, nums2Size, total/2)
            + FindKthNumber(nums1, nums1Size, nums2, nums2Size, total/2 + 1)) / 2;
}
