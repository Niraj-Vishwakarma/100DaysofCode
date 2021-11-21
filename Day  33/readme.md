Recursion ::

Two loops using  recursion - 

n=4

o o o o

o o o 

o o

o


void function( int r, int c )
{
    //base condition If row is 0
    if(r<0)
    {
        return ;
    } 
    if(r>c)
    {
      cout<<"o";
      function(r, c+1);
    }
    else {
              function (r-1, 0);
         }
    
}


-------

BUBBLE SORT

SELECTION SORT




