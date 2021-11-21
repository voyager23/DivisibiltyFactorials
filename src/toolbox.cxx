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
	printf("Starting Sieve for n = %lu\n",n);
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

ul fsf(ul prime, ul power){
	ul result = 0;
	
	ul factorial = prime*power;	// initial guess at factorial	
	while(factorial>1){
		ul sum = 0;
		ul p_dash = prime;
		result = (ul)(factorial/p_dash);
		while(result > 0){
			sum += result;
			p_dash *= prime;
			result = (ul)(factorial/p_dash);
		}
		if(sum == power) return factorial;
		
		// New Line
		if(sum < power) return (factorial+prime);
		// --------
		
		factorial -= prime;
	}
	return 0;
}


void prt_map(MapFactN mfn){
	
	for(auto i = mfn.begin(); i != mfn.end(); ++i){
		printf("s(%lu): ", i->first);
		for(auto j = i->second.begin(); j != i->second.end(); ++j)
			printf("%lu ", *j);
		NL;
	}
}
ul fsf_v2(PrimePower pp, std::map<PrimePower, ul> &cache){
	// search cache for existing solution for PrimePower
	// if found:
	//		return existing solution
	// else:
	//		calc new solution
	//		add new solution to cache
	//		return new solution
	std::map<PrimePower, ul>::iterator it = cache.find(pp);
	if(it != cache.end()) return it->second;
	
	ul prime = pp.first;
	ul power = pp.second;
	ul result = 0;
	ul factorial = prime*power;	// initial guess at factorial	
	while(factorial>1){
		ul sum = 0;
		ul p_dash = prime;
		result = (ul)(factorial/p_dash);
		while(result > 0){
			sum += result;
			p_dash *= prime;
			result = (ul)(factorial/p_dash);
		}
		
		if(sum == power){
			cache.insert(std::pair< std::pair<ul,ul>, ul>({{prime,power}, factorial}));
			return factorial;
		}

		if(sum < power){
			cache.insert(std::pair< std::pair<ul,ul>, ul>({{prime,power}, factorial+prime}));
			return (factorial+prime);
		}
		
		factorial -= prime;
	}
	return 0;
}


//-------------------Test code------------------
#if(0)

int main(void) {
	const ul n = 10000; // high prime
	// expected result 10125843
    std::vector<ul> primes;
    
    SieveOfEratosthenes(primes,n+2);
	std::map<PrimePower, ul> cache;
	PfactOfN pfn;	// vector of prime/powers
	ul sum = 0;
	for(ul m = 2; m <= n; ++m){
		generate_descriptors(primes, m, pfn); // clears pfn on entry
		ul max = 0;
		for(auto pp = pfn.begin(); pp != pfn.end(); ++pp){
			ul s = fsf_v2(*pp, cache);
			if(s > max) max = s;
		}
		sum += max;
	}
	NL;
	std::cout<<"Sum = "<<sum<<std::endl;
}
#endif


