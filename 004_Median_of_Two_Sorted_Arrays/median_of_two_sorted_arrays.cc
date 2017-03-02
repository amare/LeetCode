
#include "median_of_two_sorted_arrays.h"

#include <iostream>
using std::cout;
using std::endl;


int main()
{
    int test_a[] = {1};
    int test_b[] = {2};

    cout << findMedianSortedArrays(test_a, 1, test_b, 1) << endl;

    int test_a1[] = {0, 1, 2};
    int test_b1[] = {3, 4};
    cout << findMedianSortedArrays(test_a1, 3, test_b1, 2) << endl;

    int test_a2[] = {0, 1, 2, 10, 12};
    int test_b2[] = {3, 4, 20, 40};
    cout << findMedianSortedArrays(test_a2, 5, test_b2, 4) << endl;


    return 0;
}
