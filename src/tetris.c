/**
 * @file tetris.c
 * @author Daniel Adamkovic (dadamkovic@protonmail.ch)
 * @brief 
 * @version 0.1
 * @date 15-10-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "tetris.h"

char field[(MAX_ROWS+STAGE_SIZE)*MAX_COLUMNS];

uint8_t tetrisSetup(tf_writeChar *wrChar, tf_getRandom *getR){
    writeChar = wrChar;
    getRandom = getR;


    return GAME_START_OK;
}

uint8_t tetrisStartGame(void){
    for(int16_t i=0; i<MAX_ROWS; i++){
        for(int16_t j=0; j<MAX_COLUMNS; j++){
            *(field+i*MAX_COLUMNS+j) = ' ';
            }
    }

    addShape(field);
    moveShape(field, MOVE_DOWN);
    printField(field);

    return GAME_START_OK;
}


uint16_t tetrisGetScore(void){
    return score(RET_SCORE);
}


uint8_t tetrisMove(enum_Move_Type move){
    uint8_t res = moveShape(field, move);
    printField(field);
    return res;
}


uint8_t tetrisAdvance(){
    uint8_t res = moveShape(field, MOVE_DOWN);
    printField(field);
    return res;
}


uint8_t tetrisCheckGameOver(){
    return checkFinished(field);
}
