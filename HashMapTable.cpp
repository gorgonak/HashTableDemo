#include "HashMapTable.h"

HashMapTable::HashMapTable()
{
	ht = new HashTableEntry * [T_S]; // reserving memory addresses for the array of hash table entries with a size of T_S

	for(int i = 0; i < T_S; i++)
	{
		ht[i] = NULL;
	}	
}

int HashMapTable::HashFunction(int key) // this determines the total size of our hash table using T_S as the variable.
{
	return key % T_S;
}

void HashMapTable::Insert(int k, string v)
{
	int hash_val = HashFunction(k); // getting hash value

	HashTableEntry* p = NULL; // p = previous
	HashTableEntry* en = ht[hash_val];  // entry set to the current position in the hash table by running the hash function on the key supplied

	while (en != NULL) // this will help us loop through our chain
	{
		p = en;
		en = en->n;
		
	}
	if (en == NULL)  // if there is no current entry, create a new one
	{
		en = new HashTableEntry(k, v);
		if (p == NULL)
		{
			ht[hash_val] = en;
		}
		else
			p->n = en;
	}
	else
		en->v = v;
	
}

void HashMapTable::SearchKey(int k)
{
	int hash_val = HashFunction(k);
	bool flag = false;  // using the boolean as a trigger if the key value is found or not.

	HashTableEntry* en = ht[hash_val];  // sets the value we are looking for in the hash table

	if (en != NULL)
	{
		while (en != NULL)  // loops through our hash until we find the hash value we are looking for. 
		{
			if (en->k == k)
			{
				flag = true;
			}
			if (flag)
			{
				cout << "ELEMENT FOUND AT KEY: " << k <<  endl;
				cout << en->v << endl;
			}
			en = en->n;
			
		}
	}
	if(!flag)  // if you cannot find the key then it notifies the user
	{
		cout << "ELEMENT NOT FOUND WITH KEY: " << k << endl;
	}
	
}

void HashMapTable::Remove(int k)   // optional remove function for hash table
{
	int hash_val = HashFunction(k);
	HashTableEntry* en = ht[hash_val];
	HashTableEntry* p = NULL;
	
	if (en == NULL || en->k != k)  // if the key cannot be found it notifies the user
	{
		cout << "NO ELEMENT FOUND AT KEY: " << k << endl;
		return;
	}
	while (en->n != NULL)
	{
		p = en;
		en = en->n;
	}
	if (p != NULL)
	{
		p->n = en->n;
	}
	
	delete en;  // when we finally find the value we are looking for, we delete it.
	
	cout << "ELEMENT DELETED" << endl;
}


HashMapTable::~HashMapTable()  // free up memory 
{
	delete[] ht;
}


