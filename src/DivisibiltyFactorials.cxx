/*
 *DivisibilityFactorials.cxx
 * 
 * Copyright 2021 Michael Tate <mike@Michaels-MBP>
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
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

#define VERBOSE 1

#include "../inc/toolbox.hxx"

/*
 * 61756338
 * 47624262
 * 47441580
 * 41952751
 * 30140354
 * 16275126
 * 95917269
 * 29299552
 * 34988785
 * 61762778
 */

int main(int argc, char **argv)
{
	
	const ul n = 1000; // high prime
	const ul hi_fact = 1000;
    std::vector<ul> primes;
    SieveOfEratosthenes(primes,n);
	PfactOfN vd;
	PfactOfN temp ;
	vector<PfactOfN> db;
	temp.push_back({2,1});	//2!
	db.push_back(temp);
	temp.clear();
	
	cout<<"Constructing database to "<<hi_fact<<"!"<<endl;
	for(ul m = 3; m <= hi_fact; ++m){
		// generate the prime description of m
		vd.clear();
		generate_descriptors(primes, m, vd);
		temp = db.back();	// setup temp variable
		for(auto a = vd.begin(); a != vd.end(); ++a){
			// pair<prime,power>
			auto b = temp.begin();
			while(b != temp.end()){
				if (b->first == a->first) break;
				++b;
			}
			if(b != temp.end()){	// found prime
				b->second += a->second;
			} else {					// new prime,power pair
				temp.push_back(*a);
			}
		} // for a...
		db.push_back(temp);
	} // for m=3...
	
	
#if(VERBOSE)
	ul fact1 = 2;
	ul range = 50;
	auto a = db.begin()+fact1-2;
	auto b = a + range;
	while(a < b){
		printf("%llu! = ", fact1);
		for(auto g = a->begin(); g != a->end(); ++g) printf("{%u,%u} ", g->first,g->second);
		NL;
		++a;
		++fact1;
	}
#endif
	
	const uint trials = 400;
	std::array<std::vector<uint>,trials> aSn;	// associate s(n) with multiple values of n
	for(uint n = 2; n <= trials; n++){
		vd.clear();
		generate_descriptors(primes, n, vd);
		aSn[find_smallest_factorial(db, vd)-2].push_back(n);
	}
	for(auto idx = 0; idx < trials; ++idx){
		if(!aSn[idx].empty()){
			printf("s(%u): ", idx+2);
			for(auto i = aSn[idx].begin(); i != aSn[idx].end(); ++i) printf("%u ", *i);
			NL;
		}
	}
	
	vd.clear();
	generate_descriptors(primes,35,vd);
	printf("s(35) = %u\n", find_smallest_factorial(db,vd) );
	
	vd.clear();
	generate_descriptors(primes,36,vd);
	printf("s(36) = %u\n", find_smallest_factorial(db,vd) );
	
	vd.clear();
	generate_descriptors(primes,198,vd);
	printf("s(198) = %u\n", find_smallest_factorial(db,vd) );
	
} // end

