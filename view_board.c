#include "REVERSI.h"

void view_board()
{
	// ゲームボードを端末に表示

	//カウンタ変数
	int i, j;


	/*--盤面の表示--*/

	//横の座標番号を表示
	for(i=0; i<WIDTH+1; i++) printf("%2d", i);
	puts(" |");

	for(i=0; i<WIDTH; i++){	//石の表示ループ

		//縦の座標番号を表示
		printf("%2d", i+1);

		//盤面を走査、対応の記号を印字
		for(j=0; j<HEIGHT; j++){
			switch(board[i][j]){
				case MARK:
					printf("  ");	//半角空白2つです
					break;
				case BLACK:
					printf(" B");
					break;
				case WHITE:
					printf(" W");
					break;
				default:
					printf("\n\n\aerror: 二次元配列boardに不明な値が格納されています\n\n\n");
			}
		}

		//右枠の表示と改行
		printf(" |\n");

	}

	//下枠の表示
	for(i=0; i<WIDTH+2; i++) printf("--");
	puts("");

}