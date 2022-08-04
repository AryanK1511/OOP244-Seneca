// Name: Aryan Khurana
// ID: 145282216
// Email: akhurana22@myseneca.ca
// Date: 03/08/2022
// Section: NDD

#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_
#include <iostream>
#include "Collection.h"

namespace sdds {
	// Find with 3 parameters
    // Function template to check if a key value matches an array item at a provided index Arguments
	template <typename type1, typename type2>
	bool find(type1 arr[], type2 key, int index) {
        return (arr[index] == key);
    }

	// Find with 4 parameters
    // Goes through all the elements of the array of objects checks if the keys are comparable to the array object
    template <typename type1, typename type2, typename type3>
    int find(const type1 arg1[], int numberOfElements, const type2 arg2, const type3 arg3) {
        int i, result = -1, flag = 1;
        for (i = 0; i < numberOfElements && flag == 1; i++) {
            if ((arg1[i] == arg2) && (arg1[i] == arg3)) {
                result = i;
                flag = 0;
            }
        }

        return result;
    }

	// Insertion operator overload
    // Iterate over every item in the collection and insert it and an endl into the ostream parameter.
    template <typename T>
	std::ostream& operator<<(std::ostream& os, Collection<T>& collection) {
        int i;
        for (i = 0; i < collection.size(); i++) {
            os << collection[i] << std::endl;
        }

        return os;
    }

	// Load Collection
    // It will call the overloaded += operator in the collections class to add the new item.
    template <typename type1>
    const Collection<type1>& loadCollection(Collection<type1>& collection, type1 obj) {
        collection += obj;
        return collection;
    }
}
#endif // !SDDS_SEARCH_H_

