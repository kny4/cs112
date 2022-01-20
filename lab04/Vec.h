/* Vec.h provides a simple vector class named Vec.
 * Team Member 1: Sadie Kornoelje smk92
 * Team Member 2: Kelsey Yen kny4
 * Date: March 3, 2020
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <stdexcept>
#include <cassert>
#include <fstream>
using namespace std;

template<class Item>

class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec<Item>& original);
	Vec<Item>& operator=(const Vec<Item>& original);
	virtual ~Vec();
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec<Item>& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	Item& operator[](unsigned i);
	const Item& operator[](unsigned i) const;
	bool operator!=(const Vec<Item>& v2) const;
	void readFrom(string fileName);
	void writeTo(string fileName);
	Vec<Item> operator+(const Vec<Item>& other);
	Vec<Item> operator-(const Vec<Item>& other);
	double operator*(const Vec<Item>& other);

private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};



/* Default Constructor
 * Postcondition: mySize = 0, myArray = NULL
 */
template <class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = NULL;
}

/* Explicit-Value Constructor
 * @param: unsigned size
 * Postcondition: mySize = size
 * 				 if size = 0, myArray = NULL
 * 				 if size > 0, myArray points to a dynamically
 * 				 allocated array of size mySize
 */
template <class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	if (size > 0) {
		myArray = new Item[size]();
	}
	else {
		myArray = NULL;
	}
}

/* Copy Constructor
 * @param: const Vec& orignal
 * Postcondition: A new Vec is created as a deep copy of original
 */
template <class Item>
Vec<Item>::Vec(const Vec<Item>& original) {
	unsigned size = original.mySize;
	mySize = size;

	if (size > 0) {
		Item * array = new Item[size]();
		for (unsigned i = 0; i < size; i++) {
			array[i] = original.myArray[i];
		}
		myArray = array;
	}
	else {
		myArray = NULL;
	}
}

/* Destructor
 * Postcondition: Memory at myArray is returned to the system
 * 				  mySize set to 0, myArray set to NULL
 */
template <class Item>
Vec<Item>::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}

/* Assignment Operator
 * @param: const Vec& orignal
 * Return: Vec on the left-hand side as a deep copy of original
 */
template <class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {

	if (this != &original) {
		if (original.mySize != mySize) {
			if (mySize > 0) {
				delete [] myArray;
				myArray = NULL;
			}
			if (original.mySize > 0) {
				Item * array = new Item[original.mySize]();
				myArray = array;
			}
			mySize = original.mySize;
		}
		for (unsigned i = 0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	}
	return *this;
}

/* Size Getter
 * Return: returns mySize
 */
template <class Item>
unsigned Vec<Item>::getSize() const {
	return mySize;
}

/* Item Setter
 * @param: unsigned index, const Item& it
 * Postcondition: value at index is set to it
 */
template <class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if (index >= mySize) {
		throw range_error("Index out of range");
	}
	else {
		myArray[index] = it;
	}
}

/* Item Getter
 * @param: unsigned index
 * Return: returns the value at index
 */
template <class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if (index >= mySize) {
		throw range_error("Index out of range");
	}
	else {
		return myArray[index];
	}
}

/* Size Setter
 * @param: unsigned newSize
 * Postcondition: mySize is set to newSize
 * 				  if mySize is 0, memory is deallocated and myArray is set to NULL
 * 				  new indices are set to 0, if any, and any indices past the new size are removed
 */
template <class Item>
void Vec<Item>::setSize(unsigned newSize) {
	if (mySize == newSize) {
		return;
	}
	if (newSize == 0) {
		mySize = 0;
		delete [] myArray;
		myArray = NULL;
	}
	else {
		Item * newArray = new Item[newSize]();
		if (newSize > mySize) {
			for (unsigned i = 0; i < mySize; i++) {
				newArray[i] = myArray[i];
			}
		}
		else {
			for (unsigned i = 0; i < newSize; i++) {
				newArray[i] = myArray[i];
			}
		}
		mySize = newSize;
		delete [] myArray;
		myArray = newArray;
	}
}

/* Equality Operator
 * @param: const Vec& v2
 * Return: True only if the vectors contain the same values and are the same size
 */
