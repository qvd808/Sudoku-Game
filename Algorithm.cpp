#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<int> * Board;

//Generate a 9x9 board filled with 0
Board MakeBoard(){
    Board result = new vector<int>[9];
    for (int i(0); i < 9; i++){
        for (int j(0); j < 9; j++){
            result[i].push_back(0);
        }
    }
    return result;
}

//Check if the number filled at board[row][col] is valid according to Sudoku rule
bool IsValid(Board board, int row, int col, int num){
    //Check Row
    for (int i(0); i < 9; i++){
        if (board[row][i] == num)
            return false;
    }
    //Check Column
    for (int i(0); i < 9; i++){
        if (board[i][col] == num)
            return false;
    }

    //Check box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i(0); i < 3; i++){
        for (int j(0); j < 3; j++){
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

//check if the current board is empty
bool IsEmpty(Board board){
    for (int i(0); i < 9; i++){
        for (int j(0); j < 9; j++){
            if (board[i][j] == 0)
                return true;
        }
    }
    return false;
}
//Input: Emptry sudoku board filled with 0
//Output: A random Sudoku Board that is valid
bool GenerateBoard(Board board){
    srand(time(NULL));

    vector<int> numList;
    for (int i(1); i <= 9; i++)
        numList.push_back(i);

    int row = 0;
    int col = 0;
    for (int i(0); i < 81; i++){
        row = i / 9;
        col = i % 9;
        if (board[row][col] == 0){
            random_shuffle(numList.begin(), numList.end());

            for (int j(0); j < numList.size(); j++)
            {
                if (IsValid(board, row, col, numList[j])){
                    board[row][col] = numList[j];

                    if (!IsEmpty(board)){
                        return true;
                    } else{
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

// Board EasyMode(){

// }

int main(){

    Board board = MakeBoard();
    GenerateBoard(board);

    for (int i(0); i < 9; i++){
        for (int j(0); j < 9; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    delete board;

    return 0;
}