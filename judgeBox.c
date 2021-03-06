#include "REVERSI.h"

/*
  dirc:
	0:下
	1:右下
	2:右
	3:右上
	4:上
	5:左上
	6:左
	7:左下
*/

int judge_line(int dirc, int a, int b, int man);

int judgeBox(int a, int b, int man)
{

	int dirc;

	for(dirc=0;dirc<8;dirc++){ /* 8方向について一つづつ調べるというループ */
		if(judge_line(dirc,a,b,man) == 1) return 1;
		/* 一度でも置けると判断すれば1を返す */
	}

	return 0;
	/* 残念ながら置けませんでした */

}

int judge_line(int dirc,int a,int b,int man)
{
	int yoko, tate;
	/* 縦、横のループカウンタ */
	int dirc_cnter[8][2]={
		{ 0, 1},
		{ 1, 1},
		{ 1, 0},
		{ 1,-1},
		{ 0,-1},
		{-1,-1},
		{-1, 0},
		{-1, 1}
	};
	/* 方向を表す用の加算・減算用変数 */
	int flag=0;
	/* 最低でもひとつは相手の色と隣り合ってたよ！っていうフラグ */

	int enemy;
	switch(man){
		case BLACK: enemy=WHITE; break;
		case WHITE: enemy=BLACK; break;
	}
	/* 相手の色をenemy変数に記憶 */


	/* 相手の色が隣り合う限りずらして行く */
	for (yoko=b+dirc_cnter[dirc][0],tate=a+dirc_cnter[dirc][1]; ; yoko+=dirc_cnter[dirc][0],tate+=dirc_cnter[dirc][1]){

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
	if(board[tate][yoko] == man && flag==1){
		return 1; /* 無事に挟まれていました */
	} else {
		return 0; /* 挟まれてないやん */
	}

}
