#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>
#include <windows.h>
#include <MMSystem.h>
#include <stdlib.h>
#pragma comment(lib, "Winmm.lib")
#include <conio.h>
#include <iomanip>
using namespace std;

vector <int> grid;

void clearinam() {
    grid.clear();
}
void zaidimas() {
    vector <int> skaiciai;

    cin.ignore();
    system("cls");
    srand(static_cast<unsigned int>(time(0)));
    int randomNum=0;
    set<int> generuotiNum;//set<int> gali buti leisti tik unikalus elementai
    for (int i=0; i<25; i++) { //generuoja skaicius
        randomNum= 1 + (rand()%25);
        while (generuotiNum.count(randomNum)>0) { //jeigu count daugiau nei 0, vadinasi toks elementas jau buvo gride, todel ji sugeneruoja is naujo ir ideda
            randomNum= 1 + (rand()%25);
        }
        grid.push_back(randomNum);
        generuotiNum.insert(randomNum);
    }
    /*grid[0]=1;
    grid[1]=2;
    grid[2]=3;
    grid[3]=4;
    grid[4]=5;*/
    cout<<setw(75)<<"ivesk savo laimingus skaichius iki 25, shmiki"<<endl;
    for (int i=0; i<5; i++) {
        int gaidys;
        cin>>gaidys;
        if (gaidys>0 && gaidys <=25) {
            skaiciai.push_back(gaidys);
        }
        else cout <<"nesugebejai net perskaityt kas rashoma welnes :/"<<endl;
    }
    for (int j=0; j<grid.size(); j++) {
        if (j%5==0) {
            cout<<endl;
        }
        bool found = false;
        for (int i=0; i<skaiciai.size(); i++) {
            if (grid[j]==skaiciai[i]) {
                cout<<"X"<<" ";
                grid[j]=420;
                found = true;
                break;
            }
        }
        if (!found) {
            cout<<grid[j]<<" ";
        }
    }
    return;
}

void rollinam () {
    //hardcodinu nes tikrai neieskosiu visu formuliu pjbt man
     bool win = false;

    if ((grid[0] == 420 && grid[4] == 420 && grid[20] == 420 && grid[24] == 420 && grid[12] == 420) || // Main diagonal
        (grid[0] == 420 && grid[1] == 420 && grid[2] == 420 && grid[3] == 420 && grid[4] == 420) ||     // First row
        (grid[20] == 420 && grid[21] == 420 && grid[22] == 420 && grid[23] == 420 && grid[24] == 420) || // Last row
        (grid[0] == 420 && grid[5] == 420 && grid[10] == 420 && grid[15] == 420 && grid[20] == 420) ||  // First column
        (grid[4] == 420 && grid[9] == 420 && grid[14] == 420 && grid[19] == 420 && grid[24] == 420) || // Last column
        (grid[0] == 420 && grid[6] == 420 && grid[12] == 420 && grid[18] == 420 && grid[24] == 420) || // Main diagonal from top left to bottom right
        (grid[20] == 420 && grid[16] == 420 && grid[12] == 420 && grid[8] == 420 && grid[4] == 420) ||  // Main diagonal from bottom left to top right
        (grid[5] == 420 && grid[6] == 420 && grid[7] == 420 && grid[8] == 420 && grid[9] == 420) ||    // Second row
        (grid[10] == 420 && grid[11] == 420 && grid[12] == 420 && grid[13] == 420 && grid[14] == 420) ||// Third row
        (grid[15] == 420 && grid[16] == 420 && grid[17] == 420 && grid[18] == 420 && grid[19] == 420) ||// Fourth row
        (grid[1] == 420 && grid[6] == 420 && grid[11] == 420 && grid[16] == 420 && grid[21] == 420) ||  // Second column
        (grid[2] == 420 && grid[7] == 420 && grid[12] == 420 && grid[17] == 420 && grid[22] == 420) ||  // Third column
        (grid[3] == 420 && grid[8] == 420 && grid[13] == 420 && grid[18] == 420 && grid[23] == 420))    // Fourth column
    {
        win = true;
    }

    if (win) {
        cout <<endl<< "pyzdiec, laimejai" << endl;
    } else {
        cout <<endl<< "nevykelis" << endl;
    }
}

int main()
{
    vector <double> procentai;
    srand(static_cast<unsigned int>(time(0)));
    for (int i=0; i<10; i++) {
        double procentas = 1.2 + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(9.4-1.2)));
        procentai.push_back(procentas);
    }
    int pasirinkimas, bilietai=10;
    bool playAgain = true;
    //PlaySound(TEXT("dainuske.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
    cout<<setw(75)<<"zdarof, sw atwykes y pashilu kazino"<<endl<<setw(75)<<"tu krc turi 10 bilietu, wisus sunaudoji ir vsio laiswas"<<endl;
    while (playAgain) {
        if (bilietai>0) {
                cout<<setw(75)<<"pasirink ar zhaisi ar ne nevykeli"<<endl<< "1. zhaisiu!!!11!!!!1!!!"<<endl<<"2. nezhaisiu haha"<<endl;
        cin>>pasirinkimas;
    if (pasirinkimas==1) {
        clearinam();
        zaidimas();
        rollinam();
    }
    else playAgain = false;
    cout<<"dar zhaisi? jei normalus, spausk 1. jei trioxala, spausk 0"<<endl<<"liko "<<bilietai<<" talonu"<<endl<<"nepamirshk kad "<<% save gerbianchiu gambleriu isheina priesh laimedami aukso poda"<<endl;
    cin>>playAgain;
    bilietai--;
    }
    }

    return 0;
}
