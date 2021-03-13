#include "SMMIterator.h"
#include "SortedMultiMap.h"

//theta(1)
SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d) {
	//TODO - Implementation
	next_v = d.next_slla;
	current_pos = 0;
	key_pos = d.head_slla;
	first_pos = d.head_slla;
	elm = d.T;
}

//theta(1)
void SMMIterator::first() {
	//TODO - Implementation
	if (valid()) {
		current_pos = 0;
		key_pos = first_pos;
	}
}

//theta(1)
void SMMIterator::next() {
	//TODO - Implementation
	if (valid()) {
		if (current_pos == elm[key_pos].size - 1) {
			// a ajuns la sf vectorului de valori => trece la urm cheie
			key_pos = next_v[key_pos];
			current_pos = 0;
		}
		else {
			current_pos++;
		}
	}
}

//theta(1)
bool SMMIterator::valid() const {
	//TODO - Implementation
	if (key_pos < 0) {
		return false;
	}
	return true;
}

//theta(1)
TElem SMMIterator::getCurrent() const {
	//TODO - Implementation
	TElem elem;
	if (valid()) {
		elem.first = elm[key_pos].key;
		elem.second = elm[key_pos].val[current_pos];
		return elem;
	}
	return NULL_TELEM;
}


