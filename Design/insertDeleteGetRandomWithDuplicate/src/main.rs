extern crate input;
extern crate num;
#[macro_use]
extern crate num_derive;

use std::io;
use std::vec::Vec;
use std::rc::Rc;
use std::cell::RefCell;
use std::str::FromStr;
use std::num::ParseIntError;
use std::collections::HashMap;
use std::collections::HashSet;
use rand::distributions::Uniform;
use rand::Rng;

struct RandomizedCollection {
    distri: Vec<i32>,
    map: HashMap<i32, HashSet<usize>>
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedCollection {

    /** Initialize your data structure here. */
    fn new() -> Self {
        RandomizedCollection {
            distri: Vec::new(),
            map: HashMap::new()
        }
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    fn insert(&mut self, val: i32) -> bool {
        let mut ret = false;
        self.distri.push(val);

        if !self.map.contains_key(&val) {
            self.map.insert(val, HashSet::new());
            ret = true;
        }

        if let Some(set) = self.map.get_mut(&val) {
            set.insert(self.distri.len() - 1);
            ret
        }
        else {
            false
        }
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    fn remove(&mut self, val: i32) -> bool {
        if let Some(set) = self.map.get_mut(&val) {
            if let Some(&idx) = set.iter().next() {
                set.remove(&idx);
                if idx < self.distri.len() - 1 {
                    if let Some(l) = self.distri.last() {
                        if let Some(sl) = self.map.get_mut(&l) {
                            sl.remove(&(self.distri.len() - 1)); sl.insert(idx);
                        }
                    }
                    self.distri.swap_remove(idx);
                }
                else {
                    self.distri.remove(idx);
                }
                true
            }
            else {
                false
            }
        }
        else {
            false
        }
    }

    /** Get a random element from the collection. */
    fn get_random(&self) -> i32 {
        let mut rng = rand::thread_rng();
        let sample = rng.sample(Uniform::from(0..self.distri.len())) as usize;

        self.distri[sample]
    }
}

#[derive(Debug, PartialEq, FromPrimitive)]
enum Operation {
    Insert = 1,
    Remove,
    Random,
}

impl FromStr for Operation {
    type Err = ParseIntError;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let op_id = s.trim().parse::<u32>()?;
        match num::FromPrimitive::from_u32(op_id) {
            Some(op) => Ok(op),
            _ => Ok(Operation::Insert),
        }
    }
}

fn main() {
    use input::Scanner;

    let (stdin, _stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let t = scan.token::<usize>();

    for _ in 0..t {
        println!("New Test Case");
        let n = scan.token::<usize>();
        let mut rc = RandomizedCollection::new();

        (0..n).for_each( |_| {
            let inst = scan.token::<Operation>();

            match inst {
                Operation::Insert => {
                    let num = scan.token::<i32>();
                    println!("Insert {}: {}", num, rc.insert(num));
                },
                Operation::Remove => {
                    let num = scan.token::<i32>();
                    println!("Remove: {}", rc.remove(num));
                },
                Operation::Random => println!("GetRandom: {}", rc.get_random()),
            }
        });
    }
}




