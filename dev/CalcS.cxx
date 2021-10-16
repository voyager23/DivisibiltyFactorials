/*
 * CalcS.cxx
 * 
 * Copyright 2021 Mike <mike@pop-os>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * Considering numbers 2 <= i <= 10^8
 */

using namespace std;

#include <iostream>
#include <vector>

#include "../inc/toolbox.hxx"

int main(int argc, char **argv)
{
	//const ul N = 100000000;
	const ul N = 1000;	// restricted debug value
	vector<ul> primes;
	vector<ul> factors;
	SieveOfEratosthenes(primes, N);
	// use examples of n=10 and n=25
	for(ul x = 2; x <= 100; ++x){
		find_factors(primes, x, factors);
		cout << x << ":  ";
		for(auto f = factors.begin(); f != factors.end(); ++f)
			cout << *f << " ";
		NL;
	}
	
}

