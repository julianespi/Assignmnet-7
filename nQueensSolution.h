#pragma once
class placedQneen
{
private:
    int row;
    int column;
public:

    //default constructor 
    placedQneen()
    {
        row = 0;
        column = 0;
    }

    //copy constructor
    placedQneen(int newRow, int newColumn)
    {
        row = newRow;
        column = newColumn;
    }

    //Precondition: a int
    //Postcondition: sets new int to row
    void setRow(int newRow)
    {
        row = newRow;
    }
    //Precondition: a int
    //Postcondition: sets new int to coulumn
    void setColumn(int newColumn)
    {
        column = newColumn;
    }
    //Precondition: none
    //Postcondition: returns the row
    int getRow()
    {
        return row;
    }

    //Precondition: none
    //Postcondition: returns the column
    int getColumn()
    {
        return column;
    }

    //Precondition: a placed queen on the left and right
    //Postcondition: returns true of they are equal flase if they are not
    friend bool operator ==(const placedQneen& R1, const placedQneen& R2);
};

//Precondition: a placed queen on the left and right
//Postcondition: returns true of they are equal flase if they are not
bool operator ==(const placedQneen& R1, const placedQneen& R2)
{
    return R1.row * R2.column == R2.row * R1.column;
}

const int QUEENSVLAUE = 100;
//Precondition:takes the board, the size of the board, and the number of queens on the board
//Postcondition: returns ture if you found a soultion flase if you havent.
bool endGame(int** nQueens, int sizeOfBoard, int numberOfQueensOnBoard)
{
    int pointsChecked = 0;
    if (numberOfQueensOnBoard == sizeOfBoard)
    {
        return true;
    }

    return false;
}

//Precondition: takes input user from board size
//Postcondition: displays board size based upon user input
void displayBoard(int** nQueens, int sizeOfBoard)
{
    // displays the bored
    for (int i = 0; i < sizeOfBoard; i++) {
        for (int j = 0; j < sizeOfBoard; j++) {
            if (j == 0)
                cout << "|";
            if (nQueens[i][j] == QUEENSVLAUE)
                cout << "Q";
            else if (nQueens[i][j] > 0)
                cout << "*";
            else
                cout << " ";
            cout << "|";
            if (j == sizeOfBoard - 1)
                cout << endl;
        }
        for (int i = 0; i < sizeOfBoard; i++)
        {
            if (i == 0)
                cout << "-";
            cout << "--";
            if (i == sizeOfBoard - 1)
                cout << endl;
        }
    }
    cout << endl << endl << endl;
}

//Precondition: takes the board, the size of the board, the row and column you want to places a queen on
//Postcondition: returns true if there is no overlap and false if there is overlap
bool isSafe(int** nQueens, int sizeOfBoard, int row, int column)
{
    if (nQueens[row][column] == QUEENSVLAUE)
    {
        //cout << "Invalid. A queen is already placed here. Try Again." << endl;
        return false;
    }
    else if (nQueens[row][column] > 0)
    {
        //cout << "Invalid. in the path of a current Queen. Try Again." << endl;
        return false;
    }
    else
    {
        return true;
    }
}

