// first = pases all case
vector<string> bomberMan(int n, vector<string> grid) {
    
    vector <string> arr1; 
    string s ="";
    int r=grid.size();
    int m=grid[r-1].size();
    if(n==1)
    return grid;
    
    
    for(int i=0;i<r;i++)
    {   s="";
        for(int i=0;i<m;i++)
        {
         s+="O";
         }
         arr1.push_back(s);

    }
    if(n%2==0)
    return arr1;
    string arr[r][m];
    string arr2[r][m];
    string arr3[r][m];
    arr1.clear();
    cout<<endl;

// 6 7 3   
// .......     
// ...O...    
// ....O..
// .......
// OO.....
// OO.....
  


   arr = grid;
   arr2 = grid;
   arr3 = grid;
    
    
    if((n-1)%4!=0)
    n=3;
    else
    n=5;
 
 for(int k=2;k<=n;k++)
 {
     
    
    if(k%2==0)
    {
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr[i][j]="O";
            }  
        }
            
     
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]!=arr2[i][j])
                {  
                    arr2[i][j]="O";
                }
                else
                arr2[i][j]=".";
                
            } 
        }
        
    }
     
    else 
    if(k%2!=0)
    {  
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<m;j++)
            { 

                if(arr3[i][j]=="O")
                {   
                    if(i!=r-1)
                    arr[i+1][j]=".";

                    if(i!=0)
                    arr[i-1][j]=".";

                    if(j!=0)
                    arr[i][j-1]=".";

                    if(j!=m-1)
                    arr[i][j+1]=".";

                    arr[i][j]=".";
                }
            }
           
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr3[i][j]=arr2[i][j];
            }  
        }
               
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<m;j++)
            {   if(arr3[i][j]==arr[i][j]&&arr[i][j]=="O")
                arr3[i][j]="O";
                else
                arr3[i][j]=".";
                
            }  
        }        
    }
}
        
     string s2d="";
        for(int i=0;i<r;i++)
        {  s2d = "";
            for(int j=0;j<m;j++)
            {   
             s2d+=arr[i][j];
            } 
            arr1.push_back(s2d);
            cout<<endl; 

        }     
 return arr1;    
}
