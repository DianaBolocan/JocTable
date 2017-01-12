#include "proiect.h"
using namespace std;

void resetZaruri(player &playerNo)
{
    playerNo.zar1 = 0;
    playerNo.zar2 = 0;
}

void defaultTabla(char tabla[26][15])
{
    short linie,coloana;
    for(linie=0; linie<26; linie++)
        for(coloana=0; coloana<15; coloana++)
            tabla[linie][coloana] = ' ';
    for(linie=0; linie<26; linie++)
    {
        if(linie == 1)
        {
            for(coloana=0; coloana<2; coloana++)
                tabla[linie][coloana] = 'N';
        }
        else if(linie == 6 || linie == 13)
        {
            for(coloana=0; coloana<5; coloana++)
                tabla[linie][coloana] = 'A';
        }
        else if(linie == 8)
        {
            for(coloana=0; coloana<3; coloana++)
                tabla[linie][coloana] = 'A';
        }
        else if(linie == 24)
        {
            for(coloana=0; coloana<2; coloana++)
                tabla[linie][coloana] = 'A';
        }
        else if(linie == 12 || linie == 19)
        {
            for(coloana=0; coloana<5; coloana++)
                tabla[linie][coloana] = 'N';
        }
        else if(linie == 17)
        {
            for(coloana=0; coloana<3; coloana++)
                tabla[linie][coloana] = 'N';
        }
    }
}

short numarPiese(char tabla[26][15],short linie)
{
    short piese=0;
    for(short coloana=6;coloana<15;coloana++)
        if(tabla[linie][coloana]!=' ')
    {
        piese++;
    }
    return piese;
}

void afisareTabla(char tabla[26][15])
{
    short linie,coloana;
    cout<<"  24  23  22  21  20  19 ||  18  17  16  15  14  13 "<<endl;
    cout<<"=========================||========================="<<endl;
    for(coloana=0;coloana<=5;coloana++)
    {
        cout<<" ";
        for(linie=24;linie>=13;linie--)
        {
                if(coloana!=5)
                    cout<<" "<<tabla[linie][coloana]<<" ";
                else
                {
                    if(tabla[linie][6]!=' ')
                    {
                        short piese;
                        piese = numarPiese(tabla,linie);
                        cout<<tabla[linie][5]<<"+"<<piese;
                    }
                    else
                        cout<<" "<<tabla[linie][5]<<" ";
                }
            cout<<" ";
            if(linie==19)
                cout<<"|| ";
        }
        cout<<endl;
    }
    cout<<"                         ||"<<endl;
    for(coloana=5;coloana>=0;coloana--)
    {
        cout<<" ";
        for(linie=1;linie<=12;linie++)
        {
            if(coloana!=5)
                cout<<" "<<tabla[linie][coloana]<<" ";
            else
            {
                if(tabla[linie][5]!=' ')
                {
                    short piese;
                    piese = numarPiese(tabla,linie);
                    cout<<tabla[linie][5]<<"+"<<piese;
                }
                else
                    cout<<" "<<tabla[linie][coloana]<<" ";
            }
            cout<<" ";
            if(linie == 6)
                cout<<"|| ";
        }
        cout<<endl;
    }
    cout<<"=========================||========================="<<endl;
    cout<<"  1   2   3   4   5   6  ||  7   8   9   10  11  12 "<<endl;
}

short randomDices()
{
    short dice;
    dice =(rand() % 6) + 1;
    return dice;
}

int sumaZar(short zar1,short zar2)
{
    zar1 = randomDices();
    zar2 = randomDices();
    short suma;
    if(zar1 == zar2)
        suma = 4*zar1;
    else
        suma = zar1 + zar2;
    return suma;
}

short primulJucator(player &player1,player &player2)
{
    srand(time(nullptr));
    short suma1 = sumaZar(player1.zar1,player1.zar2);
    short suma2 = sumaZar(player2.zar1,player2.zar2);
    if(suma1 > suma2)
    {
        cout<<"Prima mutare va fi facuta de "<<player1.nume<<"."<<endl;
        resetZaruri(player2);
        return 1;
    }
    else
        if(suma2>suma1)
        {
            cout<<"Prima mutare va fi facuta de "<<player2.nume<<"."<<endl;
            resetZaruri(player1);
            return 2;
        }
    else primulJucator(player1,player2);
}

