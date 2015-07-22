#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include<map>

using namespace std;

map<unsigned long long, string> Anagrams;
void insertAnagram(unsigned long long key,string word)
{
    if (Anagrams.find(key) != Anagrams.end())
	{
        Anagrams[key] += " " + word;
    }
    else
        Anagrams[key] = word;
}

unsigned long long calculatehashkey(string s){

	char arr[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
	int i = 0 , index;
    unsigned long long productkey = 1;
	for(i = 0 ; i < s.length() ; i++){
		index = s[i] - 'A';
		productkey *= arr[index];
    }
	return productkey;
}


void printAnagrams()
{
	for (map<unsigned long long, string>::iterator ii = Anagrams.begin(); ii != Anagrams.end(); ++ii)
	{
	    string s=(*ii).second;
	    if(s.find(' ') != -1){

		cout << s << endl;

                }

	}
}

int main(){

    ifstream inFile;
    inFile.open("sowpods.txt");
    string line;
    while (!inFile.eof())
    {
        getline(inFile, line);

        unsigned long long key = calculatehashkey(line);

        insertAnagram(key,line);

    }

   printAnagrams();
   return 0;
}

