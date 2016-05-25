#include "REVERSI.h"

// main関数の中でグローバル変数を書き換えないように
//	 ->	ルールというわけではないけれど、Ri-oneでプログラム書く練習だと思ってやってみてください

void div_line();

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
	view_board();

	// 入力を受け取る変数
	int iHeight, iWidth;

	// ゲームはいつ終わるかわからないので無限ループにした方がいいと思う
	while(1)
	{
		// playerが置ける場所があるか調べる。なかったらスキップ

		/* ●●●●まだ中身がないものは、コメントアウトしておきます●●●●
		if (numAbleBox(player) == 0)
		{
			continue;
		}
		*/


		/* --------入力-------- */
		// とりあえず座標を入力する方法で進めておきます

		while(1){

			/* 誘導 */
			(player) ? printf("\n 黒 ") : printf("\n 白 ");
			printf("のターンです.\nどこに石を置きますか？\n(横, 縦) : ");

			/* 入力 */
			scanf("%d,%d",&iHeight, &iWidth);
			iHeight--; iWidth--; /* 配列が0から始まるので…… */
			div_line();

			/* 範囲外時再入力 */
			if( !((0<=iHeight&&iHeight<HEIGHT) && (0<=iWidth&&iWidth<WIDTH)) ){
				printf("\a範囲外の値が入力されました。\n\n");
				view_board();
				continue;
			}

			/* その場所に石が置けるか判定、置けなければエラーメッセージを表示し再入力 */
			if( judgeBox(iHeight,iWidth) >= 1 ){
				printf("置けます！\n\n");
				break;
			} else {
				printf("\aその場所に石は置けないようです...\n\n");
				view_board();
				continue;
			}

		}


		// 入力された座標に対応するマスをひっくり返す関数
		//returnBox(iWidth, iHeight);

		// ゲームボードを表示
		view_board();

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

void div_line(){
	int i;
	puts("");
	for(i=0; i<WIDTH; i++) printf("====");
	printf("\n\n");
}