/*
 * list11.cxx
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
 * listing of multiples of 11, 11^2, 11^3 etc up to 1000
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

int main(int argc, char **argv)
{
	const ul N = 470;	// upper limit
	ul n; //working variable
	for(n = 11; n < N; n += 11){
		if((n % (11*11))==0) continue;
		cout<<n<<" ";
	}
	NL;
	for(n = (11*11); n < N; n += (11*11)) cout<<n<<" ";
	NL;
	return 0;
}

