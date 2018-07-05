#include <string>
#include <iostream>

using namespace std;

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
  P   A   H   N
  A P L S I I G
  Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:
  Input: s = "PAYPALISHIRING", numRows = 3
  Output: "PAHNAPLSIIGYIR"

Example 2:
  Input: s = "PAYPALISHIRING", numRows = 4
  Output: "PINALSIGYAHRPI"
  Explanation:

    P     I    N
    A   L S  I G
    Y A   H R
    P     I
*/
class Solution
{
public:
  string convert(string s, int numRows)
  {
    string output(s);
    if (s.length() <= 1 || numRows == 1) return output;
    int cur_pos, cur_char = 0;
    for (int cur_row = 0; cur_row < numRows; cur_row++)
    {
      cur_pos = cur_row;
      int jump_odd = (numRows - cur_row - 1) * 2;
      int jump_even = 2 * cur_row;
      bool flag = false;
      while (cur_pos < s.length())
      {
        if ((!flag && jump_odd) || (flag && jump_even)) output[cur_char++] = s[cur_pos];
        if (flag) cur_pos += jump_even;
        else cur_pos += jump_odd;
        flag = !flag;
      }
    }
    return output;
  }
};

int main() {
  string s;
  int numRows;
  while(true) {
    cin >> s >> numRows;
    cout << Solution().convert(s, numRows) << '\n';
  }
}