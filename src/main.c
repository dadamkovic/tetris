#include "defines.h"
#include "game_control.h"
#include "shape_moves.h"

uint8_t main(){
    srand(time(NULL));

    char field[(MAX_ROWS+STAGE_SIZE)*MAX_COLUMNS];
    uint16_t count = sizeof(char)*MAX_COLUMNS*(MAX_ROWS+STAGE_SIZE);
    memset(field,EMPTY_SYMBOL,sizeof(char)*MAX_COLUMNS*(MAX_ROWS+STAGE_SIZE));

    char scan[1];
    while(checkFinished(field) != GAME_FINISHED){
        addShape(field);
        while(moveShape(field, MOVE_DOWN) != MOVE_IMPOS){
            printField(field);
            scanf("%c",scan);
            printf("\n");
            switch(*scan){
                case 'r':
                    rotateShape(field);
                    break;
                case 'a':
                    moveShape(field, MOVE_LEFT);
                    break;
                case 's':
                    moveShape(field, MOVE_RIGHT);
                    break;
                default:
                    break;
            }
            if(checkFinished(field) == GAME_FINISHED)goto FIN;
        }
    }
    
    FIN:
    printField(field);
    printf("\nGAME OVER!\n");
    printf("YOUR SCORE: %d",score(RET_SCORE));
    

    return 0;
}