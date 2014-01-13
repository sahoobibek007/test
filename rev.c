#include <iostream>
//#include <windows.h>
using namespace std;
 
	 
#define LIGHTRED 12
	 
	// Smaller board for testing purposes.  Actual size is 8x8.
	const int ROWS = 8;  
	const int COLS = 8;
	 
	// Discs
	const char HUMAN_PLAYER = 'X';
	const char COMPUTER_PLAYER = 'O';
	 
	 
	/****************************************************************************/
	 
	// Display the board to the screen.
	// [in] board - Game board
	void DisplayBoard(const char board[][COLS])
	{
	    cout << " ";
	    for (int c = 0; c < COLS; c++)
	        cout << c;
	    cout << endl;
	 
	    for (int r = 0; r < ROWS; r++)
	    {
	        cout << r;
	        for (int c = 0; c < COLS; c++)
	            cout << board[r][c];
	        cout << endl;
	    }
}
	 
	/****************************************************************************/
	 
	// Place the disc on the board, flip the discs affected, and
	// return the number of discs flipped.  Note if 0 is returned,
	// the position moved is illegal, and the board is not changed.
	// [in/out] board - Game board
	// [in]  row   - Row in board to move to
	// [in]  col   - Col in board to move to
	// [in]  disc  - Player's disc to be placed (X or O)
	int PlaceDisc(char board[][COLS], int row, int col, char disc)
	{
	    int num_flipped = 0;
	 
	    if (board[row][col] != ' ')
	        return 0;
	 
	    board[row][col] = disc;
	 
	    char opposing_disc;
	    if (disc == HUMAN_PLAYER)
	        opposing_disc = COMPUTER_PLAYER;
	    else
        opposing_disc = HUMAN_PLAYER;
	 
	    // Do we have discs to the right to flip?
	    int disc_pos = -1;
	    for (int c = col + 1; c < COLS && board[row][c] != ' ' && disc_pos == -1; c++)
	    {
	        if (board[row][c] == disc)
	            disc_pos = c;
	    }
	 
	    // Make sure we found a disc and that it is at least 2 spots away
   if (disc_pos != -1 && disc_pos > col + 1)
	    {
	        // Flip discs to the right
	        for (int c = col + 1; c < disc_pos; c++)
	        {
	            board[row][c] = disc;
	            num_flipped++;
	        }
	    }
	 
	    // Do we have discs to the left to flip?
	    disc_pos = -1;
	    for (int c = col - 1; c >= 0 && board[row][c] != ' ' && disc_pos == -1; c--)
	    {
	        if (board[row][c] == disc)
	            disc_pos = c;
	    }
	 
	    //if (disc_pos > -1) cout << "left disc_pos = " << disc_pos << endl;
	 
	    // Make sure we found a disc and that it is at least 2 spots away
	    if (disc_pos != -1 && disc_pos < col - 1)
	    {
	        // Flip discs to the left
	        for (int c = col - 1; c > disc_pos; c--)
	        {
	            board[row][c] = disc;
	            num_flipped++;
	        }
	    }
	 
	    // Do we have discs above to flip?
	    disc_pos = -1;
	    for (int r = row - 1; r >= 0 && board[r][col] != ' ' && disc_pos == -1; r--)
	    {
	        if (board[r][col] == disc)
	            disc_pos = r;
	    }
	 
	    // Make sure we found a disc and that it is at least 2 spots away
	    if (disc_pos != -1 && disc_pos < row - 1)
	    {
	        // Flip discs above
	        for (int r = row - 1; r > disc_pos; r--)
	        {
	            board[r][col] = disc;
	            num_flipped++;
	        }
	    }
	 
	    // Do we have discs below to flip?
	    disc_pos = -1;
	    for (int r = row + 1; r < ROWS && board[r][col] != ' ' && disc_pos == -1; r++)
	    {
	        if (board[r][col] == disc)
	            disc_pos = r;
	    }
	 
	    // Make sure we found a disc and that it is at least 2 spots away
	    if (disc_pos != -1 && disc_pos > row + 1)
	    {
	        // Flip discs below
	        for (int r = row + 1; r < disc_pos; r++)
	        {
	            board[r][col] = disc;
	            num_flipped++;
	        }
	    }
	 
	    // Do we have discs diagnally up-left to flip?
	    disc_pos = -1;
	    int c = col - 1;
	    for (int r = row - 1; c >= 0 && r >= 0 && board[r][c] != ' ' && disc_pos == -1; r--)
	    {
	        if (board[r][c] == disc)
	            disc_pos = r;
	        c--;
	    }
	 
	    // Make sure we found a disc and that it is at least 2 spots away
	    if (disc_pos != -1 && disc_pos < row - 1)
	    {
	        c = col - 1;
	        for (int r = row - 1; r > disc_pos; r--)
	        {
	            board[r][c] = disc;
	            num_flipped++;
            c--;
	        }
   }
	 
	    // Do we have discs diagnally up-right to flip?
	    disc_pos = -1;
	    c = col + 1;
	    for (int r = row - 1; c < COLS && r >= 0 && board[r][c] != ' ' && disc_pos == -1; r--)
	    {
	        if (board[r][c] == disc)
	            disc_pos = r;
	        c++;
	    }
	 
	    // Make sure we found a disc and that it is at least 2 spots away
	    if (disc_pos != -1 && disc_pos < row - 1)
	    {
	        c = col + 1;
	        for (int r = row - 1; r > disc_pos; r--)
	        {
	            board[r][c] = disc;
	            num_flipped++;
	            c++;
	        }
	    }
	 
	    // Do we have discs diagnally down-left to flip?
	    disc_pos = -1;
	    c = col - 1;
	    for (int r = row + 1; c >= 0 && r < ROWS && board[r][c] != ' ' && disc_pos == -1; r++)
	    {
	        if (board[r][c] == disc)
	            disc_pos = r;
	        c--;
	    }
	 
	    // Make sure we found a disc and that it is at least 2 spots away
	    if (disc_pos != -1 && disc_pos > row + 1)
	    {
	        c = col - 1;
        for (int r = row + 1; r < disc_pos; r++)
	        {
	            board[r][c] = disc;
	            num_flipped++;
            c--;
	        }
	    }
	 
	    // Do we have discs diagnally down-right to flip?
	    disc_pos = -1;
	    c = col + 1;
	    for (int r = row + 1; c < COLS && r < ROWS && board[r][c] != ' ' && disc_pos == -1; r++)
	    {
	        if (board[r][c] == disc)
	            disc_pos = r;
	        c++;
    }
	 
	    // Make sure we found a disc and that it is at least 2 spots away
	    if (disc_pos != -1 && disc_pos > row + 1)
	    {
	        c = col + 1;
	        for (int r = row + 1; r < disc_pos; r++)
        {
	            board[r][c] = disc;
	            num_flipped++;
	            c++;
	        }
	    }
	 
	    // Reset board if nothing was flipped... illegal move
	    if (num_flipped == 0)
	        board[row][col] = ' ';
	 
	    return num_flipped;
	}
	 
	/****************************************************************************/
	 
	// Check to see if the given player can make a valid move on the game board.
	// Return 1 if a move can be made, 0 otherwise.
	// [in] board  - Game board
	// [in] player - Character representing the player (X or O)
	int MoveIsPossible(const char board[][COLS], char player)
	{
	    return 1;
	}
	 
	/****************************************************************************/
	 
	// Get the human's move (if a legal move is possible) and place it on the board. 
