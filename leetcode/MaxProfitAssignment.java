import java.util.Arrays;
import java.util.Comparator;

// https://leetcode.com/problems/most-profit-assigning-work/
class MaxProfitAssignment {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int n = difficulty.length;
        int[][] diff_profits = new int[n][2];
        int[] sorted_profits = new int[n];
        int[] max_profits = new int[2];
        
        // Load difficulty and profits into a same stream
        for (int i = 0; i < n; i++) {
            diff_profits[i][0] = difficulty[i];
            diff_profits[i][1] = profit[i];
        }
        
        // Sort stream
        // Sort by difficulty first and then profit
        Arrays.sort(diff_profits, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return a[0] - b[0];
            }
        });
        
        sorted_profits[0] = diff_profits[0][1];
        // Extract profits but in sorted difficulty
        // Keep only the max profits up until every index
        for (int k = 1; k < n; k++) {
            sorted_profits[k] = Math.max(diff_profits[k][1], sorted_profits[k-1]);
        }
        
        int max_profit = 0, left, right, mid, hit;
        // Binary search for each worker
        for (int j = 0; j < worker.length; j++) {
            left = 0; right = n; mid = 0; hit = 0;
            
            // Bin search for the perfect difficulty
            while (left < right) {
                mid = (left+right)/2;
                if (diff_profits[mid][0] <= worker[j]) {
                    left = mid + 1;
                    hit = mid;
                } else {
                    right = mid;
                    hit = Math.max(mid-1, 0);
                }
            };
            
            
            // Only if hit is higher
            if (worker[j] >= diff_profits[hit][0])
                max_profit += sorted_profits[hit];
        }
        
        return max_profit;
    }
}