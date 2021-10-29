#include <bits/stdc++.h>

using namespace std;

int main ()
{
    long m,n,r;
    cin>>m>>n>>r;
    long mat[m][n];
    // input 
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            long input;
            cin>>input;
            mat[i][j]=input;      
        }
    }
    //rotate ny layers
    for(int i=0; i< (min(m,n)/2); i++)
    {
        long rf = r%(2*(m+n) - 8*i -4); 
        
        for(int k=1; k<=rf; k++ )
        {
            //top row;
            for(int j=i; j<n-1-i; j++)
            {
                long temp = mat[i][j];
                mat[i][j] = mat[i][j+1];
                mat[i][j+1] = temp;
            }
            //right col;
            int tempR = i;
            for(int j= n-i-1; tempR<m-1-i; tempR++ )
            {
                long temp = mat[tempR][j];
                mat[tempR][j] = mat[tempR+1][j];
                mat[tempR+1][j] = temp;
                
            }
            //bottom row;
            tempR = m-1-i; 
            for(int j = n-i-1; j>i; j-- )
            {
                long temp = mat[tempR][j];
                mat[tempR][j] = mat[tempR][j-1];
                mat[tempR][j-1] = temp;
            }
            //left col
            tempR = m-1-i;
            for(int j=i; tempR>i+1; tempR-- )
            {
                long temp = mat[tempR][j];
                mat[tempR][j] = mat[tempR-1][j];
                mat[tempR-1][j] = temp;
            }
        }
    }
    
    // print 
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
           cout<<mat[i][j]<<" ";      
        }
        cout<<"\n";
    }
    return 0;
}
