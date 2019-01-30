class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<int>();
        vector<int> output;
        
        // current coordinates
        int row = 0, col = 0;

        // min_row, max_row, min_col, max_col are the min/max row/col we can be at
        // these boudaries changes when we changes direction
        int min_row = 0, max_row = matrix.size() - 1, min_col = 0, max_col = matrix[0].size() - 1;

        // current direction
        enum direction { LEFT, UP, RIGHT, DOWN } curdir = RIGHT;
        bool done = false;
        while (!done) {
            output.push_back(matrix[row][col]);
            switch (curdir) {
                case LEFT:
                    if (col == min_col) {
                        if (row == min_row)
                            done = true;
                        else {
                            curdir = UP;
                            --row;
                            --max_row;
                        }
                    }
                    else if (col > min_col) {
                        --col; 
                    }
                    break;
                case UP:
                    if (row == min_row) {
                        if (col == max_col)
                            done = true;
                        else {
                            curdir = RIGHT;
                            ++col;
                            ++min_col;
                        }
                    }
                    else if (row > min_row) {
                        --row;
                    }
                    break;
                case RIGHT:
                    if (col == max_col) {
                        if (row == max_row)
                            done = true;
                        else {
                            curdir = DOWN;
                            ++row;
                            ++min_row;
                        }
                    }
                    else if (col < max_col) {
                        ++col;
                    }
                    break;
                case DOWN:
                    if (row == max_row) {
                        if (col == min_col)
                            done = true;
                        else {
                            curdir = LEFT;
                            --col;
                            --max_col;
                        }
                    }
                    else if (row < max_row) {
                        ++row;
                    }
                    break;
            }
        }
        return output;
    }
};
