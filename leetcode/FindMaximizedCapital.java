import java.util.PriorityQueue;
import java.util.Comparator;

// Problem: Find Maximized Capital
// https://leetcode.com/problems/ipo/
class FindMaximizedCapital {
    public static void main(String[] args) {
        FindMaximizedCapital obj = new FindMaximizedCapital();
        System.out.println(obj.findMaximizedCapital(2, 0, new int[]{1,2,3}, new int[]{0,1,1}));
    }    
    
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        // (profit, capital)
        int n = profits.length;
        
        int curr = w;
        // Max-heap for profit
        PriorityQueue<int[]> pq_profit = new PriorityQueue<int[]>(new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return b[0] - a[0];
            }
        });
        // Min-heap for capital
        PriorityQueue<int[]> pq_capital = new PriorityQueue<int[]>(new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[1] - b[1]; 
            }
        });
        
        // Load investments
        for (int i = 0; i < n; i++) {
            pq_profit.add(new int[]{profits[i], capital[i]});
        }
        
        int[] curr_inv;
        while (k > 0) {
            // Adjust pq to get rid of not possible investments
            while (pq_profit.size() > 0 && pq_profit.peek()[1] > curr) {
                pq_capital.add(pq_profit.remove());
            }
            
            if (pq_profit.size() == 0) break;
            
            curr += pq_profit.remove()[0];
            k -= 1;
            // Add back some possible investments
            while (pq_capital.size() > 0 && pq_capital.peek()[1] <= curr) {
                pq_profit.add(pq_capital.remove());
            }
        }
        
        return curr;       
    }
}