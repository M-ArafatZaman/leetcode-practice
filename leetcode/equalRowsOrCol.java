// https://leetcode.com/problems/equal-row-and-column-pairs/

class Solution {
    public int equalPairs(int[][] grid) {
        int count = 0;
        int N = grid.length;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // Check i row vs j col
                // They are of equal length
                boolean equal = true;
                for (int n = 0; n < N; n ++) {
                    if (grid[i][n] != grid[n][j]) {
                        equal = false;
                        break;
                    }
                };

                if (equal) count++;
            }
        }

        return count;
    }
}