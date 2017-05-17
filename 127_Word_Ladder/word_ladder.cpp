#include "word_ladder.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    Solution s;
    string beginWord = "qa", endWord = "sq";
    vector<string> wordList = {"se","cm","so","ph","mt","db","mb","sb","ln","tm",
    "le","av","sm","ta","ci","ca","br","ba","to","ra","fa","yo","ow","sn","cr","sq"
    };

    cout << s.ladderLengthFirst(beginWord, endWord, wordList) << endl;

    return 0;
}
