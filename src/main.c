#include "tetris.h"

#include <stdio.h>
#include <time.h>

uint8_t pCH(char c){
    printf("%c",c);
    return 0;
}

uint8_t rnd(){
    return 15;
}

uint8_t main(){


    tetrisSetup(pCH, rnd);
    tetrisStartGame();
    tetrisAdvance();
    tetrisAdvance();
    

    return 0;
}