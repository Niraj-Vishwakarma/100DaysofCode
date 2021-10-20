//HACKERRANK
https://www.hackerrank.com/challenges/3d-surface-area/problem

/*
 * Complete the 'surfaceArea' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY A as parameter.
 */

int surfaceArea(vector<vector<int>> A) {

int H = A.size();
int W = A[0].size();
vector<vector<int>> D (H+2, vector<int>(W+2,0));
for(int i=1; i<H+1; i++)
{
    for(int j=1; j<W+1; j++)
    {
      D[i][j]=A[i-1][j-1];  
    }
}
int area = 2*W*H;
for(int i=1; i<=H; i++)
  for(int j=1; j<=W; j++)
  {
     area += max(0, D[i][j]-D[i-1][j] ); 
     area += max(0, D[i][j]-D[i+1][j] );
     area += max(0, D[i][j]-D[i][j-1] );
     area += max(0, D[i][j]-D[i][j+1] );
  }



return area;
