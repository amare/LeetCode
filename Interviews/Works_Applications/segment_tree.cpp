//
// Author:            cuckoo
// Date:              2017/05/25 08:28:33
// Update:            /*date*/
// Description:       Segment tree implementation
// Note:              /*denote*/

//

#include <cmath>        // for ceil
#include <climits>      // for INT_MAX
#include <cstring>      // for memset
#include <cstdlib>      // for free

#include <iostream>
using std::cout;
using std::endl;

/*
struct SegmentTreeNode
{
    int val;
    SegmentTreeNode() : val(0) {}
};
*/

/*
    @func - a recursive function to get the maximum value in a given range of array indexes.
    @segment_tree - Pointer to segment tree
    @root - index of current node in the segment tree
    @begin - starting index of the segment represented by current node
    @end - ending index of the segment represented by current node
    @query_begin - starting index of query range
    @query_end - ending index of query range
*/
int QueryAux(int *segment_tree, int begin, int end, int query_begin, int query_end, int root)
{
    if(query_begin > end || query_end < begin)      // if segment of this node is outside the given range
        return INT_MIN;
    if(query_begin <= begin && query_end >= end)    // if segment of this node is a part of given range
        return segment_tree[root];

    // if a part of this segment overlaps with the given range
    int mid = begin + ((end - begin) >> 1);
    return std::max(QueryAux(segment_tree, begin, mid, query_begin, query_end, 2 * root + 1),
                    QueryAux(segment_tree, mid + 1, end, query_begin, query_end, 2 * root + 2));
}

/*
    @func - get the maximum value in a given range of array indexes. it mainly uses QueryAux()
    @n - the count of the numbers in the array(the count of leaf nodes in the segment tree)
    @other - same as QueryAux()
*/
int Query(int *segment_tree, int n, int query_begin, int query_end)
{
    if(query_begin < 0 || query_end >= n || query_begin > query_end)
    {
        std::cerr << "Invalid Input" << endl;
        return -1;
    }

    return QueryAux(segment_tree, 0, n - 1, query_begin, query_end, 0);
}

/*
    @func - a recursive function to update the nodes which have the the given
        position in their range.
    @postion - index of the element to be updated. This index is in input array.
    @new_value - new value which is used to update the nodes
    @segment_tree - Pointer to segment tree
    @root - index of current node in the segment tree
    @begin - starting index of the segment represented by current node
    @end - ending index of the segment represented by current node
*/
void UpdateNodeAux(int *segment_tree, int begin, int end, int position, int new_value, int root)
{
    if(begin == end && begin == position)       // update the value of found leaf node 
    {
        segment_tree[root] = new_value;
        return;
    }

    int mid = begin + ((end - begin) >> 1);
    if(position <= mid)
        UpdateNodeAux(segment_tree, begin, mid, position, new_value, 2 * root + 1);
    else
        UpdateNodeAux(segment_tree, mid + 1, end, position, new_value, 2 * root + 2);

    // update the parent node
    segment_tree[root] = std::max(segment_tree[2 * root + 1], segment_tree[2 * root + 2]);
}

/*
    @func - update the nodes which have the the given position in their range. It mainly uses
        UpdateNodeAux()
    @array - input array
    @n - the count of the numbers in the array(the count of leaf nodes in the segment tree)
    @other - same as UpdateNodeAux()
*/
void UpdateNode(int array[], int *segment_tree, int n, int position, int new_value)
{
    if(position < 0 || position >= n)
    {
        std::cerr << "Invalid Input" << endl;
        return;
    }

    array[position] = new_value;
    UpdateNodeAux(segment_tree, 0, n - 1, position, new_value, 0);
}

void UpdateNode2(int *segment_tree, int n, int position, int new_value)
{
    if(position < 0 || position >= n)
    {
        std::cerr << "Invalid Input" << endl;
        return;
    }

    UpdateNodeAux(segment_tree, 0, n - 1, position, new_value, 0);
}

/*
    @func - a recursive function that constructs segment tree for array[begin...end].
    @array - input array
    @segment_tree - Pointer to segment tree
    @begin - starting index of the segment represented by current node
    @end - ending index of the segment represented by current node
    @root - index of current node in the segment tree
*/
int ConstructSTAux(int array[], int *segment_tree, int begin, int end, int root)
{
    if(begin == end)        // leaf node
    {
        segment_tree[root] = array[begin];
        return segment_tree[root];
    }

    int mid = begin + ((end - begin) >> 1);
    segment_tree[root]  = std::max(ConstructSTAux(array, segment_tree, begin, mid, 2 * root + 1),
            ConstructSTAux(array, segment_tree, mid + 1, end, 2 * root + 2));

    return segment_tree[root];
}

/*
    @func - function to construct segment tree from given array. This fuction allocates memory
        for segment tree and call ConstrctSTAux() to fill the allocated memory.
    @array - input array
    @n - the count of the numbers in the array(the count of leaf nodes in the segment tree)
*/
int * ConstructST(int array[], int n)
{
    // height of segment tree
    int height = static_cast<int>(std::ceil(std::log2(n)));
    // maximum size of segment tree
    int max_size = 2 * static_cast<int>(std::pow(2, height)) - 1;

    int *segment_tree = new int[max_size];
    ConstructSTAux(array, segment_tree, 0, n - 1, 0);

    return segment_tree;
}

void DestroyST(int *segment_tree)
{
    delete [] segment_tree;
}

int main()
{
    /*{
    int a[] = { 1, 3, 2, 7, 9, 11 };
    int n = sizeof(a) / sizeof(a[0]);

    int *segment_tree = ConstructST(a, n);

    int query_begin = 1, query_end = 5;
    cout << Query(segment_tree, n, query_begin, query_end) << endl;
    UpdateNode(a, segment_tree, n, 5, 4);
    cout << Query(segment_tree, n, query_begin, query_end) << endl;

    DestroyST(segment_tree);
    }*/


    int M = 0, mod = 0;
    std::cin >> M >> mod;

    int height = static_cast<int>(std::ceil(std::log2(M)));
    int max_size = 2 * static_cast<int>(std::pow(2, height)) - 1;

    int *segment_tree = new int[max_size]();    // every element is initialized to 0

    char operation = ' ';
    int parameter = 0;
    int query_result = 0, count = 0;
    for(int i = 0; i < M; ++i)
    {
        std::cin >> operation >> parameter;
        if(operation == 'Q')
        {
            if(parameter > count)
                parameter = count;
            query_result = Query(segment_tree, M, count - parameter, count - 1);
            cout << query_result << endl;
        }
        if(operation == 'I')
        {
            UpdateNode2(segment_tree, M, count, (parameter % mod + query_result % mod) % mod);
            ++count;
        }
    }

    DestroyST(segment_tree);

    return 0;
}
