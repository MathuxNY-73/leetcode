use std::cmp;


struct Solution {}

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let l1 = nums1.len();
        let l2 = nums2.len();

        let a = if l1 > l2 {
            &nums1
        }
        else {
            &nums2
        };
        let b = if l2 > l1 {
            &nums2
        }
        else {
            &nums1
        };
        let n = cmp::max(l1,l2);
        let m = cmp::min(l1,l2);

        let mut imax = m;
        let mut imin = 0;
        let mut i = (imax + imin)/2;
        let mut j = (n + m + 1) / 2 - i;

        while imin <= imax {
            if &b[j-1] > &a[i] {
                imin = i + 1;
            }
            else if &a[i-1] > &b[j] {
                imax = i - 1;
            }
            i = (imax + imin)/2;
            j = (n + m + 1) / 2 - i;
        }

        if (n+m) % 2 == 0  { cmp::min(a[i-1], b[j-1]) as f64 } else { ((a[i-1] + b[i-1]) as f64) / 2.0 }
    }
}

fn main() {
    let res = Solution::find_median_sorted_arrays(vec![0,1,3], vec![3,4,5,5]);
}



