/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
    Input: "babad"
    Output: "bab"
    
    Note: "aba" is also a valid answer.

Example 2:
    Input: "cbbd"
    Output: "bb"
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        // time complexity: O(n^2)
        // space complexity: O(n)
        if (s.empty())
            return "";

        int cur = 0;
        int curlength = 1;
        int low = 0, high = 0;

        while (cur < s.length())
        {

            int k = checkPalindromeOut(s, cur, cur);
            if (2 * k + 1 > curlength)
            {
                low = cur - k;
                high = cur + k;
                curlength = high - low + 1;
            }
            if (cur > 0 && s[cur] == s[cur - 1])
            {
                k = checkPalindromeOut(s, cur - 1, cur);
                if (2 * k + 2 > curlength)
                {

                    low = cur - k - 1;
                    high = cur + k;
                    curlength = high - low + 1;
                }
            }
            cur++;
        }
        return s.substr(low, curlength);
    }
    int checkPalindromeOut(string s, int low, int high)
    {
        // keep checking to find a palindrome s[low-k...high+k]
        // such that k is maxmimum
        // returns k
        // starts at k = 1
        int k = 1;
        while (low - k >= 0 && high + k < s.length())
        {
            if (s[low - k] == s[high + k])
                k++;
            else
                break;
        }
        return k - 1;
    }
};

int main()
{
    string inp;
    int low, high;
    while (true)
    {
        cin >> inp;
        cout << Solution().longestPalindrome(inp) << '\n';
    }
    return 0;
}