bool sfarsitJoc(short eliminate)
{
    if(eliminate == 15)
        return true;
    return false;
}

bool isMart(short eliminate)
{
    if(eliminate == 0)
        return true;
    return false;
}

void scorAdaugare(player &player1,player &player2)
{
    if(sfarsitJoc(player1.eliminate) && isMart(player2.eliminate))
        player1.linii+=2;
    else
        if(sfarsitJoc(player2.eliminate) && isMart(player1.eliminate))
        player2.linii+=2;
    else if(sfarsitJoc(player1.eliminate))
        player1.linii++;
    else
        if(sfarsitJoc(player2.eliminate))
        player2.linii++;
}

void scorTransformation(short &linii,short &partide)
{
    if(linii>=3)
    {
        partide++;
        linii = linii - 3;
    }
}

void castigatorJoc(player player1,player player2)
{
    if(player1.partide == 1)
        cout<<player1.nume<<" a castigat!";
    else
    if(player2.partide == 1)
        cout<<player2.nume<<" a castigat!";
}

void mesajMeniu()
{
    cout<<"Bine ati venit in meniul jocului de table."<<endl;
    cout<<"Va puteti alege modul de joc:"<<endl;
    cout<<"Pentru a putea juca table cu un prieten introduceti 1,altfel 2."<<endl;
}

char detMode(char &mode)
{
    //nr de mesaje = nr de  cuvinte (nu il ia in considerare pe spatiu ca facand parte dintr-un cuvant, daca apare 1 sau 2 separati ii ia ca mode)
    char verification[100];
    cin>>verification;
    if(strlen(verification) != 1)
    {
        cout<<"You can't fool us! Choose between 1 or 2!"<<endl;
        detMode(mode);
    }
    else if(verification[0] != '1' && verification[0] != '2')
    {
        cout<<"You can't fool us! Choose between 1 or 2!"<<endl;
        detMode(mode);
    }
    else
        mode = verification[0];
}

void resetScor(player &playerNo)
{
    playerNo.linii = 0;
    playerNo.partide = 0;
}

void repartizareZaruriJoc(short startJucator, player &player1, player &player2)
{
    cout<<"Zarurile sunt: ";
    if(startJucator == 1)
        {
            player1.zar1 = randomDices();
            player1.zar2 = randomDices();
            cout<<player1.zar1<<" si "<<player1.zar2<<endl;
        }
        else
        {
            player2.zar1 = randomDices();
            player2.zar2 = randomDices();
            cout<<player2.zar1<<" si "<<player2.zar2<<endl;
        }
}

void dateDeIntrare(short &deLa,short &la,player player1,player player2,short startJucator,char mode)
{
    if(mode == '1')
        {
            if(startJucator == 1)
            cout<<player1.nume;
            else
            cout<<player2.nume;
            cout<<" introduce numarul liniei de unde vrei sa iei piesa: ";
            cin>>deLa;
            cout<<" si numarul liniei unde vrei s-o pui: ";
            cin>>la;
        }
        else
        {
            if(startJucator == 1)
            {
                cout<<player1.nume;
                cout<<" introduce numarul liniei de unde vrei sa iei piesa: ";
                cin>>deLa;
                cout<<" si numarul liniei unde vrei s-o pui: ";
                cin>>la;
            }
        }
}

void addData(player &player1, player &player2, char mode)
{
    cout<<"Inainte de a incepe jocul vrem sa aflam cate ceva despre tine."<<endl;
    cout<<"Introduceti numele: ";
    cin>>player1.nume;
    resetScor(player1);
    player1.piesa = 'A';
    resetZaruri(player1);
    if(mode == '2')
        strcpy(player2.nume,"Computer");
    else
    {
        cout<<"Introduceti numele celui de-al doilea jucator: ";
        cin>>player2.nume;
    }
    resetScor(player2);
    resetZaruri(player2);
    player2.piesa = 'N';
}

