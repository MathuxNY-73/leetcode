use std::io;
use std::collections::HashMap;

struct Solution {
}

impl Solution {
    pub fn find_number_of_lis(nums: Vec<i32>) -> i32 {
        let v: Vec<Vec<(i32, i32)>> = Vec::new();
        0
    }
}

fn main() {
    use myio::Scanner;

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let t = scan.token::<usize>();

    for _ in 0..t {
        let n = scan.token::<i32>();
        let nums_size = scan.token::<usize>();

        let nums = (0..nums_size).map( |_| scan.token::<i32>()).collect();

        let res = Solution::find_number_of_lis(nums);
        println!("{}\n", res);
    }
}




