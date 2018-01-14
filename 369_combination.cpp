#include <iostream>
using namespace std;
long long array[105][105];

long long nCr(int N,int M)
{
    if(array[N][M]==0){
    if(M==0) return array[N][M]=1;
    if(N==M) return array[N][M]=1;
    if(M==1) return array[N][M]=N;
    return  array[N][M]=nCr(N-1,M-1)+nCr(N-1,M);
    }
    else return array[N][M];
}

int main()
{

    int N,M;
    while(cin>>N>>M &&N)
    {
        cout<<N<<" things taken "<<M<<" at a time is "<<nCr(N,M)<<" exactly."<<endl;
    }

    return 0;
}
