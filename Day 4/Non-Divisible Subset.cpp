// HACKERRANK PROBLEM [  https://www.hackerrank.com/challenges/non-divisible-subset/problem  ]

int nonDivisibleSubset(int k, vector<int> s) {
    int element =0;
    vector<int> rc (k, 0);
    for(int i : s)
    {
        rc[i%k]++;
    }
    element = rc[0]>0 ? 1 : 0;
    
    for(int i=1; i<=k/2; i++)
    {
        if( k-i != i)
        {
            element += max(rc[k-i], rc[i]);
        }else {
            element++;
        }
    }
    
  return element;  
}
