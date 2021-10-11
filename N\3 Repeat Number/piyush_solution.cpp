int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    //https://www.youtube.com/watch?v=3lh0j3YRH50
    //for n/k repeat, there will be k-1 candidates (k>1)
    //below is moore's voting algo using 2 candidates
    int c1=0,c2=0, ele1=INT_MIN,ele2=INT_MIN;
    
    for(auto x: A)
    {
        if(x==ele1)
            c1++;
        else if(x==ele2)
            c2++;
        else if(c1==0)
        {
            c1=1;
            ele1=x;
        }
        else if(c2==0)
        {
            c2=1;
            ele2=x;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    
    c1=c2=0;
    for(auto x:A)
    {
        if(ele1==x) c1++;
        else if(ele2==x)  c2++;
    }
    
    int n=A.size();
    if(c1 > n/3) return ele1;
    if(c2 > n/3) return ele2;
    return -1;
}
