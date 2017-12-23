/* Author: Ayat Diab and Hamnah Khan
Program : #3, Pentago
TA : Zhu Wang, Tues: 12 (Ayat)
TA :Moumita Samanta, Tues: 3 (Hamnah)
Feb 27, 2017*/
//Play the two - player game of Pentago.Be the first to get 5 in a row.
//Pentago is played on a 6 by 6 board, divided into four 3 by 3
//quadrants.There are two players, X and O, who alternate turns.
//The goal of each player is to get five of their pieces in a row,
//either horizontally, vertically, or diagonally.
//Players take turns placing one of their pieces into an empty
//space anywhere on the board, then choosing one of the four
//board quadrants to rotate 90 degrees left or right.
//If both players get five in a row at the same time, or the
//last move is played with no five in a row, the game is a tie.
//If a player makes five a row by placing a piece, there is no need
//to rotate a quadrant and the player wins immediately.
//Play online at : https://perfect-pentago.net
// Purchase at : www.mindtwisterusa.com
// For each move provide four inputs :
// row(A - F), column(1 - 6), quadrant(1 - 4), rotation direction(L or R)
// For instance input of B32R places the next piece at B3 and then
// would rotate quadrant 2 (upper - right) to the right(clockwise).
// At any point enter ’x’ to exit the program.
// 1 1 2 3 4 5 6 2
// ---------- -
// A: . . . . . . : A
// B : . . . . . . : B
// C : . . . . . . : C
// D : . . . . . . : D
// E : . . . . . . : E
// F : . . . . . . : F
// ---------- -
// 3 1 2 3 4 5 6 4
#include <stdio.h>
#include <stdlib.h> // Needed to avoid compiler error for the exit() command
#include <ctype.h>
//Author: Ayat Diab & Hamnah Khan
//Assignment : 2, Pentago
//TA : Zhu Wang, Tuesday at 12:00-12:50
//Feb 8, 2017
//Professer: Dale Reed
//Microsoft Visual Studio
//Create the Pentago game that allows user to make moves from a specific piece to an empty space or ’o’.This program lets the user
//play the game and makes sure that all the moves the user enters are valid and allowed by the game rules.
//In the end of the code, the user gets to see how many pieces they have left on the board and their score board rating after playing.
//Display all Identifying Information.

