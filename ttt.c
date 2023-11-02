#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
const char player = 'X';
const char computer = 'O';

void resetBoard();
void printBoard();
void playerMove();
void computerMove();
int checkFreeSpaces();
char checkWinner();
void printWinner(char);

int main()
{
  char winner = ' ';
  char response;

  resetBoard();
  while (winner == ' ' && checkFreeSpaces() != 0) {
	printBoard();
	playerMove();
	winner = checkWinner();
	if (winner != ' ' || checkFreeSpaces() == 0) {
	  break;
	}
	  
	computerMove();
	winner = checkWinner();
	if (winner != ' ' || checkFreeSpaces() == 0) {
	  break;
	}
  }

  printBoard();
  printWinner(winner);
  return 0;
}

void resetBoard()
{
  for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
	  board[i][j] = ' ';
	}
  }
}

void printBoard()
{
  printf(" %c | %c | %c ", board[0][0],board[0][1], board[0][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ", board[1][0],board[1][1], board[1][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ", board[2][0],board[2][1], board[2][2]);
  printf("\n---|---|---\n");
}

int checkFreeSpaces()
{
  int freespaces = 9;
  for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
	  if (board[i][j] != ' ') {
		freespaces--;
	  }
	}
  }
  return freespaces;
}

void playerMove()
{
  int x, y;
  do {
	printf("enter a row (1-3): ");
	scanf("%d", &x);
	x--;
	printf("enter a row (1-3): ");
	scanf("%d", &y);
	y--;
	if (board[x][y] != ' ') {
	  printf("invalid move\n");
	} else {
	  board[x][y] = player;
	  break;
	}
  } while (board[x][y] != ' ');
}

void computerMove()
{
  srand(time(0));
  int x;
  int y;
  do {
	x = rand() % 3;
	y = rand() % 3;
  } while (board[x][y] != ' ');
  board[x][y] = computer;
}

char checkWinner()
{
  // rows
  for (int i = 0; i < 3; i++) {
	if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
	  return board[i][0];
	}
  }

  // columns
  for (int i = 0; i < 3; i++) {
	if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
	  return board[0][i];
	}
  }

  // diagonals
  for (int i = 0; i < 3; i++) {
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
	  return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
	  return board[0][2];
	}
  }
  return ' ';
}

void printWinner(char winner)
{
  if (winner == player) {
	printf("You Won\n");
  } else if (winner == computer) {
	printf("You Lose\n");
  } else {
	printf("It's a tie!\n");
  }
}
