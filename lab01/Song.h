/* Song.h declares a class for storing song information.
 * Student Name: Kelsey Yen, kny4: Partner: Daniel Luce, drl7
 * Date: 02-11-20
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Song {
public:
	Song();
	Song(const string& title, const string& artist, unsigned year);
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;
	void readFrom(istream& in);
	void writeTo(ostream& out) const;
private:
	string   myTitle;
	string   myArtist;
	unsigned myYear;
};

#endif /*SONG_H_*/
