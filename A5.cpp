#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();
        bool dp[m + 1][n + 1];

        // Initialize DP table
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;

        // Handle patterns with *
        for (int j = 1; j <= n; ++j)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    Solution solution;

    // Test cases for Regular Expression Matching
    cout << "Is match for s='aa', p='a': " << solution.isMatch("aa", "a") << endl;                                     // Output: false
    cout << "Is match for s='aa', p='a*': " << solution.isMatch("aa", "a*") << endl;                                   // Output: true
    cout << "Is match for s='ab', p='.*': " << solution.isMatch("ab", ".*") << endl;                                   // Output: true
    cout << "Is match for s='aab', p='c*a*b': " << solution.isMatch("aab", "c*a*b") << endl;                           // Output: true
    cout << "Is match for s='mississippi', p='mis*is*p*.': " << solution.isMatch("mississippi", "mis*is*p*.") << endl; // Output: false

    return 0;
}
