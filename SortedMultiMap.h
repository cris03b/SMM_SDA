#pragma once
//DO NOT INCLUDE SMMITERATOR

//DO NOT CHANGE THIS PART
#include <vector>
#include <utility>
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);
using namespace std;
class SMMIterator;
typedef bool(*Relation)(TKey, TKey);


class SortedMultiMap {
    friend class SMMIterator;
private:
    //TODO - Representation

    // Element contine: key = cheia elm, size = lungimea vectorului de valori a cheii, val = vectorul dinamic de valori
    // T = hashtable (vectorul dinamic in care sunt elementele de tip Element)
    // m = cap, first_empty = prima poz libera din tabel, head_slla = head pt vectorul next_slla, length = lungime container, rel = relatie
    // next = vector pt coalesced Verkettung, next_slla = vector pt ordinea in functie de relatie
    // h(key) = functia de hash

    struct Element {
        TKey key;
        int size;
        TValue* val;
    };

    Element* T;
    int m, pos, first_empty, head_slla, length;
    int* next, * next_slla;
    Relation rel;
    

    int h(TKey key) {
        return key % m;
    }


public:

    // constructor
    SortedMultiMap(Relation r);

    void resize_rehash();

    //adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);

    //returns the values belonging to a given key
    vector<TValue> search(TKey c);

    //removes a key value pair from the sorted multimap
    //returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	
    SMMIterator iterator() const;

    vector<TElem> alle_paare();

    // destructor
    ~SortedMultiMap();
};

