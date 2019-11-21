#include "checksumCalculation.h"
//function calculate_check_digit
// input string, output string
string calculate_check_digit(string inputCode) {
	static int code[CODELENGTH];
	int* intValues, checksum;
	struct sum sumValues;
	// convert string to array of integers
	intValues = convert_to_int(inputCode);
	// get sum of odd and even position digits
	sumValues = get_sum(intValues);
	// checksum calculation
	checksum = calculate_checksum(sumValues);
	// return the output in the string type
	std::ostringstream os;
	for (int i = 0; i < CODELENGTH - 1; i++) {
		os << *(intValues + i);
	}
	os << checksum;
	std::string str(os.str());
	return str;
}

// function to validate input string and convert it into a int array
int* convert_to_int(string inputCode) {
	static int buffer[CODELENGTH - 1];
	// check if input string length is 11
	if (inputCode.length() == CODELENGTH - 1) {
		for (int i = 0; i < CODELENGTH - 1; i++)
		{
			int intValue = inputCode[i] - 48;
			//check if input string has single digits ie 0< number < 9
			if (intValue >= 0 && intValue <= 9) {
				buffer[i] = intValue;
			}
				else {
				// throw an error
				cerr<< "Error : UPC - A code should contain values only between 0 to 9" << endl;
			}
		}
	}
	else {
		// throw an error
		cerr << "Error : Input UPC-A code length should be 11" << endl;
		exit(0);
	}
		
	return buffer;
}


// function calculate sum of even and odd position digits
sum get_sum(int* p) {
	struct sum values;
	bool isOdd = true;
	// To store the respective sums 
	int sumOdd = 0, sumEven = 0;
	for (int i = 0; i < CODELENGTH - 1; i++)
	{
		if (isOdd)
			sumOdd += *(p + i);
		// Even positioned digit
		else
			sumEven += *(p + i);
		// Invert state 
		isOdd = !isOdd;
	}
	values.sumOdd = sumOdd;
	values.sumEven = sumEven;
	return values;
}

// function to calculate the checksum value
int calculate_checksum(struct sum values) {
	int checksum = 0;
	// checksum calculation as per document 
	int step3CheckCalculation = (values.sumOdd * 3 + values.sumEven) % 10;
	// Incase of non zero reminder, subract the reminder from 10
	if (step3CheckCalculation) {
		checksum = 10 - ((values.sumOdd * 3 + values.sumEven) % 10);
	}
	return checksum;
}
