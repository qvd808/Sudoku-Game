#include "Algorithm.cpp"

int main()
{
    srand(time(NULL));
    int randomMode = rand() % 3;

    Board board;

    switch (randomMode)
    {
    case 0:
        cout << "Enter Easy Mode" << endl;
        board = EasyMode();
        break;
    
    case 1:
        cout << "Enter Normal Mode" << endl;
        board = NormalMode();
        break;

    default:
        cout << "Enter Hard Mode" << endl;
        board = HardMode();
        break;
    }


    for (int i(0); i < 9; i++)
    {
        for (int j(0); j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << endl;

    vector<Board> solutions;
    solutions = TestUnique(board, solutions);
    for (int i(0); i < solutions.size(); i++)
    {
        for (int j(0); j < 9; j++)
        {
            for (int k(0); k < 9; k++)
            {
                cout << solutions.at(i)[j][k] << " ";
            }
            cout << endl;
        }
    }

    delete board;

    return 0;
}