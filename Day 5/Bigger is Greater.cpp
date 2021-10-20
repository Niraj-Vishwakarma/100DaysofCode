// HACKERRANK PROBLEM [  https://www.hackerrank.com/challenges/bigger-is-greater/problem  ]

/*
 * Complete the 'biggerIsGreater' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */
// method 1 ...direct function
string biggerIsGreater(string str) {
if(next_permutation(str.begin(), str.end()))
            return str;
        else
            return "no answer";
}


//method -2 ...Next permutation algorithm
string biggerIsGreater(string w) {
int i=w.length()-1;
while(i>=0)
{
    if(w[i-1]<w[i])
    {
        break;
    }
    i--;
}
if(i==0)
{
    return "no answer";
}
for(int j = w.length()-1; j>=i; j--)
{
    if(w[j]>w[i-1])
    {
        int temp;
        temp = w[i-1];
        w[i-1] = w[j];
        w[j] = temp;
        break;
    }
}
reverse(w.begin() + i, w.end());
return w;
}
