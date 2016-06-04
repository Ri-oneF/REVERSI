#include "REVERSI.h"

int isFinish()
{
    // 終了条件
    // どちらのプレイヤーも置く場所がなくなれば終了
    
    // 作成した numAbleBox関数 を使う
    
    // 終了なら return 1;
    // まだなら return 0;
    
    int gomi[HEIGHT*WIDTH][2];
    
    if(numAbleBox(BLACK, gomi)==0 && numAbleBox(WHITE, gomi)==0){
        return 1;
    } else {
        return 0;
    }
    
    return 0;
}