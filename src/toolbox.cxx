/*
 * toolbox.cxx
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

#include "../inc/toolbox.hxx"

void SieveOfEratosthenes(std::vector<ul> &primes, ul n)
{
	printf("Starting Sieve for n = %llu\n",n);
    // internal vector of bool
    std::vector<bool> prime;
    // Set n+1 entries in vector<bool> to true
    for(ul c = 0; c != n+1; ++c) prime.push_back(true);

    for (ul p = 2; p * p <= n; p++)
	{
		// If prime[p] is not changed,
		// then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples
			// of p greater than or
			// equal to the square of it
			// numbers which are multiples
			// of p and are less than p^2
			// are already been marked.
			for (ul i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
    primes.clear();
    for(ul pn = 2; pn != n+1; ++pn) if(prime[pn]) primes.push_back(pn);
    printf("Completed Sieve\n");
}

void find_factors(std::vector<ul> &primes, ul n, std::vector<ul> &factors){
	factors.clear();
	for(auto i = primes.begin(); i != primes.end(); ++i){
		ul p = *i;
		if(p > n) break;
		while((n % p)==0){
			factors.push_back(p);
			n /= p;
		}
	}
}

void generate_factorials(std::vector<ul> &factorials){
	// assume a machine limit of 20! based on 64-bit unsigned
	const ul limit = 20;
	factorials.clear();
	ul m = 1;
	factorials.push_back(m);
	factorials.push_back(m);
	for(ul n = 2; n <= limit; ++n){
		m *= n;
		factorials.push_back(m);
	}
}
		
void generate_descriptors(std::vector<ul> &primes, ul n, PfactOfN &PfactOfN){
	// Generates a vector of descriptors for integer n. Each element is a pair<prime, power>
	PrimePower temp;
	PfactOfN.clear();
	for(auto i = primes.begin(); i != primes.end(); ++i){
		ul p = *i;
		if(p > n) break;
		temp = {p,0};
		while((n % p)==0){
			temp.second += 1;
			n /= p;
		}
		// save <prime,power> to vector
		if(temp.second > 0) PfactOfN.push_back(temp);
	}
}

bool cmp_PrimePowers(PrimePower &ref, PrimePower &query){
	// Compare prime and power in each PrimePower
	// return true iff (ref.prime==query.prime)AND(ref.power>=query.power)
	return ((ref.first==query.first)&&(ref.second>=query.second));
}

void prt_pfofn(PfactOfN &pf){
	for(auto pp = pf.begin(); pp != pf.end(); ++pp) printf("{%u, %u} ", pp->first, pp->second);
	NL;
}

uint find_smallest_factorial(std::vector<PfactOfN> &db, PfactOfN &query){
	uint row,col;
	PfactOfN::iterator i_col, i_pp;
	bool solution;
	PrimePower hi_prime = query.back();
	// find the starting row,col in database
	row = 0;
	while(db[row].back().first < hi_prime.first) ++row;
	col = db[row].size() - 1;
	while (db[row][col].second < hi_prime.second) ++row;
	
	// scan db forward for row which has prime powers >= query
	for(auto idb = std::next(db.begin(),row); idb != db.end(); ++idb){
		solution = true;
		for(i_pp = query.begin(); ((solution)and(i_pp != query.end())); ++i_pp){	// stops if no solution for this row
			for(i_col = idb->begin(); ((solution)and(i_col != idb->end())); ++i_col){	// stops if no solution for this row
				if(i_col->first != i_pp->first) continue;	// select matching primes
				if(i_col->second < i_pp->second) solution = false;
			}
		}
		if(solution) return (std::distance(db.begin(), idb) + 2);
	}	
	return 0;
}
	




#if(0)
int main(void) {
    std::vector<ul> primes;
    const ul n = 100000000; //10^8 requires about 9 seconds
    SieveOfEratosthenes(primes,n);
    //for(auto pf = primes.begin(); pf != primes.end(); ++pf) printf("%lu  ", *pf);
    //NL;
 
}
#endif


