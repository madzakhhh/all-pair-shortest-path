#include <iostream>
#include <vector>

using namespace std;

void DFS( vector<vector<int>>&G,vector<vector<bool>>&C,int root,int susjed){

    for(int i=0;i<G.size();i++){
         if (!C[root][i] && G[susjed][i]!=INT_MAX ){ //ako nije posjecen put root->i i ako postoji grana iz susjeda do i.
           // cout<<"pozivam nad "<<root<<" I " <<i<<endl;
            C[root][i]=true;
            DFS(G,C,root,i);

        }
    }
}
void closure (vector<vector<int>>&G2){
    int n=G2.size();
    vector<vector<bool>> C(n, vector<bool>(n, false));
    for(int v=0;v<n;v++){
        C[v][v]=true;
        DFS(G2,C,v,v);
    }

    for (int u = 0; u < n; u++) {
        for(int j=0;j<n;j++)
            cout<<C[u][j];
                cout<<endl;
             }

}


int main(){

vector<vector<int>>G{
{
    0,INT_MAX,INT_MAX,INT_MAX
},
{
    INT_MAX,0,1,1
},
{
    INT_MAX,1,0,INT_MAX
},
{
    1,INT_MAX,1,0
}

};

vector<vector<int>>G2{
    {0,1,1,INT_MAX},
    {INT_MAX,0,1,INT_MAX},
    {1,INT_MAX,0,1},
    {INT_MAX,INT_MAX,INT_MAX,0}


};

vector<vector<int>>S{
{
    0, INT_MAX,INT_MAX,INT_MAX
},
{
    INT_MAX,0,1,1
},
{
    INT_MAX,1,0,INT_MAX
},
{
    1,INT_MAX,1,0
}};


closure(G);

}
