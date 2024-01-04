#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int gcd(int a, int b);

int main() {
	freopen("input.txt", "r", stdin);
	int a, b;
	cin >> a >> b;
	int ans = gcd(a, b);
	printf("The GCD of %d and %d is %d\n", a, b, ans);
	return 0;
}

// !!! DO NOT MODIFY THE CODE ABOVE !!!
////////////////////////////////////////////////////////////////////////
// Your task

// Returns the GCD of a and b
int gcd(int a, int b) {
	// TODO
	if (a == 0) {
		return b;
	} else if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
	// return 0;
}

