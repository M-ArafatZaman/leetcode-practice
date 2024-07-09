// https://leetcode.com/problems/average-waiting-time/
struct Solution;
impl Solution {
    pub fn average_waiting_time(customers: Vec<Vec<i32>>) -> f64 {
        let mut times = Vec::<i32>::new();
        let mut curr_time = 0;
        
        for order in &customers {
            if curr_time < order[0] {
                curr_time = order[0].clone();
            } 
            times.push( order[1] + (curr_time - order[0]) );
            curr_time += order[1];
        }
        
        let mut sum: f64 = f64::from(0);
        for time in times {
            sum += (time as f64);
        }
        
        sum / (customers.len() as f64)
    }
}

fn main() {
    assert_eq!(vec![vec![1,2], vec![2,5], vec![4,3]] , f64::from(5));
}