void displayIdentifyInformation()
{
	printf("Author: Ayat Diab & Hamnah Khan\n");
	printf("Assignment : 3, Pentago\n");
	printf("TA : Zhu Wang, Tues 12\n");
	printf("Feb 18, 2017\n");
}
//Display all of the instructions for the Pentago.
void displayInstructions()
{
	printf("Play the two-player game of Pentago. Be the first to get 5 in a row.\n");
	printf("Pentago is played on a 6 by 6 board, divided into four 3 by 3\n");
	printf("quadrants.There are two players, X and O, who alternate turns.\n");
	printf("The goal of each player is to get five of their pieces in a row,\n");
	printf("either horizontally, vertically, or diagonally.\n");
	printf("Players take turns placing one of their pieces into an empty\n");
	printf("space anywhere on the board, then choosing one of the four\n");
	printf("board quadrants to rotate 90 degrees left or right.\n");
	printf("If both players get five in a row at the same time, or the\n");
	printf("last move is played with no five in a row, the game is a tie.\n");
	printf("If a player makes five a row by placing a piece, there is no need\n");
	printf("to rotate a quadrant and the player wins immediately.\n");
	printf("For each move provide four inputs :");
	printf("row(A - F), column(1 - 6), quadrant(1 - 4), rotation direction(L or R)\n"
	);
	printf("For instance input of B32R places the next piece at B3 and then\n");
	printf("would rotate quadrant 3 (lower - left) to the right(clockwise)\n");
}
//Displaying board, and creating a 1 dimensional array
void displayBoard(char board[]) {
	printf("1 1 2 3 4 5 6 2\n");
	printf(" -----------\n");
	printf("A: %c %c %c %c %c %c :A\n", board[0], board[1], board[2], board[3], board[4], board[5]);
	printf("B: %c %c %c %c %c %c :B\n", board[6], board[7], board[8], board[9], board[10], board[11]);
	printf("C: %c %c %c %c %c %c :C\n", board[12], board[13], board[14], board[15],board[16], board[17]);
	printf("D: %c %c %c %c %c %c :D\n", board[18], board[19], board[20], board[21],board[22], board[23]);
	printf("E: %c %c %c %c %c %c :E\n", board[24], board[25], board[26], board[27],board[28], board[29]);
	printf("F: %c %c %c %c %c %c :F\n", board[30], board[31], board[32], board[33],board[34], board[35]);
	printf(" -----------\n");
	printf("3 1 2 3 4 5 6 4\n");
}
//Depending on which player is making the move place an X or an O
int makeMove(char row, char column, char quadrant, char direction, char board[], int move)
{ // use ascii
	int playerO;
	int playerX;
	char startRow;
	char colOffSet;
	int index = (row - 'A') * 6 + (column - '1'); ;
	/*index = startRow + colOffSet;*/

		if (move % 2 == 0) {
			board[index] = 'O';
		}
		else {
			board[index] = 'X';
		}
		++move;
		return move;
}
//Function that makes sure that the user inputs the correct row, column, quadrant, and direction
int restrictMove(char row, char column, char quadrant, char direction, char board[], int move) {
	if (row < 'A' || row > 'F') {
		printf("*** Invalid source. Please retry ****\n");
		return 1; // Input was invalid, so return 1 (true)
	}
	// 2. Destination is out of range
	if (column < '1' || column > '6') {
		printf("*** Invalid destination. Please retry ****\n");
		return 1; // Input was invalid, so return 1 (true)
	}
	if (quadrant < '1' || quadrant > '4') {
		printf("*** Invalid destination 1. Please retry ****\n");
		return 1; // Input was invalid, so return 1 (true)
	}
	int index = (row - 'A') * 6 + (column - '1');
	if (index >= 36 || index < 0) {
		printf("*** Invalid destination 2. Please retry ****\n");
		return 1;
	}
	if (direction != 'R' && direction != 'L') {
		printf("*** Quadrant rotation direction is invalid. Please retry.\n");
		return 1;
	}
}
//Rotates the board L and R depending on the quadrant and position
void rotateBoard(char board[], char direction, char quadrant) {
	if (direction == 'R' && quadrant == '1') {
		//Rotating quadrant 1 to the right
		int start = 0;
		char temp1 = board[start];
		char temp2 = board[start + 6];
		board[start] = board[start + 12];
		board[start + 6] = board[start + 13];
		board[start + 12] = board[start + 14];
		board[start + 13] = board[start + 8];
		board[start + 14] = board[start + 2];
		board[start + 8] = board[start + 1];
		board[start + 2] = temp1;
		board[start + 1] = temp2;
	}

	else if (direction == 'R' && quadrant == '2') {
		// Rotating quadrant 2 to the right
		int start = 3;
		char temp1 = board[start];
		char temp2 = board[start + 6];
		board[start] = board[start + 12];
		board[start + 6] = board[start + 13];
		board[start + 12] = board[start + 14];
		board[start + 13] = board[start + 8];
		board[start + 14] = board[start + 2];
		board[start + 8] = board[start + 1];
		board[start + 2] = temp1;
		board[start + 1] = temp2;
	}
	else if (direction == 'R' && quadrant == '3') {
		//Rotating quadrant 3 to the right
		int start = 18;
		char temp1 = board[start];
		char temp2 = board[start + 6];
		board[start] = board[start + 12];
		board[start + 6] = board[start + 13];
		board[start + 12] = board[start + 14];
		board[start + 13] = board[start + 8];
		board[start + 14] = board[start + 2];
		board[start + 8] = board[start + 1];
		board[start + 2] = temp1;
		board[start + 1] = temp2;
	}
	else if (direction == 'R' && quadrant == '4') {
		//Rotating quadrant 4 to the right
		int start = 21;
		char temp1 = board[start];
		char temp2 = board[start + 6];
		board[start] = board[start + 12];
		board[start + 6] = board[start + 13];
		board[start + 12] = board[start + 14];
		board[start + 13] = board[start + 8];
		board[start + 14] = board[start + 2];
		board[start + 8] = board[start + 1];
		board[start + 2] = temp1;
		board[start + 1] = temp2;
	}
	//Rotation to the Left
	else if (direction == 'L' && quadrant == '1') {
		//Quadrant 1
		int start = 0;
		char temp1 = board[start];
		char temp2 = board[start + 1];
		board[start] = board[start + 2];
		board[start + 1] = board[start + 8];
		board[start + 2] = board[start + 14];
		board[start + 8] = board[start + 13];
		board[start + 14] = board[start + 12];
		board[start + 13] = board[start + 6];
		board[start + 12] = temp1;
		board[start + 6] = temp2;
	}
	else if (direction == 'L' && quadrant == '2') {
		//Quadrant 2
		int start = 3;
		char temp1 = board[start];
			char temp2 = board[start + 1];
		board[start] = board[start + 2];
		board[start + 1] = board[start + 8];
		board[start + 2] = board[start + 14];
		board[start + 8] = board[start + 13];
		board[start + 14] = board[start + 12];
		board[start + 13] = board[start + 6];
		board[start + 12] = temp1;
		board[start + 6] = temp2;
	}
	else if (direction == 'L' && quadrant == '3') {
		//Quadrant 3
		int start = 18;
		char temp1 = board[start];
		char temp2 = board[start + 1];
		board[start] = board[start + 2];
		board[start + 1] = board[start + 8];
		board[start + 2] = board[start + 14];
		board[start + 8] = board[start + 13];
		board[start + 14] = board[start + 12];
		board[start + 13] = board[start + 6];
		board[start + 12] = temp1;
		board[start + 6] = temp2;
	}
	else if (direction == 'L' && quadrant == '4') {
		//Quadrant 4
		int start = 21;
		char temp1 = board[start];
		char temp2 = board[start + 1];
		board[start] = board[start + 2];
		board[start + 1] = board[start + 8];
		board[start + 2] = board[start + 14];
		board[start + 8] = board[start + 13];
		board[start + 14] = board[start + 12];
		board[start + 13] = board[start + 6];
		board[start + 12] = temp1;
		board[start + 6] = temp2;
	}
}
//Function that checks if there are any X’s and O’s in row in order to declare a winner or a tie.
int checkForWin(char board[], int position, int offSet, char player) {
	int win = true;
	for (int i = 0; i < 5; i++) {
		if (board[position] != player) {
			win = false;
			break;
		}
		position = position + offSet;
	}
	return win;
}
// Checking for a Horizontal Win for X or O
void gameCheck(char board[]) {
	int XWin = false;
	int OWin = false;
	if (checkForWin(board, 0, 1, 'X'))
		XWin = true;
	if (checkForWin(board, 0, 1, 'O'))

		OWin = true;
	if (checkForWin(board, 1, 1, 'X'))
		XWin = true;
	if (checkForWin(board, 1, 1, 'O'))
		OWin = true;
	if (checkForWin(board, 6, 1, 'X'))
		XWin = true;
	if (checkForWin(board, 6, 1, 'O'))
		OWin = true;
	if (checkForWin(board, 7, 1, 'X'))
		XWin = true;
	if (checkForWin(board, 7, 1, 'O'))
		OWin = true;
	if (checkForWin(board, 12, 1, 'X'))
		XWin = true;
	if (checkForWin(board, 12, 1, 'O'))
		OWin = true;
	if (checkForWin(board, 13, 1, 'X'))
		XWin = true;
	if (checkForWin(board, 13, 1, 'O'))
		OWin = true;
	if (checkForWin(board, 18, 1, 'X'))
		XWin = true;
	if (checkForWin(board, 18, 1, 'O'))
		OWin = true;
	if (checkForWin(board, 19, 1, 'X'))
		XWin = true;
	if (checkForWin(board, 19, 1, 'O'))
		OWin = true;
	if (checkForWin(board, 24, 1, 'X'))
		XWin = true;
	if (checkForWin(board, 24, 1, 'O'))
		OWin = true;
	if (checkForWin(board, 25, 1, 'X'))
		XWin = true;
	if (checkForWin(board, 25, 1, 'O'))
		OWin = true;
	if (checkForWin(board, 30, 1, 'X'))
		XWin = true;
	if (checkForWin(board, 30, 1, 'O'))
		OWin = true;
	if (checkForWin(board, 31, 1, 'X'))
		XWin = true;
	if (checkForWin(board, 31, 1, 'O'))
		OWin = true;
	//Checking for a Vertical win for X and O
	if (checkForWin(board, 0, 6, 'X'))
		XWin = true;
	if (checkForWin(board, 0, 6, 'O'))
		OWin = true;
	if (checkForWin(board, 6, 6, 'X'))
		XWin = true;
	if (checkForWin(board, 6, 6, 'O'))
		OWin = true;
	if (checkForWin(board, 1, 6, 'X'))
		XWin = true;
	if (checkForWin(board, 1, 6, 'O'))
		OWin = true;
	if (checkForWin(board, 7, 6, 'X'))
		XWin = true;
	if (checkForWin(board, 7, 6, 'O'))
		OWin = true;
	if (checkForWin(board, 2, 6, 'X'))
		XWin = true;
		if (checkForWin(board, 2, 6, 'O'))
			OWin = true;
	if (checkForWin(board, 8, 6, 'X'))
		XWin = true;
	if (checkForWin(board, 8, 6, 'O'))
		OWin = true;
	if (checkForWin(board, 3, 6, 'X'))
		XWin = true;
	if (checkForWin(board, 3, 6, 'O'))
		OWin = true;
	if (checkForWin(board, 9, 6, 'X'))
		XWin = true;
	if (checkForWin(board, 9, 6, 'O'))
		OWin = true;
	if (checkForWin(board, 4, 6, 'X'))
		XWin = true;
	if (checkForWin(board, 4, 6, 'O'))
		OWin = true;
	if (checkForWin(board, 10, 6, 'X'))
		XWin = true;
	if (checkForWin(board, 10, 6, 'O'))
		OWin = true;
	if (checkForWin(board, 5, 6, 'X'))
		XWin = true;
	if (checkForWin(board, 5, 6, 'O'))
		OWin = true;
	if (checkForWin(board, 11, 6, 'X'))
		XWin = true;
	if (checkForWin(board, 11, 6, 'O'))
		OWin = true;
	//Checking for a diagnol win for X or O
	if (checkForWin(board, 4, 5, 'X'))
		XWin = true;
	if (checkForWin(board, 4, 5, 'O'))
		OWin = true;
	if (checkForWin(board, 5, 5, 'X'))
		XWin = true;
	if (checkForWin(board, 5, 5, 'O'))
		OWin = true;
	if (checkForWin(board, 10, 5, 'X'))
		XWin = true;
	if (checkForWin(board, 10, 5, 'O'))
		OWin = true;
	if (checkForWin(board, 11, 5, 'X'))
		XWin = true;
	if (checkForWin(board, 11, 5, 'O'))
		OWin = true;
	if (checkForWin(board, 6, 7, 'X'))
		XWin = true;
	if (checkForWin(board, 6, 7, 'O'))
		OWin = true;
	if (checkForWin(board, 0, 7, 'X'))
		XWin = true;
	if (checkForWin(board, 0, 7, 'O'))
		OWin = true;
	if (checkForWin(board, 7, 7, 'X'))
		XWin = true;
	if (checkForWin(board, 7, 7, 'O'))
		OWin = true;
	if (checkForWin(board, 1, 7, 'X'))
		XWin = true;
	if (checkForWin(board, 1, 7, 'O'))
		OWin = true;
	//Checks for a Tie
	if ((XWin == 1) && (OWin == 1)) {
		printf("It’s a Tie! \n");
		displayBoard(board);
		exit(0);
	}
	//Check for X win

		if (XWin) {
			printf("X wins! \n");
			displayBoard(board);
			exit(0);
		}
	//Check for O win
	if (OWin) {
		printf("O wins! \n");
		displayBoard(board);
		exit(0);
	}
}
//main function displays board, makes move, and makes calls for all previous functions inorder to successfuly play the game
int main() {
	char board[36];
	char row;
	char column, quadrant, direction;
	char playerToMove = 'X';
	int move = 1;
	displayIdentifyInformation();
	displayInstructions();
	//Board displaying the ’.’ character
	int i;
	for (i = 0; i <= 36; i++)
	{
		board[i] = '.';
	}
	int moveNumber = 0;
	while (1) {
		++moveNumber;
		displayBoard(board);
		//Ask the user for input row, column, quadrant, rotation m direction
		printf("%d.Enter row, column, quadrant, direction", moveNumber);
		scanf(" %c", &row);
		//Letting User enter in X to exit game
		if (toupper(row) == 'X') {
			printf("Exiting program...\n");
			exit(0);
		}
		scanf(" %c", &column);
		scanf(" %c", &quadrant);
		scanf(" %c", &direction);
		//Converts any input to upper case
		direction = toupper(direction);
		row = toupper(row);
		restrictMove(row, column, quadrant, direction, board, move);
		move = makeMove(row, column, quadrant, direction, board, move);
		gameCheck(board);
		rotateBoard(board, direction, quadrant);
		gameCheck(board);
	}
	//Display Final Board
	displayBoard(board);
	return 0;
}


