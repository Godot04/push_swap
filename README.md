# push_swap - Efficient Stack Sorting Algorithm

![42 school](https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42&logoColor=white)
![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)
![Norminette](https://img.shields.io/badge/Norminette-passing-success?style=flat-square)

## 📖 About

**push_swap** is a project that challenges you to sort a stack of integers using a limited set of operations, with the goal of minimizing the number of moves. The program takes a list of integers as arguments and outputs a series of instructions to sort them using two stacks (A and B) and a specific set of allowed operations (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr). 

Through this project, I got some skills of algorithmic thinking, complexity analysis, and some knowledge about optimization techniques.

## 🎯 Project Goals

- Implement an efficient sorting algorithm for stack-based data structures
- Optimize the number of operations to achieve the best possible sorting efficiency
- Understand algorithm complexity and performance analysis
- Work with doubly-linked lists and stack operations

## 📚 Allowed Operations

### Stack Operations

The program can use the following operations:

- **sa** (swap a) - Swap the first 2 elements at the top of stack A
- **sb** (swap b) - Swap the first 2 elements at the top of stack B
- **ss** - Execute `sa` and `sb` simultaneously
- **pa** (push a) - Take the first element at the top of b and put it at the top of a
- **pb** (push b) - Take the first element at the top of a and put it at the top of b
- **ra** (rotate a) - Shift up all elements of stack a by 1 (The first element becomes the last one)
- **rb** (rotate b) - Shift up all elements of stack b by 1 (The first element becomes the last one)
- **rr** - Execute `ra` and `rb` simultaneously
- **rra** (reverse rotate a) - Shift down all elements of stack a by 1 (The last element becomes the first one)
- **rrb** (reverse rotate b) - Shift down all elements of stack b by 1 (The last element becomes the first one)
- **rrr** - Execute `rra` and `rrb` simultaneously

## 🧠 Algorithm Strategy

My implementation uses an optimized sorting strategy:

### For Small Stacks (2-5 elements)

- **2 elements**: Simple swap if needed
- **3 elements**: Identifies the highest value and positions it at the bottom, then swaps if needed to sort the remaining two elements
- **4-5 elements**: Push smallest elements to stack B, sort remaining in A, then push back

### For Large Stacks (6+ elements)

The algorithm uses a **cost-based approach** with the following steps:

1. **Push to Stack B**: Move elements from A to B (except 3 elements)
2. **Target Analysis**: For each element in A, find its optimal target position in B
3. **Rotation Cost Calculation**: Calculate the cost of moving each element
4. **Best Move Selection**: Choose the element with the lowest total rotation cost
5. **Optimized Rotations**: Use combined rotations (rr/rrr) when both stacks need rotation
6. **Final Sort**: Sort remaining 3 elements in A, then push all back from B to A
7. **Final Rotation**: Rotate stack A to place smallest element on top

### Key Features

- **Median-based positioning**: Determines whether to rotate up or down
- **Combined rotations**: Optimizes by rotating both stacks simultaneously when possible
- **Target node selection**: Intelligently pairs elements between stacks
- **Cost analysis**: Evaluates all possible moves to find the most efficient path

## 🛠️ Compilation

### Building the Program

To compile the program, simply run:

```bash
make
```

This creates the `push_swap` executable.

### Available Commands

- `make` - Compile the program
- `make clean` - Remove object files
- `make fclean` - Remove object files and the executable
- `make re` - Recompile everything from scratch

## 🚀 Usage

### Basic Usage

```bash
./push_swap [list of integers]
```

### Examples

```bash
# Sort 5 random numbers
./push_swap 3 2 5 1 4

# Sort with negative numbers
./push_swap -1 -5 0 3 2

# Sort with quoted string input
./push_swap "3 2 5 1 4"
```

### Output

The program outputs the sequence of operations needed to sort the stack:

```bash
./push_swap 3 2 1
sa
rra
```

### Error Handling

The program outputs "Error\n" to standard error for:

- Non-numeric arguments
- Numbers outside the integer range (INT_MIN to INT_MAX)
- Duplicate numbers
- Invalid input format

## 📊 Implementation Structure

The project is organized with a modular approach:

- **push_swap.c** - Main program entry point and stack creation
- **push_swap.h** - Header file with structure definitions and function prototypes
- **sorting.c** - Sorting algorithms for small and large stacks
- **operations_for_a.c** - Operations analysis for stack A
- **operations_for_b.c** - Operations analysis for stack B
- **commands_push.c** - Push operations (pa, pb)
- **commands_swap.c** - Swap operations (sa, sb, ss)
- **commands_rotate.c** - Rotate operations (ra, rb, rr)
- **commands_reverse_rotate.c** - Reverse rotate operations (rra, rrb, rrr)
- **rotation_operations.c** - Rotation cost analysis and optimization
- **push_swap_utils.c** - Utility functions for stack manipulation
- **utils_for_utils.c** - Additional helper functions
- **funct_continue.c** - Continuation helper functions
- **Libft/** - Custom C library for string manipulation and utilities
- **ft_printf/** - Custom printf implementation for formatted output

### Data Structure

```c
typedef struct s_stack
{
    int             value;              // The actual integer value
    int             index;              // Position in the stack
    int             rotations;          // Cost to move this element
    int             is_below_medium;    // Flag for rotation direction
    int             is_best_move_choice;// Flag for optimal move
    struct s_stack  *target;            // Target node in other stack
    struct s_stack  *next;              // Next node in the stack
    struct s_stack  *previous;          // Previous node in the stack
} t_stack;
```

## ⚙️ Technical Details

- **Language**: C
- **Compiler**: gcc
- **Flags**: `-Wall -Wextra -Werror`
- **Norm**: 42 Norminette
- **Data Structure**: Doubly-linked list (circular)
- **Dependencies**: libft, ft_printf

## 🎮 Testing

You can test the program with various inputs:

```bash
# Test with 3 random numbers (should be < 3 operations)
ARG="3 2 1"; ./push_swap $ARG

# Test with 5 random numbers (should be < 12 operations)
ARG="5 4 3 2 1"; ./push_swap $ARG | wc -l

# Test with 100 random numbers (should be < 700 operations for max grade)
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with 500 random numbers (should be < 5500 operations for max grade)
ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Verify the sorting is correct
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker_linux $ARG
```

## 📝 Notes

- All functions follow the 42 Norminette coding standards
- Memory is properly managed with no leaks
- The algorithm is optimized to minimize the number of operations
- Handles edge cases (negative numbers, INT_MIN, INT_MAX, duplicates)
- The implementation uses a cost-based approach for optimal performance
- Combined rotations (rr/rrr) are used when both stacks need rotation

## 👤 Author

**opopov** - 42 School Student

## 📅 Project Timeline

- **Created**: March 13, 2025
- **Last Updated**: March 28, 2025
