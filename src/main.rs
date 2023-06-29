
mod l2259{

pub struct Solution;

impl Solution{
    pub fn remove_digit(number:String, digit: char) -> String {

        let mut ret = (0..number.len()-1).map(|_| "0").collect::<String>();

        for idx in 0..number.len() {
            if number.chars().nth(idx).unwrap() != digit {
                continue;
            }

            let mut changed = number.clone();
            changed.remove(idx);

            assert!(ret.len() == number.len()-1);

            ret = ret.max(changed);
        }


        return ret;
    }

}
}

mod l2260{

    use std::collections::HashMap;
    use std::collections::hash_map::Entry::{Occupied, Vacant};

pub struct Solution;

impl Solution{
     pub fn minimum_card_pickup(cards: Vec<i32>) -> i32 {

            let mut best = i32::MAX;

            let mut current_start = HashMap::new();

            for (idx, number) in cards.iter().enumerate() {

                match current_start.entry(number) {
                    Occupied(mut entry) => {
                        let number_steps = idx - entry.get() + 1;
                        if number_steps == 2{
                            return 2;
                        }

                        best = best.min(number_steps as i32);
                        entry.insert(idx);
                        continue;
                    },

                    Vacant(entry) => {
                        entry.insert(idx);
                        continue;
                    }
                }
            }


            if best == i32::MAX {
                -1
            }else{
                best
            }
        
    }

}
}

mod l2261{

use std::collections::hash_map::DefaultHasher;
use std::collections::{HashMap, BTreeSet};
use std::hash::{Hash, Hasher};
use std::ops::Bound::{Included, Excluded};

struct Range<'a> {
        nums: &'a Vec<i32>,
        begin_idx: usize,
        end_idx: usize,
}

impl <'a> Hash for Range<'a> {
    fn hash<H: Hasher>(&self, state: &mut H) {
            self.nums[self.begin_idx..self.end_idx].hash(state);
    }
}

impl <'a> PartialEq for Range<'a> {
    fn eq(&self, other: &Self) -> bool {
            if self.end_idx - self.begin_idx != other.end_idx - other.begin_idx {
                return false;
            }
            //
            for i in 0 .. self.end_idx - self.begin_idx{
                if self.nums[self.begin_idx + i] != other.nums[other.begin_idx + i] {
                    return false;
                }
            }

            true
    }
}

pub struct Solution{}

impl Solution {
    pub fn count_distinct(nums: Vec<i32>, k: i32, p: i32) -> i32 {

            let div_pos = nums.iter().enumerate().filter(|(_, &x)| x % p == 0).map(|(idx, _)| idx).collect::<BTreeSet<usize>>();

            let mut unique_sets = HashMap::new();

            for begin_idx in 0.. nums.len(){
                for end_idx in begin_idx + 1 .. nums.len()+1 {

                    let div_range = div_pos.range((Included(&begin_idx), Excluded(&end_idx)));

                    if div_range.count() as i32 > k {
                        break;
                    }

                    let new_range = Range{
                        nums:&nums,
                        begin_idx,
                        end_idx};

                    let mut hasher = DefaultHasher::new();
                    new_range.hash(& mut hasher);
                    let this_hash = hasher.finish();

                    let vec = unique_sets.entry(this_hash).or_insert(Vec::new());

                    match vec.iter().position(|r| r == &new_range){
                        Some(_)=>{
                            continue;
                        }
                        None=>{
                            vec.push(new_range);
                        }
                    }


                }
            }

            unique_sets.iter().map(|(_,v)| v.len()).sum::<usize>() as i32
    }
}
}

mod l2748{

    pub struct Solution;

impl Solution {
    pub fn count_beautiful_pairs(nums: Vec<i32>) -> i32 {
            let mut ret = 0;

            for begin_idx in 0.. nums.len()-1{
                for end_idx in begin_idx + 1 .. nums.len() {

                    let mut begin_number = {
                        let mut temp = nums[begin_idx];
                        
                        while temp >= 10 {
                            temp/=10;
                        }
                        temp
                    };

                    let mut end_number = nums[end_idx] % 10;

                    let mut try_gcd = begin_number.min(end_number);

                    while try_gcd != 1{
                        let reminder = begin_number.max(end_number) % try_gcd;

                        if reminder == 0{
                            break;
                        }

                        begin_number= begin_number.min(end_number);
                        end_number = try_gcd;
                        try_gcd = reminder;
                    }

                    ret += if try_gcd == 1 {1} else {0};
                }
            }
            ret
    }
}

}

mod l2749{

    pub struct Solution;

impl Solution {
    pub fn make_the_integer_zero(num1: i32, num2: i32) -> i32 {


            for try_number in  1.. 60+1 {

                let mut diff = num1 as i64 - num2 as i64 * try_number as i64;

                if diff < 1 {
                    return -1;
                }

                if diff < try_number{
                    continue;
                }

                let mut binary_1s = 0 as i32;
                while (diff > 0) & (binary_1s < try_number as i32) {
                    binary_1s += (diff %2) as i32;
                    diff = diff / 2;
                }

                if diff == 0 {
                    return try_number as i32;
                }

            }
            -1
        }


}

}

fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests{

    #[test]
    fn test_case_2259(){
        use crate::l2259::Solution;
        assert_eq!(Solution::remove_digit("123".to_string(), '3'), "12");
        assert_eq!(Solution::remove_digit("1231".to_string(), '1'), "231");
        assert_eq!(Solution::remove_digit("551".to_string(), '5'), "51");
    }

    #[test]
    fn test_case_2260(){
        use crate::l2260::Solution;

        let vec = vec![3,4,2,3,4,7];

        assert_eq!(Solution::minimum_card_pickup(vec), 4);
       
    }

    #[test]
    fn test_case_2261(){
        use crate::l2261::Solution;

        let vec = vec![2,3,3,2,2];
        assert_eq!(Solution::count_distinct(vec,2,2), 11);

        let vec = vec![1,2,3,4];
        assert_eq!(Solution::count_distinct(vec,4,1), 10);
       
    }

    #[test]
    fn test_case_2748(){
        use crate::l2748::Solution;

        let vec = vec![2,5,1,4];
        assert_eq!(Solution::count_beautiful_pairs(vec), 5);

        let vec = vec![11,21,12];
        assert_eq!(Solution::count_beautiful_pairs(vec), 2);

        let vec = vec![1799,259,1453,374,1854,2212,2104,2221];
        assert_eq!(Solution::count_beautiful_pairs(vec), 23);
       
    }

    #[test]
    fn test_case_2749(){
        use crate::l2749::Solution;

        assert_eq!(Solution::make_the_integer_zero(5, 7), -1);
        assert_eq!(Solution::make_the_integer_zero(3, -2), 3);
        assert_eq!(Solution::make_the_integer_zero(112577768,-501662198), 16);
    }
}
