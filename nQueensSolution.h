#pragma once
class placedQneen
{
private:
    int row;
    int column;
public:
    placedQneen()
    {
        row = 0;
        column = 0;
    }
    
    placedQneen(int newRow, int newColumn)
    {
        row = newRow;
        column = newColumn;
    }

    void setRow(int newRow)
    {
        row = newRow;
    }

    void setColumn(int newColumn)
    {
        column = newColumn;
    }

    int getRow()
    {
        return row;
    }

    int getColumn()
    {
        return column;
    }

    friend bool operator ==(const placedQneen& R1, const placedQneen& R2);
};

bool operator ==(const placedQneen& R1, const placedQneen& R2)
{
    return R1.row * R2.column == R2.row * R1.column;
}

const int QUEENSVLAUE = 100;
bool endGame(int** nQueens, int sizeOfBoard, int numberOfQueensOnBoard)
{
    int pointsChecked = 0;
    if (numberOfQueensOnBoard == sizeOfBoard)
    {
        return true;
    }

    //for (int i = 0; i < sizeOfBoard; i++) {
    //    for (int j = 0; j < sizeOfBoard; j++) {

    //        if (nQueens[i][j] == 0)
    //        {
    //            return false;
    //        }
    //    }
    //}

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
}

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

//Precondition: takes input user from board size
//Postcondition: displays the values of the board
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

void removeQueen(int**& nQueens, int sizeOfBoard, int& row, int column, int& numberOfQueensOnBoard)
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

//bool possibleSoultion(int**& nQueens, int sizeOfBoard, int& row, int column, int& numberOfQueensOnBoard)
//{
//
//}

void nQueensSoultion()
{
    //left int is row, right int is column
    stack<placedQneen> placedQueens;
    placedQneen temp;

	int sizeOfBoard = inputInteger("Enter a number (1...100) if queens: ", 1, 100);
	int column = inputInteger("Enter the column (1.." + to_string(sizeOfBoard) + ") to place the first queen: ",1, sizeOfBoard);
    int row = 1;
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

    bool placedQueen;
    addQueen(nQueens, sizeOfBoard, 0, column -1, numberOfQueens);
    temp.setRow(0);
    temp.setColumn(column - 1);
    placedQueens.push(temp);
    displayBoard(nQueens, sizeOfBoard);
    cout << endl << endl << endl;
    


    while (true)
    {
        if (endGame(nQueens, sizeOfBoard, numberOfQueens))
            break;
        placedQueen = false;
        int movePosition = 0;
        for (int i = 0; i < sizeOfBoard; i++)
        {
            if (nQueens[row][i]==0)
            {
                addQueen(nQueens, sizeOfBoard, row, i, numberOfQueens);
                temp.setRow(row);
                temp.setColumn(i);
                placedQueens.push(temp);
                row++;  
                placedQueen = true;
                displayBoard(nQueens, sizeOfBoard);
                cout << endl << endl << endl;
                break;
            }
        }
        if (placedQueen == false)
        {
            row--;
            temp = placedQueens.top();
            placedQueens.pop();
            removeQueen(nQueens, sizeOfBoard, row,temp.getColumn() , numberOfQueens);
            displayBoard(nQueens, sizeOfBoard);
            cout << endl << endl << endl;
            
            for (int i = 0; i < sizeOfBoard; i++)
            {
                if (nQueens[row][i] == 0)
                {
                    if (row != temp.getRow() && column != temp.getColumn())
                    {
                        temp.setColumn(temp.getColumn() + 1);
                        addQueen(nQueens, sizeOfBoard, temp.getRow(), temp.getColumn(), numberOfQueens);
                    }
                }
            }
            displayBoard(nQueens, sizeOfBoard);
            cout << endl << endl << endl;
        }

        //displayBoard(nQueens, sizeOfBoard);
        //cout << endl << endl << endl;

    }
    displayBoard(nQueens, sizeOfBoard);
}