
#include "htable.h"

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters

int HT::hash(const string &s) {
  int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');

  return n % hsize;
}

/*
* Default constructor
******************************************************************************/
HT::HT(const unsigned &hs)
{
	hTable.resize(hs);
	hsize = hs;
}

/*
* Destructor
******************************************************************************/
HT::~HT()
{
	hTable.clear();
	pTable.clear();
}

/*
* Insert Function
*
* inserts the record of the item e:(key, desc, num) into the hash table
* prints an error message if the key already exists in the table, otherwise
* prints the index value of the inserted record and inserts the address of
* the record into the pointer table
******************************************************************************/
void HT::insert(const Entry &e)
{
	int pos = hash(e.key);
	list<Entry> &l = hTable[pos];

	auto look = find_if(l.begin(), l.end(), [e](const Entry& x){ return x.key == e.key; });

	if(look != l.cend())
	{
		cout << " not inserted - duplicate key!!!" << endl;
	}

	else
	{
		cout << " entry =  " << setw(2) << left << pos << endl;

		hTable[pos].push_front(e);
		pTable.push_back(&hTable[pos].front());
	}
}

/*
* Search Function
*
* searches the hash table for a record with the string key.
* prints the information of the searched record, otherwise prints an error
* message if the key is not in the hash table
******************************************************************************/
void HT::search(const string &key)
{
	int pos = hash(key);
	list<Entry> &l = hTable[pos];

	auto look = find_if(l.begin(), l.end(), [key](const Entry& x){ return x.key == key; });

	if(look != l.cend())
	{
		cout << " ==> number: " << setw(4) << right << look->num << " - item:" << look->desc << endl;
	}

	else
	{
		cout << " not in table!!" << endl;
	}
}

/*
* Hash table print
*
* prints the subscript and contents of all the active records in the hash table
* along with printing formatting
******************************************************************************/
void HT::hTable_print()
{
	cout << endl;

	for(unsigned int i = 0; i < hTable.size(); i++)
	{
		if(!hTable[i].empty())
		{
			for(auto it = hTable[i].begin(); it != hTable[i].end(); it++)
			{
				cout << setw(4) << left << i << ":" << it->key << setw(6) << right << " - " << setw(4) << left << it->num << setw(6) << internal << " -  ";
				cout << left << it->desc << endl;
			}
		}
	}
}

/*
* Compare test function
*
* returns true if the key of the item in location p comes before the item in
* location q in alphabetical order
******************************************************************************/
bool cmp(Entry *p, Entry *q)
{
	return (p->key.compare(q->key) < 0);
}

/*
* Pointer table print
*
* prints the contents of all the active records in the hash table in
* alphabetical order using the STL sort() and cmp() functions to sort by key
******************************************************************************/
void HT::pTable_print()
{
	sort(pTable.begin(), pTable.end(), cmp);

	for(unsigned int i = 0; i < pTable.size(); i++)
	{
		cout << setw(6) << right << pTable[i]->key << "  - " << setw(5) << right << pTable[i]->num << "  -  " << pTable[i]->desc << endl;
	}
}
