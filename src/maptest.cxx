/*
 * maptest.cxx
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
 * Test harness for using std::map
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

void add_map(MapFactN &map, ul s, ul m);

void prt_map(MapFactN mfn){
	
	for(auto i = mfn.begin(); i != mfn.end(); ++i){
		printf("s(%lu): ", i->first);
		for(auto j = i->second.begin(); j != i->second.end(); ++j)
			printf("%lu ", *j);
		NL;
	}
}

void add_map(MapFactN &mfn, ul s, ul m){
    MapFactN::iterator working = mfn.find(s);
    if(working == mfn.end()){
		// new value
		MapType temp {s, std::vector<ul> {m} };
		mfn.insert(temp); 
	} else { // add to vector
		working->second.push_back(m);
	}	
}

//----------------------------------------------------------

int main(int argc, char **argv)
{
	const ul N = 100;	//consider 2 <= n <= N
    std::vector<ul> primes;
    SieveOfEratosthenes(primes,N);
    ul n;
    PfactOfN pfn;
    ul sum = 0;
    uint max, sf;
    for(n = 2; n <= N; ++n){
		generate_descriptors(primes, n, pfn);
		max = 0;
		for(auto d = pfn.begin(); d != pfn.end(); ++d){
			sf = fsf(d->first, d->second);
			if(sf > max) max = sf;
		}
		printf("s(%lu) = %u", n, sf);
		NL;	
		sum += max;
	}
	printf("S(%lu) = %lu\n", N, sum);
	
		
#if(0)  
    MapFactN mfn;
    MapFactN::iterator working;
    // add test values
	add_map(mfn, 9, 27);
	add_map(mfn, 10, 25);
	add_map(mfn, 11,11);
	
	add_map(mfn, 9, 81);
	add_map(mfn, 11,33);
	
	add_map(mfn, 9, 54);
	add_map(mfn, 10, 50);
	add_map(mfn, 11,22);
	
	prt_map(mfn);
#endif

    NL;
}

