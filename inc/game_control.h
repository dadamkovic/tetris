/**
 * @file game_contro.h
 * @author Daniel Adamkovic (dadamkovic@protonmail.ch)
 * @brief 
 * @version 0.1
 * @date 04-07-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _GAME_CONTROLS_H
#define _GAME_CONTROLS_H

#include "defines.h"


/**
 * @brief Checks for any dead shapes in stage  (finish condition)
 * 
 * @param play_field char array of MAX_ROWS x MAX_COLUMS
 * @return uint8_t GAME_FINISHED or GAME_RUNNING
 */
uint8_t checkFinished(char *play_field);


/**
 * @brief Add a random shape into random position in the stage
 * 
 * @param play_field char array of MAX_ROWS x MAX_COLUMS
 * @return uint8_t Always returns 0
 */
uint8_t addShape(char *play_field);

/**
 * @brief Prints the playing field into the console without stage.
 * 
 * @param play_field char array of MAX_ROWS x MAX_COLUMS
 * @return uint8_t Always returns 0
 */
uint8_t printField(char *play_field);

/**
 * @brief Prints the playing field with stage into the console.
 * 
 * @param play_field char array of MAX_ROWS x MAX_COLUMS
 * @return uint8_t Always returns 0
 */
uint8_t printFullField(char *play_field);

/**
 * @brief Used by printField & printFullField for printing the game
 * 
 * @param play_field char array of MAX_ROWS x MAX_COLUMS
 * @param type 
 * @return uint8_t Always returns 0
 */
uint8_t printGame(char *play_field, enum_ShowSelect_Type type);

/**
 * @brief Used to select a random BLOCK
 * 
 * @return struct_Shape_Data* Block data & block width (all blocks 4 high)
 */
struct_Shape_Data *getRandomShape();

/**
 * @brief Gets the coordinates of all shape 'pixels'
 * 
 * @param play_field char array of MAX_ROWS x MAX_COLUMS
 * @param shape_coord int8_t array[4][2] - [](x,y)
 * @return uint8_t Always returns 0
 */
uint8_t getShapeCoord(char *play_field, int8_t (*shape_coord)[2]);


/**
 * @brief Locates the block's pixels and removes them from the play_field
 * 
 * @param play_field char array of MAX_ROWS x MAX_COLUMS
 * @return uint8_t ALways return 0
 */
uint8_t eraseShape(char *play_field);

/**
 * @brief Writes the shape's pixels into paly_field at spec. coordinates
 * 
 * @param play_field char array of MAX_ROWS x MAX_COLUMS
 * @param shape_coord int8_t array[4][2] - [](x,y)
 * @return uint8_t Always returns 0
 */
uint8_t writeShape(char *play_field, int8_t (*shape_coord)[2]);

/**
 * @brief Finds the currently active block and turns it into wall
 * 
 * @param play_field char array of MAX_ROWS x MAX_COLUMS
 * @return uint8_t Always return 0
 */
uint8_t killShape(char *play_field);


uint8_t checkFullRow(char *play_field);
uint16_t score(enum_Score_Type op);


#endif


