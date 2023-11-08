#include <bits/stdc++.h>
using namespace std;

template <class T> void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}" << endl; }

template <class T, class S> void print_map(unordered_map<T, S>& _m) { cout << "{ "; for (auto & n : _m) { cout << n.first << " = " << n.second << ", "; } cout << "\b }" << endl; }


// https://leetcode.com/problems/valid-sudoku/
class Solution {
    public:
    int getGrid(int i, int j) {
        return floor(i/3) + (floor(j/3)*3);
    }

    bool isValidMap(unordered_map<int, int> &mp) {
        int min = 10;
        int max = 0;
        for (auto & p: mp) {
            if (p.first < min) min = p.first;
            if (p.first > max) max = p.first;
            if (p.second != 1) return false;
        }

        return min >= 1 && max <= 10;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // Grids
        vector<unordered_map<int, int>> grids(9);
        // Rows and cols
        vector<unordered_map<int, int>> rows(9);
        vector<unordered_map<int, int>> cols(9);

        for (int j = 0; j < 9; ++j) {
            for (int i = 0; i < 9; ++i) {
                int currGrid = getGrid(i, j);
                int currNum = board[j][i];
                if (currNum != '.') {

                    // Grid insertion
                    if (grids[currGrid][currNum - '0'] >= 1) {
                        grids[currGrid][currNum - '0'] += 1;
                    } else {
                        grids[currGrid][currNum - '0'] = 1;
                    }

                    // Row insertion
                    if (rows[j][currNum - '0'] >= 1) {
                        rows[j][currNum - '0'] += 1;
                    } else {
                        rows[j][currNum - '0'] = 1;
                    }

                    // Cols insertion
                    if (cols[i][currNum - '0'] >= 1) {
                        cols[i][currNum - '0'] += 1;
                    } else {
                        cols[i][currNum - '0'] = 1;
                    }

                    if (!isValidMap(grids[currGrid]) || !isValidMap(rows[j]) || !isValidMap(cols[i])) return false;

                }
            }
        }


        return true;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> in1 = {{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};

    cout << sol.isValidSudoku(in1) << endl;

    return 0;
}