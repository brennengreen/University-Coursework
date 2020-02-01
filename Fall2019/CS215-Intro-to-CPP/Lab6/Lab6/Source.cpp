//--------------------------------------------------------------------------
//								CS215-003 LAB6
//--------------------------------------------------------------------------
// Author: Brennen Green
// Date: 10/15/2019
// Description: performs various arithmetic on two given fractions
//--------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct frac { // A Fractiom
	int num; // numerator
	int den; // denominator
};


//===========================================================================
//								AskFraction()
//===========================================================================
frac AskFraction() {
	int num = -99999;
	int den = -99999;
	cout << "Numerator:           ";
	cin >> num;
	while (den <= 0) {
		cout << "Denominator ( > 0 ): ";
		cin >> den;
	}
	frac fraction;
	fraction.den = den;
	fraction.num = num;
	return fraction;
}

//===========================================================================
//								DecimalValue()
//===========================================================================
double DecimalValue(frac givenFraction) {
	return (float)givenFraction.num / (float)givenFraction.den;
}

//===========================================================================
//								PrintFraction()
//===========================================================================
void PrintFraction(int num, int den) {
	frac fraction;
	fraction.num = num;
	fraction.den = den;
	cout << setw(3) << num << endl;
	cout << "--- = " << DecimalValue(fraction) << endl;
	cout << setw(3) << den << endl;
}

//===========================================================================
//								Multiply()
//===========================================================================
frac Multiply(frac fracOne, frac fracTwo) {
	frac fraction;
	fraction.num = (fracOne.num * fracTwo.num);
	fraction.den = (fracOne.den * fracTwo.den);
	return fraction;
}

//===========================================================================
//								Add()
//===========================================================================
frac Add(frac fracOne, frac fracTwo) {
	frac fraction;
	if (fracOne.den == fracTwo.den) {
		fraction.num = fracOne.num + fracTwo.num;
		fraction.den = fracOne.den;
	}
	else {
		fraction.num = (fracOne.num * fracTwo.den) + (fracTwo.num * fracOne.den);
		fraction.den = fracOne.den * fracTwo.den;
	}
	return fraction;

}

//===========================================================================
//								Simplify()
//===========================================================================
void Simplify(frac& fraction) {
	for (int i = 2; i < fraction.den; ++i) {
		if ((fraction.num % i == 0) && (fraction.den % i == 0)) {
			fraction.num = fraction.num / i;
			fraction.den = fraction.den / i;
		}
	}
}

//===========================================================================
//								Simplify()
//===========================================================================
int main() {
	cout << "Fraction One: \n";
	frac fracOne = AskFraction();
	cout << endl;
	cout << "Fraction Two: \n";
	frac fracTwo = AskFraction();

	cout << "PRODUCT: \n";
	frac product = Multiply(fracOne, fracTwo);
	PrintFraction(product.num, product.den);
	cout << endl;

	cout << "SUM: \n";
	frac sum = Add(fracOne, fracTwo);
	PrintFraction(sum.num, sum.den);
	cout << endl;

	cout << "PRODUCT SIMPLIFIED: \n";
	Simplify(product);
	PrintFraction(product.num, product.den);

	system("pause");
	return 0;
}