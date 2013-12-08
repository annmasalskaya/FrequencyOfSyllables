#include "assotiativeArray.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "smartPtr.h"
using namespace std;

typedef SmartPointer<MapContainer> MapContainerSharedPtr;

int main()
{
    MapContainerSharedPtr Syllables(new MapContainer());
    //cout<<Syllables.getCouter();
    ifstream in;
    in.open("text");
    string word;
    vector<char*> accumulator;
    while (in>>word)
    {
        for (string::iterator it = word.begin() ; it != word.end(); ++it)
            *it = tolower(*it);
        char *temp = strdup(word.c_str());
        word = strtok(temp, " ,.");
        vector<char*> vect=splitWord(word);
        for (vector<char*>::iterator it=vect.begin() ; it!=--vect.end(); ++it)
        {
            word=string(*it);
            Syllables->addElement(word,0);
            Syllables->find(word);
            accumulator.push_back(*it);
        }

    }
    try
    {
        Syllables->print();
    }
    catch(exception &exc)
    {
        cout << exc.what() <<endl;
    }

    Syllables->oftenSeldomOccur();
    cout<<"\nТекст разбит на "<<accumulator.size()<<" слогов." <<endl;
    cout<<"Медиана:"<<MedianaFind(accumulator)<<endl;
    cout<<"Граница 30 перцентиля :"<<thirtiethPerz(accumulator)<<endl;
    cout<<"Граница 70 перцентиля :"<<seventiethPerz(accumulator)<<endl;


    return 0;
}
