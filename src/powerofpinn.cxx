// C++ implementation of finding power of p in n!
//#include <bits/stdc++.h>

#include <iostream>

using namespace std;

// Returns power of p in n!
int PowerOFPINnfactorial(int n, int p)
{
	// initializing answer
	int ans = 0;

	// initializing
	int temp = p;

	// loop until temp<=n
	while (temp <= n) {

		// add number of numbers divisible by n
		ans += n / temp;

		// each time multiply temp by p
		temp = temp * p;
	}
	return ans;
}

// Driver function
int main()
{
	cout << PowerOFPINnfactorial(1000, 2) << endl;
	return 0;
}

