#include "dictionary.h"

//Overloaded operator used for sorting
bool operator<(ENTRY i, ENTRY j){return (i.w < j.w);}

DICT::DICT(int size){

	this->size = size;
}


void DICT::insert(WORD w){

	int loc = this->LocateWord(w);
	if(loc == -1){
		ENTRY tmp;
		tmp.w = w;
		tmp.freq = 1;
		this->d.push_back(tmp);
	}
	else{
		this->d[loc].freq++;
	}
}


DICT DICT::operator+(WORD w){

	this->insert(w);
	return *this;
}


void DICT::dump(ostream &o, int numwords) {

	sort(this->d.begin(), this->d.end());	
	o << endl;
	o << "Word                Frequency" << endl;
	o << "-----------------------------" << endl;
	//Print the words and counts
	if(numwords == -1){
		for(int i=0; i < this->d.size(); i++){
			o << this->d[i].w;
			if(this->d[i].w.length() <= 20)
				for(int j=0; j< 20 - this->d[i].w.length(); j++) o << ' '; 
				//Prints a fixed amount of spaces based off length of word
			else o << ' ';
			o << this->d[i].freq << endl;
		}
	}
	else{
		for(int i=0; i < numwords; i++){
			o << this->d[i].w;
			if(this->d[i].w.length() <= 20)
				for(int j=0; j< 20 - this->d[i].w.length(); j++) o << ' '; 
			
			else o << ' ';
			o << this->d[i].freq << endl;
		}
	}
}


ostream &operator<<(ostream &o, DICT &dict){

	sort(dict.d.begin(), dict.d.end());	
	o << endl;
	o << "Word              Frequency" << endl;
	o << "---------------------------" << endl;
	//Print the words and counts
	for(int i=0; i < dict.d.size(); i++){
		o << dict.d[i].w;
		if(dict.d[i].w.length() <= 20)
			for(int j=0; j< 20 - dict.d[i].w.length(); j++) o << ' '; 
			//Prints a fixed amount of spaces based off length of word
		else o << ' ';
		o << dict.d[i].freq << endl;
	}
	
	return o;
}


WORD GetNextWord(int choice){

	WORD w;
	char ch;
	bool inword = false;
	if(choice == 0){
		while( cin.good() ){
			ch = cin.get();
			if ( isalpha(ch) ){  /* function test if ch is A-Z, a-z */
				w.push_back(ch);
				inword = true;
			}
			else if (inword) return w;
		}
		return w;
	}
	else {
		while( cin.good() ){
			ch = cin.get();
			if ( !isalpha(ch) ){  /* function test if ch is NOT A-Z, a-z */
				w.push_back(ch);
				inword = true;
			}
			else if (inword) return w;
		}
		return w;
	}
}



int DICT::LocateWord(WORD w) {

	int found = 0;
	int loc = -1;
	for(int i = 0; i < this->d.size(); i++){	//Go through each element of dict
		if(w == this->d[i].w){	//Compare target word with entry word
			found = 1;
		
			loc = i;
			break;
		}
	}

	return loc;
}


