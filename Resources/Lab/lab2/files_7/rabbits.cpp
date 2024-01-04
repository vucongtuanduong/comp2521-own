#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
long long rabbits(int month);

int main() {
	freopen("input.txt", "r", stdin);
	int months = 0;
	cin >> months;

	long long numRabbits = rabbits(months);
	printf("Number of rabbits after %d month(s): %lld\n",
	       months, numRabbits);

	return 0;
}

// !!! DO NOT MODIFY THE CODE ABOVE !!!
////////////////////////////////////////////////////////////////////////
// Your task

// Returns the number of rabbits after the given number of months
long long rabbits(int months) {
	// TODO
	if (months == 0 || months == 1) {
		return 2;
	}
	return rabbits(months - 1) + rabbits(months - 2);
	// return 42;
}

