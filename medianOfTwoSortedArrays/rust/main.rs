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
        let b = if l1 > l2 {
            &nums2
        }
        else {
            &nums1
        };
        let n = cmp::max(l1,l2);
        let m = cmp::min(l1,l2);

        if m == 0 {
            if (m % 2) == 0 {
                ((a[n / 2] + a[(n+1)/2]) as f64) / 2.0
            }
            else {
                a[n/2] as f64
            }
        }
        else {

        let mut imax = m;
        let mut imin = 0;

        let mut maxLeft = 0;
        let mut minRight = 0;

        while imin <= imax {
            let i = (imax + imin)/2;
            let j = (n + m + 1) / 2 - i;
            if i < imax && a[j-1] > b[i] {
                imin = i + 1;
            }
            else if i > imin && b[i-1] > a[j] {
                imax = i - 1;
            }
            else {
                if i == 0 {
                    maxLeft = a[j-1];
                }
                else if j == 0 {
                    maxLeft = b[i -1];
                }
                else {
                    maxLeft = cmp::max(a[j-1], b[i-1]);
                }

                if i == m {
                    minRight = a[j];
                }
                else if j == n {
                    minRight = b[i];
                }
                else {
                    minRight = cmp::min(a[j],b[i]);
                }
                break;
            }
        }

            if (n+m) % 2 == 1 { maxLeft as f64 } else { ((maxLeft + minRight) as f64) / 2.0 }
        }
    }
}

fn main() {
    let res = Solution::find_median_sorted_arrays(vec![0,1,3], vec![3,4,5,5]);
    println!("Res is {}", res);
}



