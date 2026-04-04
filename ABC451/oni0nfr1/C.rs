use std::{
    io::{self, Read},
    str::{FromStr, SplitWhitespace},
    fmt::Write,
};

fn read_value<T>(tokens: &mut SplitWhitespace<'_>) -> Option<T>
where
    T: FromStr,
    T::Err: std::fmt::Debug,
{
    tokens.next()?.parse::<T>().ok()
}

struct Node {
    value: i32,
    count: usize,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32) -> Self {
        Node {
            value,
            count: 1,
            left: None,
            right: None,
        }
    }

    fn append(&mut self, value: i32) {
        if self.value < value {
            if let Some(right) = &mut self.right {
                right.append(value);
            } else {
                // 실수 (오타)
                // self.right = Some(Box::new(Node::new(value)));
                self.left = Some(Box::new(Node::new(value)));
            }
        } else if self.value > value {
            if let Some(left) = &mut self.left {
                left.append(value);
            } else {
                self.left = Some(Box::new(Node::new(value)));
            }
        }

        self.count += 1;
    }

    fn extract_left(&mut self) -> Option<Box<Self>> {
        if let Some(extracted) = self.left.take() {
            self.count -= extracted.count;
            self.left = None;
            return Some(extracted);
        } else {
            return None;
        }
    }

    fn cut(mut self, value: i32) -> Option<Box<Self>> {
        // 루트가 value보다 작으면 자신은 버리고, 자신의 오른쪽을 cut한 값을 반환 (재귀)
        // 오른쪽이 비어 있으면?
        // None 반환

        // 루트가 value와 같으면 자신은 버리고, 자신의 오른쪽을 반환 (재귀 끝)
        // 오른쪽이 비어 있으면?
        // None 반환

        // 루트가 value보다 크면, 자신의 왼쪽을 cut하고(재귀) 그 결과를 루트에 다시 넣음, 루트를 반환
        // 왼쪽이 비어 있으면?
        // 그냥 자기 반환

        if self.value < value {
            return self.right?.cut(value);
        } else if self.value > value {
            if let Some(left) = self.extract_left() {
                let left_result = left.cut(value);
                // 버그: 왼쪽을 뗐다가 붙이면서 count 값을 다시 복구하지 않음
                // if let Some(left_result_node) = &left_result {
                //     self.count += left_result_node.count;
                // }
                self.left = left_result;
                return Some(Box::new(self));
            } else {
                return Some(Box::new(self));
            }
        } else {
            return self.right;
        }
    }
}

fn main() {
    let mut input_buf = String::new();
    io::stdin().read_to_string(&mut input_buf).unwrap();
    let mut input = input_buf.split_whitespace();
    let mut output = String::new();

    let q: usize = read_value(&mut input).unwrap();
    let mut root: Option<Box<Node>> = None;

    for _ in 0..q {
        let cmd: u8 = read_value(&mut input).unwrap();
        let h: i32 = read_value(&mut input).unwrap();

        if cmd == 1 {
            if let Some(mut root_some) = root.take() {
                root_some.append(h);
                root = Some(root_some);
            } else {
                root = Some(Box::new(Node::new(h)));
            }
        } else if cmd == 2 {
            if let Some(root_some) = root.take() {
                root = root_some.cut(h);
            }
        }

        // 디버그용
        println!("{}", root.is_none());

        if let Some(root_some) = &root {
            writeln!(output, "{}", root_some.count).unwrap();
        } else {
            writeln!(output, "0").unwrap();
        }
    }

    print!("{output}");
}