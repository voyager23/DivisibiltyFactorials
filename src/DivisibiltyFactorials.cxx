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

using namespace std;

#define VERBOSE 0

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
	const ul n = 10000; // high prime
	const ul hi_fact = 10000;
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
	
	//std::vector<ul> Queries = {61756338,47624262,47441580,41952751,30140354,16275126,95917269,29299552,34988785,61762778};
	std::vector<ul> Queries = {9329,6417,4296,8978,4182,7192,3185,6219,8004,7441};
	for(auto iq = Queries.begin(); iq != Queries.end(); ++iq){
		
		std::cout<<*iq<<std::endl;
		
		vd.clear();
		generate_descriptors(primes, *iq, vd);
		uint sf = find_smallest_factorial(db, vd);
		prt_pfofn(vd);
		NL;
		printf("sf = %u\n",sf);
		NL;
		prt_pfofn(db[sf]);
		NL;

	}
} // end

