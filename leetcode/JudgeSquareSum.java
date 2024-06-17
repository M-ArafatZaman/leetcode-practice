import java.util.HashSet;

// https://leetcode.com/problems/sum-of-square-numbers/
class JudgeSquareSum {
    public static void main(String[] args) {
        JudgeSquareSum jss = new JudgeSquareSum();
        System.out.println(jss.judgeSquareSum(5));
        System.out.println(jss.judgeSquareSum(3));
        System.out.println(jss.judgeSquareSum(4));
    }

    public boolean judgeSquareSum(int c) {
        HashSet<Long> visited = new HashSet<>();
        long a_sqrd, b_sqrd;
        
        for (int i = 0; i <= Math.sqrt(c); i++) {
            // a = i
            // b^2 = c - a^2
            // Check if we visited b^2 before
            a_sqrd = (long)(i*i);
            b_sqrd = c - a_sqrd;
            if (visited.contains(b_sqrd)) return true;
            // edge case
            // a == b
            if ((int)(a_sqrd*2) == c) return true;
            
            visited.add(a_sqrd);
        } 
        return false;
    }
}