//Precondition: takes the board, the size of the board, the row and column you want to places a queen on and the number of queens on the board
//Postcondition: adds a queen to the board
void addQueen(int**& nQueens, int sizeOfBoard, int row, int column, int& numberOfQueensOnBoard)
{


    if (nQueens[row][column] == QUEENSVLAUE)
    {
        //cout << "Invalid. A queen is already placed here. Try Again." << endl;
        return;
    }
    else if (nQueens[row][column] > 0)
    {
        //cout << "Invalid. in the path of a current Queen. Try Again." << endl;
        return;
    }
    else
    {
        nQueens[row][column] = QUEENSVLAUE;
        numberOfQueensOnBoard++;
    }


    for (int i = 0; i < sizeOfBoard; i++)
    {

        if (column != i)
            nQueens[row][i] += 1;
    }

    for (int i = 0; i < sizeOfBoard; i++)
    {
        if (row != i)
            nQueens[i][column] += 1;
    }

    //handle diagonal line going bottom right.
    int temp1 = -1;
    for (int i = row; i < sizeOfBoard; i++)
    {
        temp1++;
        if (i >= sizeOfBoard)
            break;
        for (int j = column; j < sizeOfBoard; j++) {

            if (j >= sizeOfBoard)
                break;
            if (i == row + temp1 && j == column + temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] += 1;
            }

        }
    }

    temp1 = -1;
    for (int i = row; i > -1; i--)
    {
        temp1++;
        if (i <= -1)
            break;
        for (int j = column; j > -1; j--) {

            if (j <= -1)
                break;
            if (i == row - temp1 && j == column - temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] += 1;
            }

        }
    }

    temp1 = -1;
    for (int i = row; i < sizeOfBoard; i++)
    {
        temp1++;
        if (i >= sizeOfBoard)
            break;
        for (int j = column; j > -1; j--) {

            if (j <= -1)
                break;
            if (i == row + temp1 && j == column - temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] += 1;
            }

        }
    }

    temp1 = -1;
    for (int i = row; i > -1; i--)
    {
        temp1++;
        if (i <= -1)
            break;
        for (int j = column; j < sizeOfBoard; j++) {

            if (j >= sizeOfBoard)
                break;
            if (i == row - temp1 && j == column + temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] += 1;
            }

        }
    }

}

//Precondition: takes the board, the size of the board, the row and column you want to remove a queen from and the number of queens on the board
//Postcondition: removes a queen from the board
void removeQueen(int**& nQueens, int sizeOfBoard, int row, int column, int& numberOfQueensOnBoard)
{

    if (nQueens[row][column] == QUEENSVLAUE)
    {
        nQueens[row][column] = 0;
        numberOfQueensOnBoard--;
    }
    else if (nQueens[row][column] > 0)
    {
        //cout << "Invalid. This is a Queens path not a Queen. Try Again." << endl;
        return;
    }
    else
    {
        //cout << "Invalid. This is a blank space. Try Again." << endl;
        return;
    }

    nQueens[row][column] = 0;

    for (int i = 0; i < sizeOfBoard; i++)
    {

        if (column != i)
            nQueens[row][i] -= 1;
    }

    for (int i = 0; i < sizeOfBoard; i++)
    {
        if (row != i)
            nQueens[i][column] -= 1;
    }

    int temp1 = -1;
    for (int i = row; i < sizeOfBoard; i++)
    {
        temp1++;
        if (i >= sizeOfBoard)
            break;
        for (int j = column; j < sizeOfBoard; j++) {

            if (j >= sizeOfBoard)
                break;
            if (i == row + temp1 && j == column + temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] -= 1;
            }

        }
    }

    temp1 = -1;
    for (int i = row; i > -1; i--)
    {
        temp1++;
        if (i <= -1)
            break;
        for (int j = column; j > -1; j--) {

            if (j <= -1)
                break;
            if (i == row - temp1 && j == column - temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] -= 1;
            }

        }
    }

    temp1 = -1;
    for (int i = row; i < sizeOfBoard; i++)
    {
        temp1++;
        if (i >= sizeOfBoard)
            break;
        for (int j = column; j > -1; j--) {

            if (j <= -1)
                break;
            if (i == row + temp1 && j == column - temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] -= 1;
            }

        }
    }

    temp1 = -1;
    for (int i = row; i > -1; i--)
    {
        temp1++;
        if (i <= -1)
            break;
        for (int j = column; j < sizeOfBoard; j++) {

            if (j >= sizeOfBoard)
                break;
            if (i == row - temp1 && j == column + temp1)
            {
                if (row != i && column != j)
                    nQueens[i][j] -= 1;
            }

        }
    }
}

