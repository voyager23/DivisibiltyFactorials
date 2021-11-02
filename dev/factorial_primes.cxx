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

/*
 *  12!    = 479001600
 *  10^8 = 100000000
 *  11!    =   39916800
*/

int main(int argc, char **argv)
{
	// test data
	const ul fact19 = 121645100408832000;
	// end test
	
	const ul n = 12; 
    std::vector<ul> primes;
    SieveOfEratosthenes(primes,n);
	PfactOfN vd;
	PfactOfN temp ;
	vector<PfactOfN> db;
	temp.push_back({2,1});	//2!
	db.push_back(temp);
	temp.clear();
	
	cout<<"Constructing database from 2! to "<<n<<"!"<<endl;
	for(ul n = 3; n <= 100; ++n){
		// generate the prime description of n
		vd.clear();
		generate_descriptors(primes, n, vd);
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
	} // for n=3...
	
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
	
	PfactOfN query = {  {2,19}, {5,7}, {13,3}, {23,1}  };

	uint sf = find_smallest_factorial(db, query);
	
	printf("sf = %u\n",sf);
	prt_pfofn(query);
	NL;
} // end

