bool sudoku2(std::vector<std::vector<char>> grid) 
{
    for(int i=0; i<9; i++)
    {
        int A[10] = {0};
        for(int j=0; j<9; j++)
        {
            if(grid[i][j]!='.')
            {
                if(A[grid[i][j]-'1']==1)
                {
                    
                    return false;
                }
                A[grid[i][j]-'1']=1;
            }
        }
    }
    
    for(int i=0; i<9; i++)
    {
        int A[10] = {0};
        for(int j=0; j<9; j++)
        {
            if(grid[j][i]!='.')
            {
                if(A[grid[j][i]-'1']==1)
                {
                    
                    return false;
                }
                A[grid[j][i]-'1']=1;
            }
        }
    }
    
    for(int block=0; block<9; block++)
    {
        int A[10] = {0};
        for (int i = block / 3 * 3; i < block / 3 * 3 + 3; i++)
            for (int j = block % 3 * 3; j < block % 3 * 3 + 3; j++)
            {
                if(grid[i][j]!='.')
                {
                    if(A[grid[i][j]-'1']==1)
                {
                    
                    return false;
                }
                    A[grid[i][j]-'1']=1;
                }
            }
    }
    
    return true;
}
