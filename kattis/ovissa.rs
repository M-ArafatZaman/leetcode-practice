use std::io;

// https://open.kattis.com/problems/ovissa
fn main() {
    let mut sound = String::new();
    io::stdin().read_line(&mut sound);

    println!("{}", sound.trim().len());
}