#include <stdio.h>
#include <stdbool.h>

int guessingGame(int *guessNum, int *games)
{
	
	int guessThisRun = 0;
	*games += 1;
	int guess = 50, maxNum = 100, minNum = 1;
	bool numFound = false;
	char response = ' ';
	puts("Think of a number between 1 and 100.");
	while (!numFound) {

		guessThisRun = guessThisRun + 1;
		*guessNum = *guessNum + 1;
	  	printf("Is your number %d (< > =) ? ", guess);
				
		scanf("%c", &response);
		getchar();
		if (response == '=') {
			numFound = true;
			printf("I got it in %d tries!\n", guessThisRun);			
		} else if (response == '<') {
			if (guess == maxNum) {
				guess = minNum;
			} else {
				maxNum = guess;
				guess = (maxNum + minNum)/2;
			}
		} else if (response == '>') {
			if (guess == minNum) {
				guess = maxNum;
			} else {
				minNum = guess;
				guess = (minNum + maxNum)/2;
			}
		} else {
			char extra = ' ';
			while (extra != '\n') {
				extra = getchar();
			}
			puts("Invalid input.  Use only '< > =' please.");
			*guessNum = *guessNum - 1;
			guessThisRun = guessThisRun - 1;
		}
	}
}

main() {

	int games = 0, guesses = 0;
	double avg = 0;
	char response;
	bool play = true;

	guessingGame(&guesses, &games);
	while (play) {
		puts("Play again (yes or no)? ");
		scanf("%c", &response);
		getchar();
		if (response == 'y') {
			guessingGame(&guesses, &games);
		} else {
			play = false;
		}
	}
	avg = ((double) guesses) / ((double) games);
	printf("You played %d games.\nIt took the computer an average of %f guesses to determine your number.\n\n", games, avg);
}
