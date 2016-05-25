#include "REVERSI.h"

void init()
{
	// ２次元配列boardの初期化
	/* 既に0で初期化されてるはず…？ */

	// やむを得ずグローバルに変数等を置いた時は、それを初期化する関数を作ります。
	// ここで初期化するのは board[HEIGHT][WIDHT] と player
	player = BLACK;

	// init は initial(イニシャル) の省略です
	// 関数名は別になんでもいいです

	// スタート地点になる真ん中の4つも配置する
	board[HEIGHT/2-1][WIDTH/2-1] = WHITE;
	board[HEIGHT/2  ][WIDTH/2  ] = WHITE;
	board[HEIGHT/2  ][WIDTH/2-1] = BLACK;
	board[HEIGHT/2-1][WIDTH/2  ] = BLACK;

	/*
	オセロ協会的には石の初期位置は白が左上で、黒が先行だそうです
	*/

}