import java.util.Arrays;

// https://leetcode.com/problems/minimum-increment-to-make-array-unique/
class MinIncrementForUnique {
    public static void main(String[] args) {
        MinIncrementForUnique runner = new MinIncrementForUnique();

        System.out.println(runner.minIncrementForUnique(new int[]{1,2,2}));
        System.out.println(runner.minIncrementForUnique(new int[]{3,2,1,2,1,7}));
    }
    
    public int minIncrementForUnique(int[] nums) {
        Arrays.sort(nums);
        int count = 0;
        int last = -1;
        for (int j : nums) {
            if (last == -1) {
                last = j;
                continue;
            }
            
            if (j <= last) {
                count += (last + 1 ) - j;
                last += 1;
            } else {
                last = j;
            }
        }
        
        return count;
    }
}