class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        bool visited[m][n];

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[i][j] =false;
            }
        }

        while (true)
        { 
            int r=0,c=0,k=0; 

            for(int i=0;i<m-1;i++)
            {
                for(int j=0;j<n-1;j++)
                {
                    if(board[r][c] == word[k++])
                    {
                        visited[i][j]=true;
                        if(board[++r][c]!=word[k++] && board[--r][c]!=word[k++] && board[r][++c]!=word[k++] && board[r][--c]!=word[k++])
                            return false;
                        else 
                            return true;

                    }
                }
            }
        }
    }
};
