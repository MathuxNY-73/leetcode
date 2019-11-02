use std::io;
use std::ops;
use std::collections::HashMap;

#[derive(PartialEq, Eq, Hash, Clone, Copy)]
struct Point {
    x: i32,
    y: i32
}

impl Point {
    fn l2_norm(self) -> f64 {
        ((self.x.pow(2) + self.y.pow(2)) as f64).sqrt()
    }
}

impl ops::Add<&Point> for &Point {
    type Output = Point;

    fn add(self, rhs: &Point) -> Point {
        Point {
            x: self.x + rhs.x,
            y: self.y + rhs.y
        }
    }
}

impl ops::Sub<&Point> for &Point {
    type Output = Point;

    fn sub(self, rhs: &Point) -> Point {
        Point {
            x: self.x - rhs.x,
            y: self.y - rhs.y
        }
    }
}

impl ops::Sub<&Point> for Point {
    type Output = Point;

    fn sub(self, rhs: &Point) -> Point {
        Point {
            x: self.x - rhs.x,
            y: self.y - rhs.y
        }
    }
}


struct Solution {
}

impl Solution {
    pub fn min_area_free_rect(points: Vec<Vec<i32>>) -> f64 {
        let mut seen: HashMap<i32, HashMap<Point, Vec<Point>>> = HashMap::new();

        let points_p: Vec<Point> = points.into_iter().map(|p| {Point {x: p[0], y: p[1]}}).collect();

        for i in 0..points_p.len() {
            for j in i+1..points_p.len() {
                let center = &points_p[i] + &points_p[j];
                let vect = &points_p[j] - &points_p[i];
                let rad = vect.x * vect.x + vect.y * vect.y;

                if !seen.contains_key(&rad) {
                    seen.insert(rad, HashMap::new());
                }

                let cent = seen.get_mut(&rad).expect("Should exist!");
                if !cent.contains_key(&center) {
                    cent.insert(center, Vec::new());
                }
                cent.get_mut(&center).expect("Should exist!").push(points_p[i]);
            }
        }

        let mut res = std::f64::MAX;
        for (rad, center_cand) in seen.iter() {
            for (cent, cand) in center_cand.iter() {
                for i in 0..cand.len() {
                    for j in i+1..cand.len() {
                        let q = &cand[i];
                        let p = &cand[j];
                        let q_p = cent - q;
                        res = res.min((q - p).l2_norm() * (q_p - p).l2_norm());
                    }
                }
            }
        }

        if res == std::f64::MAX {
            0f64
        }
        else {
            res
        }
    }
}

fn main() {
    use myio::Scanner;

    let (stdin, _stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let t = scan.token::<usize>();

    for _ in 0..t {
        let n = scan.token::<i32>();

        let points = (0..n).map( |_| vec![scan.token::<i32>(), scan.token::<i32>()]).collect();

        let sol = Solution::min_area_free_rect(points);
        println!("Hello world, {}", sol);
    }
}




