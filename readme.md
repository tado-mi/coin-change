# Limited Coin Change Problem

Code written by [Youssef Hussein](https://github.com/youssefmohamed552), forked and modified by [Lusine Keshishyan](https://github.com/tado-mi) in order to practice coding in C++. Please see the commit history for details.

Following is an implementation of the [Limited Coin Change](https://en.wikipedia.org/wiki/Change-making_problem) problem, written while taking **CSC 282: Design of Efficient Algorithms**  at the University of Rochester. It is not a solution to an assignment, as the course did not have any coding assignments. It was just written as a practice to better understand Dynamic Programming.

Given a value and a limited list of coins the algorithm returns the minimum number of coins required to get the value. The `main.cpp` is heavily commented to explain the logic.

# Running

To compile, hit `g++ main.cpp` in the directory where the `main.cpp` is stored. That will create a default `a.out` executable. It can be ran as `./a.out A c_1 c_2 ... c_n`, where `A` is an optional argument representing the amount, and `c_1 c_2 ... c_n` are optional arguments listing the denominations. If ran as just `./a.out`, the `main` will prompt to insert the amount, and the denominations.
