/*
 * listPrime.cxx
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
 * MA 02Prime0-1301, USA.
 * 
 * listing of multiples of Prime, Prime^2, Prime^3 etc up to 1000
 */


#include <iostream>
#include <vector>
#include <iterator>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

#define VERBOSE 1

#include "../inc/toolbox.hxx"

int main(int argc, char **argv)
{
	const ul N = 100;	// upper limit
	
	std::vector<ul> primes;
	SieveOfEratosthenes(primes, N+2); // prepare a vector of primes
	
	// outer loop selects primes <= N
	// inner loop enumerates powers of prime <= N
	ul S = 0;
	for(auto p = primes.begin(); p != primes.end(); ++p){
		const ul Prime = *p;
		if(Prime > N) break;
		std::cout<<"Prime: "<<Prime<<std::endl;
		ul start = Prime;
		ul modulus = Prime*Prime;
		do{
			for(auto n = start; n <= N; n += start){
				if((n % (modulus))==0) continue;
				cout<<n<<" ";
				S += Prime;
			}
			NL;
			modulus *= Prime;
			start *= Prime;
		}while(modulus <= N);
	} // for p...
	std::cout << "S(" << N << ") = " << S << std::endl;
	return 0;
}

