// The program reads an integer number and then calculate the product of its digits.
// It then identify whether the product of digits for the integer is an even or odd number, and a multiple of 3, and/ or 5.


#include <iostream>
using namespace std;

int main() {
	int num, product;
	product = 1;
	cout << "Enter an integer number: ";
	cin >> num;

	while (num != 0) {
		int digit;
		digit = num % 10;
		product *= digit;
		cout << digit;
		num /= 10;
		if (num != 0) {
			cout << " + ";
		}
	}

	cout << " = " << product << endl; //product of the digits 

	bool even = (product % 2 == 0);
	bool Multiple3 = (product % 3 == 0);
	bool Multiple5 = (product % 5 == 0);

	if (even) {
		cout << product << " is even number. \n";
	} 
	else {
		cout << product << " is odd number. \n";		
	}
	if (Multiple3) {
		cout << product << " is the multiple of 3. \n";
	}
	if (Multiple5) {
		cout << product << " is the multiple of 5. \n";
	}
	return 0;
}

