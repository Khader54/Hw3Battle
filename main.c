#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8
#define NUM_OF_BOARDS 5
#define SUBMARINE 'S'
#define EMPTY '~'
#define HIDDEN ' '

// Function Declarations
void print_welcome_message();
void print_wrong_board_number();
void print_enter_position();
void print_error_row_or_col();
void print_error_position_already_bombed();
void print_winning_message(int n_submarines, int n_moves);
void printMatrix(char matrix[ROWS][COLS]);


// Optional Boards

const char MATRIX_1[ROWS][COLS] = {
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', 'S', '~', '~', '~', 'S', '~'},
        {'~', '~', 'S', '~', '~', '~', 'S', '~'},
        {'~', '~', 'S', '~', '~', '~', 'S', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'S', '~', '~', 'S', '~', '~', '~', '~'},
        {'S', '~', '~', 'S', '~', '~', '~', '~'},
        {'S', '~', '~', 'S', '~', '~', '~', '~'}
};
const char MATRIX_2[ROWS][COLS] = {
        {'S', '~', '~', '~', '~', '~', '~', '~'},
        {'S', '~', 'S', '~', '~', '~', '~', '~'},
        {'S', '~', 'S', '~', '~', '~', '~', '~'},
        {'~', '~', 'S', '~', '~', '~', '~', 'S'},
        {'~', '~', '~', '~', '~', '~', '~', 'S'},
        {'~', '~', '~', '~', '~', '~', '~', 'S'},
        {'~', 'S', 'S', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'}
};
const char MATRIX_3[ROWS][COLS] = {
        {'~', 'S', 'S', 'S', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', 'S', 'S', 'S'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', 'S', 'S', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', 'S', 'S', 'S', 'S', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'S', '~', '~', '~', '~', '~', '~', '~'}
};
const char MATRIX_4[ROWS][COLS] = {
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'}
};
const char MATRIX_5[ROWS][COLS] = {
        {'S', '~', 'S', '~', '~', '~', '~', 'S'},
        {'~', '~', '~', '~', '~', 'S', '~', '~'},
        {'~', '~', 'S', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', 'S', '~'},
        {'~', '~', '~', 'S', '~', '~', '~', '~'},
        {'~', 'S', '~', '~', '~', '~', 'S', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'S', '~', '~', 'S', '~', '~', '~', 'S'}
};

const char Boards[5][ROWS][COLS] =
        {MATRIX_1, MATRIX_2, MATRIX_3, MATRIX_4, MATRIX_5};

void print_welcome_message(){
    printf("Welcome to Battleship! Please enter board number:\n");
}
void print_wrong_board_number(){
    printf("Error in board number, try again\n");
}
void print_enter_position(){
    printf("Please enter position:\n");
}
void print_error_row_or_col(){
    printf("Error in row or column - out of bound\n");
}
void print_error_position_already_bombed(){
    printf("This position was already bombed - try again!\n");
}
void print_winning_message(int n_submarines, int n_moves){
    printf("Congratulations, Admiral!\nYou've successfully "
           "revealed all %d submarines in %d moves!\n", n_submarines , n_moves);
}


// Print a ROWSxCOLS matrix
void printMatrix(char matrix[ROWS][COLS]) {
    // Print column headers
    printf("  ");
    for (int j = 0; j < COLS; j++) {
        printf(" %c", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        // Print row label
        printf("%d ",  i);

        // Print row
        for (int j = 0; j < COLS; j++) {
            // Each cell is in "|x|" format
            printf("|%c", matrix[i][j]);
        }
        printf("|\n");
    }
}


// Add your functions here

//Taking the board number, and making sure it is 1-5
int getBoardNumber()
{
    int board_number = -1;
    if(scanf("%d", &board_number) != 1)
    {
        exit(1);
    }
    while(board_number > 5 || board_number < 1)
    {
        print_wrong_board_number();
        if(scanf("%d", &board_number) != 1)
        {
            exit(1);
        }
    }
    return board_number;
}


//Building the board, asking for position just the first time
void fillMatrix(char gameBoard[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            gameBoard[i][j] = ' ';
        }
    }
    printMatrix(gameBoard);
    print_enter_position();
}


// Check pos, Checks pos, so it is valid.
bool checkPosition(int intPos, char charPos, char gameBoard[ROWS][COLS])
{
    if(intPos < 0 || intPos > 7 || charPos > 'H' || charPos < 'A')
    {
        print_error_row_or_col();
        print_enter_position();
        return false;
    }
    if(gameBoard[intPos][charPos - 'A'] != ' ')
    {
        print_error_position_already_bombed();
        print_enter_position();
        return false;
    }

    return true;
}


//maybe the wrong is here :) <3
// this function counts the ships in the board
int shipCnt(int gameNum)
{
    char copy[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            copy[i][j]= Boards[gameNum][i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if(copy[i][j] != 'S')
            {
                continue;
            }
            copy[i][j] = ' ';
            cnt++;

            int tempRow = i, tempCol = j;

            //down
            while(++tempRow < ROWS && copy[tempRow][j] == 'S')
            {
                copy[tempRow][j] = ' ';
            }
            tempRow = i;
            //up
            while(--tempRow > 0 && copy[tempRow][j] == 'S')
            {
                copy[tempRow][j] = ' ';
            }
            //right
            while(++tempCol < COLS && copy[i][tempCol] == 'S')
            {
                copy[i][tempCol] = ' ';
            }
            tempCol = j;
            //left
            while(--tempCol > 0 && copy[i][tempCol] == 'S')
            {
                copy[i][tempCol] = ' ';
            }
        }
    }
    return cnt;
}


//check if game is over
bool IsGameOver(int numOfShips)
{





}

// if u have smth wrong, check this, I think it is the problem
// u call it when u want to know if cnt++ for the ship count, so u can know if
// the game ended(cntfromhere = numOfallships)
bool checkIfShip(int row,char col, gameBoard[ROWS][COLS], int gNum)
{
    if(Boards[gNum][row][col] == 'S')
    {
        for(int right = row + 1; right < ROWS; right++)
        {
            if(Boards[gNum][right][col] == 'S')
            {
                gameBoard[right][col] = 'S';
            }
        }
        for(int up = col + 1; up < COLS; up++)
        {
            if(Boards[gNum][row][up] == 'S')
            {
                gameBoard[row][up] = 'S';
            }
        }
        for(int left = row - 1; left >= 0; left--)
        {
            if(Boards[gNum][left][col] == 'S')
            {
                gameBoard[left][col] = 'S';
            }
        }
        for(int down = col - 1; down <= COLS; down++)
        {
            if(Boards[gNum][row][down] == 'S')
            {
                gameBoard[row][down] = 'S';
            }
        }
        return true;
    }
    return false;
}


int readInt()
{
    int x;
    if(scanf("%d", &x) != 1)
    {
        exit(1);
    }
    return x;
}
char readChar()
{
    char c;
    if(scanf(" %c", &c) != 1)
    {
        exit(1);
    }
    return c;
}


void runGame(char gameBoard[ROWS][COLS])
{

    int board_number = getBoardNumber();
    int numOfShips = shipCnt(board_number);



    int targetRow, cntHit = 0;
    char targetCol;

    while (IsGameOver(numOfShips) == true)
    {

        targetRow = readInt();
        targetCol = readChar();
        if(checkPosition(targetRow, targetCol, gameBoard) != true)
        {
            continue;
        }

        gameBoard[targetRow][targetCol - 'A'] =
            Boards[board_number - 1][targetRow][targetCol - 'A'];
        if(checkIfShip(targetRow, targetCol, gameBoard,board_number) == 1)
        {
            cntHit++;
        }




        print_enter_position();
    }
}

int main(void)
{



    print_welcome_message();
    char gameBoard[ROWS][COLS];
    fillMatrix(gameBoard);
    runGame(gameBoard);








    return 0;
}