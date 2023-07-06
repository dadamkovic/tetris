/**
 * @file defines.h
 * @author Daniel Adamkovic (dadamkovic@protonmail.ch)
 * @brief 
 * @version 0.1
 * @date 04-07-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _DEFINES_H
#define _DEFINES_H

#include "inttypes.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>


//#define ERASE_SCREEN

#define STAGE_SIZE 4
#define MAX_ROWS 10+STAGE_SIZE
#define MAX_COLUMNS 5

#define GAME_FINISHED 1
#define GAME_RUNNING 0
#define MOVE_POS 1
#define MOVE_IMPOS 0


#define SCORED 1
#define NOT_SCORED 0

#define BLOCK_SYMBOL '#'
#define EMPTY_SYMBOL ' '
#define DEAD_SYMBOL 'X'

typedef enum{
    RET_SCORE = 0,
    INC_SCORE = 1
    
}enum_Score_Type;

typedef enum{
    I_BEAM,
    O_BLOCK,
    T_BLOCK,
    L_BLOCK,
    J_BLOCK,
    S_BLOCK,
    Z_BLOCK,
    N_SHAPES
}enum_Shape_Type;

typedef enum{
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT
}enum_Move_Type;

typedef enum{
    NO_STAGE_GAME,
    FULL_GAME
}enum_ShowSelect_Type;

typedef struct{
    const char *data;
    uint8_t width;
}struct_Shape_Data;

#define NUM_SHAPES N_SHAPES 




#endif
