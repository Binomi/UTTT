#include <iostream>
#include <stdlib.h>

using namespace std;

int field[11][9];
int field_pos=-1;
int fieldsDecided=0;
bool isActive=true;

void reset () {
    for(int i=0; i<sizeof(field)/sizeof(field[0]); i++) {
        for(int j=0; j<sizeof(field[i])/sizeof(field[j][0]); j++) {
            field[i][j]=0;
        }
    }
}

void printField() {
    for(int i=0; i<11; i++) {
        cout << i << ": ";
        for(int j=0; j<9; j++) {
            cout << field[i][j] << "  ";
        }
        cout << endl;

    }
    cout << endl;
}

int victory (int arr[]) {
    for (int i=0;i<3;i++) {
        if ((arr[i*3]==arr[i*3+1])&&(arr[i*3]==arr[i*3+2])&&(arr[i*3]!=0)){
            return arr[i*3];
        }
        if ((arr[i]==arr[i+3])&&(arr[i]==arr[i+6])&&(arr[i]!=0)){
            return arr[i];
        }
    }
    if ((arr[0]==arr[4])&&(arr[4]==arr[8])&&(arr[4]!=0)){
        return arr[4];
    }
    if ((arr[2]==arr[4])&&(arr[4]==arr[6])&&(arr[4]!=0)){
        return arr[4];
    }
    return 0;
}

void tie(int pos) {
    if(field[10][pos]==9) {field[9][pos]=2;}
}

bool set(int player, int pos) {
    if(field[field_pos][pos]==0) {
        field[field_pos][pos]=player;
         field[10][field_pos]++;
    } else {return false;}
    int result=victory(field[field_pos]);
    if (result!=0) {
        field[9][field_pos]=result;
        fieldsDecided++;
        printField();
        int overall_vic=victory(field[9]);
        if(overall_vic!=0) {
            cout << "Spieler " << overall_vic << " hat das gesamte Spiel gewonnen." << endl;
            isActive=false;
        }
    } else {tie(field_pos);}

    if (field[9][field_pos]==0){field_pos=pos;}
    else {field_pos=-1;}

    return true;
}

void randomPlayer(int player) {
    if(field_pos==-1) {
        int newFP;
        do {
            newFP = rand()%9;
        } while(field[9][newFP]!=0);
        field_pos=newFP;
    }
    int pos=rand()%9;
    while(!set(player, pos)) {
        pos=rand()%9;
    }
}

int main()
{
    int k=0;
    int player=1;
    while(isActive && (fieldsDecided<9)) {
        randomPlayer(player);
        k++;
        player*=-1;
    }
    cout << k << endl;
    printField();
    return 0;
}

