/*
 ============================================================================
 Name        : LKelleyThreeNPlusOne.c
 Author      : Lucas Kelley
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defines functions for later use
int computeMaxSequenceLength(int first, int last);
int computeSequenceLength(int num);
int computeNextValue(int val);

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	// defines character arrays to hold the user inputed first last and outFileName values
	char sFirst[BUFSIZ];
	char sLast[BUFSIZ];
	char outFileName[BUFSIZ];

	// prompts the user to input a filename
	puts("Enter the output filename:");
	fgets(outFileName, BUFSIZ, stdin);
	outFileName[strlen(outFileName) - 1] = '\0';
	// opens the file for writing
	FILE *outFile = fopen(outFileName, "w");

	// while loop that executes as long as both range values are not newline characters [\n]
	while (sFirst[0] != '\n' || sLast[0] != '\n') {
		// gets the users input if it is a newline character it breaks out of the loop
		fgets(sFirst, BUFSIZ, stdin);
		if (sFirst[0] == '\n') {
			break;
		}
		// converts the user inputed string into an integer
		int first = atoi(sFirst);
		// gets the users input if it is a newline character it breaks out of the loop
		fgets(sLast, BUFSIZ, stdin);
		if (sLast[0] == '\n') {
			break;
		}
		// converts the user inputed string into an integer
		int last = atoi(sLast);
		// calls the computeMaxSequenceLength function on the two user inputed range values
		int maxSequenceLength = computeMaxSequenceLength(first, last);
		// prints the first and last values of the range and the maxSequenceLength to the output file
		fprintf(outFile, "%d\t%d\t%d\n", first, last, maxSequenceLength);
	}
	// prints Complete\n to stdout
	printf("Complete\n");
	return EXIT_SUCCESS;
}
// defines function computeMaxSequenceLength that takes in two integers, the first and last of a range and finds the max sequence length
int computeMaxSequenceLength(int first, int last) {
	int maxSequenceLength = 0;
	// for loop where it runs until the sequenceLength of all values of the range have been computed
	for (int iTurns = first; iTurns <= last; iTurns++) {
		int sequenceLength = computeSequenceLength(iTurns);
		// compares the two sequence lengths whichever one is larger stays
		if (sequenceLength > maxSequenceLength) {
			maxSequenceLength = sequenceLength;
		}
	}
	return maxSequenceLength;
}
// defines function computeSequenceLength that takes in a value and computes the number of steps it takes for that number to reach 1
int computeSequenceLength(int num) {
	int sequenceLength = 1;
	int nextVal = 1;
	// if the number is greater than 1 computeNextValue of the number and increment the sequence length
	if (num > 1) {
		nextVal = computeNextValue(num);
		sequenceLength += 1;
	}
	// while next val is not 1 computeNextValue of nextVal and increment the sequence length
	while (nextVal != 1) {
		nextVal = computeNextValue(nextVal);
		sequenceLength += 1;
	}
	return sequenceLength;
}
// defines function computeNextValue that takes in a value and performs an operation to find the next value in the sequence
int computeNextValue(int val) {
	int nextVal = 0;
	// if the value is even it is divided by 2
	if (val % 2 == 0) {
		nextVal = val / 2;
	// else it is odd so it gets multiplied by 3 the added to 1
	} else {
		nextVal = (val * 3) + 1;
	}
	return nextVal;
}
