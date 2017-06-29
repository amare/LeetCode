/*
 Author:            cuckoo
 Date:              2017/05/24 20:01:50
 Update:            
 Problem:           越狱
 Company:           Work Application 
 Source:            http://www.lydsy.com/JudgeOnline/problem.php?id=1008

 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int kMod = 100003;
typedef long long LL;

LL QuickPow(LL x, LL p)
{
    LL ans = 1;
    x = x % kMod;

    while(p != 0)
    {
        if(p & 1 == 1)      // p is odd
            ans = ans * x % kMod;
        p >>= 1;
        x = x * x % kMod;
    }

    return ans;
}

int main()
{
    LL M = 0, N = 0, ans = 0;
    cin >> M >> N;
    if(M <= 0 || N <= 0)
        return -1;

    ans = QuickPow(M, N) + kMod - M * QuickPow(M - 1, N - 1) % kMod;
    ans %= kMod;
    cout << ans << endl;

    return 0;
}
