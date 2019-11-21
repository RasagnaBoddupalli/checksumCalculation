Readme:
This folder consists of 2 cpp files, checksumCalculation.cpp and test.cpp
checksumCalculation.cpp: Has a main function "calculate_check_digit" which takes a string as parameter containing a
UPC-A code and returns the UPC-A code appended with the check digit.

test.cpp : Contains few testcases to verify "calculate_check_digit"

code compilation:
compiler: gcc
commands:
 g++ -c checksumCalculation.cpp
 g++ -c test.cpp
 g++ -o output checksumCalculation.o test.o
 output
