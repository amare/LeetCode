/*
 Author:            cuckoo
 Date:              2017/05/26 10:45:55
 Update:            
 Problem:           Compare Version Numbers
 Difficulty:        Medium
 Source:            https://leetcode.com/problems/compare-version-numbers/#/description

 */

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

#include <vector>
using std::vector;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        return CompareVersionSecond(version1, version2);
    }
    
    int CompareVersionFirst(string &version1, string &version2)
    {
        vector<string> v1, v2;
        string number;
        istringstream is(version1);
        while(getline(is, number, '.'))
            v1.push_back(number);
        is = istringstream(version2);
        while(getline(is, number, '.'))
            v2.push_back(number);
        
        // make the vecotr which has smaller length to increase with padding "0"   
        int length1 = v1.size(), length2 = v2.size();
        int difference = length1 - length2;
        if(difference >= 0)
            while(difference--)
                v2.push_back(string("0"));
        else
            while(difference++)
                v1.push_back(string("0"));
        
        int i = 0, j = 0;
        string number1, number2;
        while(i < v1.size())
        {
            // remove leading zeros
            int index1 = v1[i].find_first_not_of('0'), index2 = v2[i].find_first_not_of('0');
            number1 = index1 == string::npos ? "0" : v1[i].substr(index1);
            number2 = index2 == string::npos ? "0" : v2[i].substr(index2);
            
            int size1 = number1.size(), size2 = number2.size();
            if(size1 < size2)
                return -1;
            else if(size1 > size2)
                return 1;
                
            // size1 == size2
            int result = number1.compare(number2);

            if(result < 0)
                return -1;
            else if(result > 0)
                return 1;
                
            ++i;
            ++j;
        }
        
        return 0;
    }
    
    int CompareVersionSecond(string &version1, string &version2)
    {
        istringstream iss1(version1), iss2(version2);
        
        int n1 = 0, n2 = 0;
        string number1, number2;
        while(true)
        {
            
            if(not iss1 and not iss2)
                return 0;
                
            n1 = 0, n2 = 0;
            if(getline(iss1, number1, '.'))
                n1 = stoi(number1);
            if(getline(iss2, number2, '.'))
                n2 = stoi(number2);
            
            if(n1 < n2)
                return -1;
            if(n1 > n2)
                return 1;
        }
    }
};
