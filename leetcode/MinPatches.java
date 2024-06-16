
// https://leetcode.com/problems/patching-array/
class MinPatches {
    public static void main(String[] args) {
        MinPatches minPatches = new MinPatches();
        System.out.println(minPatches.minPatches(new int[]{1,5,10}, 20));
    }

    public int minPatches(int[] nums, int n) {
        long patches =  0;
        long test = 1;
        int curr_i = 0;
        
        while (test <= n) {
            if (curr_i < nums.length && nums[curr_i] <= test) {
                test += nums[curr_i];
                curr_i++;
            } else {
                test += test;
                patches += 1;
            }
        }
        
        return (int)patches;
    }
}