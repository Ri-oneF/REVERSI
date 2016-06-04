#include "REVERSI.h"

int judge_line(int dirc, int a, int b, int man);


void returnBox(int a, int b)
{
    // 引数として渡された座標から対応するマスをひっくり返す関数
        int tate, yoko;
        int i;//ループカウンタ
        int retu[8] = { 1, 1, 0, -1, -1, -1, 0, 1};//列部分
        int gyou[8] = { 0, 1, 1, 1, 0, -1, -1, -1};//行部分
        int enemy;
        switch(player){
            case BLACK: enemy = WHITE; break;
            case WHITE: enemy = BLACK; break;
        }

    for(i = 0; i < 8; i++ )
    {
      if(judge_line(i, a, b, player) == 1){
            for(tate = a + retu[i], yoko = b + gyou[i]; ; tate += retu[i], yoko += gyou[i])//周りを調べる！
                if(board[tate][yoko] == player){//自分のがあったら抜ける
                    break;
                }
                else if(board[tate][yoko] == enemy)
                    board[tate][yoko] = player;//相手の色があれば自分の色にぬりつぶす！
      }
    }
    board[a][b] = player;//指定された座標に置く！
}


// グローバル変数player に現在プレーしている方が格納されている