// [in/out] board - Game board
void GetHumanMove(char board[][COLS])
	{
	    int row, col;
	    bool illegal_move;
	 
	    // Make sure there is a legal move that can be made
	    if (MoveIsPossible(board, HUMAN_PLAYER))
	    {
        do
	        {
	            illegal_move = false;
	 
	            cout << "Row? ";
	            cin >> row;
	            while (row < 0 || row >= ROWS)
	            {
	                cout << "Please select a row between 0 and " << (ROWS - 1) << ".\n";
	                cout << "Row? ";
	                cin >> row;
	            }
	 
	            cout << "Col? ";
	            cin >> col;
	            while (col < 0 || col >= COLS)
	            {
	                cout << "Please select a column between 0 and " << (COLS - 1) << ".\n";
	                cout << "Col? ";
	                cin >> col;
	            }
	 
	            if (board[row][col] != ' ')
	            {
	                cout << "Please select an empty row and column.\n";
	                illegal_move = 1;
	            }
	            else
	            {
	                int discs_flipped = PlaceDisc(board, row, col, HUMAN_PLAYER);  
	                if (discs_flipped == 0)
	                {
	                    cout << "Illegal move.\n";
	                    illegal_move = true;
	                }
	                else if (discs_flipped == 1)
	                    cout << "Flipped 1 disc.\n\n";
	                else
	                    cout << "Flipped " << discs_flipped << " discs.\n\n";
	            }
	        } while (illegal_move);
    }
	    else
	    {
	        cout << "X cannot move.\n";
	    }
	}
	 
	void SaveBoard(char board[][COLS], char temp_board[][COLS])
	{
	 
	    for( int i = 0; i < ROWS; i++)
	    {
	        for(int j =0; j < COLS; j++)
	            temp_board[i][j]= board[i][j];
	    }
	}
	 
	 
	 
	 
	 
	void GetComputerMove(char board[][COLS])
	{
	    char temp_board[ROWS][COLS];
	    int disk_flipped[ROWS][COLS];
	    int temp = 0;
	 
	 
	    SaveBoard(board,temp_board);
	 
	 
	 
	    for(int i = 0; i< ROWS; i++)
	    {
	        for(int j = 0; j < COLS; j++)
	        {
	            if(board[i][j] != 'X' ||board[i][j] !='O')
	            {
	                disk_flipped[i][j] = PlaceDisc(board,i,j,'O');
	            }
	        }
	         
    }
	 
	 
	}
	 
	 
	void main()
	{
	 
	    //Run these two lines first
	    HANDLE hcolor;
	    hcolor = GetStdHandle (STD_OUTPUT_HANDLE);
	    char board[ROWS][COLS];
	 
	    //Use this function to set your colors
	    SetConsoleTextAttribute(hcolor, LIGHTRED);
	 
	 
	    // Create a test configuration
	    strncpy(board[0],"      ", COLS);
	    strncpy(board[1],"      ", COLS);
	    strncpy(board[2],"      ", COLS);
	    strncpy(board[3],"   OX   ", COLS);
	    strncpy(board[4],"   XO   ", COLS);
	    strncpy(board[5],"      ", COLS);
	    strncpy(board[6],"      ", COLS);
	    strncpy(board[7],"      ", COLS);
	 
	 
	    DisplayBoard(board);
	 
	    cout << endl;
	 
	    GetHumanMove(board);
	 
	    DisplayBoard(board);   
	 
	}
