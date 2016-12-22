#include <iostream>
#include <string.h>
#include "proiect.h"
using namespace std;

void mesajMeniu()
{
    cout<<"Bine ati venit in meniul jocului de table."<<endl;
    cout<<"Va puteti alege modul de joc:"<<endl;
    cout<<"Pentru a putea juca table cu un prieten introduceti 2,altfel 1."<<endl;
    cout<<"Pentru iesirea din joc tastati exit.";
}
char detMode()
{
    char mode;
    cin>>mode;
    if(mode!=1 && mode!=2)
       {
           cout<<"WARNING:introduceti din nou modul de joc!";
           cin>>mode;
       }
    else
        return mode;
}

zar resetZaruri(zar zaruri)
{
    zaruri.zar1 = 0;
    zaruri.zar2 = 0;
    return zaruri;
}

scor resetScor(scor scor)
{
    scor.linii = 0;
    scor.partide = 0;
}

void addData(player player1, player player2, char mode)
{
    cout<<"Ati ales modul "<<mode<<"."<<endl;
    cout<<"Inainte de a incepe jocul vrem sa aflam cate ceva despre tine."<<endl;
    cout<<"Intoduceti numele: ";
    cin.get(player1.nume);
    resetScor(player1.scor);
    player1.piesa = 'A';
    resetZaruri(player1.zaruri);
    if(mode == '1')
        strcpy(player2.nume,"Computer");
    else
    {
        cout>>"Introduceti numele celui de-al doilea jucator: ";
        cin.get(player2.nume);
    }
    resetScor(player2.scor);
    resetZaruri(player2.zaruri);
    player2.piesa = 'N';
}

void ojocTable()
{
    mesajMeniu();
    addData(player player1,player player2,detMode())
    // More to come.
}

int main()
{
    return 0;
}
