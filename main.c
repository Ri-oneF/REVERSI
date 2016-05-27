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
	update_screen("　F-team REVERSI\n\n");

	// 入力を受け取る変数
	int iHeight, iWidth;

	// ゲームはいつ終わるかわからないので無限ループにした方がいいと思う
	while(1){

		/* --------プレイヤーが置ける場所があるか確認、なければスキップ-------- */
		/*
		if (numAbleBox(player) == 0)
		{
			(player) ? printf("\n 黒 ") : printf("\n 白 ");
			printf("のターンです... が、置ける場所がありません！\n");
			continue;
		}
		*/

		/* --------プレイヤーがひっくり返せるまでループさせる-------- */
		// とりあえず座標を入力する方法で進めておきます
		while(1){

			/* 誘導と入力 */
			(player) ? printf(" 黒 ") : printf(" 白 ");
			printf("のターンです.\nどこに石を置きますか？\n(横, 縦) : ");
			scanf("%d,%d",&iHeight, &iWidth);
			puts("");

			iHeight--; iWidth--; /* 配列が0から始まるので */

			/* ----石が置けるかどうかの判定---- */
			if( !((0<=iHeight&&iHeight<HEIGHT) && (0<=iWidth&&iWidth<WIDTH)) ){
				update_screen("\a　範囲外の値が入力されました。\n\n");
			} else if( board[iHeight][iWidth] != MARK ){
				update_screen("\a　その場所には既に石が置かれています。\n\n");
			} else if( judgeBox(iHeight,iWidth) >= 1 ){
				/* ====その場所で相手の石を挟めるか判定==== */
				/* ====ひっくり返してからループを抜ける==== */
				returnBox(iHeight, iWidth); /* ここでひっくり返してます！ */
				update_screen("　置けました！\n\n");
				break;
			} else {
				update_screen("\a　その場所に石は置けないようです...\n\n");
			}

		}

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