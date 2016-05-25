#include "REVERSI.h"

// main関数の中でグローバル変数を書き換えないように
//	 ->	ルールというわけではないけれど、Ri-oneでプログラム書く練習だと思ってやってみてください

void draw_div_line();

int main()
{
	// ゲームボードの初期化
	init();

	/* テスト用 */
	/*
	board[0][2] = WHITE;
	board[0][3] = WHITE;
	board[0][4] = WHITE;
	board[0][5] = WHITE;
	board[0][6] = WHITE;
	board[0][7] = BLACK;
	*/

	// ゲームボードを表示
	//view_board(); /* 必要ないかも… */

	// 入力を受け取る変数
	int iHeight, iWidth;

	// ゲームはいつ終わるかわからないので無限ループにした方がいいと思う
	while(1)
	{
		// playerが置ける場所があるか調べる。なかったらスキップ
		/*
		if (numAbleBox(player) == 0)
		{
			(player) ? printf("\n 黒 ") : printf("\n 白 ");
			printf("のターンです,\nが,置ける場所がありません！\n");
			continue;
		}
		*/


		/* --------入力-------- */
		// とりあえず座標を入力する方法で進めておきます

		while(1){

			/* ゲームボードの表示 */
			view_board();

			/* 誘導 */
			(player) ? printf(" 黒 ") : printf(" 白 ");
			printf("のターンです.\nどこに石を置きますか？\n(横, 縦) : ");

			/* 入力 */
			scanf("%d,%d",&iHeight, &iWidth);

			/* 配列が0から始まるので…… */
			iHeight--; iWidth--;

			/* インターフェースのために。 */
			puts(""); draw_div_line();


			/* ----分岐---- */
			if( !((0<=iHeight&&iHeight<HEIGHT) && (0<=iWidth&&iWidth<WIDTH)) ){

				/* ゲームボード範囲外時、再入力 */
				printf("\a範囲外の値が入力されました。\n\n");
				continue;

			} else if( board[iHeight][iWidth] != MARK ){

				/* そのマスに既に石が置かれていたら、再入力 */
				printf("\aその場所には既に石が置かれています\n\n");
				continue;

			} else if( judgeBox(iHeight,iWidth) >= 1 ){

				/* XXXXその場所に石が置けるか判定XXXX */
				printf("置けました！\n\n");
				break;

			} else {

				/* 置けない */
				printf("\aその場所に石は置けないようです...\n\n");
				continue;

			}

		}


		// 入力された座標に対応するマスをひっくり返す関数
		//returnBox(iWidth, iHeight);

		// ゲームボードを表示
		//view_board(); /* 必要ないかも */

		// プレイヤーを相手に交代
		//changePlayer();

		// 終了条件を満たしたら break
		/*
		if (isFinish() == 1)
		{
			break;
		}
		*/
	}

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

void draw_div_line(){
	int i;
	for(i=0; i<WIDTH; i++) printf("====");
	printf("\n\n");
}