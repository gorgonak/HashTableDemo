#pragma once
#include "HashTableEntry.h"


const int T_S = 193; // initializing our table at 193 (prime numbers help eliminate the number of collisions which in turn helps efficiency)

class HashMapTable
{
public:
	HashTableEntry** ht, ** top;
	HashMapTable();
	int HashFunction(int key); // need a hash function to have a functional hash table
	void Insert(int k, string v);
	void SearchKey(int k);
	void Remove(int k);
	~HashMapTable();  // clean up
	
};


// check HashMapTable.cpp for further comments