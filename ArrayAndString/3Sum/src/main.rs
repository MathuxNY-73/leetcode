extern crate input;

use std::io;
use input::Scanner;
use std::cmp::Ordering;

struct Solution {
}


impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut nums_m = nums;
        nums_m.sort();

        let mut res: Vec<Vec<i32>> = Vec::new();

        for i in 0..nums_m.len() {
            if i > 0 && nums_m[i] == nums_m[i - 1] { continue; }
            if nums_m[i] > 0 { break; }

            let mut l = i + 1;
            let mut r = nums_m.len() - 1;

            while l < r {
                match (nums_m[i] + nums_m[l] + nums_m[r]).cmp(&0) {
                    Ordering::Equal => {
                        let left = nums_m[l]; let right = nums_m[r];
                        res.push([nums_m[i], left, right].to_vec());
                        while l < r && nums_m[l] == left { l += 1; }
                        while l < r && nums_m[r] == right { r -= 1; }
                    },
                    Ordering::Greater => r -= 1,
                    Ordering::Less => l += 1,
                }
            }

        }

        res
    }
}

fn main() {
    let (stdin, _stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let t = scan.token::<usize>();

    for _ in 0..t {
        println!("New Test Case");
        let n = scan.token::<usize>();
        let nums = (0..n).map(|_| scan.token::<i32>()).collect();

        let res = Solution::three_sum(nums);
        for triplet in &res {
            print!("[");
            for x in triplet {
                print!("{}, ", x);
            }
            print!("]\n");
        }
        println!();

    }
}




