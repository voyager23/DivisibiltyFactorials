/*
 * factorial_primes.cxx
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
using namespace std;

#define VERBOSE 1

#include "../inc/toolbox.hxx"

// Describe each factorial by a vector of prime,power pairs
// entries 0,1 empty
// 2! = {2,1}
// 3! = 3 * 2! = {3,1} + {2,1}
// 4! = 4 * 3! = {3,1} + {2,2}

int main(int argc, char **argv)
{
	const ul n = 1000; //10^8 requires about 9 seconds
	const ul hi_fact = 1000;
    std::vector<ul> primes;
    SieveOfEratosthenes(primes,n);
	PfactOfN vd;
	PfactOfN temp ;
	vector<PfactOfN> db;
	temp.push_back({2,1});	//2!
	db.push_back(temp);
	temp.clear();
	
	cout<<"Starting database at 3!"<<endl;
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
	ul range = 40;
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
	
	// load vector temp with test query
	// 5! { {5,1}, {3,1}, {2,3} }
	// 9! { { {2,7} {3,4} {5,1} {7,1} }
	
	PfactOfN query = {  {2,19}, {23,1}  };

	uint sf = find_smallest_factorial(db, query);
	
	printf("sf = %u\n",sf);
	prt_pfofn(query);
	NL;
} // end

