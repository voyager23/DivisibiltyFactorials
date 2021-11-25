/*
 * matrix.cxx
 * 
 * Copyright 2021 mike <mike@pop-os>
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
 * 
 */


#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;
#include "../inc/toolbox.hxx"

int main(int argc, char **argv)
{
	const ul N = 1000;	// restricted debug value
	const ul L = N*N;
	
	vector<ul> factors;	// holds prime factors for a single integer
	vector<ul> factorials;
	vector<ul> primes;
	SieveOfEratosthenes(primes, N);
	map<PrimePower,ul> cache;
	vector<vector<ul>> matrix;	// primary index selects a prime, secondary index selects s(p^e) for e >= 1;
	for(auto i = primes.begin(); i != primes.end(); ++i){ // scan for primes <= N
		if(*i > N) break;
		ul prime = *i;
		ul power = 1;
		while(1){
			ul sf = fsf_v2(PrimePower{prime, power}, cache);
			if ((ul)(pow(prime,power)) > L) break;
			printf("s(%ld^%ld) = %ld   ", prime, power, sf);
			power += 1;
		}
		NL;	
	}
	NL;
	return 0;
}

