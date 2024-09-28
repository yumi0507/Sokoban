#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <vector>
#include "sokoban.h"
using namespace std;

Map::Map(fstream* file){
    times = 0;
    end = false;
    *file >> Row >> Col;
    for(int r = 0; r < Row; r++){
        vector<char> aRow;
        for(int c = 0; c < Col; c++){
            char str;
            *file >> str;
            if(str == '/')
                aRow.push_back('#');
            else if(str == '-')
                aRow.push_back(' ');
            else if(str == '0'){
                playerRow = r;
                PR = r;
                playerCol = c;
                PC = c;
                aRow.push_back(' ');
            }
            else if(str == '1'){
                boxRow = r;
                BR = r;
                boxCol = c;
                BC = c;
                aRow.push_back(' ');
            }
            else if(str == '2')
                aRow.push_back('G');
        }map.push_back(aRow);
    }
}

void Map::Play(){
    while(true){
        showMap();
        cout << "Enter W, A, S, D to control your movement, R to reset, E to exit.";
        int move; move = getch();
        if(move == int('e') || move == int('E')){
            cout << endl;
            break;
        }else if(move == 224){
            move = getch();
            switch(move){
                case 72:
                    move = 'w';
                    break;
                case 80:
                    move = 's';
                    break;
                case 75:
                    move = 'a';
                    break;
                case 77:
                    move = 'd';
                    break;
                default:
                    break;
            }
        }
        Move(char(move));
        if(end){
            cout << "You reach the goal." << endl;
            cout << "You move " << times << " step";
            if(times != 0 && times != 1)
                cout << "s";
            cout << " in total." << endl << endl;
            break;
        }
    }
}

void Map::Move(char move){
    if(move >= 'A' && move <= 'Z')
        move += 32;
    
    bool boxMove = false, playerMove = false;
    if(move == 'w'){
        if(map[playerRow-1][playerCol] == '#'){

        }else if(playerRow-1 == boxRow && playerCol == boxCol){
            if(map[boxRow-1][boxCol] == '#'){

            }else if(map[boxRow-1][boxCol] == 'G'){
                end = true;
                boxMove = playerMove = true;
            }else{
                boxMove = playerMove = true;
            }
        }else{
            playerMove = true;
        }

        if(playerMove){
            times++;
            playerRow--;
        }
        if(boxMove){
            boxRow--;
        }
    }else if(move == 's'){
        if(map[playerRow+1][playerCol] == '#'){

        }else if(playerRow+1 == boxRow && playerCol == boxCol){
            if(map[boxRow+1][boxCol] == '#'){

            }else if(map[boxRow+1][boxCol] == 'G'){
                end = true;
                boxMove = playerMove = true;
            }else{
                boxMove = playerMove = true;
            }
        }else{
            playerMove = true;
        }

        if(playerMove){
            times++;
            playerRow++;
        }
        if(boxMove){
            boxRow++;
        }
    }else if(move == 'a'){
        if(map[playerRow][playerCol-1] == '#'){

        }else if(playerCol-1 == boxCol && playerRow == boxRow){
            if(map[boxRow][boxCol-1] == '#'){

            }else if(map[boxRow][boxCol-1] == 'G'){
                end = true;
                boxMove = playerMove = true;
            }else{
                boxMove = playerMove = true;
            }
        }else{
            playerMove = true;
        }

        if(playerMove){
            times++;
            playerCol--;
        }
        if(boxMove){
            boxCol--;
        }
    }else if(move == 'd'){
        if(map[playerRow][playerCol+1] == '#'){

        }else if(playerCol+1 == boxCol && playerRow == boxRow){
            if(map[boxRow][boxCol+1] == '#'){

            }else if(map[boxRow][boxCol+1] == 'G'){
                end = true;
                boxMove = playerMove = true;
            }else{
                boxMove = playerMove = true;
            }
        }else{
            playerMove = true;
        }

        if(playerMove){
            times++;
            playerCol++;
        }
        if(boxMove){
            boxCol++;
        }
    }else if(move == 'r'){
        Reset();
    }

    system("cls");
}

void Map::Reset(){
    playerRow = PR;
    playerCol = PC;
    boxRow = BR;
    boxCol = BC;
    times = 0;
}

void Map::showMap(){
    cout << endl;
    for(int r = 0; r < Row; r++){
        cout << " ";
        for(int c = 0; c < Col; c++){
            if(boxRow == r && boxCol == c)
                cout << 'O';
            else if(playerRow == r && playerCol == c)
                cout << '@';
            else
                cout << map[r][c];
        }cout << endl;
    }cout << endl;

    cout << "You have moved " << times << " step";
    if(times != 0 && times != 1)
        cout << "s";
    cout << "." << endl << endl;

}