#include <iostream>
#include <cstdlib>
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
    mesajMeniu();
    cin>>mode;
    if(mode!=1 && mode!=2 && mode!='exit' && mode!='EXIT' && mode!='Exit')
       { cout<<"WARNING:introduceti din nou modul de joc!";
          cin>>mode;
       }
    else
    if(mode=='exit'||mode=='EXIT')
         exit(0);
    else
        return mode;

}
