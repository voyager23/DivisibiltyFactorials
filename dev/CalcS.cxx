/*
 * CalcS.cxx
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
 * MA 02110-1301, USA.
 * 
 * Considering numbers 2 <= i <= 10^8
 */

using namespace std;

#include <iostream>
#include <vector>
#include <iterator>

#include "../inc/toolbox.hxx"

int main(int argc, char **argv)
{
	const ul N = 100;
	
	vector<ul> factors;	// holds prime factors for a single integer
	vector<ul> factorials;
	vector<ul> primes;
	SieveOfEratosthenes(primes, N);
	ul S = 0;	// Sum of s(i). S(100) = 2012

	// vector of prime,power,product for 2 <= i <= 100
	vector<PPP> v_p3;
	PPP p3;
	PPP greatest_product;
	for(ul n = 2; n <= N; ++n){
		find_factors(primes,n,factors);	// 2,2,3,13...
		// remap factors vector to struct PPP
		vector<ul>::iterator i = factors.begin();
		vector<ul>::iterator j;
		v_p3.clear();
		greatest_product = {0,0,0};
		while(i != factors.end()){
			p3 = {*i, 0, 0};
			j = i;
			while((j != factors.end())&&(*i == *j)){
				p3.power += 1;
				++j;
			}
			p3.product = p3.prime*p3.power;
			if(p3.product > greatest_product.product) greatest_product = p3;		
			v_p3.push_back(p3);
			i = j;
		} // while i
		// debug print the values of n & v_p3
		cout << "\nN:" << n << endl;
		//for(auto i = v_p3.begin(); i != v_p3.end(); ++i) cout << "{" << i->prime << "," << i->power << "," << i->product << "}\n";
		cout << "{" << greatest_product.prime << "," << greatest_product.power << "," << greatest_product.product << "}\n";
		S += greatest_product.product;
	} // while n...
	cout << "S(" << N << ") = " << S << endl;
} // end main