//Precondition: none
//Postcondition: solves the nQueens board
void nQueensSoultion()
{
    //left int is row, right int is column
    stack<placedQneen> placedQueens;
    placedQneen temp;

	int sizeOfBoard = inputInteger("Enter a number (1...100) if queens: ", 1, 100);
	int column = inputInteger("Enter the column (1.." + to_string(sizeOfBoard) + ") to place the first queen: ",1, sizeOfBoard);
    int row = 0;
    int numberOfQueens = 0;
    int** nQueens = new int* [sizeOfBoard];

    //creates the array and fills the array with blank spaces
    for (int i = 0; i < sizeOfBoard; i++) {

        // Declare a memory block
        // of size sizeOfBoard
        nQueens[i] = new int[sizeOfBoard];
    }

    // Traverse the 2D array
    for (int i = 0; i < sizeOfBoard; i++) {
        for (int j = 0; j < sizeOfBoard; j++) {

            // Assign values to the
            // memory blocks created
            nQueens[i][j] = 0;
        }
    }

    addQueen(nQueens, sizeOfBoard, row, column - 1, numberOfQueens);
    displayBoard(nQueens, sizeOfBoard);
    temp.setRow(row);
    temp.setColumn(column - 1); 
    placedQueens.push(temp);
    row++;
    
    bool clearRow = false;

    while (true)
    {

        for(int a = 0; a < sizeOfBoard-1;a++)
        {
            for (int i = 0; i < sizeOfBoard; i++)
            {
                if (endGame(nQueens, sizeOfBoard, numberOfQueens))
                {
                    cout << "soultion for " << sizeOfBoard << " queens." << endl;
                    displayBoard(nQueens, sizeOfBoard);
                    return;
                }
                if (isSafe(nQueens, sizeOfBoard, row, i))
                {
                    addQueen(nQueens, sizeOfBoard, row, i, numberOfQueens);
                    displayBoard(nQueens, sizeOfBoard);
                    temp.setRow(row);
                    temp.setColumn(i);
                    for (int c = 0; c < sizeOfBoard; c++)
                    {
                        if (row < sizeOfBoard-1)
                        {

                            if (nQueens[row + 1][c] == 0)
                                clearRow = true;
                        }

                    }

                    if (clearRow == true)
                    {
                        temp.setRow(row);
                        temp.setColumn(i);
                        placedQueens.push(temp);
                        row++;
                        displayBoard(nQueens, sizeOfBoard);
                        break;
                    }
                    else
                    {
                        removeQueen(nQueens, sizeOfBoard, row, i, numberOfQueens);
                        displayBoard(nQueens, sizeOfBoard);
                        for (int c = 0; c < sizeOfBoard; c++)
                        {
                            if (nQueens[row][c] == 0 && c > temp.getColumn())
                            {
                                addQueen(nQueens, sizeOfBoard, row, c, numberOfQueens);
                                temp.setRow(row);
                                temp.setColumn(c);
                                placedQueens.push(temp);
                                row++;
                                displayBoard(nQueens, sizeOfBoard);
                            }
                        }
                    }
                }
            }
        }
        
        bool newStart = false;
        cout << endl;
        int loopCount = placedQueens.size();
        while(newStart == false)
        {
            temp = placedQueens.top();
            removeQueen(nQueens, sizeOfBoard, temp.getRow(), temp.getColumn(), numberOfQueens);
            placedQueens.pop();
            row--;
            displayBoard(nQueens, sizeOfBoard);
            if (row == 0 && temp.getColumn() == sizeOfBoard - 1)
            {
                cout << "No Soulltions" << endl;
                return;
            }
            for (int a = 0; a < sizeOfBoard; a++)
            {
                if (nQueens[row][a] == 0 && a > temp.getColumn())
                {

                    addQueen(nQueens, sizeOfBoard, row, a, numberOfQueens);
                    temp.setRow(row);
                    temp.setColumn(a);
                    placedQueens.push(temp);
                    row++;
                    displayBoard(nQueens, sizeOfBoard);
                    newStart = true;
                    break;
                }
            }
            
        }

    }
}
