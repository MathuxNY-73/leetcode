extern crate input;

use std::io;
use std::collections::HashMap;
use input::Scanner;

struct Solution {
}


impl Solution {
    pub fn count_smaller(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut indices: Vec<usize> = (0..n).collect();

        let mut bit = vec![0;n];

        indices.sort_by(|a, b| nums[*a].cmp(&nums[*b]));

        let mp: HashMap<_,_>= (0..n).map(|v| (indices[v],v)).collect();

        let reversed_res: Vec<i32> = (0..n).rev().map(|v| {
            let res = Solution::get_sum(&bit, mp[&v]);
            Solution::update(&mut bit, mp[&v]);
            res
        }).collect();


        reversed_res.into_iter().rev().collect()
    }

    fn update(bit: &mut Vec<i32>, idx: usize) {
        let mut i = idx;
        while i < bit.len() {
            bit[i] += 1;
            i  = i | (i + 1);
        }
    }

    fn get_sum(bit: &Vec<i32>, idx: usize) -> i32 {
        let mut sum = 0;
        let mut i = idx as i32;
        while i >= 0 {
            sum += bit[i as usize];
            i = (i & (i + 1)) - 1;
        }
        sum

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

        let res = Solution::count_smaller(nums);
        for i in &res {
            print!("{} ", i);
        }
        println!();

    }
}




