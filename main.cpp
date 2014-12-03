#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>

using namespace std;

int field[11][9];
int field_pos=-1;
int fieldsDecided=0;
bool isActive=true;
int wonGames[3]={0,0,0};
int playedGames=0;

void reset () {
    for(int i=0; i<sizeof(field)/sizeof(field[0]); i++) {
        for(int j=0; j<sizeof(field[i])/sizeof(field[j][0]); j++) {
            field[i][j]=0;
        }
    }
    fieldsDecided=0;
    isActive=true;
    field_pos=-1;
}

void printField() {
/*		cout << "----------------------------------------------" << endl;	
    for(int i=0; i<3; i++) {
	for(int j=0;j<3; j++){
		cout <<"| " << field[i*3][j*3] << "  " << field[i*3][j*3+1] << "  " << field[i*3][j*3+2] << "\t| " << field[i*3+1][j*3] << "  " <<field[i*3+1][j*3+1] << "  " <<field[i*3+1][j*3+2] << "\t| " << field[i*3+2][j*3] << "  " << field[i*3+2][j*3+1] << "  " << field[i*3+2][j*3+2] << " |" << endl;
	}
		cout << "----------------------------------------------" << endl;
*/
	    //}
	    //cout << " | ";
	/*cout << i << ": ";
        for(int j=0; j<9; j++) {
            cout << field[i][j] << "  ";
        }
        cout << endl;
*/
    
    cout << "Spieler 1: " <<wonGames[0] << " Spieler -1: " << wonGames[1] << " Unentschieden: " << wonGames[2] << endl;
    for(int i=0;i<3;i++){
	cout << field[9][i*3] << " | " << field[9][i*3+1] << " | " << field[9][i*3+2] << endl;
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
    if(field[10][pos]==9) {
        field[9][pos]=2;
        fieldsDecided++;
    }
}

bool set(int player, int pos) {
    if(field[field_pos][pos]==0) {
        field[field_pos][pos]=player;
         field[10][field_pos]++;
    } else {return false;}
    int result=victory(field[field_pos]);
    if (result==0){wonGames[2]+=1;}
    if (result!=0) {
        field[9][field_pos]=result;
        fieldsDecided++;
        int overall_vic=victory(field[9]);
        if(overall_vic!=0) {
		if (overall_vic==1){
			wonGames[0]+=1;
		} else {wonGames[1]+=1;}

            //cout << "Spieler " << overall_vic << " hat das gesamte Spiel gewonnen." << endl;
            isActive=false;
        }
    } else {tie(field_pos);}

    if (field[9][pos]==0){field_pos=pos;}
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
    while (playedGames<1e5) {
	playedGames++;
    	srand(time(0));
    	reset();
   	int k=0;
    	int player=1;
    	while(isActive && (fieldsDecided<9)) {
        	randomPlayer(player);
        	k++;
        	player*=-1;
    	}
    	//cout << k << endl;
    	//printField();
    //sleep(1);
    }
    printField();
    return 0;
}

