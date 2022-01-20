/* array.cpp defines "C style" array operations
 * Name: Kelsey Yen, kny4
 * Partner: Daniel Luce, drl7
 * Date: 02-17-20
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "array.h"

void initialize(double *a, unsigned size) {
	int val = 0;
	for (unsigned i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}

void print(double *a, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}		

double average(double *a, unsigned size) {
	double sum = 0;
	for( unsigned i = 0; i < size; i++) {
		sum += *a;
		a++;
	}
	return sum / size;
}

double sum(double *a, unsigned size) {
	double sum = 0;
	for( unsigned i = 0; i < size; i++) {
		sum += *a;
		a++;
	}
	return sum;
}

void read(istream & in, double *&a, unsigned size) {

}

void fill(const string& fileName, double *&a, unsigned &numValues) {

}

void resize(double *&a, unsigned oldSize, unsigned newSize) {

}

void concat(double *a1, unsigned size1, double *a2, unsigned size2, double *&a3, unsigned &size3) {

}
