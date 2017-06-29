
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const long long MOD = 1e9 + 7;
string s1, s2;

// dp[i][j] 表示s1前i个字符同s2前j个字符的公共字串的个数
int dp[3300][3300];

int main(){
    cin >> s1;
    s2 = s1;
    reverse(s2.begin(),s2.end());
    memset( dp, 0, sizeof( dp ) );
    cout << sizeof(dp) << endl;
    for( int i = 1; i <= s1.size(); i++ ){
        for( int j = 1; j <= s2.size(); j++ ){
            long long temp = dp[i-1][j];
            temp += dp[i][j-1] - dp[i-1][j-1] + MOD;
            dp[i][j] = temp % MOD;
            if( s1[i-1] == s2[j-1] ){
                long long temp = dp[i][j] + dp[i-1][j-1] + 1;
                dp[i][j] = ( temp + MOD ) % MOD;
            }
        }
    }
    long long ans = 0;
    for( int i = 1; i <= s1.size(); i++ ){
        ans = ( ans + dp[i-1][s1.size()-i] + 1 ) % MOD;
    }
    cout << ans << endl;
    return 0;
}
/*
axbcba
*/
