use std::env;
use std::fs;
pub struct Solution {}

impl Solution { 
    // pub fn new () -> Solution {}
    pub fn odd_even_jumps(&self, arr: Vec<i32>) -> i32 {
        
        let n : usize = arr.len();
        let mut next_higher : Vec<i32> = Vec::new();
        let mut next_lower : Vec<i32>  = Vec::new();
        let mut high_jump : Vec <bool> = Vec::new();
        let mut low_jump : Vec <bool> = Vec::new();
        for _i in 1..n {
            next_higher.push(-1);
            next_lower.push(-1);
            high_jump.push(false);
            low_jump.push(false);
        }
        let mut nums_sorted : Vec <(i32, usize)> = Vec::new();
        for i in 1..n {
            
            nums_sorted.push((arr[i-1], i-1));
        }
        // nums_sorted.sort_by();
        return 0;
    }
}

struct Config {
    query: String,
    filename: String,
}

fn parse_config(args: &[String]) -> Config {
    let query = args[1].clone();
    let filename = &args[2];

    Config { query, filename }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let config = parse_config(&args);
    println!("Searching for '{}'", config.query);
    println!("In file {}", config.filename);

    let contents = fs::read_to_string(config.filename).
        expect("Something went wrong reading the file");

    println!("With contents:\n{}", contents);
    // let s : Solution = 
}
