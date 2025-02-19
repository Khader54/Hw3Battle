#include <stdio.h>
#include <stdbool.h>

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


int main(void) {

    // Enter your code here

    return 0;
}
