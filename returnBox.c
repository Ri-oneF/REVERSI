#include "REVERSI.h"

int judge_line_2(int dirc, int a, int b);

void returnBox(int a, int b)
{
	int tate, yoko;
	int dirc;
	int yc[8] = { 0, 1, 1, 1, 0,-1,-1,-1};
	int tc[8] = { 1, 1, 0,-1,-1,-1, 0, 1};
	int enemy;
	switch(player){
		case BLACK: enemy=WHITE; break;
		case WHITE: enemy=BLACK; break;
	}

	for(dirc=0; dirc<8; dirc++){
		if(judge_line_2(dirc, a, b) == 1){
			for(tate=a+tc[dirc],yoko=b+yc[dirc]; ; tate+=tc[dirc],yoko+=yc[dirc]){
				if(board[tate][yoko] == enemy){
					board[tate][yoko] = player;
				} else if(board[tate][yoko] == player){
					break;
				} else {
					puts("error");
				}
			}
		}
	}

	board[a][b] = player;

}


int judge_line_2(int dirc,int a,int b)
{
	int yoko, tate;
	/* 縦、横のループカウンタ */
	int yc, tc;
	/* 方向を表す用の加算・減算用変数 */
	int flag=0;
	/* 最低でもひとつは相手の色と隣り合ってたよ！っていうフラグ */

	int enemy;
	switch(player){
		case BLACK: enemy=WHITE; break;
		case WHITE: enemy=BLACK; break;
	}
	/* 相手の色をenemy変数に記憶 */


	/* 方向によってカウンタを動かす向きを変える */
	switch(dirc){
		case 0: yc= 0; tc= 1; break;
		case 1: yc= 1; tc= 1; break;
		case 2: yc= 1; tc= 0; break;
		case 3: yc= 1; tc=-1; break;
		case 4: yc= 0; tc=-1; break;
		case 5: yc=-1; tc=-1; break;
		case 6: yc=-1; tc= 0; break;
		case 7: yc=-1; tc= 1; break;
		default :puts("error in judge_line");
	}

	/* 相手の色が隣り合う限りずらして行く */
	for (yoko=b+yc,tate=a+tc; ; yoko+=yc,tate+=tc){

		/* ゲームボード範囲内の走査 */
		if ((0<=tate&&tate<HEIGHT && 0<=yoko&&yoko<WIDTH)){

			if(board[tate][yoko] == enemy){
				flag=1; /* 最低でも一個は相手の色と隣り合うことをここで記憶しておく */
				continue;
			} else {
				break;
			}

		/* ゲームボードの範囲を超えて走査しようとすると、もう挟めることもないので、諦める */
		} else {

			return 0;

		}
	}

	/* 自分の色ではさめてるかな？ */
	if(board[tate][yoko] == player && flag==1){
		return 1; /* 無事に挟まれていました */
	} else {
		return 0; /* 挟まれてないやん */
	}

}
