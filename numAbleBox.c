#include "REVERSI.h"

int numAbleBox(int man)
{
	// 引数 man が置ける場所の数を返す
	// (重要) グローバル変数のplayerではなくて引数のmanを使うように！

	// 置けたら 1、置けなかったら 0 でもいいけど、
	// 後で拡張することも視野にいれるならこの方がいいと思う

	// 作成したjudgeBox関数を使う

  int i,j,count=0;

  for(i=0; i<8; i++){
    for(j=0;j<8; j++){
      if(judgeBox(i,j,man)==1)
	count++;
    }
  }
 
  return count;
      
}
