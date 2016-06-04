#include "REVERSI.h"

int getWinner()
{
	// 両チームのコマの数を数える

	// 黒の勝ちなら return BLACK;
	// 白の勝ちなら return WHITE;
	// 引き分けなら return MARK;

	int i,j;
	int black_c=0, white_c=0;

	for(i=0; i<HEIGHT; i++){
		for(j=0; j<WIDTH; j++){
			if(board[i][j] == BLACK){
				black_c++;
			} else if(board[i][j] == WHITE) {
				white_c++;
			}
		}
	}

	if(black_c > white_c){
		return BLACK;
	} else if(white_c > black_c){
		return WHITE;
	} else if(black_c == white_c){
		return MARK;
	}

	return 0;
}