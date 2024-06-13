import java.util.Stack;

// https://leetcode.com/problems/largest-rectangle-in-histogram/
class LargestRectAreaHist {
    // A 2-tuple ds
    public class Tuple {
        public int index;
        public int height;
        public Tuple(int x, int y) {
            index = x;
            height = y;
        }
    }

    // Runner
    public static void main(String args[]) {
        LargestRectAreaHist runner = new LargestRectAreaHist();

        System.out.println(runner.largestRectangleArea(new int[]{2,1,5,6,2,3}));
    }
    
    public int largestRectangleArea(int[] heights) {
        int maxArea = 0;
        int currInd = 0;
        int currHei = 0;
        Stack<Tuple> stack = new Stack<>();
        Tuple last;
        
        // Find heights to consider
        for (int i = 0; i < heights.length; i++) {
            currInd = i;
            currHei = heights[i];
            
            // If the stack is empty
            if (stack.empty()) {
                stack.push(new Tuple(currInd, currHei));
                continue;
            } 
            
            // Stack is not empty
            while (!stack.empty() && stack.peek().height > currHei) {
                // Loop back and remove large heights
                last = stack.pop();
                maxArea = Math.max(maxArea, (i-last.index)*last.height );
                currInd = last.index;
            }
            
            // Put it back on to stack
            stack.push(new Tuple(currInd, currHei));
        };
        
        // Loop back and check largest area
        while (!stack.empty()) {
            last = stack.pop();
            maxArea = Math.max(maxArea, (heights.length - last.index) * last.height);
        };
        
        return maxArea;
    }
}