#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<int> *Board;

// Generate a 9x9 board filled with 0
Board MakeBoard()
{
    Board result = new vector<int>[9];
    for (int i(0); i < 9; i++)
    {
        for (int j(0); j < 9; j++)
        {
            result[i].push_back(0);
        }
    }
    return result;
}

// Check if the number filled at board[row][col] is valid according to Sudoku rule
bool IsValid(Board board, int row, int col, int num)
{
    // Check Row
    for (int i(0); i < 9; i++)
    {
        if (board[row][i] == num)
            return false;
    }
    // Check Column
    for (int i(0); i < 9; i++)
    {
        if (board[i][col] == num)
            return false;
    }

    // Check box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i(0); i < 3; i++)
    {
        for (int j(0); j < 3; j++)
        {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

// check if the current board is empty
bool IsEmpty(Board board)
{
    for (int i(0); i < 9; i++)
    {
        for (int j(0); j < 9; j++)
        {
            if (board[i][j] == 0)
                return true;
        }
    }
    return false;
}
// Input: Emptry sudoku board filled with 0
// Output: A random Sudoku Board that is valid
bool GenerateBoard(Board board)
{
    srand(time(NULL));

    vector<int> numList;
    for (int i(1); i <= 9; i++)
        numList.push_back(i);

    int row = 0;
    int col = 0;
    for (int i(0); i < 81; i++)
    {
        row = i / 9;
        col = i % 9;
        if (board[row][col] == 0)
        {
            random_shuffle(numList.begin(), numList.end());

            for (int j(0); j < numList.size(); j++)
            {
                if (IsValid(board, row, col, numList[j]))
                {
                    board[row][col] = numList[j];

                    if (!IsEmpty(board))
                    {
                        return true;
                    }
                    else
                    {
                        if (GenerateBoard(board))
                            return true;
                    }
                }
            }
            break;
        }
    }
    board[row][col] = 0;
    return false;
}
//Return the copy of the current Board
Board CopyBoard(Board board)
{
    Board result = new vector<int>[9];
    for (int i(0); i < 9; i++)
    {
        for (int j(0); j < 9; j++)
        {
            result[i].push_back(board[i][j]);
        }
    }
    return result;
}

//Input: Board and a vector of Board to record the solutions
//Output: Return the number of solutions a Board can have. Our aim is to have exactly one solutions
vector<Board> &TestUnique(Board board, vector<Board> &solutions)
{
    int memorize = board[8][8];

    if (solutions.size() < 2)
    {
        vector<int> numList;
        for (int i(1); i <= 9; i++)
        {
            numList.push_back(i);
        }

        int row(0), col(0);

        for (int i(0); i < 81; i++)
        {
            row = i / 9;
            col = i % 9;
            if (board[row][col] == 0)
            {
                for (int j(0); j < numList.size(); j++)
                {
                    if (IsValid(board, row, col, numList[j]))
                    {
                        board[row][col] = numList[j];

                        if (!IsEmpty(board))
                        {
                            Board result = CopyBoard(board);
                            solutions.push_back(result);
                        }
                        solutions = TestUnique(board, solutions);
                    }
                }
                break;
            }
        }
        board[row][col] = 0;
    }
    board[8][8] = memorize;
    return solutions;
}

//Intput: number of cell needed to delete
//Output: A Sudoku puzzle has a unique solution with that number of cells deleted
Board GeneratePuzzle(int cell)
{
    srand(time(NULL));
    Board board = MakeBoard();
    GenerateBoard(board);

    vector<int> choices;
    for (int i(0); i < 81; i++)
    {
        choices.push_back(i);
    }
    random_shuffle(choices.begin(), choices.end());

    while (choices.size() > cell)
    {
        int index = choices.at(0);
        choices.erase(choices.begin());
        int num = board[index / 9][index % 9];
        board[index / 9][index % 9] = 0;
        vector<Board> solutions;
        solutions = TestUnique(board, solutions);
        if (solutions.size() >= 2)
        {
            choices.push_back(index);
            board[index / 9][index % 9] = num;
        }
    }

    return board;
}

Board EasyMode(){
    srand(time(NULL));
    int cells = rand() % 10 + 40;
    Board board = GeneratePuzzle(cells);
    return board;
}

Board NormalMode()
{
    srand(time(NULL));
    int cells = rand() % 10 + 30;
    Board board = GeneratePuzzle(cells);
    return board;
}

Board HardMode()
{
    srand(time(NULL));
    int cells = rand() % 5 + 25;
    Board board = GeneratePuzzle(cells);
    return board;
}
