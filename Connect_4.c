#include <stdio.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 7

//First we need to initialize the board to arrange the spaces that we are going to use. 
void initializeBoard (char board[ROWS][COLS])
{
    for (int i = 0; i<ROWS; i++)
    {
        for (int q = 0; q <COLS; q++)
        {
            board[i][q] =' ';

        }
    }

}

//After initializing our board we can start and create it properly
void createBoard(char board[ROWS][COLS])
{
    for (int i = 0; i< ROWS; i++)
    {
        for (int q = 0; q <COLS; q++)
        {
            printf("|  %c", board[i][q]); 

        }
        printf("| \n");

        for (int q = 0; q<COLS ; q++)
        {
            printf("|___");  
            
        }
        printf ("| \n");
    }
    for (int z = 1 ; z <8 ; z++ )
    {
       printf("  %d ",z); 
    }
    
   
}

bool winCondition (char board[ROWS][COLS], char player)
{
    //Horizontal condition
    //COLS - 3 because to prevent spilling out of the array becuase we are adding j+3 in the if loop
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS - 3; j++) 
        {
            if (board[i][j] == player &&
             board[i][j + 1] == player &&
                board[i][j + 2] == player &&
                 board[i][j + 3] == player) 
            {
                return true;
            }
        }
    }
    //Vertical condition
    //ROWS - 3 because to prevent spilling out of the array becuase we are adding i+3 in the if loop
    for (int i = 0; i < ROWS - 3; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            if (board[i][j] == player &&
             board[i + 1][j] == player &&
                board[i + 2][j] == player &&
                 board[i + 3][j] == player) 
            {
                return true;
            }
        }
    }
    // Diagonal negative condition.
    //ROWS - 3 and COLS - 3 because to prevent spilling out of the array while checking the if condition.
    for (int i = 0; i < ROWS - 3; i++) 
    {
        for (int j = 0; j < COLS - 3; j++) 
        {
            if (board[i][j] == player &&
             board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player &&
                 board[i + 3][j + 3] == player) 
            {
                return true;
            }
        }
    }
    // Diagonal positive condition.
    //ROWS - 3 and COLS - 3 because to prevent spilling out of the array while checking the if condition bu this time we are counting backwards from the array.
    for (int i = 0; i < ROWS - 3; i++) 
    {
        for (int j = 3; j < COLS -3 ; j++) 
        {
            if (board[i][j] == player &&
             board[i + 1][j - 1] == player &&
                board[i + 2][j - 2] == player &&
                 board[i + 3][j - 3] == player) 
            {
                return true;
            }
        }
    }

    return false;
}



bool makeAmove(char board[ROWS][COLS], int col, char symbol)
{
    //Because connect 4 game starts from filling up the bottom, we need to start the game from the bottom aswell
    int r;
        for (r = ROWS - 1; r >= 0; r--)     //This loop checks if the space is empty or not. If it is empty it breaks out from the loop and enters the players input.
        {
            if (board[r][col-1] == ' ') 
            {
                break;
            }
        }

    board[r][col-1] = symbol; //Places the symbol.
    createBoard(board); //Creating the board again to get the updated version.

    return winCondition(board, symbol); //Checking win condition after the move
}


void playTime(char board[][COLS])
{
    
    createBoard(board);

    bool isTrue;
    int move;
    int counter = 0;
    int player = 1;
    char player1symbol = 'X';
    char player2symbol = 'O';


    while (true)
    {
        printf("\nPlayer %d make a move: ", player); //Taking the move input from the player 1.
        scanf("%d", &move);

        if ( move< 1 || move> 7) //Preventing the player from entering numbers outside of the tables boundaries.
        {
            createBoard(board);
            printf("\nEnter a valid number!");
        }

        else if( board[0][move-1] != ' ') //If the players input doesn't have a place in the array/table give an error. (Arrays start from 0 that's why we need -1)
        {
            createBoard(board);
            printf("\nYou cannot play here!");
            
        }
            
        else 
                
        {   
            if(player==1)   //Player 1 makes a move and then passes the turn to the player 2 with player++.
            {               // After makeAmove function checks the win condition it transmits the value to isTrue variable.

                isTrue = makeAmove(board, move, player1symbol);

                if(isTrue){ //Game winning condition.
                    printf("\nPlayer %d Won!", player);
                    return;
                }

                player++;
            }
            
            else

            {

                isTrue = makeAmove(board, move, player2symbol);

                if(isTrue){ //Game winning condition.
                    printf("\nPlayer %d Won!", player);
                    return;
                }

                player--;
            }   

            counter++;
            if(counter == ROWS * COLS)
            {
                printf("\nGame is Draw!");
                return;
            }               
        }
    }
}


int main ()
{
    char board[ROWS][COLS];
    initializeBoard(board);
    playTime(board);

}