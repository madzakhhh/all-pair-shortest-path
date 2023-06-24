#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;
void Ispisi(vector<vector<int>>& v){
for (int i =0;i<v.size();i++){
    for (int j=0;j<v[i].size();j++){
        if (v[i][j]==INT_MAX)
            cout<<"- ";
        else
            cout<<v[i][j]<< " ";
    }
    cout<<endl;
}}


void FloydWarshall(vector<vector<int>> &W){
    int n=W.size();
    vector<vector<int>> D(W);
    for (int k=0;k<n;k++){
        //vector<vector<int>>Dk(n,vector<int>(n));
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (D[i][k]!=INT_MAX && D[k][j]!=INT_MAX && D[i][j]>D[i][k]+D[k][j]){
                D[i][j]=D[i][k]+D[k][j];
                }
            }
        }
        Ispisi(D);cout<<endl;
    }
}
int main(){
//primjeri
vector<vector<int>> W{
{
   0,-3,INT_MAX,INT_MAX,-1,INT_MAX
},
{
    1,0,INT_MAX,2,0,INT_MAX
},
{
   INT_MAX,2,0,INT_MAX,INT_MAX,-8
},
{
   -4,INT_MAX,INT_MAX,0,-5,INT_MAX
}
,{
    INT_MAX,7,INT_MAX,INT_MAX,0,INT_MAX
},{
    INT_MAX,5,10,INT_MAX,INT_MAX,0}
};
vector<vector<int>>E{
    {
        0,INT_MAX,INT_MAX,INT_MAX
    },
    {
        INT_MAX,0,1,1
    },
    {
        INT_MAX,1,0,INT_MAX
    },{
        1,INT_MAX,1,0
    }
};

vector<vector<int>>WS{
    {
        0,1,INT_MAX,INT_MAX,INT_MAX
    },{
        INT_MAX,0,2,INT_MAX,INT_MAX
    },{
        INT_MAX,INT_MAX,0,3,INT_MAX
    },
    {
        INT_MAX,INT_MAX,INT_MAX,0,-3
    },{
        -4,INT_MAX,INT_MAX,INT_MAX,0}
};
FloydWarshall(WS);

}
