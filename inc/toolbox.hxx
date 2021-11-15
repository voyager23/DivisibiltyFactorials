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
#ifndef __TOOLBOX_HXX__
#define __TOOLBOX_HXX__
#include <iostream>
#include <numeric>
#include <array>
#include <vector>
#include <utility>
#include <map>

	#define NL std::cout<<std::endl
	
	typedef uint64_t ul;
	// Describe n! as sequence of prime powers
	typedef std::pair<uint,uint> PrimePower;
	typedef std::vector<PrimePower> PfactOfN;  // describes the prime powers of a factorial
	
	typedef std::pair<ul, std::vector<ul>> MapType;
	typedef std::map<ul, std::vector<ul>> MapFactN;	// map a smallest factorial to a vector of corresponding values of n
	
	void SieveOfEratosthenes(std::vector<ul> &primes, ul n);
	void find_factors(std::vector<ul> &primes, ul n, std::vector<ul> &factors);
	void generate_factorials(std::vector<ul> &factorials);
	void generate_descriptors(std::vector<ul> &primes, ul n, PfactOfN &PfactOfN);
	bool cmp_PrimePowers(PrimePower &l, PrimePower &r);
	void prt_pfofn(PfactOfN &pf);
	uint find_smallest_factorial(std::vector<PfactOfN> &db, PfactOfN &query);
	uint fsf(uint prime, uint power);	// replacement for find_smallest_factorial()
	
#endif
