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
	Database db;
	cout<<"Starting database"<<endl;
	for(ul n = 0; n <= 100; ++n){
		vd.clear();
		generate_descriptors(primes, n, vd);
		db.push_back(vd);
	}
    NL;
    int idx = 0;
    for(auto a = db.begin(); a != db.end(); ++a){
		printf("N:idx%u", idx);
		NL;
		for(auto b = a->begin(); b != a->end(); ++b){
			printf("prime:%u  power:%u\n", b->first, b->second);
		}
		NL;
		idx++;
	}
    
}
