struct Solution;
impl Solution {
    pub fn num_water_bottles(num_bottles: i32, num_exchange: i32) -> i32 {
        let mut curr = num_bottles;
        let mut total = num_bottles;
        let mut bott = 1;
        while (curr > 0) && (bott > 0) {
            bott = curr/num_exchange;
            curr = curr - (bott*num_exchange) + bott;
            total += bott;
        }
        total
    }
}

fn main() {
    assert_eq!(Solution::num_water_bottles(9, 3), 13);
}