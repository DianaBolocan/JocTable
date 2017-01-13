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
        cout<<"First moves will be made by "<<player1.nume<<"."<<endl;
        resetZaruri(player2);
        return 1;
    }
    else
        if(suma2>suma1)
        {
            cout<<"First moves will be made by "<<player2.nume<<"."<<endl;
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
        cout<<player1.nume<<" won!";
    else
    if(player2.partide == 1)
        cout<<player2.nume<<" won!";
}

void mesajMeniu()
{
    cout<<"Welcom to our tables game."<<endl;
    cout<<"You can choose your type of game."<<endl;
    cout<<"If you want to play the game, press 1."<<endl;
}

char detMode(char &mode)
{
    char verification[1001];
    cin.getline(verification,1001);
    if(strlen(verification) != 1)
    {
        cout<<"You can't fool us! Choose 1 or exit the game!"<<endl;
        detMode(mode);
    }
    if(verification[0] != '1')
    {
        cout<<"You can't fool us! Choose 1 or exit the game!"<<endl;
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

bool checkLinieIncadrare(char verification[1001])
{
    if(strlen(verification) > 2)
    {
        cout<<"Can't do that!"<<endl;
        return false;
    }
    else
    {
        if(strlen(verification) == 2)
        {
            if(verification[0] != '1' && verification[0] != '2' && verification[0] != '-')
            {
                cout<<"Can't do that!"<<endl;
                return false;
            }
            {if(verification[0] == '-')
                if(verification[1] != '1')
                {
                    cout<<"Can't do that!"<<endl;
                    return false;
                }
            else if(verification[1] < '0' || verification[1] > '9')
            {
                cout<<"Can't do that!"<<endl;
                return false;
            }}
        }
        else if(strlen(verification) == 1)
        {
            if(verification[0] < '0' || verification[0] > '9')
            {
                cout<<"Can't do that!"<<endl;
                return false;
            }
        }
    }
    return true;
}

void transformCharInt(short &number,char verification[100])
{
    if(strlen(verification) == 2)
    {
        number = (int)verification[0] - 48;
        number = number*10;

        number = number + ((int)verification[1] - 48);
    }
    else
        number = (int)verification[0] - 48;
}

void cinGetLine(char verification[1001])
{
    cin.getline(verification,1001);
}

void repartizareZaruriJoc(short startJucator, player &player1, player &player2)
{
    cout<<"The dices are: ";
    if(startJucator == 1)
        {
            player1.zar1 = randomDices();
            player1.zar2 = randomDices();
            cout<<player1.zar1<<" and "<<player1.zar2<<endl;
        }
        else
        {
            player2.zar1 = randomDices();
            player2.zar2 = randomDices();
            cout<<player2.zar1<<" and "<<player2.zar2<<endl;
        }
}

void dateDeIntrare(short &deLa,short &la,player player1,player player2,short startJucator,char mode,bool &firstMove)
{
    char verification1[1001],verification2[1001];
    if(mode == '1')
    {
        if(startJucator == 1)
        {
            if(firstMove == true)
            {
                cout<<player1.nume;
                cout<<" is first to make a move."<<endl;
                cin.get();
                cout<<"From where do you want to take the piece? ";
                cinGetLine(verification1);
                if(checkLinieIncadrare(verification1) == false)
                    dateDeIntrare(deLa,la,player1,player2,startJucator,mode,firstMove);
                else
                    transformCharInt(deLa,verification1);
                cout<<"Where do you want to place the piece? "<<endl;
                cinGetLine(verification2);
                if(checkLinieIncadrare(verification2) == false)
                    dateDeIntrare(deLa,la,player1,player2,startJucator,mode,firstMove);
                else
                    transformCharInt(la,verification2);
                firstMove = false;
            }
            else
            {
                cout<<player1.nume;
                cout<<", press ENTER to give us the numbers.";
                cin.get();
                cout<<"From where do you want to take the piece? ";
                cinGetLine(verification1);
                if(checkLinieIncadrare(verification1) == false)
                    dateDeIntrare(deLa,la,player1,player2,startJucator,mode,firstMove);
                else
                    transformCharInt(deLa,verification1);
                cout<<"Where do you want to place the piece? ";
                cinGetLine(verification2);
                if(checkLinieIncadrare(verification2) == false)
                    dateDeIntrare(deLa,la,player1,player2,startJucator,mode,firstMove);
                else
                    transformCharInt(la,verification2);
            }
        }
        else
        {
            if(firstMove == true)
            {
                cout<<player2.nume;
                cout<<" is first to make a move."<<endl;
                cin.get();
                cout<<"From where do you want to take the piece? ";
                cinGetLine(verification1);
                if(checkLinieIncadrare(verification1) == false)
                    dateDeIntrare(deLa,la,player1,player2,startJucator,mode,firstMove);
                else
                    transformCharInt(deLa,verification1);
                cout<<"Where do you want to place the piece? ";
                cinGetLine(verification2);
                if(checkLinieIncadrare(verification2) == false)
                    dateDeIntrare(deLa,la,player1,player2,startJucator,mode,firstMove);
                else
                    transformCharInt(la,verification2);
                firstMove = false;
            }
            else
            {
                cout<<player2.nume;
                cout<<", press ENTER to give us the numbers.";
                cin.get();
                cout<<"From where do you want to take the piece? ";
                cinGetLine(verification1);
                if(checkLinieIncadrare(verification1) == false)
                    dateDeIntrare(deLa,la,player1,player2,startJucator,mode,firstMove);
                else
                    transformCharInt(deLa,verification1);
                cout<<"Where do you want to place the piece? ";
                cinGetLine(verification2);
                if(checkLinieIncadrare(verification2) == false)
                    dateDeIntrare(deLa,la,player1,player2,startJucator,mode,firstMove);
                else
                    transformCharInt(la,verification2);
            }
        }
    }

}

void addData(player &player1, player &player2, char mode)
{
    cout<<"Before we start, we'd like to know about you! :)"<<endl;
    cout<<"Player 1, what's your name? ";
    cin>>player1.nume;
    resetScor(player1);
    player1.piesa = 'A';
    resetZaruri(player1);
    if(mode == '2')
        strcpy(player2.nume,"Computer");
    else
    {
        cout<<"What about you, Player 2? ";
        cin>>player2.nume;
    }
    resetScor(player2);
    resetZaruri(player2);
    player2.piesa = 'N';
}

void checkToatePieseleInCasa(char tabla[26][15],short startJucator,short &piese1,short &piese2)
{
    if(startJucator == 1)
    {
        piese1=0;
        for(short linie=1;linie<=6;linie++)
            for(short coloana=0;coloana<15;coloana++)
                if(tabla[linie][coloana] == 'A')
                    piese1++;
    }
    else if(startJucator == 2)
    {
        piese2=0;
        for(short linie=19;linie<=24;linie++)
            for(short coloana=0;coloana<15;coloana++)
                if(tabla[linie][coloana] == 'N')
                    piese2++;
    }
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
            cout<<"Keep it between 19 and 24."<<endl;
            return false;
        }
        if(25-la != player1.zar1 && 25-la != player1.zar2)
        {
            cout<<"Your move doesn't match the dices"<<endl;
            return false;
        }
        if(tabla[la][1] == 'N')
        {
            cout<<"That point is already occupied by your opponent."<<endl;
            return false;
        }
    }
    else
    {
        if(la<1 || la>6)
        {
            cout<<"Keep it between 1 and 6."<<endl;
            return false;
        }
        if(la != player2.zar1 && la != player2.zar2)
        {
            cout<<la<<" "<<player2.zar1<<" "<<player2.zar2<<endl;
            cout<<"Your move doesn't match the dices."<<endl;
            return false;
        }
        if(tabla[la][1] == 'A')
        {
            cout<<"That point is already occupied by your opponent."<<endl;
            return false;
        }
    }
    return true;
}

