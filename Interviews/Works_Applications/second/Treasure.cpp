#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

// dp[30][1100000], 下面是做了空间优化的结果
// dp[i][j]表示从前i个数（任取）的和取模后的结果是否可以为j
long long dp[2][1100000];
long long n, m;
int num[33];

int main(){

    scanf("%lld%lld", &n, &m);

    for( int i = 0; i < n; i++ ){
        scanf( "%lld", &num[i] );
    }
    memset( dp, 0, sizeof( dp ) );
    dp[0][num[0]%m] = 1;
    int pos = 1;
    for( int i = 1; i < n; i++ ){
        memset(dp[pos], 0, sizeof( dp[pos] ) );
        dp[pos][num[i]%m] = 1;
        for( int j = 0; j < m; j++ ){
            if( dp[pos^1][j] == 1) {
                dp[pos][j] = 1;
                dp[pos][(j + num[i])%m] = 1;
            }
        }
        pos ^= 1;
    }
    if (dp[pos^1][0])
        printf("Yes");
    else
        printf("No");
    return 0;
}
