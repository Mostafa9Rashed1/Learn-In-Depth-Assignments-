#include <stdio.h>
#include <string.h>

void reverseWords(char str[]) {
	int length = strlen(str);
	int start = 0;

	// Reverse the entire string
	for (int i = 0; i < length / 2; i++) {
		char temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
	}

	// Reverse each individual word
	for (int i = 0; i <= length; i++) {
		if (str[i] == ' ' || str[i] == '\0') {
			// Found a word boundary, reverse the word
			for (int j = start, k = i - 1; j < k; j++, k--) {
				char temp = str[j];
				str[j] = str[k];
				str[k] = temp;
			}
			start = i + 1; // Move the start index to the next word
		}
	}
}

int main() {
	char str[100];

	printf("Enter a sentence: ");
	fgets(str, sizeof(str), stdin);

	// Remove the newline character from fgets
	str[strcspn(str, "\n")] = '\0';

	reverseWords(str);

	printf("Reversed sentence: %s\n", str);

	return 0;
}