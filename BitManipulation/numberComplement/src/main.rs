extern crate input;

use std::io;

struct Solution {
}

impl Solution {
    pub fn find_complement(num: i32) -> i32 {
        let mut num_m = num;
        let mut cnt = 0;
        let mut res = 0;

        while num_m > 0{
            res |= ((num_m & 1) ^ 1) << cnt;
            println!("At cnt={} res={} and num_m={}", cnt, res, num_m);
            cnt += 1;
            num_m >>= 1;
        }

        res
    }
}

fn main() {
    use input::Scanner;

    let (stdin, _stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let n = scan.token::<usize>();

    for _ in 0..n {
        let num = scan.token::<i32>();

        let res = Solution::find_complement(num);
        println!("{}", res);
    }
}
