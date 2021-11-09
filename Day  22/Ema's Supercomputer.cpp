//First approach - passes all cases

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r,c;
    cin>>r>>c;
    int g[r][c];
    char t;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>t;
            if(t=='G')
                g[i][j]=0;
            else
                g[i][j]=-1;
        }
    }
    int temp,min,a;
    vector<vector<int>> v;
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(g[i][j]!=-1)
            {
                min=100;
                temp=0;
                for(a=i+1;a<r;a++)
                {
                    if(g[a][j]==-1)
                        break;
                    else
                        temp+=1;
                }
                if(temp<min)
                    min=temp;
                temp=0;
                for(a=i-1;a>=0;a--)
                {
                    if(g[a][j]==-1)
                        break;
                    else
                        temp+=1;
                }
                if(temp<min)
                    min=temp;
                temp=0;
                for(a=j+1;a<c;a++)
                {
                    if(g[i][a]==-1)
                        break;
                    else
                        temp+=1;
                }
                if(temp<min)
                    min=temp;
                temp=0;
                for(a=j-1;a>=0;a--)
                {
                    if(g[i][a]==-1)
                        break;
                    else
                        temp+=1;
                }
                if(temp<min)
                    min=temp;
                g[i][j]=min;
            }
            if(g[i][j]>0)
                v.push_back(vector<int>{i,j});
        }
    }
    int j;
    if(v.size()==0)
    {
        cout<<1;
    }
    else if(v.size()==1)
    {
        int n=g[v[0][0]][v[0][1]];
        cout<<1+n*4;
    }
    else
    {
        int q=1;
        int area=1;
        for(int i=0;i<v.size();i++)
        {
            area=1;
            int h[r][c];
            memcpy(h,g,sizeof(g));
            h[v[i][0]][v[i][1]]=-1;
            int n=g[v[i][0]][v[i][1]];
            for(int y=1;y<n+1;y++)   
            {   h[v[i][0]+y][v[i][1]]=-1;
                h[v[i][0]-y][v[i][1]]=-1;
                h[v[i][0]][v[i][1]+y]=-1;
                h[v[i][0]][v[i][1]-y]=-1;
            int m;
            for(j=0;j<v.size();j++)
            {
                int flag=0;
                if(j!=i)
                {             
                    m=g[v[j][0]][v[j][1]];
                    for(int k=1;k<m+1;k++)
                    {
                        if(h[v[j][0]+k][v[j][1]]==-1)
                        {
                            m=k-1;
                            break;
                        }
                    }
                        for(int k=1;k<m+1;k++)
                        {
                            if(h[v[j][0]-k][v[j][1]]==-1)
                            {
                                m=k-1;
                                break;   
                            }   
                        }
                        for(int k=1;k<m+1;k++)
                        {
                            if(h[v[j][0]][v[j][1]+k]==-1)
                            {
                                m=k-1;
                                break;  
                            }  
                        }
                        for(int k=1;k<m+1;k++)
                        {
                            if(h[v[j][0]][v[j][1]-k]==-1)
                            {
                                m=k-1;
                                break;
                            } 
                        }
                    if((1+y*4)>area)
                        area=(1+y*4);
                    if((1+y*4)*(1+m*4) > area)
                    {
                        area=(1+y*4)*(1+m*4);
                    }
                }
                }    
            }
            if(area>q)
                q=area;
        }
        cout<<q;
    }
    return 0;
}

// second approaches - passes few cases
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'twoPluses' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY grid as parameter.
 */

int maxP = 0;

void check(int x, int y, int l, vector<string> g)
{
    int tempP= 4*l +1;
    maxP =tempP;
    //change plus to B
    for(int a =1; a<=l; a++ )
    {
       g[x][y] = 'B'; 
        g[x+a][y] = 'B'; 
        g[x-a][y] = 'B'; 
        g[x][y+a] = 'B'; 
        g[x][y-a] = 'B'; 
    }
    //Find rest of plus and check if their product is maximum
    int r= g.size();
    int c=g[0].size();
     for(int i=1; i<r-1; i++)
    {
      for(int j=1; j<c-1; j++)
        {
            int l = 1;
           while(g[i][j] == 'G' && i-l>=0 && i+l<=c && j+l<=r && j-l>=0) 
           {
               if( g[i][j+l] == 'G' && g[i][j-l] == 'G' && g[i-l][j] == 'G' && g[i+l][j] == 'G')
               {
                   tempP *= 4*l +1;
                  if(tempP>maxP)
                  {
                      maxP = tempP;
                  }
                  tempP = tempP/( 4*l +1) ;
                   l++;
                  
               } else {
               break;
               }
           }
           
           
        }
    }    
    
}

int main()
{
    //inputs
    int r,c;
    cin>>r>>c;
    vector<string> g(r);
    for(int i=0; i<r; i++)
    {
        cin>>g[i];
    } 
    //Find all possible plus individually
    vector<vector<int>> plus;
    int k=0;
    for(int i=1; i<r-1; i++)
    {
      for(int j=1; j<c-1; j++)
        {
            int l = 1;
           while(g[i][j] == 'G' && i-l>=0 && i+l<=c && j+l<=r && j-l>=0) 
           {
               vector<int>temp;
               if( g[i][j+l] == 'G' && g[i][j-l] == 'G' && g[i-l][j] == 'G' && g[i+l][j] == 'G')
               {
                   temp.push_back(i);
                   temp.push_back(j);
                   temp.push_back(l);
                   plus.push_back(temp);
                   l++;
               } else {
               break;
               }
           }
        }
    } 
  
    if(plus.size()==0)
    {
        cout<<1;
    } else if(plus.size()==1)
            {
                cout<<4*plus[0][2] +1;
            } else {
                
                for(int i=0; i<plus.size(); i++)
                {
                    check(plus[i][0], plus[i][1], plus[i][2], g);
                    
                }  
                cout<<maxP;   
            }
    
    
    
    return 0;
}




