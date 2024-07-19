#include <stdio.h>

int countMaxOnesBetweenZeros(int num) {
	int maxOnes = 0;
	int currentOnes = 0;
	int foundZero = 0;

	while (num > 0) {
		if (num % 2 == 1) {
			currentOnes++;
			if (foundZero && currentOnes > maxOnes) {
				maxOnes = currentOnes;
			}
			} else {
			foundZero = 1;
			currentOnes = 0;
		}
		num /= 2;
	}

	return maxOnes;
}

int main() {
	int num;

	printf("Enter a binary number: ");
	scanf("%d", &num);

	int maxOnes = countMaxOnesBetweenZeros(num);

	printf("The maximum number of ones between two zeros is: %d\n", maxOnes);

	return 0;
}