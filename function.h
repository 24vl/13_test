#ifndef FUNCTION_H_
#define FUNCTION_H_


#include "Character.h"
#include <string>
#include<iostream>
using namespace std;

enum GAME_STATE
{
    START,
    PLAY,
    END,
    QUIT
};

string cmd;

void nameset(string cmd);



void bossEvent();


#endif // !FUNCTION_H_
