#include <string>
#include <iostream>

using namespace std;

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
