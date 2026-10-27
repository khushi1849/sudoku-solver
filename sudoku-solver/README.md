# Sudoku Solver

A Sudoku solver in C++ using backtracking.

## How it works
For each empty cell (0), the solver tries digits 1-9. If a digit is valid
(no repeat in the row, column or 3x3 box), it places it and moves on.
If it gets stuck, it backtracks and tries the next digit.

The final `solver.cpp` uses bitmasks for O(1) validity checks and the MRV
heuristic (fill the cell with the fewest valid options first).

## Build and run
```
g++ solver.cpp -o solver
./solver
```

## Input format
9 lines, 9 numbers each, separated by spaces. Use 0 for empty cells.

```
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

## Output
The solved grid, or `No solution` if the puzzle is unsolvable.
## Benchmarks

Tested on one hard puzzle (`hard.txt`), compiled with `g++ -O2`.
Times are for a single run on my laptop, so they vary a little between runs.

| Version | Time |
|---|---|
| Naive backtracking | 4.44 ms |
| Bitmask | 1.45 ms |
| Bitmask + MRV | 5.61 ms |

MRV did not help on this puzzle because scanning all empty cells at every
step costs more than it saves here. It may do better on other puzzles.

Code for each version is in the `versions/` folder.