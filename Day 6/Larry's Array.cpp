//hackerrank problem
https://www.hackerrank.com/challenges/larrys-array/problem

string larrysArray(vector<int> a) {
int inversion=0;
for(int i=0;i<a.size();i++)
{
    for(int j=i+1; j<a.size(); j++)
    {
        if(a[i]>a[j])
        inversion++;
    }
}

if(inversion%(2)==0)
return "YES";
else 
return "NO";
}
