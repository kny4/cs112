/* PlayList.h declares class PlayList.
 * Student Name: kelsey Yen, kny4; Partner: Daniel Luce, drl7
 * Date: 02-11-20
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Song.h"
#include <vector>   // STL vector
#include <string>
using namespace std;

class PlayList {
public:
	PlayList(const string& fileName);
	unsigned getNumSongs() const;
	vector<Song> searchByArtist(const string& artist) const;
	vector<Song> searchByYear(unsigned year) const;
private:
   vector<Song> mySongs;

};

#endif /*PLAYLIST_H_*/
