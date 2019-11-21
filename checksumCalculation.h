#pragma once
#include <iostream>
#include <string>
#include <sstream>
#define CODELENGTH 12
using namespace std;
struct sum
{
	int sumOdd;
	int sumEven;
};
int* convert_to_int(string inputCode);
struct sum get_sum(int code[CODELENGTH - 1]);
int calculate_checksum(struct sum values);
string calculate_check_digit(string inputCode);
