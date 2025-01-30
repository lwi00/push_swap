# Push Swap

## Description
Push Swap is a sorting algorithm project from 42 School. The goal is to sort a list of integers using two stacks (A and B) with a limited set of operations.

## Features
- Implements an efficient sorting algorithm using stacks.
- Supports sorting of different list sizes (3, 5, and large numbers).
- Includes optimized operations to minimize instruction count.

## Installation
Clone the repository:
```sh
git clone https://github.com/lwi00/push_swap.git
cd push_swap
make
```

## Usage

Run the program with a list of space-separated integers:

./push_swap 3 2 5 1 4
This will output the sequence of operations needed to sort the numbers.

## Operations

The program uses the following stack operations:

sa / sb / ss - Swap top elements of stack A/B/both.
pa / pb - Push top element from one stack to another.
ra / rb / rr - Rotate stack A/B/both upwards.
rra / rrb / rrr - Reverse rotate stack A/B/both.

## Testing

To check the efficiency of the sorting algorithm, use a checker:

ARG="4 67 3 87"; ./push_swap $ARG | ./checker_linux $ARG

