#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>

using namespace std;
using std::string;

#define MAX 100

char character;
int wordCount = 0;


string GetNextWord() {
	bool endWord = false;
	string word;

	while (cin.good()) {
		character = cin.get();
		if (isalpha(character)){
			word.push_back(character);
			endWord = true;
		}
		else{
			if (endWord){
				return word;
			}
		}
	}
	return word;
}

void DumpDictionary(string Dict [], int count []) {
	cout << "Word                |Frequency \n";
	for(int r=0; r<wordCount; r++){
		printf("%-20s|%9i \n", Dict[r].c_str(), count[r]);
	}
}

int LocateWord(string Dict [], string word) {

	for (int i = 0; i<MAX; i++){
		if (Dict[i]==word) return i;
	}
	return -1;
}

int InsertWord(string Dict [], string word) {

	if (wordCount < MAX) {
		Dict[wordCount] = word;
		wordCount++;
		return 1;
	}
	else {
		return 0;
	}
}
