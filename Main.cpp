#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;
using std::string;

#define MAX 100

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];

string word;
int count[MAX];   //tracks word frequencies
string dictionary[MAX];

extern int LocateWord(string [], string);
extern int FullDictionary(string []);
extern int InsertWord(string [],string);
extern string GetNextWord();
extern void DumpDictionary(string [],int []);

int main (void) {
    int pos;

	for (int i = 0; i<MAX; i++) count[i] = 1;

    while (1) {
       word = GetNextWord();
       if (word.empty())  {
           DumpDictionary(dictionary,count);
           break;
       }
       if ((pos = LocateWord(dictionary,word)) >=  0 ) 
           count[pos]++;
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word << " cannot be added\n";
    }
    return 0;
}
