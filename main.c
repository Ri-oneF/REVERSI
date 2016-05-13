#include "REVERSI.h"

// main関数の中でグローバル変数を書き換えないように
//	 ->	ルールというわけではないけれど、Ri-oneでプログラム書く練習だと思ってやってみてください

int main()
{
	// ゲームボードの初期化
	init();

	// ゲームボードを表示
	view_board();

	// 入力を受け取る変数
	int iHeight, iWidth;

	// ゲームはいつ終わるかわからないので無限ループにした方がいいと思う
	while(1)
	{
		// playerが置ける場所があるか調べる。なかったらスキップ
		if (numAbleBox(player) == 0)
		{
			continue;
		}

		// とりあえず座標を入力する方法で進めておきます

		// iHeightに座標の縦、iWidthに座標の横を入力
		// そのマスに player は置くことができるか判定。置けなかったらもう一度入力へ
		// とりあえず１回は入力して欲しいのでdo~while文を使うと良い
		do{
			// 座標入力
		} while(judgeBox(iHeight, iWidth) == 0);

		/* もしくは、エラーの場合に出力したいなら
		while(1)
		{
			// 座標入力

			if (judgeBox(iHeight, iWidth) >= 1)
			{
				break;
			}

			// エラー文章
		}
		のように書くこともできる */

		// 入力された座標に対応するマスをひっくり返す関数
		returnBox(iHeight, iWidth);

		// ゲームボードを表示
		view_board();

		// プレイヤーを相手に交代
		changePlayer();

		// 終了条件を満たしたら break
		if (isFinish() == 1)
		{
			break;
		}
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