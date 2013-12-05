#include "assotiativeArray.h"
#include <iostream>
#include<algorithm>

using namespace std;

//----------- функция вне класса ( для сортировки map по значению )

bool cmp(const pair< string, int > &a, const pair< string, int > &b)
{
    return a.second >b.second;
}

//-------------------- MapContainer

MapContainer::MapContainer():
   syllables(new map<string,int>)
{

}

/*MapContainer::~MapContainer()
{
    cout<<"-==============";
    syllables->clear();
}
*/
void MapContainer::addElement(string ar,int value)
{
    syllables->insert(make_pair(ar,value));
}

void MapContainer::print()
{
    if(!syllables->empty())
    {
        map <string,int>::iterator cur;
        cout<<"//////////////////////////"<<endl;
        cout<<"Слог /  Кол-во раз в тексте "<<endl;
        cout<<"//////////////////////////"<<endl;
        for (cur= syllables->begin(); cur!= syllables->end(); cur++)
        {
            cout<<(*cur).first;
            cout<<": "<<(*cur).second<<endl;

        }
    }
    else throw MapIsEmpty();
}

bool MapContainer::find(string ar)
{
    map <string,int>::iterator cur;
    for (cur= syllables->begin(); cur!= syllables->end(); cur++)
        if((*cur).first==ar)
        {
            ++(*cur).second;
            return true;
        }

    return false;

}

void MapContainer::oftenSeldomOccur() // выводит 20 наиболее частых слогов и 40 наиболее редко встречаемых
{
    vector<pair< string, int > >   vec(syllables->begin(), syllables->end() );
    sort(vec.begin(), vec.end(), cmp);
    unsigned counter=1,amount=20;
    cout<<"_______________________________"<<endl<<endl;
    cout<<" 20 слогов наиболее встречаемых "<<endl<<endl;
    cout<<"_______________________________"<<endl;
    for (vector<pair< string, int > >::iterator it=vec.begin(); counter<=amount; ++it, ++counter)
    {
        if(counter<=9)cout <<counter<<"  | ";
        else cout <<counter<<" | ";
        cout<< it->first << ": " << it->second << endl;
    }
    counter=1;
    amount=vec.size()-40;
    cout<<"_______________________________"<<endl<<endl;
    cout<<" 40 слогов наиболее редких "<<endl<<endl;
    cout<<"_______________________________"<<endl;
    for (vec[amount]; amount<vec.size(); ++amount)
    {
        if(counter<=9)cout <<counter<<"  | ";
        else cout <<counter<<" | ";
        counter++;
        cout<< vec[amount].first << ": " << vec[amount].second << endl;
    }

}

