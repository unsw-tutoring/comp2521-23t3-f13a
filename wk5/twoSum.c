#include <stdbool.h>
#include <stdio.h>

#include "BST.h"

// return whether there are two numbers in the array that sum to 'sum'
// n = size of the array
// O(n^2) solution
bool hasTwoSum(int *arr, int n, int sum) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] == sum) {
				return true;
			}
		}
	}
	return false;
}

// use a binary search tree
bool hasTwoSum(int *arr, int n, int sum) {
	// TODO
	BSTree bst = BSTNew();  // O(1)

	// O(n log n)
	for (int i = 0; i < n; i++) {  // n times
		BSTInsert(bst, arr[i]);    // O(log n)
	}

	// O(n log n)
	for (int i = 0; i < n; i++) {      // n times
		int target = sum - arr[i];     // O(1)
		if (BSTSearch(bst, target)) {  // O(log n)
			BSTFree(bst);
			return true;
		}
	}

	BSTFree(bst);
	return false;
}
