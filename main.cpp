#include "dictionary.h"

DICT dictionary(MAX);  //your dictionary 
WORD word;       

int main (void) {
    int pos;

    while (1) {
	
	word = GetNextWord(0);
        if ( word.empty() )  {
            cout << "dumping whole dictionary..." << endl;
            cout << dictionary;
            cout << "dumping first 5 words in dictionary...." << endl;
            dictionary.dump(cout,5);
            break;
        }
        //dictionary.insert(word);
	dictionary = dictionary + word;
    }
    return 0;
}


