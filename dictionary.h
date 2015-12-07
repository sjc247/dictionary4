#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using std::string;

#define MAX 100

typedef string WORD;
//typedef int itr;
 
struct ENTRY {
  friend bool operator<(ENTRY, ENTRY);
  WORD w;
  int freq;
};

bool operator<(ENTRY, ENTRY);

class DICT {
private:
   vector<ENTRY> d;
   int size;
public :
   //constructor. size is the initial size of dictionary
   DICT(int size = 0);

   //locateWord will either return the location of found word in dictionary or -1 if it's not found
   int LocateWord(WORD w); //itr, nope!


   //insert() will insert the word WORD in the dictionary if it's not already there; otherwise, it
   //will increase its frequency by 1 ( this is what operator+() does below)
   void insert(WORD w);


   //this overloaded addition operator will insert the word w into the dictionary if it's not already there; 
   //otherwise, it will increase its frequency by 1
   DICT operator+(WORD w);

   //dump() will dump the first i words in dictionary to ostream o or all words if i = -1
   void dump (ostream &o, int numwords = -1);

   //see below
   friend ostream &operator<<(ostream &, DICT &);
};



//this is just dump() re-written as an overloaded operator. note that it should dump the WHOLE dictionary
ostream &operator<<(ostream &, DICT &);


/*
  this GetNextWord() will return the next word in the input stream, but with a slight twist
  if the parameter == 0 then a word is a sequence of upper and lower case letters ( 'A'..'Z', 'a'..'z')
  parameter != 0 then a word is a sequence of everthing BUT upper and lower case letters.
*/
WORD GetNextWord(int = 0);


#endif



