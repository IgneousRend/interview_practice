int Kadane(vector<int> &A, int n)
{
    signed int i,cMax=A[0],gMax=A[0];
    for(i=1; i<n; i++)
    {
        cMax = A[i] > (A[i]+cMax) ? A[i] : A[i]+cMax;
        gMax = cMax > gMax ? cMax : gMax;
    }
    return gMax;
}
