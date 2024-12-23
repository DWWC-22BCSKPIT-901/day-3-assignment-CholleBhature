#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> charSet;
    int left = 0, maxLength = 0;

    for (int right = 0; right < s.length(); ++right)
    {
        // If the character is already in the set, remove characters from the left
        while (charSet.find(s[right]) != charSet.end())
        {
            charSet.erase(s[left]);
            ++left;
        }

        // Add the current character to the set
        charSet.insert(s[right]);

        // Update the maximum length
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main()
{
    string input = "abcabcbb";
    cout << "Length of the longest substring without repeating characters: " << lengthOfLongestSubstring(input) << endl;

    input = "bbbbb";
    cout << "Length of the longest substring without repeating characters: " << lengthOfLongestSubstring(input) << endl;

    input = "pwwkew";
    cout << "Length of the longest substring without repeating characters: " << lengthOfLongestSubstring(input) << endl;

    return 0;
}
