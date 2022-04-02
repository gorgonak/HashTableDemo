#pragma once
#include <iostream>
#include <string>


using namespace std;

struct HashTableEntry
{
	int k; // key
	string v; // value

	HashTableEntry* n; // next

	HashTableEntry(int k, string v)
	{
		this->k = k; // key
		this->v = v; // value
		this->n = NULL; // next
	}
	
	
};

