// Playground - noun: a place where people can play

import Cocoa

var field = Array<Array<Int>>()
var rowFieldNr = 11
var columnFieldNr = 9
for i in 0..<columnFieldNr {
    field.append(Array(count: rowFieldNr, repeatedValue: Int()))
}
for i in 0..<columnFieldNr{
    for j in 0..<rowFieldNr{
        field[i][j]=0
    }
}
var field_pos = -1
var fieldsDecided = 0;
var isActive = true;

func reset ()-> Void {
    for(var i=0; i<field.count; i++) {
        for(var j=0; j<field[i].count; j++) {
            field[i][j]=0;
        }
    }
}

func prvarField()->Void {
    for(var i=0; i<11; i++) {
        println("\(i): ");
        for(var j=0; j<9; j++) {
            println( "\(field[i][j])  ");
        }
        
        
    }
}

func victory(var arr:[Int])->Int {
    for (var i=0;i<3;i++) {
        if ((arr[i*3] == arr[i*3+1]) && (arr[i*3] == arr[i*3+2]) && (arr[i*3] != 0)){
            return arr[i*3];
        }
        if ((arr[i] == arr[i+3]) && (arr[i]==arr[i+6]) && (arr[i] != 0)){
            return arr[i];
        }
    }
    if ((arr[0] == arr[4]) && (arr[4] == arr[8]) && (arr[4] != 0)){
        return arr[4];
    }
    if ((arr[2] == arr[4])&&(arr[4] == arr[6]) && (arr[4] != 0)){
        return arr[4];
    }
    return 0;
}

func tie(var pos:Int)->Void {
    if(field[10][pos]==9) {field[9][pos]=2;}
}

func set(var player:Int, var pos:Int)->Bool {
    if(field[field_pos][pos]==0) {
        field[field_pos][pos]=player;
        field[10][field_pos]++;
    } else {return false;}
    var result=victory(field[field_pos]);
    if (result != 0) {
        field[9][field_pos]=result;
        fieldsDecided++;
        prvarField();
        var overall_vic=victory(field[9]);
        if(overall_vic != 0) {
            println( "Spieler \(overall_vic) hat das gesamte Spiel gewonnen.");
            isActive=false;
        }
    } else {tie(field_pos);}
    
    if (field[9][pos]==0){field_pos=pos;}
    else {field_pos = -1;}
    
    return true;
}

func randomPlayer(var player:Int)->Void {
    if(field_pos == -1) {
        var newFP:Int
        do {
            newFP = Int(rand())%9;
        } while ((field[9][newFP] != 0)) {
            field_pos=newFP
        }
    }
    var pos=Int(rand())%9;
    while(!set(player, pos)) {
        pos=Int(rand())%9;
    }
}
//while true{
    var k=0;
    var player=1;
    while(isActive && (fieldsDecided < 9)) {
        randomPlayer(player);
        k++;
        player *= -1;
    }
    println(" \(k) ")
    prvarField();
//}