bool checkToatePieseleInCasa(char tabla[26][15],short startJucator)
{
    if(startJucator == 1)
    {
        if(tabla[0][0] != ' ')
            return false;
        for(short linie=24;linie>6;linie++)
            if(tabla[linie][0] != ' ')
            return false;
    }
    if(startJucator == 2)
    {
        if(tabla[25][0] != ' ')
            return false;
        for(short linie=1;linie<19;linie++)
            if(tabla[linie][0] != ' ')
            return false;
    }
    return true;
}

bool checkPieseEliminate(short startJucator,char tabla[26][15])
{
    if(startJucator == 1)
    {
        if(tabla[0][0] == ' ')
            return true;
    }
    if(startJucator == 2)
    {
        if(tabla[25][0] == ' ')
            return true;
    }
    return false;
}

bool checkDeLa(short dela,short startJucator)
{
    if(startJucator == 1)
        if(dela != 0)
            return false;
    if(startJucator == 2)
        if(dela != 25)
            return false;
    return true;
}

bool checkDatePieseEliminate(short dela,short la,short startJucator,player player1,player player2,char tabla[26][15])
{
    if(startJucator == 1)
    {
        if(la<19 || la>24)
        {
            cout<<"S-a depasit limita"<<endl;
            return false;
        }
        if(25-la != player1.zar1 && 25-la != player1.zar2)
        {
            cout<<"Mutarea nu coincide cu zarul"<<endl;
            return false;
        }
        if(tabla[la][1] == 'N')
        {
            cout<<"Linie ocupata de oponent"<<endl;
            return false;
        }
    }
    else
    {
        if(la<1 || la>6)
        {
            cout<<"S-a depasit limita"<<endl;
            return false;
        }
        if(la != player2.zar1 && la != player2.zar2)
        {
            cout<<la<<" "<<player2.zar1<<" "<<player2.zar2<<endl;
            cout<<"Mutarea nu coincide cu zarul."<<endl;
            return false;
        }
        if(tabla[la][1] == 'A')
        {
            cout<<"Linie ocupata de oponent"<<endl;
            return false;
        }
    }
    return true;
}

bool checkDateIntrare(short dela,short la,short startJucator,player player1,player player2,char tabla[26][15])
{
    if(checkToatePieseleInCasa(tabla,startJucator) == true)
    {
        if(startJucator == 1)
        {
            if(dela<1 || dela>6)
            {
                cout<<"S-a iesit din limite"<<endl;
                return false;
            }
            if(la!=-1 && (la<1 || la>5))
            {
                cout<<"S-a iesit din limite"<<endl;
                return false;
            }
            if(dela <= la)
            {
                cout<<"directie gresita"<<endl;
                return false;
            }
            if(tabla[dela][0] == ' ' || tabla[dela][0] == 'N')
            {
                cout<<"nu exista piesa sau spatiu ocupat de oponent"<<endl;
                return false;
            }
            if(la == -1)
            {
                if(dela != player1.zar1 || dela != player1.zar2)
                {
                    cout<<"mutarea nu coincide cu zarul"<<endl;
                    return false;
                }
            }
            else
            {
                if(dela - la != player1.zar1 || dela - la != player1.zar2)
                {
                    cout<<"mutarea nu coincide cu zarul"<<endl;
                    return false;
                }
                if(tabla[la][0] == 'N' && tabla[la][1] == 'N')
                {
                    cout<<"la ocupat de oponent"<<endl;
                    return false;
                }
            }
        }
        else
        {
            if(dela>24 && dela<19)
            {
                cout<<"S-a iesit din limite"<<endl;
                return false;
            }
            if(la!=-1 && (la<20 || la>24))
            {
                cout<<"S-a iesit din limite"<<endl;
                return false;
            }
            if(dela >= la && la != -1)
            {
                cout<<"directie gresita"<<endl;
                return false;
            }
            if(tabla[dela][0] == ' ' || tabla[dela][0] == 'A')
            {
                cout<<"nu exista piesa sau spatiu ocupat de oponent"<<endl;
                return false;
            }
            if(la == -1)
            {
                if(25 - dela != player1.zar1 || 25 - dela != player1.zar2)
                {
                    cout<<"mutarea nu coincide cu zarul"<<endl;
                    return false;
                }
            }
            else
            {
                if(la - dela != player1.zar1 || la - dela != player1.zar2)
                {
                    cout<<"mutarea nu coincide cu zarul"<<endl;
                    return false;
                }
                if(tabla[la][0] == 'A' && tabla[la][1] == 'A')
                {
                    cout<<"la ocupat de oponent"<<endl;
                    return false;
                }
            }
        }

    }
    else
    {
        if(dela<0 || dela>25)
        {
            cout<<"S-a iesit din limite"<<endl;
            return false;
        }
        if(la<=0 || la>=25)
        {
            cout<<"S-a iesit din limite"<<endl;
            return false;
        }
        if(startJucator == 1)
        {
            if(dela - la <= 0)
            {
                cout<<"Directie gresita"<<endl;
                return false;
            }
            if(tabla[dela][0] == ' ' || tabla[dela][0] == 'N')
            {
                cout<<"dela invalid. spatiu gol sau ocupat de oponent"<<endl;
                return false;
            }
            if((dela - la) != player1.zar1 && (dela - la) != player1.zar2)
            {
                cout<<"mutarea nu coincide cu zarul"<<endl;
                return false;
            }
            if(tabla[la][0] == 'N' && tabla[la][1] == 'N')
            {
                cout<<"la ocupat de oponent"<<endl;
                return false;
            }
        }
        if(startJucator == 2)
        {
            if(dela - la >= 0)
            {
                cout<<"directie gresita"<<endl;
                return false;
            }
            if(tabla[dela][0] == ' ' || tabla[dela][0] == 'A')
            {
                cout<<"dela invalid. spatiu gol sau ocupat de oponent"<<endl;
                return false;
            }
            if((la - dela) != player2.zar1 && (la - dela) != player2.zar2)
            {
                cout<<"mutarea nu coincide cu zarul"<<endl;
                return false;
            }
            if(tabla[la][0] == 'A' && tabla[la][1] == 'A')
            {
                cout<<"la ocupat de oponent"<<endl;
                return false;
            }
        }
    }
    return true;
}

