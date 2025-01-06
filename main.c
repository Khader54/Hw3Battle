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
const char Boards[5][ROWS][COLS] = {
    {
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', 'S', '~', '~', '~', 'S', '~'},
        {'~', '~', 'S', '~', '~', '~', 'S', '~'},
        {'~', '~', 'S', '~', '~', '~', 'S', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'S', '~', '~', 'S', '~', '~', '~', '~'},
        {'S', '~', '~', 'S', '~', '~', '~', '~'},
        {'S', '~', '~', 'S', '~', '~', '~', '~'}
    },
    {
        {'S', '~', '~', '~', '~', '~', '~', '~'},
        {'S', '~', 'S', '~', '~', '~', '~', '~'},
        {'S', '~', 'S', '~', '~', '~', '~', '~'},
        {'~', '~', 'S', '~', '~', '~', '~', 'S'},
        {'~', '~', '~', '~', '~', '~', '~', 'S'},
        {'~', '~', '~', '~', '~', '~', '~', 'S'},
        {'~', 'S', 'S', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'}
    },
    {
        {'~', 'S', 'S', 'S', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', 'S', 'S', 'S'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', 'S', 'S', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', 'S', 'S', 'S', 'S', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'S', '~', '~', '~', '~', '~', '~', '~'}
    },
    {
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'}
    },
    {
        {'S', '~', 'S', '~', '~', '~', '~', 'S'},
        {'~', '~', '~', '~', '~', 'S', '~', '~'},
        {'~', '~', 'S', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', 'S', '~'},
        {'~', '~', '~', 'S', '~', '~', '~', '~'},
        {'~', 'S', '~', '~', '~', '~', 'S', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~'},
        {'S', '~', '~', 'S', '~', '~', '~', 'S'}
    }
};

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
//reading
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
    if (scanf(" %c", &c) != 1)
    {
        exit(1);
    }
    return c;
}
//reading


// Taking the board number, and making sure it is 1-5
int getBoardNumber()
{
    int board_number = readInt();

    while (board_number > 5 || board_number < 1)
    {
        print_wrong_board_number();
        board_number = readInt();
    }
    return board_number;
}

// Building the board, asking for position just the first time
void fillMatrix(char gameBoard[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            gameBoard[i][j] = ' ';
        }
    }
    printMatrix(gameBoard);
    print_enter_position();
}

// Check pos, Checks pos, so it is valid.
bool checkPosition(const int intPos, const char charPos,
    const char gameBoard[ROWS][COLS])
{
    if (intPos < 0 || intPos > 7 ||
        charPos > 'H' || charPos < 'A')
    {
        print_error_row_or_col();
        print_enter_position();
        return false;
    }

    if (gameBoard[intPos][charPos - 'A'] != ' ')
    {
        print_error_position_already_bombed();
        print_enter_position();
        return false;
    }
    return true;
}

// maybe the wrong is here :) <3
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


//check if game is over, it needs to print things.
bool IsGameOver(int numOfShips, int numOfHit, int numOfMoves)
{
    if(numOfHit == numOfShips)
    {
        print_winning_message(numOfShips,numOfMoves);
        return false;
    }
    return true;
}

// if u have smth wrong, check this, I think it is the problem
// u call it when u want to know if cnt++ for the ship count, so u can know if
// the game ended(cntfromhere = numOfallships)
bool shipIsVer(const int row, const int col, const char gameBoard[ROWS][COLS],
    const int gNum)
{
    if ((row + 1 < ROWS && Boards[gNum][row + 1][col] == 'S')
        || (row - 1 >= 0 && Boards[gNum][row - 1][col] == 'S')
    ) {
        return true;
    }
    return false;
}

//Check if the target is a ship, and reveals all the S's on the board
//the row and col were Const, ask why?
bool checkIfShip(int row, char col, char gameBoard[ROWS][COLS],
    const int gNum)
{
    col = col - 'A';
    if (Boards[gNum][row][col] != 'S')
    {
        return false;
    }

    if (shipIsVer(row, col, gameBoard, gNum) == true)
    {
        for(int up = row + 1; up < ROWS; up++)
        {
            if(Boards[gNum][up][col] == 'S')
            {
                gameBoard[up][col] = 'S';
            }
        }
        for(int down = row - 1; down >= 0; down--)
        {
            if(Boards[gNum][down][col] == 'S')
            {
                gameBoard[down][col] = 'S';
            }
        }
        return true;
    }

    for(int right = col + 1; right < COLS; right++)
    {
        if(Boards[gNum][row][right] == 'S')
        {
            gameBoard[row][right] = 'S';
        }
    }
    for(int left = col - 1; left >= 0; left--)
    {
        if(Boards[gNum][row][left] == 'S')
        {
            gameBoard[row][left] = 'S';
        }
    }
    return true;
}



void runGame(char gameBoard[ROWS][COLS])
{
    int board_number = getBoardNumber() - 1;
    fillMatrix(gameBoard);
    int numOfShips = shipCnt(board_number);
    int cntHit = 0, numOfMoves = 0;
    int targetRow;
    char targetCol;

    while (IsGameOver(numOfShips, cntHit, numOfMoves) == true)
    {
         targetRow = readInt();
         targetCol = readChar();

        if (checkPosition(targetRow, targetCol, gameBoard) != true)
        {
            continue;
        }
        numOfMoves++;

        gameBoard[targetRow][targetCol - 'A'] =
            Boards[board_number][targetRow][targetCol - 'A'];

        if(checkIfShip(targetRow, targetCol, gameBoard,board_number) == 1)
        {
            cntHit++;
        }

        printMatrix(gameBoard);
        print_enter_position();
    }
}

int main(void)
{
    print_welcome_message();
    char gameBoard[ROWS][COLS];

    runGame(gameBoard);


    return 0;
}