bool checkDateIntrare(short dela,short la,short startJucator,player player1,player player2,char tabla[26][15])
{
    if(dela<0 || dela>25)
    {
        cout<<"Keep it between 0 and 25."<<endl;
        return false;
    }
    if(la<=0 || la>=25)
    {
        cout<<"Keep it between 1 and 24."<<endl;
        return false;
    }
    if(startJucator == 1)
    {
        if(dela - la <= 0)
        {
            cout<<"Wrong way!"<<endl;
            return false;
        }
        if(tabla[dela][0] == ' ' || tabla[dela][0] == 'N')
        {
            cout<<"You can't pick that number."<<endl;
            return false;
        }
        if((dela - la) != player1.zar1 && (dela - la) != player1.zar2)
        {
            cout<<"Your move doesn't match the dices."<<endl;
            return false;
        }
        if(tabla[la][0] == 'N' && tabla[la][1] == 'N')
        {
            cout<<"That point is already occupied by your opponent."<<endl;
            return false;
        }
    }
    if(startJucator == 2)
    {
        if(dela - la >= 0)
        {
            cout<<"Wrong way!"<<endl;
            return false;
        }
        if(tabla[dela][0] == ' ' || tabla[dela][0] == 'A')
        {
            cout<<"You can't pick that number."<<endl;
            return false;
        }
        if((la - dela) != player2.zar1 && (la - dela) != player2.zar2)
        {
            cout<<"Your move doesn't match the dices."<<endl;
            return false;
        }
        if(tabla[la][0] == 'A' && tabla[la][1] == 'A')
        {
            cout<<"That point is already occupied by your opponent."<<endl;
            return false;
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

bool mutareImposibila(char tabla[26][15],short startJucator,short zar)
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
                    if(linie - zar < 0)
                        return true;
                    if(tabla[linie-zar][1] == ' ' || tabla[linie-zar][1] == 'A')
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
                {
                    if(linie+zar > 25)
                        return true;
                    if(tabla[linie+zar][1] == ' ' || tabla[linie+zar][1] == 'N')
                        return false;
                }
            }
        }
    }
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

