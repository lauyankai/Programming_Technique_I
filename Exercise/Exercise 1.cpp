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
			cout << " * ";
		}
	}

	cout << " = " << product << endl; //product of the digits
	
	bool Multiple4 = (product % 4 == 0);
	bool Multiple5 = (product % 5 == 0);
	bool Multiple7 = (product % 7 == 0);

	if (Multiple4)
		cout << product << " is the multiple of 4. \n";
	if (Multiple5) 
		cout << product << " is the multiple of 5. \n";
	if (Multiple7) 
		cout << product << " is the multiple of 7.";
	return 0;
}
