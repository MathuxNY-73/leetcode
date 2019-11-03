extern crate input;

use std::io;
use std::collections::HashMap;
use rand::distributions::Uniform;
use rand::Rng;


struct Solution {
    dist: Uniform<u32>,
    map: HashMap<i32, i32>
}

impl Solution {
    pub fn new(N: i32, blacklist: Vec<i32>) -> Self {
        let mut b = blacklist; b.sort();
        let l_b = b.len();
        let diff = N - l_b as i32;

        let random = Uniform::new(0u32, diff as u32);

        let mut i = 0;

        while i < l_b && b[i] < diff {
            i += 1;
        }

        let mut j = diff;
        let mut map = HashMap::new();
        let mut k = 0;
        while k < i && j < N {
            while i < l_b && b[i] == j { j += 1; i += 1;}
            map.insert(b[k], j);
            j += 1;
            k += 1;
        }

        Solution {
            dist: random,
            map
        }
    }

    pub fn pick(&self) -> i32 {
        let sample = rand::thread_rng().sample(self.dist) as i32;
        if let Some(k) = self.map.get(&sample) {
            (*k) as i32
        }
        else {
            sample as i32
        }
    }
}

fn main() {
    use input::Scanner;

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let n = scan.token::<usize>();

    for _ in 0..n {
        let N = scan.token::<i32>();
        let b_size = scan.token::<usize>();

        let blacklist = (0..b_size).map( |_| scan.token::<i32>()).collect();

        let sol = Solution::new(N, blacklist);

        let n_pick = scan.token::<i32>();

        for _ in 0..n_pick {
            print!("{} ", sol.pick());
        }
        println!("");
    }
}
