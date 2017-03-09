/*
 Author:            cuckoo
 Date:              2017/03/07 19:58:37
 Update:
 Problem:           Regular Expression Matching
 Difficulty:        hard
 Source:            https://leetcode.com/problems/regular-expression-matching

 */

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch_2(s, p);
    }

    bool isMatch_1(string s, string p)
    {
        if(p.empty())
            return s.empty();
        if(1 == p.size())
            return (1 == s.size() && (p.at(0) == s.at(0) || '.' == p.at(0)));
        if('*' == p.at(1))
            return (isMatch_1(s, p.substr(2)) || !s.empty() && (s.at(0) == p.at(0) || '.' == p.at(0)) && isMatch_1(s.substr(1), p));
        else
            return (!s.empty() && (s.at(0) == p.at(0) || '.' == p.at(0)) && isMatch_1(s.substr(1), p.substr(1)));
    }

    bool isMatch_2(string s, string p)
    {
        int s_size = s.size(), p_size = p.size();
        vector<vector<bool>> table(s_size + 1, vector<bool>(p_size + 1, false));

        table[0][0] = true;
        if(s_size >= 1 && p_size >= 1)
            table[1][1] = (s[0] == p[0] || '.' == p[0]);
        /* it's not necessary, because table[i][0], table[i][1] has been set to false when table is initialized
        // initialize table[i][0]
        for(int i = 1; i <= s_size; ++i)
        {
            table[i][0] = false;
        }

        //initialize table[i][1]
        for(int i = 2; i <= s_size; ++i)
        {
            table[i][1] = false;
        }
        */

        // initialize table[0][j]
        /* it's not necessary
        if(p_size >= 1)
            table[0][1] = false;
        */
        for(int j = 2; j <= p_size; ++j)
        {
            table[0][j] = ('*' == p[j-1] && table[0][j-2]);
        }

        for(int i = 1; i <= s_size; ++i)
        {
            for(int j = 2; j <= p_size; ++j)
            {
                if(p[j-1] != '*')
                    table[i][j] = ((s[i-1] == p[j-1] || '.' == p[j-1]) && table[i-1][j-1]);
                else
                    table[i][j] = (table[i][j-2] || (('.' == p[j-2] || s[i-1] == p[j-2]) && table[i-1][j]));
            }
        }

        return table[s_size][p_size];
    }


    /* wrong answer
    // wrong understanding: '*' is not a placeholder, and it matches zero or more of the [preceding element].
    bool isMatch_0(string &s, string &p)
    {
        int size_s = s.size();
        int size_p = p.size();

        int i = 0, j = 0;
        while(i < size_s && j < size_p)
        {
            if(s.at(i) == p.at(j) || p.at(j) == '.')
            {
                ++i;
                ++j;
            }
            else if(p.at(j) == '*')
            {
                // ++i;
                ++j;
                if(j == size_p)
                    return true;
                while(i < size_s)
                {
                    if(s.at(i) != p.at(j))
                    {
                        ++i;
                    }
                    else
                    {
                        ++i;
                        ++j;
                        break;  //don't forget it
                    }
                }
            }
            else
            {
                return false;
            }
        }

        if(i == size_s && j == size_p)
        {
            return true;
        }

        if(i == size_s)
        {
            if(p.at(j) == '*' && (j+1) == size_p)
                return true;
            else
                return false;
        }
        if(j == size_p)
        {
            return false;
        }
    }
    */
    /* wrong thinking method
    // can not resolve it.
    bool isMatch_1(string &s, string &p)
    {
        int size_s = s.size();
        int size_p = p.size();

        int i = size_s - 1;
        int j = size_p - 1;
        while(i >= 0 && j >= 0)
        {
            if(s.at(i) == p.at(j) || p.at(j) == '.')
            {
                --i;
                --j;
            }
            else if(p.at(j) == '*')
            {
                --j;
                if(p.at(j) != s.at(i) && p.at(j) != '.')
                {
                    --j;
                    continue;
                }
                if(p.at(j) != s.at(i) && p.at(j) == '.')
                {
                    --j;
                    if(j < 0)
                    {
                        return true;
                    }
                    else
                    {
                        if(p.at(j) != '*' && p.at(j) != '.')
                        {
                            while(i >= 0 && s.at(i) != p.at(j))
                            {
                                --i;
                            }
                            if(i < 0)
                            {
                                return false;
                            }
                            else
                            {
                                --i;
                                --j;
                                continue;
                            }
                        }
                        if(p.at(j) == '.')
                        {

                        }
                    }
                }

                if(p.at(j) == s.at(i))
                {
                    int same_p = j;
                    --j;
                    while(j >= 0 && p.at(j) == p.at(same_p))
                    {
                        --j;
                    }
                    int num_of_same_p = same_p - 1 - j;

                    int same_s = i;
                    while(i >= 0 && s.at(i) == s.at(same_s))
                    {
                        --i;
                    }
                    int num_of_same_s = same_s - i;

                    if(num_of_same_s < num_of_same_p)
                    {
                        return false;
                    }
                    continue;
                }

            }
            else
            {
                return false;
            }
        }

        if(i < 0 && j < 0)
        {
            return true;
        }
        if(j == 1 && p.at(j) == '*')
        {
            return true;
        }

        return false;
    }
    */
};
