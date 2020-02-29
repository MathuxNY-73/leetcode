use std::io;
use std::vec::Vec;

const SIZE: usize = 1001;

struct Solution {

}

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let s_b = s.as_bytes();
        let mut dp: [[bool; SIZE]; SIZE] = [[false; SIZE]; SIZE];
        let mut res: &str = "";

        for i in 0..s.len() {
            for j in (0..=i).rev() {
                if s_b[i] == s_b[j] {
                    if i - j <= 1 {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i-1][j+1];
                    }

                    if dp[i][j] && res.len() < i - j + 1 {
                        res = &s[j..=i];
                    }
                }
            }
        }
        String::from(res)
    }
}

fn main() {
    use myio::Scanner;

    let (stdin, _stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let t = scan.token::<usize>();

    for _ in 0..t {
        //println!("New Test Case");
        let _nums_size = scan.token::<usize>();
        let s = scan.token::<String>();
        let res = Solution::longest_palindrome(s);

        println!("{}", res);

        /*for i in &nums {
            print!("{} ", i);
        }
        println!("");*/

    }
}




