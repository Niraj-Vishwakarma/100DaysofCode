// HACKERRANK PROBLEM [   https://www.hackerrank.com/challenges/extra-long-factorials/problem  ]

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void extraLongFactorials(int n) {
vector<int> res(1,1);
int m = 2;
while(m<=n)
{
    vector<int>temp;
    int carry =0;
    for(int i=0; i<res.size(); i++)
    {
        int product = m*res[i] + carry;
        temp.push_back(product%10 );
        carry = product/10;       
    }
    while(carry)
    {
        temp.push_back(carry%10);
        carry /= 10;
    }
   res = temp;
   
   m++; 
}
for(int i=res.size()-1; i>=0; i--)
{
 cout<<res[i];   
}
cout<<"\n";
}
