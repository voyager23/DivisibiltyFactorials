/*
 * toolbox.hxx
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
#include <numeric>
#include <array>
#include <vector>

#ifndef __TOOLBOX_HXX__
#define __TOOLBOX_HXX__

	#define NL std::cout<<std::endl
	
	typedef uint64_t ul;
	typedef struct{
		ul prime;
		ul power;
		ul product;
	}PPP;
	 
	void SieveOfEratosthenes(std::vector<ul> &primes, ul n);
	void find_factors(std::vector<ul> &primes, ul n, std::vector<ul> &factors);
	void generate_factorials(std::vector<ul> &factorials);
		
#endif
