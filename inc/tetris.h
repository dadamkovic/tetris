/**
 * @file tetris.h
 * @author Daniel Adamkovic (dadamkovic@protonmail.ch)
 * @brief 
 * @version 0.1
 * @date 15-10-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _TETRIS_H
#define _TETRIS_H

#include "defines.h"
#include "game_control.h"
#include "shape_moves.h"

#define GAME_START_OK 0 
#define GAME_START_FAIL 1



uint8_t tetrisSetup(tf_writeChar *, tf_getRandom *);
uint8_t tetrisStartGame(void);
uint16_t tetrisGetScore(void);
uint8_t tetrisMove(enum_Move_Type move);
uint8_t tetrisAdvance();
uint8_t tetrisCheckGameOver();

#endif