#include <iostream>

using namespace std;

int field[11][9];
int field_pos=-1;

void reset () {
    for(int i=0; i<sizeof(field)/sizeof(field[0]); i++) {
        for(int j=0; j<sizeof(field[i])/sizeof(field[j][0]); j++) {
            field[i][j]=0;
        }
    }
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
        int overall_vic=victory(field(9));
        if(overall_vic!=0) {
            cout << "Spieler " + overall_vic + " hat das gesamte Spiel gewonnen." << endl;
        }
    } else {tie(field_pos);}

    if (field[9][field_pos]!=0){field_pos=pos;}
    else {field_pos=-1;}

    return true;
}


int main()
{

    return 0;
}

