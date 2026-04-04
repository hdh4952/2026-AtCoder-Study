use std::{
    io::{self, Read},
    str::{FromStr, SplitWhitespace},
};

fn read_value<T>(tokens: &mut SplitWhitespace<'_>) -> Option<T>
where
    T: FromStr,
    T::Err: std::fmt::Debug,
{
    tokens.next()?.parse::<T>().ok()
}

fn main() {
    let mut input_buf = String::new();
    io::stdin().read_to_string(&mut input_buf).unwrap();
    let mut input = input_buf.split_whitespace();

    let n: usize = read_value(&mut input).unwrap();
    let m: usize = read_value(&mut input).unwrap();

    let mut result = vec![0; m];

    for _ in 0..n {
        let a: usize = read_value::<usize>(&mut input).unwrap() - 1;
        let b: usize = read_value::<usize>(&mut input).unwrap() - 1;

        result[a] -= 1;
        result[b] += 1;
    }

    for idx in 0..m {
        println!("{}", result[idx]);
    }
}
