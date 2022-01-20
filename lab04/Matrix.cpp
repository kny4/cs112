/* Matrix.cpp defines Matrix class methods.
 * Team Member 1: Sadie Kornoelje smk92
 * Team Member 2: Kelsey Yen kny4
 * Date: March 3, 2020
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "Matrix.h"

// Default Constructor
Matrix::Matrix() {
	myRows = myColumns = 0;
}

// Explicit Constructor
Matrix::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}

// Subscript Operator (writeTo)
Vec<Item>& Matrix::operator[](unsigned index) {
	if (index >= myRows) {
		throw range_error("index is too large");
	}
	return myVec[index];
}

// Subscript Operator (readFrom)
const Vec<Item>& Matrix::operator[](unsigned index) const {
	if (index >= myRows) {
		throw range_error("index is too large");
	}
	return myVec[index];
}

// Equality
bool Matrix::operator==(const Matrix& m2) const {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return false;
	} else {
		return myVec == m2.myVec;
	}
}

//Inequality
bool Matrix::operator!=(const Matrix& m2) const {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return true;
	} else {
		return myVec != m2.myVec;
	}
}
