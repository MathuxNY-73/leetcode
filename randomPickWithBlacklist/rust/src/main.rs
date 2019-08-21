use rand::distributions::Uniform;
use rand::Rng;


struct Solution {
    rng: Rng,
    dist: Uniform
}

impl Solution {
    pub fn new(N: i32, blacklist: Vec<i32>) -> Self {

        let mut rng = rand::thread_rng();
        let random = Uniform::new(0u32, N);
    }

    pub fn pick(&self) -> i32 {

    }
}

fn main() {
    let res = Solution::find_median_sorted_arrays(vec![0,1,3], vec![3,4,5,5]);
    println!("Res is {}", res);
}



