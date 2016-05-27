#include "REVERSI.h"

// main関数の中でグローバル変数を書き換えないように
//	 ->	ルールというわけではないけれど、Ri-oneでプログラム書く練習だと思ってやってみてください

/* 指定された文字で区切り線を表示する */
void draw_line(char c);
/* draw_line('-')で囲まれた文字列を表示します（メッセージウィンドウ的な使い方） */
void msg_window(char c[]);

/* draw_line()とview_board()とmessage()をひとまとめにしてゲームの、1ターンの画面とします */
void update_screen(char c[]);


int main()
{
	// ゲームボードの初期化
	init();

	// ゲームボードを表示
	putchar('\n');
	update_screen("  F-team REVERSI\n\n");

	int returnAble[HEIGHT*WIDTH][2];
	int returnAbleNum;
	int num;

	// ゲームはいつ終わるかわからないので無限ループにした方がいいと思う
	while(1){

		/* プレイヤーひっくり返すことのできる座標の数を調べる */
		returnAbleNum = numAbleBox(player, returnAble);

		/* ０ならスキップ */
		if (returnAbleNum == 0)
		{
			switch(player){
				case BLACK: printf(" 黒 "); break;
				case WHITE: printf(" 白 "); break;
			}
			printf("のターンです... が、置ける場所がありません！\n");
			changePlayer();
			continue;
		}

		/* 入力ループ */
		while(1){

			/* 誘導 */
			switch(player){
				case BLACK: printf(" 黒 "); break;
				case WHITE: printf(" 白 "); break;
			}
			printf("のターンです.\nどこに石を置きますか？: ");

			/* 入力 */
			scanf("%d",&num);

			/* 入力値の検証 */
			if(num <= 0 || returnAbleNum < num){
				update_screen("正しい値を入力してください。\n\n");
			} else {
				break;
			}


		}

		/* ｰｰｰｰｰｰｰｰ相手の石をひっくり返しメッセージを表示ｰｰｰｰｰｰｰｰ */
		returnBox(returnAble[num-1][0], returnAble[num-1][1]);
		update_screen("  置けました！\n\n");

		/* --------プレイヤーを相手に交代-------- */
		//changePlayer();

		/* --------ゲーム終了判定-------- */
		/*
		if (isFinish() == 1)
		{
			break; // 勝敗判定へ
		}
		*/


	}

	/* ========ここから勝敗判定======== */

	// 黒と白それぞれのコマの数を数えて、多いほうが価値
	if (getWinner() == BLACK)
	{
		// 黒の勝ち
	}
	else if (getWinner() == WHITE)
	{
		// 白の勝ち
	}
	else
	{
		// 引き分け
	}

	return 0;
}



void draw_line(char c){
	int i;
	for(i=0; i<(WIDTH+2)*4; i++) putchar(c);
	printf("\n\n");
}

void msg_window(char c[]){
	int i=0;
	draw_line('-');
	while(c[i]) putchar(c[i++]);
	draw_line('-');
}

void update_screen(char c[]){
	draw_line('=');
	view_board();
	msg_window(c);
}