void recalculateCountMutari(short startJucator,player &player1,player &player2,char tabla[26][15],short &countMutari)
{
    if(isDubla(translatePlayer(startJucator,player1,player2)) == true)
    {
        if(startJucator == 1)
        {
            if(mutareImposibila(tabla,startJucator,player1.zar1) == true)
            {
                countMutari = 0;
                player1.zar1 = 0;
                player2.zar2 = 0;
            }
        }
        else
        {
            if(mutareImposibila(tabla,startJucator,player2.zar1) == true)
            {
                countMutari = 0;
                player2.zar1 = 0;
                player2.zar2 = 0;
            }
        }
    }
    else
    {
        if(startJucator == 1)
        {
            if(checkPieseEliminate(startJucator,tabla) == false)
            {
                if(tabla[0][1] != ' ')
                {
                    if(mutareImposibila(tabla,startJucator,player1.zar1) == true)
                    {
                        countMutari--;
                        player1.zar1 = 0;
                    }
                    if(mutareImposibila(tabla,startJucator,player1.zar2) == true)
                    {
                        countMutari--;
                        player1.zar2 = 0;
                    }
                }
                else
                {
                    if(mutareImposibila(tabla,startJucator,player1.zar1) == true && mutareImposibila(tabla,startJucator,player1.zar2) == true)
                    {
                        countMutari = 0;
                        player1.zar1 = 0;
                        player1.zar2 = 0;
                    }
                    else if(player1.zar1 == 0)
                    {
                        if(mutareImposibila(tabla,startJucator,player1.zar2) == true)
                        {
                            countMutari = 0;
                            player1.zar2 = 0;
                        }
                    }
                    else if(player1.zar2 == 0)
                    {
                        if(mutareImposibila(tabla,startJucator,player1.zar1) == true)
                        {
                            countMutari == 0;
                            player1.zar1 =0;
                        }
                    }
                }
            }
            else
            {
                if(mutareImposibila(tabla,startJucator,player1.zar1) == true && mutareImposibila(tabla,startJucator,player1.zar2) == true)
                {
                    countMutari = 0;
                    player1.zar1 = 0;
                    player1.zar2 = 0;
                }
                else
                {
                    if(mutareImposibila(tabla,startJucator,player1.zar1) == true && mutareImposibila(tabla,startJucator,player1.zar2) == true)
                    {
                        countMutari = 0;
                        player1.zar1 = 0;
                        player1.zar2 = 0;
                    }
                    else if(player1.zar1 == 0)
                    {
                        if(mutareImposibila(tabla,startJucator,player1.zar2) == true)
                        {
                            countMutari = 0;
                            player1.zar2 = 0;
                        }
                    }
                    else if(player1.zar2 == 0)
                    {
                        if(mutareImposibila(tabla,startJucator,player1.zar1) == true)
                        {
                            countMutari == 0;
                            player1.zar1 =0;
                        }
                    }
                }
            }
        }
        else
        {
            if(checkPieseEliminate(startJucator,tabla) == false)
            {
                if(tabla[0][1] != ' ')
                {
                    if(mutareImposibila(tabla,startJucator,player2.zar1) == true)
                    {
                        countMutari--;
                        player2.zar1 = 0;
                    }
                    if(mutareImposibila(tabla,startJucator,player2.zar2) == true)
                    {
                        countMutari--;
                        player2.zar2 = 0;
                    }
                }
                else
                {
                    if(mutareImposibila(tabla,startJucator,player2.zar1) == true && mutareImposibila(tabla,startJucator,player2.zar2) == true)
                    {
                        countMutari = 0;
                        player2.zar1 = 0;
                        player2.zar2 = 0;
                    }
                    else if(player2.zar1 == 0)
                    {
                        if(mutareImposibila(tabla,startJucator,player2.zar2) == true)
                        {
                            countMutari = 0;
                            player2.zar2 = 0;
                        }
                    }
                    else if(player2.zar2 == 0)
                    {
                        if(mutareImposibila(tabla,startJucator,player2.zar1) == true)
                        {
                            countMutari == 0;
                            player2.zar1 =0;
                        }
                    }
                }
            }
            else
            {
                if(mutareImposibila(tabla,startJucator,player2.zar1) == true && mutareImposibila(tabla,startJucator,player2.zar2) == true)
                {
                    countMutari = 0;
                    player2.zar1 = 0;
                    player2.zar2 = 0;
                }
                else
                {
                    if(mutareImposibila(tabla,startJucator,player2.zar1) == true && mutareImposibila(tabla,startJucator,player2.zar2) == true)
                    {
                        countMutari = 0;
                        player2.zar1 = 0;
                        player2.zar2 = 0;
                    }
                    else if(player2.zar1 == 0)
                    {
                        if(mutareImposibila(tabla,startJucator,player2.zar2) == true)
                        {
                            countMutari = 0;
                            player2.zar2 = 0;
                        }
                    }
                    else if(player2.zar2 == 0)
                    {
                        if(mutareImposibila(tabla,startJucator,player2.zar1) == true)
                        {
                            countMutari == 0;
                            player2.zar1 =0;
                        }
                    }
                }
            }
        }
    }
}

