/*
Given a string, find the length of the longest substring without repeating characters.

Examples:
    Given "abcabcbb", the answer is "abc", which the length is 3.
    Given "bbbbb", the answer is "b", with the length of 1.
    Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;

        unordered_map<char, int> table = {
            {s[0], 0}
        };

        int low = 0, high = 0, max_len = 1;

        while (high < s.length() - 1)
        {            
            ++high;
            char high_char = s[high];

            if (table.find(high_char) != table.end() && table[high_char] >= low)
            {
                // if char appeared before
                int prev_max_high = table[high_char];
                max_len = (high - prev_max_high) > max_len ? (high - prev_max_high) : max_len;
                low = prev_max_high + 1;
            }
            else
            {
                // if char hasn't appeared
                max_len = (high - low) + 1 > max_len ? high - low + 1 : max_len;
            }

            table[high_char] = high;
        }

        return max_len;
    }
};

int main()
{
    string inp;
    while (true) {
        cin >> inp;
        cout << Solution().lengthOfLongestSubstring(inp) << '\n';
    }
    return 0;
}