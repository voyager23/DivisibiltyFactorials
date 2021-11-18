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
//......................................................................
void prt_map(MapFactN mfn);
void prt_map(MapFactN mfn){
	
	for(auto i = mfn.begin(); i != mfn.end(); ++i){
		printf("s(%lu): ", i->first);
		for(auto j = i->second.begin(); j != i->second.end(); ++j)
			printf("%lu ", *j);
		NL;
	}
}
//......................................................................
void add_map(MapFactN &map, ul s, ul m);
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
	std::map<PrimePower, ul, cmp_mapkeys> cache;	// map a prime-power pair to smallest factorial
	
    std::vector<ul> primes;
    SieveOfEratosthenes(primes,N+2);	// ensure all relevant primes are included
    
	// add some values to the cache for testing
	for(auto i = primes.begin(); i != primes.end(); ++i){
		ul p_bar = *i;
		ul power = 1;
		while( 1 ){
			PrimePower pp = std::pair<ul,ul>{*i,power};
			ul sf = fsf_v2(pp, cache);
			power += 1;
			p_bar *= *i;
			if(p_bar > N) break;
		}
	}		 

	for(auto c = cache.begin(); c != cache.end(); ++c)
		cout<<c->first.first<<","<<c->first.second<<" : "<<c->second<<endl;
    NL;
}

