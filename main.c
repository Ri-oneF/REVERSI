#include "REVERSI.h"

// main関数の中でグローバル変数を書き換えないように
//	 ->	ルールというわけではないけれど、Ri-oneでプログラム書く練習だと思ってやってみてください

/* 指定された文字で区切り線を表示する */
void draw_line(char c);
/* draw_line('-')で囲まれた文字列を表示します（メッセージウィンドウ的な使い方） */
void msg_window(char c[]);

int main()
{
	// ゲームボードの初期化
	init();

	/* test */ /*
	board[0][1] = WHITE;
	board[0][2] = WHITE;
	board[0][3] = WHITE;
	board[0][4] = WHITE;
	board[0][5] = WHITE;
	board[0][6] = WHITE;
	board[0][7] = BLACK;
	board[1][0] = WHITE;
	board[2][0] = WHITE;
	board[3][0] = WHITE;
	board[4][0] = WHITE;
	board[5][0] = WHITE;
	board[6][0] = WHITE;
	board[7][0] = BLACK;
	board[1][1] = WHITE;
	board[2][2] = WHITE;
	board[3][3] = WHITE;
	board[4][4] = WHITE;
	board[5][5] = WHITE;
	board[6][6] = WHITE;
	board[7][7] = BLACK;
	*/


	// ゲームボードを表示
	putchar('\n');
	view_board();
	msg_window("ゲーム開始.\n\n");

	int returnAble[HEIGHT*WIDTH][2];
	int returnAbleNum;
	int num;

	// ゲームはいつ終わるかわからないので無限ループにした方がいいと思う
	while(1){

		/* ----プレイヤーひっくり返すことのできる座標の数を調べる---- */
		returnAbleNum = numAbleBox(player, returnAble);

		/* ０ならスキップ */
		if (returnAbleNum == 0)
		{
			changePlayer(); /* プレイヤーの色を変えてから盤面表示していることに注意 */
			view_board();
			draw_line('-');
			switch(player){
				case WHITE: printf(" 黒 "); break; /* 逆になってる */
				case BLACK: printf(" 白 "); break;
			}
			printf("のターンです... が、置ける場所がありません！\n\n");
			draw_line('-');
			continue;
		} else {
		}

		/* ----入力ループ---- */
		while(1){

			/* 誘導 */
			switch(player){
				case BLACK: printf(" 黒 "); break;
				case WHITE: printf(" 白 "); break;
			}
			printf("のターンです.\nどこに石を置きますか？: ");

			/* 入力 */
			scanf("%d",&num); puts("");

			/* 入力値の検証 */
			if(num <= 0 || returnAbleNum < num){
				view_board();
				msg_window("正しい値を入力してください。\n\n");
			} else {
				break;
			}


		}

		/* ｰｰｰｰｰｰｰｰ相手の石をひっくり返しメッセージを表示ｰｰｰｰｰｰｰｰ */
		returnBox(returnAble[num-1][0], returnAble[num-1][1]);

		/* --------プレイヤーを相手に交代-------- */
		changePlayer();
		view_board();

		msg_window("置けました！\n\n");

		/* --------ゲーム終了判定-------- */
		if (isFinish() == 1)
		{
			break; // 勝敗判定へ
		}


	}

	/* ========ここから勝敗判定======== */
	msg_window("ゲームが終了しました\n\n");

	// 黒と白それぞれのコマの数を数えて、多いほうが価値
	if (getWinner() == BLACK)
	{
		msg_window("黒の勝ちです\n\n");
	}
	else if (getWinner() == WHITE)
	{
		msg_window("白の勝ちです\n\n");
	}
	else
	{
		msg_window("引き分けです\n\n");
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
