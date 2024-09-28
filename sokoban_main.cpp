#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "sokoban.h"
using namespace std;

void ExplainRule();
char Choice();

int main(){
    ExplainRule();
    while(true){
        string name;
        cout << "Enter the map's name that you want to open in the folder: ";
        cin >> name;
        name += ".txt";
        fstream file(name, ios::in);
        if(!file){
            cin.get();
            cout << "Fail to open the map." << endl;
            cout << "Press Enter to continue." << endl;
            while(true){
                if(cin.get() == '\n')
                    break;
            }
            system("cls");
            continue;
        }else{
            system("cls");
            Map game(&file);
            game.Play();
            char func = Choice();
            system("cls");
            
            file.close();
            if(func == '2')
                break;
        }
    }
    
}

void ExplainRule(){
    cout << "~ Game Sokoban ~" << endl;
    cout << endl;
    cout << "Rule:" << endl;
    cout << "   \" \": the road" << endl;
    cout << "   \"@\": you are here" << endl;
    cout << "   \"O\": the box" << endl;
    cout << "   \"G\": the goal" << endl;
    cout << "   \"#\": the wall" << endl;
    cout << endl;
    cout << "   Press W: go up" << endl;
    cout << "   Press S: go down" << endl;
    cout << "   Press A: go left" << endl;
    cout << "   Press D: go right" << endl;
    cout << endl;
    
    cout << "Press Enter to start the game." << endl;
    while(true){
        if(cin.get() == '\n'){
            system("cls");
            break;
        }
    }
}

char Choice(){
    cout << "1. Start a new game" << endl;
    cout << "2. Exit the game" << endl;
    cout << "Enter the number you choose: ";
    char func = '0';
    while(func != '1' && func != '2'){
        cin >> func;
        if(func == '1' || func == '2')
            return func;
        else
            cout << "\nInput Error. Please re-enter your choice: ";
    }
}