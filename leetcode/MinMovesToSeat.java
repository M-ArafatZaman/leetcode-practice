import java.util.Arrays;

// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/
class MinMovesToSeat {
    public static void main(String args[]) {
        MinMovesToSeat runner = new MinMovesToSeat();
        int[] seat1 = {3,1,5};
        int[] students1 = {2,7,4};
        System.out.println(runner.minMovesToSeat(seat1, students1));
    }

    public int minMovesToSeat(int[] seats, int[] students) {
        Arrays.sort(seats);
        Arrays.sort(students);
        
        int moves = 0;
        
        for (int i = 0; i < students.length; i++) {
            moves += Math.abs(students[i] - seats[i]);
        }
        
        return moves;
    }
}