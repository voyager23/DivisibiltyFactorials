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
	
	temp.push_back({0,0});
	db.push_back(temp);
	db.push_back(temp);
	temp.clear();
	
	cout<<"Starting database at 2"<<endl;
	for(ul n = 2; n <= 100; ++n){
		// generate the prime description of n
		vd.clear();
		generate_descriptors(primes, n, vd);
		// make a copy of last entry in database
		temp = db.back();
		// for each prime in vd:
		//		if prime in temp - add new power to existing
		//			else - create new descriptor in temp
		// 
		// db.push_back(temp)
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
	NL;
}
