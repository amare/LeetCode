/*
 Author:            cuckoo
 Date:              2017/03/02 22:50:48
 Update:            2017/07/27 15:36:11
 Problem:           Median of Two Sorted Arrays
 Difficulty:        Hard
 Source:            https://leetcode.com/problems/median-of-two-sorted-arrays

 */

#include <vector>
using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return FindMedianSortedArraysFirst(nums1, nums2);
    }
    
    // update at 2017/07/27 15:36:11
    double FindMedianSortedArraysFirst(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size(), n = nums2.size();
        int sum = m + n;
        if(sum & 0x01)
            return FindKthSmallestElementBetter(nums1, m, nums2, n, sum / 2 + 1);
        else
            return (FindKthSmallestElementBetter(nums1, m, nums2, n, sum/ 2) + FindKthSmallestElementBetter(nums1, m, nums2, n, sum / 2 + 1)) / 2;
    }
    
    double FindKthSmallestElement(vector<int> &nums1, int left1, vector<int> &nums2, int left2, int k)
    {
        // assume left1 <= left2
        if(left1 > left2)
            return FindKthSmallestElement(nums2, left2, nums1, left1, k);
        
        int start1 = nums1.size() - left1, start2 = nums2.size() - left2;
        if(left1 == 0)
            return nums2[start2 + k - 1];
        if(k == 1)
            return std::min(nums1[start1], nums2[start2]);
        
        int use1 = std::min(left1, k / 2), use2 = k - use1;
        int p1 = start1 + use1 - 1, p2 = start2 + use2 - 1;
        if(nums1[p1] == nums2[p2])
            return nums1[p1];
        else if(nums1[p1] < nums2[p2])
            return FindKthSmallestElement(nums1, left1 - use1, nums2, left2, k - use1);
        else
            return FindKthSmallestElement(nums1, left1, nums2, left2 - use2, k - use2);
    }

    double FindKthSmallestElementBetter(vector<int> &A, int a_start, vector<int> &B, int b_start, int k)
    {
        if(a_start >= A.size())
            return B[b_start + k - 1];
        if(b_start >= B.size())
            return A[a_start + k - 1];
            
        if(k == 1)
            return std::min(A[a_start], B[b_start]);
        
        int a_mid_index = a_start + k / 2 - 1, b_mid_index = b_start + k / 2 - 1;
        int a_mid = a_mid_index >= A.size() ? INT_MAX : A[a_mid_index];
        int b_mid = b_mid_index >= B.size() ? INT_MAX : B[b_mid_index];
        
        if(a_mid < b_mid)
            return FindKthSmallestElementBetter(A, a_mid_index + 1, B, b_start, k - k / 2);
        else
            return FindKthSmallestElementBetter(A, a_start, B, b_mid_index + 1, k - k / 2);
    }

    double FindMedianSortedArraysSecond(int* nums1, int nums1Size, int* nums2, int nums2Size)
    {
        int total = nums1Size + nums2Size;
        if(total & 0x01)
            return FindKthNumber(nums1, nums1Size, nums2, nums2Size, total/2 + 1);
        else
            return (FindKthNumber(nums1, nums1Size, nums2, nums2Size, total/2)
                + FindKthNumber(nums1, nums1Size, nums2, nums2Size, total/2 + 1)) / 2;
    }
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
};
