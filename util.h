#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
	typename std::set<T>::iterator begS1 = s1.begin();
	typename std::set<T>::iterator begS2 = s2.begin();
	typename std::set<T>::iterator endS1 = s1.end();
	typename std::set<T>::iterator endS2 = s2.end();
	std::set<T> intersectHold;

	while (begS1 != endS1 && begS2 != endS2)
	{
		if (*begS1 < *begS2)
		{
			++begS1; // goes to next element
		}
		else if (*begS1 > *begS2)
		{
			++begS2; // goes to next element
		}
		else // assumes both begs are the same
		{
			intersectHold.insert(*begS1);
		}
	}
	return intersectHold;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
	typename std::set<T>::iterator begS1 = s1.begin();
	typename std::set<T>::iterator begS2 = s2.begin();
	typename std::set<T>::iterator endS1 = s1.end();
	typename std::set<T>::iterator endS2 = s2.end();
	std::set<T> unionHold;

	while (begS1 != endS1 && begS2 != endS2)
	{
		if (*begS1 < *begS2)
		{
			unionHold.insert(*begS1);
			++begS1;
		}
		else if (*begS1 > *begS2)
		{
			unionHold.insert(*begS2);
			++begS2;
		}
		else // assumes both begs are the same
		{
			unionHold.insert(*begS1);
			++begS1;
			++begS2;
		}
	}
	return unionHold;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