template <class Item>
bool Vec<Item>::operator==(const Vec& v2) const {
	if (mySize != v2.mySize) {
		return false;
	}
	for (unsigned i = 0; i < mySize; i++) {
		if (myArray[i] != v2.myArray[i]) {
			return false;
		}
	}
	return true;
}

/* Inequality Operator
 * @param: const Vec& v2
 * Return: True if the vectors are different sizes or contain different values
 */
template <class Item>
bool Vec<Item>::operator!=(const Vec<Item>& v2) const {
	if (mySize != v2.mySize) {
		return true;
	}
	for (unsigned i = 0; i < mySize; i++) {
		if (myArray[i] != v2.myArray[i]) {
			return true;
		}
	}
	return false;
}

/* Write Operator (ostream)
 * @param: ostream& out
 * Postcondition: Value of each index is outputted to out
 */
template <class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; i ++) {
		out << myArray[i] << endl;
	}
}

/* Write Operator (file)
 * @param: string fileName
 * Postcondition: Value of each index is outputted to the file with fileName
 * 				  if the file doesn't exist, it is created
 */
template <class Item>
void Vec<Item>::writeTo(string fileName) {
	ofstream fout(fileName);

	fout << mySize << endl;

	for (unsigned i = 0; i < mySize; i++) {
		fout << myArray[i] << endl;
	}
	fout.close();

}

/* Read Operator (istream)
 * @param: istream& in
 * Postcondition: Values from in are stored in each index
 */
template <class Item>
void Vec<Item>::readFrom(istream& in) {
	for (unsigned i = 0; i < mySize; i ++) {
		in >> myArray[i];
	}
}

/* Read Operator (file)
 * @param: string fileName
 * Postcondition: Vec size is changed based on first value in file with fileName
 * 				  Subsequent values are copied into indices
 */
template <class Item>
void Vec<Item>::readFrom(string fileName) {
	ifstream fin(fileName);
	string inStr;
	string size;

	getline(fin,size);
	mySize = atoi( size.c_str() );

	if (myArray != NULL) {
		delete [] myArray;
	}

	myArray = new Item [mySize];

	for (unsigned i = 0; i < mySize; i++) {
		getline(fin,inStr);
		myArray[i] = stod( inStr.c_str() );
	}
	fin.close();
}

/* Subscript Operator (non-const)
 * @param: const unsigned& index
 * Return: Value at index
 */
template <class Item>
Item& Vec<Item>::operator[](unsigned i) {
	if (mySize == 0) {
		throw range_error("Index out of range");
	}
	if (i >= mySize) {
		throw range_error("Index out of range");
	} else {
		return myArray[i];
	}
}

/* Subscript Operator (const)
 * @param: const unsigned& index
 * Return: Value at index
 */
template <class Item>
const Item& Vec<Item>::operator[](unsigned i) const{
	if (mySize == 0) {
		throw range_error("Index out of range");
	}
	if (i >= mySize) {
		throw range_error("Index out of range");
	} else {
		return myArray[i];
	}
}

/* Addition Operator
 * @param: const Vec& other
 * Return: Vec equal to sum of this and other
 */
template <class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& other) {
	Vec ret(mySize);
	if (mySize == other.mySize) {
		for (unsigned i = 0; i < mySize; i++) {
			ret[i] = myArray[i] + other.myArray[i];
		}
	}
	else {
		throw invalid_argument("Vec size mismatch");
	}
	return ret;
}

/* Subtraction Operator
 * @param: const Vec& other
 * Return: Vec equal to difference of this and other
 */
template <class Item>
Vec<Item> Vec<Item>::operator-(const Vec& other) {
	if (mySize == other.mySize){
		Vec subArray(other.mySize);
		for (unsigned i = 0; i < mySize; i ++){
			subArray[i] = myArray[i] - other.myArray[i];
		}
		return subArray;
	}
	else {
		throw invalid_argument("Vectors are not the same size");
	}

}

/* Dot Product Operator
 * @param: const Vec& other
 * Return: Item equal to dot product of this and other
 */
template <class Item>
double Vec<Item>::operator*(const Vec& other){
	Item dProd = 0;
	if (mySize == other.mySize) {
		for (unsigned i = 0; i < mySize; i++) {
			dProd += myArray[i] * other.myArray[i];
		}
	}
	else {
		throw invalid_argument("Vec size mismatch");
	}
	return dProd;
}


#endif /*VEC_H_*/
