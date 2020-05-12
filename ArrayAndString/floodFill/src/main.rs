extern crate input;

use std::io;
use std::collections::VecDeque;
use std::vec::Vec;
use std::cmp::min;

struct Solution {
}

impl Solution {
    pub fn flood_fill(image: Vec<Vec<i32>>, sr: i32, sc: i32, new_color: i32) -> Vec<Vec<i32>> {
        let r = image.len();
        if r == 0 {
            return image;
        }
        let c = image[0].len();
        if c == 0 {
            return image;
        }

        let mut new_image = image.clone();

        let mut q = VecDeque::new();
        let dx = vec![1i32, 0, -1, 0];
        let dy = vec![0i32, 1, 0, -1];

        q.push_back((sr, sc));

        while !q.is_empty() {
            if let Some((x, y)) = q.pop_front() {
                new_image[x as usize][y as usize] = new_color;
                (0..4).map(|i| (x + dx[i], y + dy[i]))
                    .filter(|&t| min(t.0, t.1) >= 0)
                    .filter(|&t| t.0 < (r as i32) && t.1 < (c as i32))
                    .filter(|&t| image[t.0 as usize][t.1 as usize] == image[x as usize][y as usize]
                            && new_image[t.0 as usize][t.1 as usize] != new_color)
                    .for_each(|t| q.push_front((t.0, t.1)));
            }
        }

        new_image
    }
}

fn main() {
    use input::Scanner;

    let (stdin, _stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let t = scan.token::<i32>();

    for _ in 0..t {
        let n = scan.token::<usize>();
        let m = scan.token::<usize>();
        let sr = scan.token::<i32>();
        let sc = scan.token::<i32>();
        let new_color = scan.token::<i32>();

        println!("n={}, m={}, sr={}, sc={}, new_color={}", n,m,sr,sc,new_color);

        let image = (0..n).map(|_| (0..m).map(|_| scan.token::<i32>()).collect()).collect();
        let res = Solution::flood_fill(image, sr, sc, new_color);

        for i in 0..n {
            for j in 0..m {
                print!("{} ", res[i][j]);
            }
            println!();
        }
    }

}
