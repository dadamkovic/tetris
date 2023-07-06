/**
 * @file game_control.c
 * @author Daniel Adamkovic (dadamkovic@protonmail.ch)
 * @brief 
 * @version 0.1
 * @date 04-07-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "game_control.h"
#include "shape_moves.h"

const char I_BLOCK_DATA[4] = {'#','#','#','#'};
const char O_BLOCK_DATA[8] = {'#','#','#','#',' ',' ',' ',' '};
const char T_BLOCK_DATA[8] = {'#',' ','#','#','#',' ',' ',' '};
const char L_BLOCK_DATA[8] = {'#','#','#',' ','#',' ',' ',' '};
const char J_BLOCK_DATA[8] = {'#','#',' ','#',' ','#',' ',' '};
const char Z_BLOCK_DATA[8] = {'#',' ','#','#',' ','#',' ',' '};
const char S_BLOCK_DATA[8] = {' ','#','#','#','#',' ',' ',' '};

uint8_t checkFinished(char *play_field){   
    for(int16_t i=0; i<STAGE_SIZE; i++){
        for(int16_t j=0; j<MAX_COLUMNS; j++){
            if(*(play_field+i*MAX_COLUMNS+j) == DEAD_SYMBOL){
                return GAME_FINISHED;
            }
        }
    }
    return GAME_RUNNING;
}

uint8_t checkMoveDown(char *play_field){
    uint8_t move_result = MOVE_POS;

    for(int16_t i=(MAX_ROWS-1); i>(-1); i--){
            for(uint16_t j=0; j<MAX_COLUMNS; j++){
                if(*(play_field + i*MAX_COLUMNS + j) == BLOCK_SYMBOL){
                    if(i == (MAX_ROWS-1)) move_result = MOVE_IMPOS;
                    if(*(play_field + (i+1)*MAX_COLUMNS + j) == DEAD_SYMBOL) move_result = MOVE_IMPOS;
                }
            }
    }
    return move_result; 
}


struct_Shape_Data *getRandomShape(){
    static struct_Shape_Data shape_data;

    switch (rand() % NUM_SHAPES){
        case I_BEAM:
            shape_data.data = I_BLOCK_DATA;
            shape_data.width = 1;
            break;
        case O_BLOCK:
            shape_data.data = O_BLOCK_DATA; 
            shape_data.width = 2;
            break;
        case T_BLOCK:
            shape_data.data = T_BLOCK_DATA;
            shape_data.width = 2; 
            break;
        case L_BLOCK:
            shape_data.data = L_BLOCK_DATA;
            shape_data.width = 2; 
            break;
        case J_BLOCK:
            shape_data.data = J_BLOCK_DATA;
            shape_data.width = 2; 
            break;
        case S_BLOCK:
            shape_data.data = S_BLOCK_DATA;
            shape_data.width = 2; 
            break;
        case Z_BLOCK:
            shape_data.data = Z_BLOCK_DATA;
            shape_data.width = 2; 
            break;
    }
    return &shape_data;
}

uint8_t getShapeCoord(char *play_field, int8_t (*shape_coord)[2]){
    uint8_t counter = 0;

    for(uint16_t i=0; i<MAX_ROWS; i++){
        for(uint16_t j=0; j<MAX_COLUMNS; j++){
            if(*(play_field + i*MAX_COLUMNS + j) == BLOCK_SYMBOL){
                shape_coord[counter][0] = j;
                shape_coord[counter][1] = i;
                counter++;
            }
        }
    }
    return 0;
}

uint8_t eraseShape(char *play_field){
    int8_t shape_coord[4][2];
    uint8_t x, y = 0;
    getShapeCoord(play_field, shape_coord);

    for(uint8_t i=0;i<4;i++){
        x = shape_coord[i][0];
        y = shape_coord[i][1];
        *(play_field + y*MAX_COLUMNS + x) = EMPTY_SYMBOL;
    }

    return 0;
}

uint8_t writeShape(char *play_field, int8_t (*shape_coord)[2]){
    uint8_t x,y = 0;

    for(uint8_t i=0;i<4;i++){
        x = shape_coord[i][0];
        y = shape_coord[i][1];
        *(play_field + y*MAX_COLUMNS + x) = BLOCK_SYMBOL;
    }

    return 0;
}

uint8_t killShape(char *play_field){
    uint8_t x,y = 0;
    int8_t shape_coord[4][2];
    getShapeCoord(play_field, shape_coord);

    for(uint8_t i=0;i<4;i++){
        x = shape_coord[i][0];
        y = shape_coord[i][1];
        *(play_field + y*MAX_COLUMNS + x) = DEAD_SYMBOL;
    }

    return 0;
}


uint8_t addShape(char *play_field){
    //todo: Consider putting this in a separate function
    struct_Shape_Data *sel_shape = getRandomShape();
    const char *shape_data = sel_shape->data;
    uint8_t shape_width = sel_shape->width;
    

    uint16_t index = rand() % (MAX_COLUMNS - shape_width);

    for(int16_t i=0; i<STAGE_SIZE; i++){
        for(int16_t j=0; j<MAX_COLUMNS; j++){
            if((j >= index) && (j-index < shape_width)){
                *(play_field+i*MAX_COLUMNS+j) = *(shape_data+i*shape_width+j-index);
            }
        }
    }

    return 0;
}


uint8_t printGame(char *play_field, enum_ShowSelect_Type type){
    uint8_t print_start = 0; 
    if(type == NO_STAGE_GAME)print_start = (STAGE_SIZE-1);

    #ifdef ERASE_SCREEN
        printf("%c%c%c%c",0x1B,0x5B,0x32,0x4A);
    #endif
    for(uint8_t r=0;r<MAX_COLUMNS;r++)printf("--");
    printf("\n");

    for(uint16_t i=print_start; i<MAX_ROWS; i++){
        printf("|");
        for(uint16_t j=0; j<MAX_COLUMNS; j++){
            printf("%c ", *(play_field + i*MAX_COLUMNS + j));
        }
        printf("|");
        printf("\n");
    }

    for(uint8_t r=0;r<MAX_COLUMNS;r++)printf("--");
    printf("\n");

    return 0;

}


uint8_t printField(char *play_field){
    printGame(play_field, NO_STAGE_GAME);
    return 0;
}

uint8_t printFullField(char *play_field){
    printGame(play_field, FULL_GAME);
    return 0;
}


uint8_t removeRow(char *play_field, uint8_t row_idx){
    for(uint8_t i=row_idx;i > 0; i--){
        for(uint8_t j=0;j < MAX_COLUMNS;j++){
            *(play_field +i*MAX_COLUMNS+j) = *(play_field +(i-1)*MAX_COLUMNS+j);
        }
    }

    return 0;
}

uint16_t score(enum_Score_Type op){
    static uint16_t score = 0;

    score += (op*MAX_COLUMNS);
    return score;
}

uint8_t checkFullRow(char *play_field){
    uint8_t full_row;
    
    for(uint8_t i=0;i<MAX_ROWS;i++){
        full_row = 1;
        for(uint8_t j=0;j<MAX_COLUMNS;j++){
            if(*(play_field +i*MAX_COLUMNS+j) != DEAD_SYMBOL){
                full_row = 0; 
            }
        }

        if(full_row){
            removeRow(play_field, i);
            score(INC_SCORE);
            checkFullRow(play_field);
            return SCORED;
        }
    }

    return NOT_SCORED;
}