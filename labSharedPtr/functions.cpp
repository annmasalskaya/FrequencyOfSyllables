#include "functions.h"
#include <cstring>
#include <iostream>
using namespace std;

bool isVowelLetter(char letter)
{
    vector<char> vowels;
    vowels.push_back('a');
    vowels.push_back('e');
    vowels.push_back('i');
    vowels.push_back('o');
    vowels.push_back('u');
    vowels.push_back('y');
    letter = tolower(letter);
    for (vector<char>::iterator it=vowels.begin() ; it!=vowels.end(); ++it)
        if(*it == letter) return true;
    return false;
}

vector<char*> splitWord(string word)  // костыльное разделение на слоги
{
    string result, syll;
    for(unsigned i=0; i<word.length(); i++)
    {
        if(!isVowelLetter(word[i]) && isVowelLetter(word[i+1]) && isVowelLetter(word[i+2]))
        {
            if(i+3<word.length())
            {
                syll = word.substr(i,2);
                result.append(syll); // добавл. в конец строки слог syll
                result += '|';
                ++(++i);
            }
        }
        else
        {
           if(i+3<word.length())
            {
                syll = word.substr(i,2);
                result.append(syll);
                result += '|';
                ++(++i);
            }
        }

        result += word[i];
    }
    char *tmp = strdup(result.c_str());
    tmp= strtok (tmp,"|");
    vector<char*> vect;
    vect.push_back(tmp);
    while (tmp!=NULL)
    {
        tmp= strtok (NULL, "|");
        vect.push_back(tmp);

    }
    return vect;
}

char* MedianaFind(vector <char*> accumulator)
{
    int size=accumulator.size();
    int mediana=size/2;
    return accumulator[mediana];

}

char* thirtiethPerz(vector <char*> accumulator)
{
    int size=accumulator.size();
    int perz=(size*30)/100;
    return accumulator[perz];

}
char* seventiethPerz(vector <char*> accumulator)
{
    int size=accumulator.size();
    int perz=(size*70)/100;
    return accumulator[perz];

}
