#include "REVERSI.h"

void draw_board_line();
void draw_stones(int i, int *count);

void view_board()
{
	// ゲームボードを端末に表示
	/*
	盤のサイズは最大2桁を想定しています。
	変更がある場合は%2d部やdraw_line()の空白の数も変えてください。
	*/

	//カウンタ変数
	int i, j;

	//置ける場所を示す番号
	int count = 1;

	/* --------盤面の表示-------- */

	/* --列番号（よこ）を表示-- */
	printf("   "); /* 半角空白3つです */
	for(i=1; i<=WIDTH; i++) printf("%2d  ", i);
	putchar('\n');
	/* ----盤面を走査---- */
	for(i=0; i<HEIGHT; i++) { /* 行（たて）のループ */

		draw_board_line(); /* 区切り線+--+の表示 */

		printf("%2d", i+1); /* 行番号（たて）の表示（最大2桁） */
		draw_stones(i, &count); /* i行目について、石や空白を表示 */

	} draw_board_line(); /* 最後の区切り線+--+ */

	puts("");

}

void draw_board_line(){

	/* 区切り線を表示（よこ） */

	int i;
	/* 行番号は最大2桁を想定していますので、
	変更がある場合は場合はここの空白の数も変えてください */
	printf("  |");
	for(i=0; i<WIDTH-1; i++)
		printf("---+");
	printf("---|\n");
}

void draw_stones(int i, int *count){

	/* i行目に関して、石やら空白やらを印字 */

	int j;

	for(j=0; j<WIDTH; j++) { /* 列のループ */

		putchar('|'); /* 区切り文字 */

		switch(board[i][j]){ /* 対応の記号を印字 */
			case MARK:
				if(judgeBox(i,j,player)==1){
					printf("%2d ", *count);
					*count = *count + 1;
				} else {
					printf("   ");
				}
				break;
			case BLACK:
				printf(" ○ ");
				break;
			case WHITE:
				printf(" ● ");
				break;
			default:
				printf("\n\n\aerror: 二次元配列boardに不明な値が格納されています\n\n\n");
		}
	} printf("|\n"); /* 最後の区切り文字と改行 */

}