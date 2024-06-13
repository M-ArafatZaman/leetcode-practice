import java.util.HashMap;

// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
class NumRollsToTarget {
    HashMap<String, Integer> cache = new HashMap<>();
    
    public static void main(String[] args) {
        NumRollsToTarget runner = new NumRollsToTarget();

        System.out.println(runner.numRollsToTarget(1, 6, 3));
        System.out.println(runner.numRollsToTarget(2, 6, 7));
        System.out.println(runner.numRollsToTarget(30, 30, 500));
    }

    public int numRollsToTarget(int n, int k, int target) {
        if (n == 0 && target == 0) {
            return 1;
        } else if (n == 0 || target < 0) {
            return 0;
        } 
        
        String key = n + "," + target;
        if (cache.containsKey(key)) {
            return cache.get(key);
        }
        
        int count = 0;
        for (int i = 1; i <= k; i++) {
            count = (count + numRollsToTarget(n-1, k, target-i)) % (int)(1e9+7);
        }
        
        cache.put(key, count);
        
        return count;
    }
}