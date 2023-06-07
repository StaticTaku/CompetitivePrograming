#!/bin/bash
g++ -g -std=c++17 -Wall -Wextra -O2 $1.cpp -o $1.out && ./$1.out < input.txt > output.txt