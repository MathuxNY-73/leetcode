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

struct TrieNode {
    letters: Vec<Option<Rc<RefCell<TrieNode>>>>,
    isLeaf: bool
}

impl TrieNode {
    fn new() -> Self {
        TrieNode {
            letters: vec![None; 26],
            isLeaf: false
        }
    }
}

struct Trie {
    root: Rc<RefCell<TrieNode>>
}

impl Trie {

    /** Initialize your data structure here. */
    fn new() -> Self {
        Trie {
            root: Rc::new(RefCell::new(TrieNode::new()))
        }
    }

    /** Inserts a word into the trie. */
    fn insert(&self, word: String) {
        let mut cur = self.root.clone();
        for i in word.chars().map(|c| (c as u32 - 'a' as u32) as usize) {
            cur = {
                let mut node = cur.borrow_mut();
                let next = node.letters[i]
                    .get_or_insert(Rc::new(RefCell::new(TrieNode::new())));
                Rc::clone(next)
            }
        }
        cur.borrow_mut().isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    fn search(&self, word: String) -> bool {
        let mut cur = self.root.clone();
        for i in word.chars().map(|char| (char as u8 - 'a' as u8) as usize) {
            cur = {
                let node = cur.borrow();
                match node.letters[i].as_ref() {
                    Some(t) => t.clone(),
                    None => { return false; },
                }
            }
        }
        let node = cur.borrow();
        node.isLeaf
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    fn starts_with(&self, prefix: String) -> bool {
        let mut cur = self.root.clone();
        for i in prefix.chars().map(|char| (char as u8 - 'a' as u8) as usize) {
            cur = {
                let node = cur.borrow();
                match node.letters[i].as_ref() {
                    Some(t) => t.clone(),
                    None => { return false; },
                }
            }
        }
        true
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
        let trie = Trie::new();

        (0..n).for_each( |_| {
            let inst = scan.token::<Operation>();
            let word = scan.token::<String>();

            match inst {
                Operation::Insert => trie.insert(word),
                Operation::Search => println!("{}", trie.search(word)),
                Operation::Prefix => println!("{}", trie.starts_with(word)),
            }
        });
    }
}




