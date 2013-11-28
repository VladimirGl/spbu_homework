#ifndef ZEROSINARRAY_H
#define ZEROSINARRAY_H

/// Amazing function to calculate the number of zeros in array.
static int countZeros(const int* array, const int& size) {
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (array[i] == 0) {
			count++;
		}
	}

	return count;
}

#endif // ZEROSINARRAY_H
