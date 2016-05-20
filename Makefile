# makefile
REVERSI:main.o getWinner.o init.o view_board.o changePlayer.o numAbleBox.o judgeBox.o returnBox.o isFinish.o 
	gcc main.o getWinner.o init.o view_board.o changePlayer.o numAbleBox.o judgeBox.o returnBox.o isFinish.o -o REVERSI
main.o:main.c REVERSI.h
	gcc -c main.c
init.o:init.c REVERSI.h
	gcc -c init.c
view_board.o:view_board.c REVERSI.h
	gcc -c view_board.c
numAbleBox.o:numAbleBox.c REVERSI.h
	gcc -c numAbleBox.c
judgeBox.o:judgeBox.c REVERSI.h
	gcc -c judgeBox.c
returnBox.o:returnBox.c REVERSI.h
	gcc -c returnBox.c
changePlayer.o:changePlayer.c REVERSI.h
	gcc -c changePlayer.c
isFinish.o:isFinish.c REVERSI.h
	gcc -c isFinish.c
getWinner.o:getWinner.c REVERSI.h
	gcc -c getWinner.c
clean:
	rm -f main.o getWinner.o init.o view_board.o changePlayer.o numAbleBox.o judgeBox.o returnBox.o isFinish.o 
