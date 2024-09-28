#ifndef SOKOBAN_H
#define SOKOBAN_H
#include <fstream>
#include <vector>
using namespace std;

class Map{
    vector<vector<char>> map;
    int Row;
    int Col;
    int playerRow;
    int PR;
    int playerCol;
    int PC;
    int boxRow;
    int BR;
    int boxCol;
    int BC;
    int times;
    bool end;

public:
    Map(fstream*);
    void Play();
    void Move(char);
    void Reset();
    void showMap();
};

#endif