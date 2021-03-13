#pragma once
#include "SortedMultiMap.h"


class SMMIterator {
	friend class SortedMultiMap;
private:
	//DO NOT CHANGE THIS PART
	const SortedMultiMap& map;
	SMMIterator(const SortedMultiMap& map);

	//TODO - Representation
	
	SortedMultiMap::Element* elm;
	int* next_v;
	int current_pos, key_pos, first_pos;

public:
	void first();
	void next();
	bool valid() const;
	TElem getCurrent() const;
};

