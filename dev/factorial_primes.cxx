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
using namespace std;
#include "../inc/toolbox.hxx"

// Describe each factorial by a vector of prime,power pairs
// entries 0,1 empty
// 2! = {2,1}
// 3! = 3 * 2! = {3,1} + {2,1}
// 4! = 4 * 3! = {3,1} + {2,2}

int main(int argc, char **argv)
{
	const ul n = 1000; //10^8 requires about 9 seconds
    std::vector<ul> primes;
    SieveOfEratosthenes(primes,n);
	Vdescriptors vd;
	Vdescriptors temp ;
	Database db;
	temp.push_back({2,1});
	db.push_back(temp);
	temp.clear();
	
	cout<<"Starting database at n=3"<<endl;
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
	
	// DEBUG print of database
	ul fact1 = 4;
	ul range = 3;
	auto a = db.begin()+fact1-2;
	auto b = a + range;
	while(a < b){
		for(auto g = a->begin(); g != a->end(); ++g) printf("{%u,%u} ", g->first,g->second);
		NL;
		++a;
	}
	// end debug section
	
	// load vector temp with test query
	temp = db[3]; // 5! { {5,1}, {3,1}, {2,3} }
	// phase 1 - scan up for first vector with largest prime
	a = db.begin();
	while(a != db.end()){
		if ((a->back()).first ==temp.back().first) break;
		++a;
	}
	if(a == db.end()){
		cout << "Query not found" << endl;
	} else {
		cout << "High prime found." << endl;
	}
	for(auto g = a->begin(); g != a->end(); ++g) printf("{%u,%u} ", g->first,g->second);
	NL;
	// phase 2 - use cmp_groups to locate first factorial which is divisible by n
	NL;
}
