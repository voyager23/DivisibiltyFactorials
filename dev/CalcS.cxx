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
<<<<<<< HEAD
	const ul N = 100;
	
=======
	//const ul N = 100000000; 
	const ul N = 1000;	// restricted debug value
>>>>>>> 7f57ddc1fe81b0154b1c77a09707146b5e082581
	vector<ul> factors;	// holds prime factors for a single integer
	vector<ul> factorials;
	vector<ul> primes;
	SieveOfEratosthenes(primes, N);
<<<<<<< HEAD
	ul S = 0;	// Sum of s(i). S(100) = 2012
=======
	
	ul S = 0;
	
#if(0)	
	for(ul x = 2; x <= 10000; ++x){
		find_factors(primes, x, factors);

		cout << x << ":  ";
		for(auto f = factors.begin(); f != factors.end(); ++f)
			cout << *f << " ";
		NL;
	}
#endif

	// machine limit is 19!
	generate_factorials(factorials);
	// factorials printout
	NL;
	for(ul fc = 0; fc != factorials.size(); ++fc)
		cout << fc << "! = " << factorials[fc] << endl;
>>>>>>> 7f57ddc1fe81b0154b1c77a09707146b5e082581


	// vector of prime,power,pxp for 2 <= i <= 100
	vector<PPP> v_p3;
	PPP p3;
<<<<<<< HEAD
	PPP greatest_product;
	for(ul n = 2; n <= N; ++n){
=======
	PPP prod;
	for(ul n = 2; n <= 100; ++n){
>>>>>>> 7f57ddc1fe81b0154b1c77a09707146b5e082581
		find_factors(primes,n,factors);	// 2,2,3,13...
		// remap factors vector to struct PPP
		vector<ul>::iterator i = factors.begin();
		vector<ul>::iterator j;
		v_p3.clear();
		prod = {0,0,0};
		while(i != factors.end()){
			p3 = {*i, 0, 0};
			j = i;
			while((j != factors.end())&&(*i == *j)){
				p3.power += 1;
				++j;
			}
			p3.pxp = p3.prime*p3.power;
			if(p3.pxp > prod.pxp) prod = p3;		
			v_p3.push_back(p3);
			i = j;
		} // while i
		
		// debug print the values of n & v_p3
		cout << "\nN:" << n << endl;
		//for(auto i = v_p3.begin(); i != v_p3.end(); ++i) cout << "{" << i->prime << "," << i->power << "," << i->product << "}\n";
<<<<<<< HEAD
		cout << "{" << greatest_product.prime << "," << greatest_product.power << "," << greatest_product.product << "}\n";
		S += greatest_product.product;
=======
		cout << "{" << prod.prime << "," << prod.power << "," << prod.pxp << "}\n";
		S += prod.pxp;
		
		// DEBUG TESTING
		// if(prod <= 19) test divisibilty of n into vector of factorials 
		if(prod.pxp <= 19){
			for(size_t i = 2; i != factorials.size(); ++i){
				
				if((factorials[i] % n)==0){
					cout << i <<"! % "<< n << " = 0" << endl;
					if(i != prod.pxp) cout << "???" << endl;		
					break;
				}
				
			} // for...
		} // if...
			
>>>>>>> 7f57ddc1fe81b0154b1c77a09707146b5e082581
	} // while n...
	cout << "S(" << N << ") = " << S << endl;
} // end main

