class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        //Approach :- Take Edge O's as our Source and apply BFS or DFS on the O's and else will become X.
        int n=board.size();
        int m =board[0].size();
        vector<vector<char>>grid(n,vector<char>(m,'X'));
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(board[i][j]=='O' && (i ==0 || i==n-1 || j==0 || j==m-1))
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        vector<int>delrow={-1,0,1,0};
	    vector<int>delcol={0,-1,0,1};

        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            grid[r][c]='O';
            

            for(int i =0;i<4;i++)
	        {
	            int row=r+delrow[i];
	            int col=c+delcol[i];
	            if(row>=0 && row<n && col>=0 && col<m && board[row][col]=='O' && vis[row][col]==0)
	            {
                    vis[row][col]=1;
	                q.push({row,col});
	            }
	        }
        }
        board=grid;
        
    }
};