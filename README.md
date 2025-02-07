# Push Swap

## 📌 Overview

**Push Swap** is a project designed to implement and optimize a set of algorithms that sort a stack of integers using a limited set of instructions. The main goal is to minimize the number of moves required to achieve correct sorting.


---

## 📖 Contents

- [Features](#Features)
- [Requirements](#requirements)
- [Compilation](#compilation)
- [Allowed Instructions](#allowedinstructions)
- [Optimization](#optimization)
- [Author](#author)

---

## 🚀 Features

- Sorts a stack of integers using a limited set of instructions.
- Implementaction of the [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- Designed to work with small and medium-sized stacks (up to 500 elements).

---
## 📂 Project Structure
| File                        | Description                                                                 |
|-----------------------------|-----------------------------------------------------------------------------|
| **`ft_libft/`**       | External custom library (libft).         |
| **`ft_printf/`**       | External library (ft_printf).            |
| **`.gitignore`** | Git ignore file.                      |
| **`algorithm.c`** | Sorting algorithm implementation.   |
| **`init_nodes_a.c`** | Stack initialization functions (part A).   |
| **`init_nodes_b.c`** | Stack initialization functions (part B).   |
| **`instructions.c`** | Implementation of allowed stack operations.   |
| **`list_utils.c`** | Linked list utility functions.   |
| **`push.c`** | Push operations (pa, pb).   |
| **`push_swap.c`** | Main entry point of the program.                                   |
| **`rev_rotate.c`** | Reverse rotate operations (rra, rrb, rrr).                                   |
| **`rotate.c`** | Rotate operations (ra, rb, rr).                                   |
| **`sort_stack.c`** | Sorting logic.                                   |
| **`stack_utils.c`** | Header file with function prototypes and macros.                                   |
| **`swap.c    `** | Swap operations (sa, sb, ss).                                   |
| **`utils.c`** | General helper functions.                                    |
| **`utils_2.c`** | Additional helper functions.                                    |
| **`utils_3.c`** | Additional helper functions.                                    |
| **`utils_4.c`** | Additional helper functions.                                  |
| **`push_swap.h`** |  Header file for function prototypes and definitions.                                   |
| **`Makefile`** | Additional helper functions.                       |


---

## ⚙️ Requirements

- Operative: **Linux**, **macOS** or **Windows**.
- Compiler: **GCC** or equivalent.
- Functional Makefile.

---

## 🛠️ Compilation

To compile the project, simply run the command:

make

## 🔀 Allowed Instructions

The program must operate exclusively with the following instructions:

- **`sa`**: Swaps the first two elements of stack `a`.
- **`sb`**: Swaps the first two elements of stack `b`.
- **`ss`**: Performs  `sa` and `sb` simultaneously.
- **`pa`**: Pushes the first element of stack `b` onto `a`.
- **`pb`**: Pushes the first element of stack `a` onto `b`.
- **`ra`**: Rotates stack `a` upwards.
- **`rb`**: Rotates stack `b` upwards.
- **`rr`**: Performs  `ra` and `rb` simultaneously.
- **`rra`**: Rotates stack `a` downwards.
- **`rrb`**: Rotates stack `b` downwards.
- **`rrr`**: Performs  `rra` and `rrb` simultaneously.

---
## Execution exmaple

Here’s a execution example and a step-by-step visualization of the sorting process:

To execute the program, use the following syntax:
```sh
./push_swap 5 3 2 1 4
```
Output:
```sh
pb
pb
sa
rra
pa
ra
ra
pa
ra
```

Sorting visualization:

![Animation](https://github.com/user-attachments/assets/8b6c128e-99df-43d8-86aa-b85a400d8712)

---
## Author 

***Pablo Alonso García***
---
