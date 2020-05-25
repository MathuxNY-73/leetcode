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

struct Trie {
    letters: Vec<Option<Rc<RefCell<Trie>>>>,
    isLeaf: bool
}

impl Trie {

    /** Initialize your data structure here. */
    fn new() -> Self {
        Trie {
            letters: vec![None; 26],
            isLeaf: false,
        }
    }

    /** Inserts a word into the trie. */
    fn insert(&mut self, word: String) {
        if let Some(c) = word.chars().next() {
            let idx = (c as u8 - 'a' as u8) as usize;
            if self.letters[idx].is_none() {
                self.letters[idx] = Some(Rc::new(RefCell::new(Trie::new())))
            }
            self.letters[idx].as_ref().unwrap().borrow_mut().insert(word[1..].to_string());
        } else {
            self.isLeaf = true
        }
    }

    /** Returns if the word is in the trie. */
    fn search(&self, word: String) -> bool {
        if let Some(c) = word.chars().next() {
            let idx = (c as u8 - 'a' as u8) as usize;
            if let Some(t) = &self.letters[idx] {
                t.borrow().search(word[1..].to_string())
            }
            else {
                false
            }
        } else {
            self.isLeaf
        }
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    fn starts_with(&self, prefix: String) -> bool {
        if let Some(c) = prefix.chars().next() {
            let idx = (c as u8 - 'a' as u8) as usize;
            if let Some(t) = &self.letters[idx] {
                t.borrow().starts_with(prefix[1..].to_string())
            }
            else {
                false
            }
        } else {
            true
        }
    }
}

#[derive(Debug, PartialEq, FromPrimitive)]
enum Operation {
    Insert = 1,
    Search,
    Prefix,
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
        //println!("New Test Case");
        let n = scan.token::<usize>();
        let mut trie = Trie::new();

        (0..n).for_each( |_| {
            let inst = scan.token::<Operation>();
            let word = scan.token::<String>();

            match inst {
                Operation::Insert => trie.insert(word),
                Operation::Search => println!("{}", trie.search(word)),
                Operation::Prefix => println!("{}", trie.starts_with(word)),
            }
        });
        /*for i in &nums {
            print!("{} ", i);
        }
        println!("");*/

    }
}




