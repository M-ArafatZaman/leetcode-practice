use std::io;

// https://open.kattis.com/problems/hradgreining
fn main() {
    let mut a = String::new();
    
    io::stdin()
        .read_line(&mut a)
        .expect("Error");

    let _contains = a.contains("COV");

    if _contains {
        println!("Veikur!");
    } else {
        println!("Ekki veikur!");
    }
}
