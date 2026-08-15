# First Semester C Coursework

Consolidated from scattered feature branches into one organized branch, grouped by
originating branch. Filenames were renamed to describe what each program does;
original filenames are noted below.

## rayblb-patch/ (from branch `Rayblb-patch`)
- `recursion_depth_demo.c` (was `solutionofabc.c`) - demonstrates call-stack depth via
  chained recursive functions `a -> b -> c -> c...`
- `point_in_rectangle.c` (was `yp1a(pdf).c`) - checks if a point lies in a
  rectangular/triangular shaded region defined by linear inequalities
- `point_in_circle.c` (was `yp1b(pdf).c`) - checks if a point lies in a circular
  shaded region using distance-from-center math
- `string_to_int_validator.c` (was `yp2pdf.c`) - reads a string, validates it's a
  clean integer via `strtol`, and converts it with `atoi`

## exercise-6/ (from branch `the-6th-exersice`)
- `pascals_triangle.c` (was `PASCALtriangle(pdf dp 2).c`) - builds and prints
  Pascal's triangle up to a user-given degree
- `array_2d_search.c` (was `searcharr(pdf 2).c`) - searches a fixed 4x4 2D array for
  a target value and reports all matching positions
- `longest_char_run.c` (was `sequencech(pdf 1).c`) - finds the longest run of a
  chosen character in a string
- `random_binary_matrix_unique_rows.c` (was `unitable 0 1 (pdf dp 1).c`) - fills a
  matrix with random 0/1 values, sorts the rows, and removes duplicate rows

## exercise-7/ (from branch `the-7th-exersice`)
- `const_pointer_demo.c` (was `ConstWontStopMe.c`) - demonstrates that casting away
  `const` through a pointer and writing to it is undefined behavior
- `swap_via_pointers.c` (was `SwapNumsAndPointers.c`) - swaps two ints via `int*`
  and swaps two C strings via `char**` (pointer-to-pointer), with commented-out
  buggy version for comparison
- `word_sort_benchmark_all_algorithms.c` (was `dp3.c`) - times selection sort,
  bubble sort, and comb sort against the same 10,000 randomly generated words
- `word_sort_interactive_menu.c` (was `yp1.c`) - reads 10 words from the user and
  lets them pick selection/bubble/comb sort (or all three) from a menu, printing
  each pass
- `comb_sort_pointer_arithmetic.c` (was `yp2.c`) - comb sort implementation that
  walks the word array using raw pointer arithmetic instead of indices
- `vowel_consonant_counter.c` (was `yp3.c`) - counts vowels and consonants in a
  single lowercase word

## Note
The dangling `git_edu` submodule reference present on `main` was dropped here as
broken/empty.
