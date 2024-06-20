
#include<bits/stdc++.h>
using namespace std;

struct Move
{
	int row, col;
};

char player = 'O', opponent = 'X';
int turn;


bool isMovesLeft(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '.')
                return true;
    return false;
}


int evaluate(char b[3][3])
{
    int ret = 0;
    for (int row = 0; row < 3; row++)
    {
        if (b[row][0] == b[row][1] &&
            b[row][1] == b[row][2])
        {
            if (b[row][0] == player)
                ret++;
            else if (b[row][0] == opponent)
                ret--;
        }
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col < 3; col++)
    {
        if (b[0][col] == b[1][col] &&
            b[1][col] == b[2][col])
        {
            if (b[0][col] == player)
                ret++;

            else if (b[0][col] == opponent)
                ret--;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
    {
        if (b[0][0] == player)
            ret++;
        else if (b[0][0] == opponent)
            ret--;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
    {
        if (b[0][2] == player)
            ret++;
        else if (b[0][2] == opponent)
            ret--;
    }

    return ret;
}


int minimax(char board[3][3], int depth, bool isMax)
{
    int score = evaluate(board);


    if (!isMovesLeft(board))
        return score;

    if (isMax)
    {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // Check if cell is empty
                if (board[i][j] == '.')
                {
                    // Make the move
                    board[i][j] = player;

                    // Call minimax recursively and choose
                    // the maximum value
                    best = max(best,
                               minimax(board, depth + 1, !isMax));

                    // Undo the move
                    board[i][j] = '.';
                }
            }
        }
        return best;
    }

        // If this minimizer's move
    else
    {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // Check if cell is empty
                if (board[i][j] == '.')
                {
                    // Make the move
                    board[i][j] = opponent;

                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best,
                               minimax(board, depth + 1, !isMax));

                    // Undo the move
                    board[i][j] = '.';
                }
            }
        }
        return best;
    }
}

// This will return the best possible move for the player
void findBestMove(char board[3][3])
{
    int bestVal = evaluate(board);

    bool flg=0;


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '.')
            {
                // Make the move
                board[i][j] = player;

                // compute evaluation function for this
                // move.
                int moveVal = minimax(board, 0, false);

                // Undo the move
                board[i][j] = '.';


                if (moveVal > bestVal||!flg)
                {
                    flg=1;
                    bestVal = moveVal;
                }
            }
        }
    }


    if(turn==0){
        bestVal=-bestVal;
    }
    cout << bestVal<<'\n';
}

// Driver code
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cin.tie(NULL);


    int t;
    cin >> t;
    while (t--) {

        cin >> turn;
        if (turn == 1) {
            player = 'O';
            opponent = 'X';
        }
        else {
            player = 'X';
            opponent = 'O';
        }
        char board[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> board[i][j];
            }
        }

        findBestMove(board);


    }

    return 0;
}