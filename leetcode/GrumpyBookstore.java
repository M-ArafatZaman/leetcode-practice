class GrumpyBookstore {
    public static void main(String[] args) {
        GrumpyBookstore gb = new GrumpyBookstore();
        System.out.println(gb.maxSatisfied(new int[]{1,0,1,2,1,1,7,5}, new int[]{0,1,0,1,0,1,0,1}, 3));
    }

    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int maxSatisfaction = 0;
        int i;
        
        // Get normal
        for (i = 0; i < customers.length; i++) {
            maxSatisfaction += grumpy[i] == 0 ? customers[i] : 0;
        }
        
        // Initiate window
        int left = 0, right = 0;
        while (right - left != minutes) {
            // Include logic
            if (grumpy[right] == 1)
                maxSatisfaction += customers[right];
            right++;
        }
        int temp = maxSatisfaction;
        // Try moving window
        while (right < customers.length) {
            
            // Include logic
            if (grumpy[right] == 1)
                temp += customers[right];
            
            // Exclude logic
            if (grumpy[left] == 1)
                temp -= customers[left];
            
            maxSatisfaction = Math.max(temp, maxSatisfaction);
            right++; left++;
        }
        
        return maxSatisfaction;       
    }
}