player translatePlayer(short startJucator,player player1, player player2)
{
    if(startJucator == 1)
        return player1;
    else
        return player2;
}

bool mutareImposibila(char tabla[26][15],short startJucator,short &zar)
{
    short linie;
    if(startJucator == 1)
    {
        if(checkPieseEliminate(startJucator,tabla) == false)
        {
            if(tabla[25-zar][1] == ' ')
                return false;
        }
        else
        {
            for(linie=24;linie>0;linie--)
            {
                if(tabla[linie][0] == 'A')
                {
                    if(tabla[linie-zar][1] == ' ' && linie-zar > 0)
                        return false;
                }
            }
        }
    }
    else
    {
        if(checkPieseEliminate(startJucator,tabla) == false)
        {
            if(tabla[zar][1] == ' ')
                return false;
        }
        else
        {
            for(linie=1;linie<25;linie++)
            {
                if(tabla[linie][0] == 'N')
                    if(tabla[linie+zar][1] == ' ' && linie+zar <25)
                        return false;
            }
        }
    }
    zar = 0;
    return true;
}

bool isDubla(player playerNo)
{
    if(playerNo.zar1 == playerNo.zar2)
        return true;
    return false;
}

void mutari(short dela,short la,char tabla[26][15])
{
    int indexParcurgere = 0, coloana = 0;
    char piesacurenta = tabla[dela][0];

    if(tabla[la][0] != piesacurenta && tabla[la][0] != ' ')
    {
        if(tabla[la][0] == 'A')
        {
            while(tabla[0][indexParcurgere] != ' ')
                indexParcurgere++;
            tabla[0][indexParcurgere] = 'A';
        }
        else
        {
            while(tabla[25][indexParcurgere] != ' ')
                indexParcurgere++;
            tabla[25][indexParcurgere] = 'N';
        }
        tabla[la][0] = piesacurenta;
    }
    else if(tabla[la][0] == ' ')
        tabla[la][0] = piesacurenta;
    else if(tabla[la][0] == piesacurenta)
    {
        while(tabla[la][coloana] != ' ')
            coloana++;
        tabla[la][coloana]=piesacurenta;
    }
    coloana = 0;
    while (tabla[dela][coloana] != ' ')
        coloana++;
    tabla[dela][coloana-1]=' ';
}

