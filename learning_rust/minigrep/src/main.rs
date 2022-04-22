use std::env;
use std::fs;
pub struct Solution {}

impl Solution { 
    pub fn odd_even_jumps(&self, nums: Vec<i32>) -> i32 {
        let n : i32 = nums.len();
        let next_higher : Vec<i32> = Vec::new();
        let next_lower : Vec<i32>  = Vec::new();
        let high_jump : Vec <bool> = Vec::new();
        let low_jump : Vec <bool> = Vec::new();
        for i in 1..n {
            next_higher.push(-1);
            next_lower.push(-1);
            high_jump.push(false);
            low_jump.push(false);
        }
        
        return 0;
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let query = &args[1];
    let filename = &args[2];
    println!("Searching for '{}'", query);
    println!("In file {}", filename);

    let contents = fs::read_to_string(filename).
        expect("Something went wrong reading the file");

    println!("With contents:\n{}", contents);

}
