extern crate input;

use std::io;

struct Solution {
}

impl Solution {
    pub fn hamming_distance(x: i32, y: i32) -> i32 {
        let mut n = x ^ y;
        let mut res = 0;
        while n > 0 {
            n &= (n - 1);
            res += 1;
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
        let x = scan.token::<i32>();
        let y = scan.token::<i32>();

        let res = Solution::hamming_distance(x, y);
        println!("{}", res);
    }
}
