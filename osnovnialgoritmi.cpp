#include <iostream>
#include <vector>
using namespace std;
void Ispisi(const vector<vector<int>>&M){
    for(int i =0 ;i<M.size();i++){
            for(int j=0;j<M[0].size();j++){
              cout<<M[i][j]<< "  ";
            }
            cout<<endl;
}
}

vector<vector<int>> Extendshortestpath(const vector<vector<int>>&Lm1,const vector<vector<int>>&Lm2){
    int n=Lm1.size();
    vector<vector<int>>L(n,vector<int>(n,INT_MAX));

    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for (int k=0;k<n;k++){
           //   cout<<"Gledam u Matrici 1 : "<<Lm1[i][k]  <<endl<< "Gledam u Matrici 2 : "<<Lm2[k][j]<<endl;
              if (Lm1[i][k]!=INT_MAX && Lm2[k][j]!=INT_MAX){
                L[i][j]=min(L[i][j],Lm1[i][k]+Lm2[k][j]);
            }
            else {
                L[i][j]=min(L[i][j],INT_MAX);
            }

            }
        }
    }

    return L;
}



vector<vector<int>> fasterallpairsshortestpaths(const vector<vector<int>>&W){
    int n=W.size();
    vector<vector<int>> L(W);
    int m=1;
    while (m<n){
        m=2*m;
       // cout<< " m je " <<m<<endl;
        vector<vector<int>>L2(Extendshortestpath(L,L));
        L=L2;
    }
    Ispisi(L);
    return L;
}

vector<vector<int>> slow(vector<vector<int>>&W){
    int n=W.size();
    vector<vector<int>> L(W);

    for (int m=1;m<n;m++){
        vector<vector<int>>L2(Extendshortestpath(L,W));
        L=L2;cout<<endl;

    }
    Ispisi(L);
    return L;
}


int main(){
vector<vector<int>> vect
    {
        {
            0,3,8,INT_MAX,-4
        } ,
        {
            INT_MAX,0,INT_MAX,1,7
        }   ,
        {
           INT_MAX,4,0,INT_MAX,INT_MAX
        }   ,
        {
            2,INT_MAX,-5,0,INT_MAX
        },
        {
            INT_MAX,INT_MAX,INT_MAX,6,0
        }
    };
vector<vector<int>>u{
{
    0,INT_MAX,3,INT_MAX,INT_MAX
},
{   4,0,INT_MAX,1,2
},
{   3,8,0,2,6},
{
    INT_MAX,1,INT_MAX,0,4},
{
    INT_MAX,1,6,4,0
}
};
//rj
//0 6 3 5 8
//4 0 7 1 2
//3 3 0 2 5
//5 1 8 0 3
//5 1 6 2 0


vector<vector<int>>W{
{
    0,INT_MAX,3,INT_MAX,INT_MAX
},
{
    4,0,INT_MAX,1,2
},
{
    3,8,0,2,6
},
{
    INT_MAX,1,INT_MAX,0,4
},
{
    INT_MAX,1,6,4,0
}};
auto k=fasterallpairsshortestpaths(W);
auto s= slow(W);


}
