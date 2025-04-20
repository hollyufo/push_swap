# 📚 Push_swap

## 📌 Goal

Write a program in **C** called `push_swap` that sorts a stack of integers (stack `a`) using the **least number of instructions**, with help from an auxiliary stack `b`.

## 🧠 Key Concepts

- Master sorting algorithms and data manipulation.
- Optimize for minimal operations.
- Understand and apply algorithmic complexity.

## 📋 Instructions Allowed

- `sa`: swap the first two elements of stack a.
- `sb`: swap the first two elements of stack b.
- `ss`: `sa` and `sb` at the same time.
- `pa`: push the first element of b onto a.
- `pb`: push the first element of a onto b.
- `ra`: rotate stack a up (first becomes last).
- `rb`: rotate stack b up.
- `rr`: `ra` and `rb` at the same time.
- `rra`: reverse rotate stack a down.
- `rrb`: reverse rotate stack b down.
- `rrr`: `rra` and `rrb` at the same time.

## 🧱 Program Structure

### Input

- List of integers as arguments.
- Must handle errors: duplicates, non-integer values, and overflows.

### Output

- A list of commands that sort the integers.
- Printed one per line to standard output.

## 🧮 Sorting Strategies

- **Small sets (3–5 elements):** Hardcoded efficient sorting.
- **Large sets:** Radix Sort or custom algorithm using indexing.
- Optimization to reduce instruction count.

## ✅ Bonus Features (Optional)

- Visualizer for stack operations.
- Interactive mode or checker program.

## 🛠 Compilation

```bash
make


## Installation
```bash
git clone https://github.com/<your-username>/push_swap.git
cd push_swap
make
```
## Usage
```bash
# Generate instructions
./push_swap "4 67 3 87 23"

# Validate solution
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

