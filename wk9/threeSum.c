#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"

// given an array of integers and a target sum S,
// determine whether the array contains two integers that sum to sum
// aim for O(n) average/expected time complexity
// worst case: O(n^2)
bool twoSum(int arr[], int size, int sum) {
	HashTable ht = HashTableNew();

	for (int i = 0; i < size; i++) {
		int other = sum - arr[i];
		if (HashTableContains(ht, other)) {
			return true;
		}
		HashTableInsert(ht, arr[i], arr[i]);
	}

	return false;
}

// given an array of integers and a target sum S,
// determine whether the array contains three integers that sum to S.
// aim for O(n^2) average/expected time complexity
bool threeSum(int arr[], int size, int sum) {
	HashTable ht = HashTableNew();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			int other = sum - arr[i] - arr[j];
			if (HashTableContains(ht, other)) {
				return true;
			}
			HashTableInsert(ht, arr[i], arr[i]);
			HashTableInsert(ht, arr[j], arr[j]);
		}
	}
	return false;
}