void scoaterePiesePl1(short startJucator,player &player1,char tabla[26][15],short ok1)
{
    short coloana,margine;
    if(startJucator == 1 && ok1 == 1)
    {
        coloana = 0;
        margine = 6;
        if(tabla[player1.zar1][0] == 'A')
        {
            while(tabla[player1.zar1][coloana] != ' ')
                coloana++;
            tabla[player1.zar1][coloana-1] = ' ';
            player1.eliminate++;
        }
        else
        {
            while(tabla[margine][0] != 'A')
                margine--;
            while(tabla[margine][coloana] != ' ')
                coloana++;
            tabla[margine][coloana-1] = ' ';
            coloana = 0;
            while(tabla[margine][coloana] != ' ')
                coloana++;
            tabla[margine - player1.zar1][coloana] = 'A';
        }
        coloana = 0;
        margine = 6;

        if(tabla[player1.zar2][0] == 'A')
        {
            while(tabla[player1.zar2][coloana] != ' ')
                coloana++;
            tabla[player1.zar2][coloana-1] = ' ';
            player1.eliminate++;
        }
        else
        {
            coloana = 0;
            while(tabla[margine][0] != 'A')
                margine--;
            while(tabla[margine][coloana] != ' ')
                coloana++;
            tabla[margine][coloana-1] = ' ';
            coloana = 0;
            while(tabla[margine][coloana] != ' ')
                coloana++;
            tabla[margine - player1.zar2][coloana] = 'A';
        }
    }
}

