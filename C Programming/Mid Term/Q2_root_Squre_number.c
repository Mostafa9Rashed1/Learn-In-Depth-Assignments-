#include <stdio.h>

float squareRoot(int number) {
	float x = number;
	float y = 1;
	float epsilon = 0.000001;  // Desired precision

	while (x - y > epsilon) 
	{
		x = (x + y) / 2;
		y = number / x;
	}

	return x;
}

int main() {
	int number;

	printf("Enter an integer number: ");
	scanf("%d", &number);

	float result = squareRoot(number);

	printf("Square root of %d is %.3f\n", number, result);

	return 0;
}