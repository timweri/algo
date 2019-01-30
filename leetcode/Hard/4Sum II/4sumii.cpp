class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> m;
        int result = 0;
        for(auto &a:A) {
            for(auto &b:B) {
                ++m[a+b];
            }
        }
        for(auto &c:C) {
            for(auto &d:D) {
                result += m[-c-d];
            }
        }
        return result;
    }
};
