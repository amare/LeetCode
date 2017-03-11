
#include "letter_combinations_of_a_phone_number.h"

int main()
{
    Solution s;
    vector<string> ans = s.letterCombinations("");
    cout << ans.size() << endl;
    for(auto &str : ans)
        cout << str << ' ';
    cout << endl;

    return 0;
}
