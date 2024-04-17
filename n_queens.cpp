//backtracking

#include <iostream>
#include <vector>

using namespace std;

//prints the board
void print(vector<vector<int>> &board) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board.size(); j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//is_safe checks if queen is safe at board[i][col]
bool is_safe(int row, int col, vector<vector<int>> &board) {

    //check if there is any queen in same row on previous columns
    for (int i = 0; i < col; i++) {
        if(board[row][i]) {
            return false;
        }
    }

    //check for upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j]) {
            return false;
        }
    }

    //check for lower diagonal
    for (int i = row, j = col; i < board.size() && j >= 0; i++, j--) {
        if(board[i][j]) {
            return false;
        }
    }

    return true;
}

//MAIN LOGIC
//Level in this game is about column
bool n_queens(int col, vector<vector<int>> &board) {
    if(col >= board.size()) {
        print(board);
        return true;
    }

    bool is_valid = false;

    //checking all possibilities
    for(int i = 0; i < board.size(); i++) {
        if(is_safe(i, col, board)) {
            //save the current possibility
            board[i][col] = 1;
            if(n_queens(col+1, board)) { // try to solve for further levels
                is_valid = true;
                return is_valid;  //if we comment this line then it will print all the solutions
            }

            //if unable to solve for further level, remove the potential possibility
            board[i][col] = 0;
        }
    }
    return is_valid;
}

int main() {
    int n;
    cin>>n;

    //nxn board with all zeroes
    vector<vector<int>> board(n, vector<int>(n,0));

    if(!n_queens(0, board)) {
        cout<<"solution does nor exist for n = "<<n<<endl;
    }
    return 0;
}