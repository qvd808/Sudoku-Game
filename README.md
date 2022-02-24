**Report Sudoku Game**

![](RackMultipart20220219-4-1xtxphm_html_83d275fd1e36ca60.png)

1. **Members**

Khoi Nguyen Nguyen

Dang Quang Vinh

Nguyen Huynh Vuong The

1. **Introduction**

This is our sudoku game development project, as well as our first game development project based entirely on C++ code, a game with a simple user-friendly interface, and players can experience different difficulty levels to challenge themselves.

1. **Algorithm**

This is a description that describes the Algorithm and how the Sudoku puzzle works. Our aim is to generate a Sudoku board 9x9, which has some cells filled with numbers for the user to solve the puzzle. The number of missing cells will be the difficulty of the Sudoku board, for example, Easy Mode will have 23 to 37 missing cells, Normal Mode will have 38 to 47 missing cells, and the final Hard Mode will have 49 to 54 missing cells. To accomplish this goal, we will have to generate a valid Sudoku Board and keep deleting the cells until the Sudoku Board satisfies its difficulty level. To achieve our goals, we&#39;ll need some functionality during the production:

- **MakeBoard()**: It will generate a 9x9 Board which all cells has a initial values of 0
- **IsValid(Board board, int row, int col, int num)**: It will take a Board, a row, a column and a number and check if the input number is available on that row, column or the box. I used this function to guarantee that the number we filled in the cells is following the Sudoku rule.
- **IsEmpty(Board board)**: It will take a Board and return True if the Board still has empty cells or it will return false otherwise.
- **GenerateBoard(Board board)**: It will take in an empty Board (a Board filled with 0) and generate a valid Sudoku Board using backtracking. If it sees an empty cell (a cell has value of 0), it will choose a random number and use the function IsValid() to see if that number satisfied the Sudoku goals. If the number is satisfied, the vacant cell will be filled with that number, and the process will continue to the next cell. If the number does not satisfy it, it will continue to test numbers from 1 to 9 until it finds one that does. If after testing all the numbers from 1 to 9 and the Board is still invalid, it will backtrack and return to the previous cells and try out a different number on that cell. The Board will eventually be filled and because the function introduces randomness at each stage of selecting a number for new cells, this method will produce a different Board each time.

However, there are some certain risks that we have to tackle. We cannot blindly remove a cell because during that process, our puzzle may create multiple solutions. Since there are numerous answers to a Sudoku puzzle, this problem is a major risk to the logic of the game as well as our check solution feature. To solve this problem, we use some functionality:

- **CopyBoard(Board board):** It will take a board and return the exact copy of that board.
- **TestUnique(Board board, vector\&lt;Board\&gt; &amp;solutions)**: It will take a puzzle board and a vector of possible solutions. This function will create a solution and push into the vector solutions. If there are more than two solutions, the functions will stop creating and return the vector of one or two possible solutions.
- **GeneratePuzzle(int cell):** It will take an integer which is the number of cells we need to delete. The function will first generate 81 choices for the 9x9 Sudoku board and shuffle it randomly and start deleting cells we generated. While deleting, it will check if the board has a unique solution or not with TestUnique. If the solution size is more than one then that cell will be put back in its place and we proceed to check and remove other cells until we reach the number of cells we want to delete. As long as the input _cell_ is larger or equal to 17, we will always get a unique board. However, this function has a bigger issue is that if we put the number of cells too low (17 - 26), it will take longer to generate a unique solution due to the nature of backtracking and looking for all possible choices. To fix this issue, we only choose the number of cells bigger than 27 to make the program generated faster.

With this Generated function, we will make another three functions EasyMode(), NormalMode(), Hardmode() and randomly generate a number from range of that difficulty. The generated number will be input of the GeneratedPuzzle() function and output a Board according to that difficulty.

![](RackMultipart20220219-4-1xtxphm_html_3703c90aad8504ca.png)

![](RackMultipart20220219-4-1xtxphm_html_44db8a73da9411bf.png)

![](RackMultipart20220219-4-1xtxphm_html_8ed1cc4f388607ff.png)
