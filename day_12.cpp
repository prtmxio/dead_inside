#include<bits/stdc++.h>
using namespace std;


// Word Search
bool valid(vector<vector<char>>& board, int i, int j){
    int m = board.size();
    int n = board[0].size();
    if(i >= 0 && i < m && j >= 0 && j < n) return true;
    return false;
}

bool search(vector<vector<char>>& board, string word, int r, int c, int wx){
    if(!valid(board, r, c)) return false;
    if(board[r][c] != word[wx]) return false;
    if(wx == word.size() - 1) return true;

    char temp =board[r][c];
    board[r][c] = '#';
    bool found = search(board, word, r+1, c, wx+1) || search(board, word, r-1, c, wx+1) ||
                search(board, word, r, c+1, wx+1) || search(board, word, r, c-1, wx+1);
    board[r][c] = temp;
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    // find wrd[0]
    // check if its even valid ---> then check if next word[1] exist in its neighbours
    // if ues move to it and repear
    // else back to square one
    int m = board.size();
    int n = board[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(search(board, word, i, j, 0)){
                return true;
            }
        }
    }
    return false;

}

// Number of islands
bool valid2(vector<vector<char>>& grid, int i, int j){
    int m = grid.size();
    int n = grid[0].size();
    if(i >= 0 && i < m && j >= 0 && j < n) return true;
    return false;
}

void check_islands(vector<vector<char>>& grid, int i, int j){
    if(!valid2(grid, i, j)) return;
    if(grid[i][j] == '#') return;
    if(grid[i][j] == '0') return;
    char temp = grid[i][j];
    grid[i][j] = '#';
    check_islands(grid, i-1, j);
    check_islands(grid, i+1, j);
    check_islands(grid, i, j-1);
    check_islands(grid, i, j+1);
    // grid[i][j] = temp;
    // didnt reverse it as we need to sink all the islands
    // we must sink all land  we have covered connected to our entry "1"
    // Foor g2 after its done it will look like :
    // g2 = [
    //   ["#","#","0","0","0"],
    //   ["#","#","0","0","0"],
    //   ["0","0","1","0","0"],
    //   ["0","0","0","1","1"]
    // ]

}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '1'){
                count += 1;
                check_islands(grid, i, j);
            }
        }
    }
    return count;
}

// Max Area of island

bool valid3(vector<vector<int>>& grid, int i, int j){
    int m = grid.size();
    int n = grid[0].size();
    if(i >= 0 && i < m && j >= 0 && j < n) return true;
    return false;
}

void island_area(vector<vector<int>>& grid, int i, int j, int& area){
    if(!valid3(grid, i, j)) return;
    if(grid[i][j] == -1) return; // already sunk
    if(grid[i][j] == 0) return;
    area += 1;
    grid[i][j] = -1; // sink it
    island_area(grid, i-1, j, area);
    island_area(grid, i+1, j, area);
    island_area(grid, i, j-1, area);
    island_area(grid, i, j+1, area);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int max_area = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                int area = 0;
                island_area(grid, i, j, area);
                max_area = max(max_area, area);
            }
        }
    }
    return max_area;
}


// surrounded regiosn

bool valid4(vector<vector<char>>& grid, int i, int j){
    int m = grid.size();
    int n = grid[0].size();
    if(i >= 0 && i < m && j >= 0 && j < n) return true;
    return false;
}

bool border(vector<vector<char>>& grid, int i, int j){
    int m = grid.size() - 1;
    int n = grid[0].size() - 1;
    if(i == 0 || i == m || j == 0 || j == n) return true;
    return false;
}

void sink_it(vector<vector<char>>& board, int i, int j){
    if(!valid4(board, i, j)) return;
    if(board[i][j] == '#') return;
    if(board[i][j] == 'X') return;
    board[i][j] = '#';
    sink_it(board, i+1, j);
    sink_it(board, i-1, j);
    sink_it(board, i, j+1);
    sink_it(board, i, j-1);
}

void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'O' && border(board, i, j)){
                sink_it(board, i, j);
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
            if(board[i][j] == '#'){
                board[i][j] = 'O';
            }
        }
    }
}

int main(){
    // vector<vector<char>> g1 = {
    //   {'1', '1', '1', '1', '0'},
    //   {'1', '1', '0', '1', '0'},
    //   {'1', '1', '0', '0', '0'},
    //   {'0', '0', '0', '0', '0'}
    // };

    // vector<vector<char>> g2 = {
    //   {'1', '1', '0', '0', '0'},
    //   {'1', '1', '0', '0', '0'},
    //   {'0', '0', '1', '0', '0'},
    //   {'0', '0', '0', '1', '1'}
    // };


    vector<vector<int>> g1 = {
      {1, 1, 1, 1, 0},
      {1, 1, 0, 1, 0},
      {1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0}
    };

    vector<vector<int>> g2 = {
      {1, 1, 0, 0, 0},
      {1, 1, 0, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 0, 1, 1}
    };

    vector<vector<char>> grid = {
      {'O', 'O', 'O'},
      {'O', 'O', 'O'},
      {'O', 'O', 'O'}
    };

    solve(grid);

    for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
    }

    // cout << maxAreaOfIsland(g1) << endl;
    // cout << maxAreaOfIsland(g2) << endl;
    return 0;
}
