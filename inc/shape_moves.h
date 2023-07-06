/**
 * @file shape_moves.h
 * @author Daniel Adamkovic (dadamkovic@protonmail.ch)
 * @brief 
 * @version 0.1
 * @date 04-07-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef _SHAPE_MOVES_H
#define _SHAPE_MOVES_H

#include "defines.h"
#include "game_control.h"

/**
 * @brief Moves the active block within the playing field or kills it
 * 
 * @param play_field char array of MAX_ROWS x MAX_COLUMS
 * @param move MOVE_LEFT, MOVE_RIGHT, MOVE_DOWN
 * @return uint8_t Returns MOVE_IMPOS if move not possible, otherwise MOVE_POS
 */
uint8_t moveShape(char *play_field, enum_Move_Type move);

/**
 * @brief Checks if the shape can be placed into given coordinates 
 * 
 * @param play_field char array of MAX_ROWS x MAX_COLUMS
 * @param shape_coord  int8_t array[4][2] - [](x,y)
 * @return uint8_t Return MOVE_IMPOS if not possible, othwerise MOVE_POS
 */
uint8_t checkMovePossible(char *play_field, int8_t (*shape_coord)[2]);

/**
 * @brief Rotates the shape's coordinates 90deg and returns new coordinates
 * 
 * @param shape_coord Current shape coordinates
 * @param adj_x In conjunction with adj_y used for selecting the rot. point
 * @param adj_y See adj_x
 * @return uint8_t Always return 0
 */
uint8_t rotateCoord(int8_t (*shape_coord)[2], int8_t adj_x, int8_t adj_y);

/**
 * @brief Finds the active block in the play_field and rotates it 90deg
 * 
 * @param play_field char array of MAX_ROWS x MAX_COLUMS
 * @return uint8_t Returns MOVE_IMPS if rotation not possible or MOVE_POS
 */
uint8_t rotateShape(char *play_field);

#endif