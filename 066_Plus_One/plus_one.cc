/*
 Author:            cuckoo
 Date:              2017/02/27 10:20:20
 Update:
 Problem:           Plus One
 Difficulty:        Easy
 Source:            https://leetcode.com/problems/plus-one
 Note:
 Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 You may assume the integer do not contain any leading zero, except the number 0 itself.
 The digits are stored such that the most significant digit is at the head of the list.

 Input: [9, 9]
 Output: [1, 0, 0]

 Solution: 1.if current digit is 9, carry

 */

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

//
vector<int> plusOne_1(vector<int> &digits)
{
    bool carry = true;
    //
    auto iter = digits.rbegin();
    for(; iter != digits.rend(); ++iter)
    {
        if(*iter == 9)
        {
            *iter = 0;
        }
        else
        {
            *iter += 1;
            carry = false;
            break;
        }
    }
    if(iter == digits.rend() && carry)  //if [the most significant digit is 9]&& [carry == 1]
    {
        vector<int> ret;
        ret.push_back(1);
        for(auto i : digits)
        {
            ret.push_back(i);
        }
        return ret;
    }
    //
    return digits;
}

vector<int> plusOne(vector<int>& digits)
{
    return plusOne_1(digits);
}

int main()
{
    vector<int> digits = {9, 9};
    vector<int> plus_one = plusOne(digits);
    for(auto i : plus_one)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
