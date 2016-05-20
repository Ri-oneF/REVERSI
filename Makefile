# makefile
REVERSI:main.o getWinner.o init.o view_board.o changePlayer.o numAbleBox.o judgeBox.o returnBox.o isFinish.o 
	gcc main.o getWinner.o init.o view_board.o changePlayer.o numAbleBox.o judgeBox.o returnBox.o isFinish.o -o REVERSI
main.o:main.c
	gcc -c main.c
init.o:init.c
	gcc -c init.c
view_board.o:view_board.c
	gcc -c view_board.c
numAbleBox.o:numAbleBox.c
	gcc -c numAbleBox.c
judgeBox.o:judgeBox.c
	gcc -c judgeBox.c
returnBox.o:returnBox.c
	gcc -c returnBox.c
changePlayer.o:changePlayer.c
	gcc -c changePlayer.c
isFinish.o:isFinish.c
	gcc -c isFinish.c
getWinner.o:getWinner.c
	gcc -c getWinner.c
clean:
	rm -f main.o getWinner.o init.o view_board.o changePlayer.o numAbleBox.o judgeBox.o returnBox.o isFinish.o 