void scoaterePiesePl2(short startJucator,player &player2,char tabla[26][15],short ok2)
{
    short coloana,margine;
    if(ok2 == 1 && startJucator == 2)
    {
        coloana = 0;
        margine = 19;
        if(tabla[25-player2.zar1][0] == 'N')
        {
            while(tabla[25-player2.zar1][coloana] != ' ')
                coloana++;
            tabla[25-player2.zar1][coloana - 1] = ' ';
            player2.eliminate++;
        }
        else
        {
            coloana = 0;
            while(tabla[margine][0] != 'N')
                margine++;
            while(tabla[margine][coloana] != ' ')
                coloana++;
            tabla[margine][coloana-1] = ' ';
            coloana = 0;
            while(tabla[margine + player2.zar1][coloana] != ' ')
                coloana++;
            tabla[margine + player2.zar1][coloana] = 'N';
        }

        coloana = 0;
        margine = 19;

        if(tabla[25-player2.zar2][0] == 'N')
        {
            coloana=0;
            while(tabla[25-player2.zar2][coloana] != ' ')
                coloana++;
            tabla[player2.zar2][coloana-1] = ' ';
            player2.eliminate++;
        }
        else
        {
            coloana = 0;
            while(tabla[margine][0] != 'N')
                margine++;
            while(tabla[margine][coloana] != ' ')
                coloana++;
            tabla[margine][coloana-1] = ' ';
            coloana = 0;
            while(tabla[margine][coloana] != ' ')
                coloana++;
            tabla[margine + player2.zar2][coloana] = 'N';
        }
    }
}

void ojocTable()
{
    char mode, tabla[26][15];
    short startJucator,countMutari,piese1=0,piese2=0,ok1=0,ok2=0;
    bool ambeleZaruriImposibile, firstMove = true;
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

        recalculateCountMutari(startJucator,player1,player2,tabla,countMutari);

        if(countMutari == 0)
            ambeleZaruriImposibile = true;

        while(countMutari)
        {
            checkToatePieseleInCasa(tabla,startJucator,piese1,piese2);

            if(piese1 == 15)
                ok1=1;
            if(piese2 == 15)
                ok2=2;
            if(ok1 == 1)
                scoaterePiesePl1(startJucator,player1,tabla,ok1);
            else if(ok2 == 1)
                scoaterePiesePl2(startJucator,player2,tabla,ok2);
            else if(ok1 ==0)
            {
                datedeintrare1:
                dateDeIntrare(deLa,la,player1,player2,startJucator,mode,firstMove);

                if(checkPieseEliminate(startJucator,tabla) == false)
                {
                    if(checkDeLa(deLa,startJucator) == false)
                    {
                        cout<<"You have pieces removed by your opponent. Get them back in the game."<<endl;
                        goto datedeintrare1;
                    }
                    if(checkDatePieseEliminate(deLa,la,startJucator,player1,player2,tabla) == false)
                        goto datedeintrare1;
                }
                else if(checkDateIntrare(deLa,la,startJucator,player1,player2,tabla) == false)
                    goto datedeintrare1;
                mutari(deLa,la,tabla);
            }
            else if(ok2 == 0)
            {
                datedeintrare2:
                dateDeIntrare(deLa,la,player1,player2,startJucator,mode,firstMove);

                if(checkPieseEliminate(startJucator,tabla) == false)
                {
                    if(checkDeLa(deLa,startJucator) == false)
                    {
                        cout<<"You have pieces removed by your opponent. Get them back in the game."<<endl;
                        goto datedeintrare2;
                    }
                    if(checkDatePieseEliminate(deLa,la,startJucator,player1,player2,tabla) == false)
                        goto datedeintrare2;
                }
                else if(checkDateIntrare(deLa,la,startJucator,player1,player2,tabla) == false)
                    goto datedeintrare2;
                mutari(deLa,la,tabla);
            }

            checkToatePieseleInCasa(tabla,startJucator,piese1,piese2);
            Sleep(100);

            system("cls");
            afisareTabla(tabla);
            if(startJucator == 1)
            {
                short mutare;
                if(deLa != 0)
                    mutare = deLa - la;
                else
                    mutare = 25 - la;
                mutareFacuta(countMutari,player1,mutare);
                cout<<player1.zar1<<" "<<player1.zar2<<endl;
            }
            else if(startJucator == 2)
            {
                short mutare;
                if(deLa != 25)
                    mutare = la - deLa;
                else
                    mutare = la;
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
            cout<<"No moves can be made."<<endl;
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
    return 0;
}