void mutareFacuta(short &countMutari, player &playerNo,short mutare)
{
    if(countMutari > 2)
    {
        countMutari--;
    }
    else
    {
        countMutari--;
        if(mutare == playerNo.zar1)
            playerNo.zar1 = 0;
        else
            playerNo.zar2 = 0;
    }
}

void switchPlayers(short &startJucator)
{
    if(startJucator == 1)
        startJucator = 2;
    else
        startJucator = 1;
}
void highScores()
{
    for(int index=0;index<10;index++)
        for(int indexy=index+1;indexy<10;indexy++)
           if(scor[index].partide<scor[indexy].partide||(scor[index].partide=scor[index].partide && scor[index].linii<scor[index].linii))
               swap(scor[index],scor[indexy]);
}
void updateScoreFile()
{
    ofstream fout;
    fout.open(file_name);
    for(int index=0;index<10;index++)
        fout<<scor[index].numeJucator<<" "<<scor[index].partide<<'\n';
    fout.close();
}
void newScore(char* nume_jucator,int partida,int linie)
{
    for(int index=0;index<10;index++)
        if(partida>scor[index].partide || (partida==scor[index].partide&& linie>scor[index].linii))
          {
            for(int indexy=9;indexy>=index+1;indexy--)
            {
                scor[indexy].partide=scor[indexy-1].partide;
                scor[indexy].numeJucator=scor[indexy-1].numeJucator;
                scor[indexy].linii=scor[indexy-1].linii;
            }
            scor[index].partide=partida;
            scor[index].numeJucator=nume_jucator;
            scor[index].linii=linie;
            break;

          }
}

