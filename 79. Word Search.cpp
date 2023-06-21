//https://leetcode.com/problems/word-search/description/
//Simple DFS approach, can lead to TLE in case of high character counts of the first letter i.e "aaaaaabc" in which case try reversing the word

class Solution {
public:
    //Global variables to store direction and board dimensions, can be removed by passing them in dfs argument list
    int n, m;
    int dirs[5] = {0, -1, 0 , 1, 0};
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(dfs(board, i, j, 0, word))
                    return true;
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, int index, string& word)
    {
        if(word.size() == index)                        //Terminating condition, implies all char counts of word have been found
            return true;
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[index])   //bound checking and character at index checking
            return false;
        char og = board[i][j];                                     //used to preserve board
        board[i][j] = '#';                                         //prevent duplication
        for(int k = 0; k < 4; k++)
            if(dfs(board, i + dirs[k], j + dirs[k + 1], index + 1, word))
                return true;
        board[i][j] = og;                                       // restore board, can be replaced by board[i][j] = word[index]
        return false;
    }
};