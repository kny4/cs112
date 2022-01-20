/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Team Member 1: Sadie Kornoelje smk92
 * Team Member 2: Kelsey Yen kny4
 * Date: March 3, 2020
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include "Vec.h"

typedef double Item;

class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	unsigned getRows() const { return myRows; }
	unsigned getColumns() const { return myColumns; }
	const Vec<Item>& operator[](unsigned index) const;
	Vec<Item>& operator[](unsigned index);
	bool operator==(const Matrix& m2) const;
	bool operator!=(const Matrix& m2) const;

private:
	unsigned         myRows;
	unsigned         myColumns;
	Vec< Vec<Item> > myVec;

	friend class MatrixTester;
};



#endif
