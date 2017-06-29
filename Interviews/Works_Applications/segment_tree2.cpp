//
// Author:            cuckoo
// Date:              2017/05/25 08:28:33
// Update:            /*date*/
// Description:       Segment tree implementation
// Note:              http://www.cnblogs.com/TenosDoIt/p/3453089.html#e

//

#include <cmath>        // for ceil
#include <climits>      // for INT_MAX
#include <cstring>      // for memset
#include <cstdlib>      // for free

#include <iostream>
using std::cout;
using std::endl;


struct SegmentTreeNode
{
    int val;
    int mark;
    SegmentTreeNode() : val(0), mark(0) {}
};

SegmentTreeNode segment_tree[1000];

/*
    @func - transmit the mark from parent to it's children
    @root - index of current node in the segment tree
*/
void PushDownMark(int root)
{
    int root_mark = segment_tree[root].mark;
    if(root_mark != 0)
    {
        // set the marks of children
        // use "+=", because the child node probably be delayed for many times
        segment_tree[2 * root + 1].mark += root_mark;
        segment_tree[2 * root + 2].mark += root_mark;

        // set the values of children
        // the maximum value in segment should be added the new value when every element
        // in the segment is added this value
        segment_tree[2 * root + 1].val += root_mark;
        segment_tree[2 * root + 2].val += root_mark;

        segment_tree[root].mark = 0;
    }
}
/*
    @func - a recursive function to get the maximum value in a given range of array indexes.
    @root - index of current node in the segment tree
    @begin - starting index of the segment represented by current node
    @end - ending index of the segment represented by current node
    @query_begin - starting index of query range
    @query_end - ending index of query range
*/
int QueryAux(int begin, int end, int query_begin, int query_end, int root)
{
    if(query_begin > end || query_end < begin)      // if segment of this node is outside the given range
        return INT_MIN;
    if(query_begin <= begin && query_end >= end)    // if segment of this node is a part of given range
        return segment_tree[root].val;

    // if a part of this segment overlaps with the given range
    PushDownMark(root);

    int mid = begin + ((end - begin) >> 1);
    return std::max(QueryAux(begin, mid, query_begin, query_end, 2 * root + 1),
                    QueryAux(mid + 1, end, query_begin, query_end, 2 * root + 2));
}

/*
    @func - get the maximum value in a given range of array indexes. it mainly uses QueryAux()
    @n - the count of the numbers in the array(the count of leaf nodes in the segment tree)
    @other - same as QueryAux()
*/
int Query(int n, int query_begin, int query_end)
{
    if(query_begin < 0 || query_end >= n || query_begin > query_end)
    {
        std::cerr << "Invalid Input" << endl;
        return -1;
    }

    return QueryAux(0, n - 1, query_begin, query_end, 0);
}

/*
    @func - a recursive function to update the nodes which have the the given
        position in their range.
    @begin - starting index of the segment represented by current node
    @end - ending index of the segment represented by current node
    @update_begin - starting index of the segment to be updated
    @update_end - ending index of the segment to be updated
    @add_value - new value which is added to the nodes
    @root - index of current node in the segment tree
*/
void UpdateSegmentAux(int begin, int end, int update_begin, int update_end, int add_value, int root)
{
    if(update_begin > end || update_end < begin)
        return;
    if(update_begin <= begin && update_end >= end)
    {
        segment_tree[root].mark += add_value;
        segment_tree[root].val += add_value;

        return;
    }

    PushDownMark(root);

    int mid = begin + ((end - begin) >> 1);
    UpdateSegmentAux(begin, mid, update_begin, update_end, add_value, 2 * root + 1);
    UpdateSegmentAux(mid + 1, end, update_begin, update_end, add_value, 2 * root + 2);

    // update the parent node
    segment_tree[root].val = std::max(segment_tree[2 * root + 1].val, segment_tree[2 * root + 2].val);
}

/*
    @func - update the nodes which have the the given position in their range. It mainly uses
        UpdateSegmentAux()
    @array - input array
    @n - the count of the numbers in the array(the count of leaf nodes in the segment tree)
    @other - same as UpdateSegmentAux()
*/
void UpdateSegment(int array[], int n, int update_begin, int update_end, int add_value)
{
    if(update_begin < 0 || update_end >= n)
    {
        std::cerr << "Invalid Input" << endl;
        return;
    }

    for(int i = update_begin; i <= update_end; ++i)
        array[i] += add_value;
    
    UpdateSegmentAux(0, n - 1, update_begin, update_end, add_value, 0);
}

/*
    @func - a recursive function that constructs segment tree for array[begin...end].
    @array - input array
    @begin - starting index of the segment represented by current node
    @end - ending index of the segment represented by current node
    @root - index of current node in the segment tree
*/
void ConstructST(int array[], int begin, int end, int root)
{
    segment_tree[root].mark = 0;
    if(begin == end)        // leaf node
    {
        segment_tree[root].val = array[begin];
        return;
    }

    int mid = begin + ((end - begin) >> 1);
    ConstructST(array, begin, mid, 2 * root + 1);
    ConstructST(array, mid + 1, end, 2 * root + 2);

    segment_tree[root].val = std::max(segment_tree[2 * root + 1].val, segment_tree[2 * root + 2].val);
}

int main()
{

    int arr[] = { 2, 5, 1, 4, 6, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    ConstructST(arr, 0, n - 1, 0);

    int query_begin = 1, query_end = 5;
    cout << Query(n, query_begin, query_end) << endl;
    UpdateSegment(arr, n, 5, 5, 4);
    cout << Query(n, query_begin, query_end) << endl;

    UpdateSegment(arr, n, 2, 3, 4);
    cout << Query(n, query_begin, query_end) << endl;

    return 0;
}
