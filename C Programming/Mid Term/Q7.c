#include <stdio.h>

int sumNumbers(int n) {
	int sum = (n * (n + 1)) / 2;
	return sum;
}

int main() {
	int result = sumNumbers(100);
	printf("The sum of numbers from 1 to 100 is: %d\n", result);
	return 0;
}