void ojocTable()
{
    char mode;
    char tabla[26][15];
    short startJucator,countMutari;
    bool ambeleZaruriImposibile = false;
    player player1, player2;

    mesajMeniu();
    detMode(mode);
    addData(player1,player2,mode);
    system("cls");
    defaultTabla(tabla);
    startJucator = primulJucator(player1,player2);

    while(sfarsitJoc(player1.eliminate) == false && sfarsitJoc(player2.eliminate) == false)
    {
        short deLa, la;
        ambeleZaruriImposibile = false;
        afisareTabla(tabla);
        cout<<endl;

        repartizareZaruriJoc(startJucator,player1,player2);

        if(isDubla(translatePlayer(startJucator,player1,player2)) == true)
            countMutari = 4;
        else
            countMutari = 2;

        if(isDubla(translatePlayer(startJucator,player1,player2)) == true)
        {
            if(startJucator == 1)
            {
                if(mutareImposibila(tabla,startJucator,player1.zar1) == true)
                    countMutari = 0;
            }
            else
            {
                if(mutareImposibila(tabla,startJucator,player2.zar1) == true)
                    countMutari = 0;
            }
        }
        else
        {
            if(startJucator == 1)
            {
                if(checkPieseEliminate(startJucator,tabla) == false)
                {
                    if(mutareImposibila(tabla,startJucator,player1.zar1) == true)
                        countMutari--;
                    if(mutareImposibila(tabla,startJucator,player1.zar2) == true)
                        countMutari--;
                }
                else
                {
                    //inca sare peste o mutare!!!!
                    if(tabla[0][1] == ' ')
                    {
                        short keepZar1 = player1.zar1;
                        short keepZar2 = player1.zar2;
                        if(mutareImposibila(tabla,startJucator,player1.zar1) == true && mutareImposibila(tabla,startJucator,player1.zar2) == false)
                            player1.zar1 = keepZar1;
                        else if(mutareImposibila(tabla,startJucator,player1.zar1) == false && mutareImposibila(tabla,startJucator,player1.zar2) == true)
                            player2.zar2 = keepZar2;
                        else if(mutareImposibila(tabla,startJucator,player1.zar1) == true && mutareImposibila(tabla,startJucator,player1.zar2) == true)
                            countMutari = countMutari - 2;
                    }
                }
            }
            else
            {
                if(checkPieseEliminate(startJucator,tabla) == false)
                {
                    if(mutareImposibila(tabla,startJucator,player2.zar1) == true)
                        countMutari--;
                    if(mutareImposibila(tabla,startJucator,player2.zar2) == true)
                        countMutari--;
                }
                else
                {
                    if(tabla[0][1] == ' ')
                    {
                        short keepZar1 = player2.zar1;
                        short keepZar2 = player2.zar2;
                        if(mutareImposibila(tabla,startJucator,player2.zar1) == true && mutareImposibila(tabla,startJucator,player2.zar2) == false)
                            player2.zar1 = keepZar1;
                        else if(mutareImposibila(tabla,startJucator,player2.zar1) == false && mutareImposibila(tabla,startJucator,player2.zar2) == true)
                            player2.zar2 = keepZar2;
                        else if(mutareImposibila(tabla,startJucator,player2.zar1) == true && mutareImposibila(tabla,startJucator,player2.zar2) == true)
                            countMutari = countMutari - 2;
                    }
                }
            }
        }

        if(countMutari == 0)
            ambeleZaruriImposibile = true;

        while(countMutari)
        {
            datedeintrare:
            dateDeIntrare(deLa,la,player1,player2,startJucator,mode);

            if(checkPieseEliminate(startJucator,tabla) == false)
            {
                if(checkDeLa(deLa,startJucator) == false)
                {
                    cout<<"Ai piese eliminate de oponent care trebuie puse inapoi in joc"<<endl;
                    goto datedeintrare;
                }
                if(checkDatePieseEliminate(deLa,la,startJucator,player1,player2,tabla) == false)
                {
                    cout<<"Can't do that!"<<endl;
                    goto datedeintrare;
                }
            }
            else if(checkDateIntrare(deLa,la,startJucator,player1,player2,tabla) == false)
            {
                cout<<"Can't do that"<<endl;
                goto datedeintrare;
            }
            if(la == -1)
            {
                if(startJucator == 1)
                    player1.eliminate++;
                else if (startJucator == 2)
                    player2.eliminate++;
            }

            mutari(deLa,la,tabla);
            system("cls");
            afisareTabla(tabla);
            if(startJucator == 1)
            {
                short mutare = deLa - la;
                mutareFacuta(countMutari,player1,mutare);
                cout<<player1.zar1<<" "<<player1.zar2<<endl;
            }
            else if(startJucator == 2)
            {
                short mutare = la - deLa;
                mutareFacuta(countMutari,player2,mutare);
                cout<<player2.zar1<<" "<<player2.zar2<<endl;
            }

            if(startJucator == 1)
            {
                if(player1.zar1 != 0)
                {
                    if(mutareImposibila(tabla,startJucator,player1.zar1) == true)
                    {
                        countMutari = 0;
                        ambeleZaruriImposibile = true;
                    }
                }
                else if(player1.zar2 != 0)
                {
                    if(mutareImposibila(tabla,startJucator,player1.zar2) == true)
                    {
                        countMutari = 0;
                        ambeleZaruriImposibile = true;
                    }
                }
            }
            else
            {
                if(player2.zar1 != 0)
                {
                    if(mutareImposibila(tabla,startJucator,player2.zar1) == true)
                    {
                        countMutari = 0;
                        ambeleZaruriImposibile = true;
                    }
                }
                else if(player2.zar2 != 0)
                {
                    if(mutareImposibila(tabla,startJucator,player2.zar2) == true)
                    {
                        countMutari = 0;
                        ambeleZaruriImposibile = true;
                    }
                }
            }
        }

        if(ambeleZaruriImposibile == true)
        {
            cout<<"Nicio mutare nu poate fi facuta."<<endl;
            Sleep(3000);
        }
        switchPlayers(startJucator);
        system("cls");
    }
    scorAdaugare(player1,player2);
    scorTransformation(player1.linii,player1.partide);
    scorTransformation(player2.linii,player2.partide);
    castigatorJoc(player1,player2);
    // More to come.
}

int main()
{
    ojocTable();
     /*int partida,linie; player player;
    ifstream fin;
    fin.open(file_name);
    for(int index=0;index<10;index++)
    {
        fin>>scor[index].numeJucator;
        fin>>scor[index].partide;
        fin>>scor[index].linii;
    }
    highScores();
    fin.close();
    for(int index=0;index<10;index++)
    {
        cout<<scor[index].numeJucator;
        cout<<scor[index].partide;
        cout<<scor[index].linii<<endl;
    }
    newScore(player.nume,partida,linie);
    updateScoreFile();*/
    return 0;
}


