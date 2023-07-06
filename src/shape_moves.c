/**
 * @file shape_moves.c
 * @author Daniel Adamkovic (dadamkovic@protonmail.ch)
 * @brief 
 * @version 0.1
 * @date 04-07-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "shape_moves.h"


uint8_t rotateShape(char *play_field){
    int8_t shape_coord[4][2];
    getShapeCoord(play_field, shape_coord);
    int8_t adj_x = shape_coord[1][0];
    int8_t adj_y = shape_coord[1][1];

    //coordinates to be adjusted in relation to second
    //found point thta is considered [0,0] coordinate
    rotateCoord(shape_coord, adj_x, adj_y);
    if(checkMovePossible(play_field, shape_coord) == MOVE_IMPOS){
        return MOVE_POS;
    }
    eraseShape(play_field);
    writeShape(play_field, shape_coord);

    return MOVE_IMPOS;
}


uint8_t rotateCoord(int8_t (*shape_coord)[2], int8_t adj_x, int8_t adj_y){
    int8_t x,y = 0;
    for(uint8_t i=0;i<4;i++){
        shape_coord[i][0] -= adj_x;
        shape_coord[i][1] -= adj_y;
        x = shape_coord[i][0];
        y = shape_coord[i][1]; 
        shape_coord[i][0] = -y;
        shape_coord[i][1] = x;
        shape_coord[i][0] += adj_x;
        shape_coord[i][1] += adj_y;

    }
    return 0;
}

uint8_t checkMovePossible(char *play_field, int8_t (*shape_coord)[2]){
    uint8_t x,y = 0;
    char helper;
    for(uint8_t i=0;i<4;i++){
        x = shape_coord[i][0];
        y = shape_coord[i][1];
        helper = *(play_field + y*MAX_COLUMNS + x);
        if(helper == DEAD_SYMBOL) return MOVE_IMPOS;
        if(x<0 || y<0) return MOVE_IMPOS;
        if(x >= MAX_COLUMNS || y >= MAX_ROWS) return MOVE_IMPOS;
    }

    return MOVE_POS;
}

uint8_t moveShape(char *play_field, enum_Move_Type move){
    int8_t shape_coord[4][2];
    getShapeCoord(play_field, shape_coord);
    int8_t x,y=0;
    switch(move){
        case MOVE_DOWN:
            y += 1;
            break;
        case MOVE_LEFT:
            x -= 1;
            break;
        case MOVE_RIGHT:
            x += 1;
            break;
        default:
            //todo: add error message
            return MOVE_IMPOS;
    }

    for(uint8_t i=0; i<4; i++){
        shape_coord[i][0] += x;
        shape_coord[i][1] += y;
    }

    if(checkMovePossible(play_field, shape_coord) == MOVE_IMPOS){
        if(move == MOVE_DOWN){
            killShape(play_field);
            checkFullRow(play_field);
            return MOVE_IMPOS;
        }
        return MOVE_IMPOS;
    }
    
    eraseShape(play_field);
    writeShape(play_field, shape_coord);

    return MOVE_POS;
}