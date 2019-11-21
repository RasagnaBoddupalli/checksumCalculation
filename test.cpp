#include "checksumCalculation.h"
//void  verifyEqual(string input, string expectedOutput, string testID);

void  verifyEqual(string input, string expectedOutput, string testID) {
	if (!input.compare(expectedOutput)) {
		cout << testID << " : Passed" << endl;
	}
	else {
		cout << testID << " : Failed" << endl;
	}
}

int main() {
	string input, expectedOutput;

	cout << "Testcase1 : Checksum check if the reminder is not 0" << endl;	
	input = "63938200039";
	expectedOutput = "639382000393";
	verifyEqual(calculate_check_digit(input), expectedOutput, "Test1");
	
	cout << "Testcase2 : Checksum check if the reminder is 0" << endl;
	input = "03620029145";
	expectedOutput = "036200291450";
	verifyEqual(calculate_check_digit(input), expectedOutput, "Test2");

	cout << "Testcase3 : Error scenario- input barcode contains a non integer value" << endl;
	input = "03620A29145";
	expectedOutput = "Error : UPC - A code should contain values only between 0 to 9";
	calculate_check_digit(input); // function will throw an error on the console	

    cout << "Testcase4 : Error scenario- input barcode has value less than 11 digits" << endl;
    input = "03620A29";
	expectedOutput = "Error : Input UPC-A code length should be 11";
	calculate_check_digit(input); // function will throw an error on the console	
	return 0;
}

