#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s, ob, rq, cq;
    int moves=0;
    cin>>s>>ob>>rq>>cq;;
    int o[ob][2];
    for(int i=0; i<ob; i++)
    {
        for(int j=0; j<2; j++)
        {
            cin>>o[i][j];
        }
    }
    //horizontal
    int tempLH =0;
    int tempRH =s+1;
    for(int i=0; i<ob; i++)
    {
        if(cq == o[i][1])
        {
           if(o[i][0]<rq)
           {
               tempLH = max(tempLH, o[i][0]);
           }else {
               tempRH = min(tempRH, o[i][0]);
           }
        }
    }
    moves += rq - tempLH -1 ;
    moves += tempRH -rq -1 ;
     
    
    //vertical
    int tempUV =s+1;
    int tempDV =0;
    for(int i=0; i<ob; i++)
    {
        if(rq == o[i][0])
        {
           if(o[i][1]<cq)
           {
               tempDV = max(tempDV, o[i][1]);
           }else {
               tempUV = min(tempUV, o[i][1]);
           }
        }
    }
    moves += cq - tempDV -1 ;
    moves += tempUV -cq -1 ;
 
    
   // secondary diagonals
   
   int tempTR = min(s+1 -rq, s+1- cq);
   int tempBL = min(rq-0, cq-0) ;
   for(int i=0; i<ob; i++)
   {
       if(o[i][0]-rq == o[i][1]-cq )
       {
           if(o[i][0]>rq)
           {
              tempTR = min(tempTR, o[i][0]- rq);
           } else {
               tempBL = min(tempBL, rq- o[i][0]);
           }
       }
   }
  moves += tempTR -1 ;
  moves += tempBL -1 ;
  
  //Primary diagonal
  int tempLT = min(s+1 - cq, rq-0 );
  int tempBR = min(s+1 - rq, cq-0);
  for(int i=0; i<ob; i++)
  {
      if(o[i][0]-rq == -(o[i][1]-cq))
      {
          if( o[i][0]<rq)
          {
              tempLT = min (tempLT, rq-o[i][0]);
          }else {
            tempBR = min(tempBR, o[i][0]-rq);
          }
      }
  }
  moves += tempLT -1;
  moves += tempBR -1;
 
 cout<<moves;

   return 0;
}

