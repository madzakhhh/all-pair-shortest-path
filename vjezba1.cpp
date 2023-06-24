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
}}
return L;}


vector<vector<int>> MODslow(vector<vector<int>>&W){
int n=W.size();
vector<vector<int>> L(W);
int m=1;
bool prekid=false;
for (m;m<=n;m++){
    vector<vector<int>>L2(Extendshortestpath(L,W));
    L=L2;
    for (int i =0;i<n;i++){
        if (L[i][i]<0)
            {
                 prekid=true;
                 break;
            }
    }
    //Ispisi(L);cout<<endl;
    if (prekid) break;

}
cout<<" Ovaj graf ima negativan ciklus sa " <<m+1<< " cvorova";
return L;
}


int main(){
vector<vector<int>> graf {

   {
       0,INT_MAX,4,INT_MAX
   } ,
   {
       5,0,INT_MAX,3
   },{ INT_MAX,-15,0,INT_MAX
   },
   {
       INT_MAX,INT_MAX,2,0
   }
}
;

vector<vector<int>> f3 {

   {
       0,4,4,3,INT_MAX,INT_MAX,INT_MAX,INT_MAX
   } ,
   {
       INT_MAX,0,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX
   },
   {
       INT_MAX,INT_MAX,0,INT_MAX,4,-2,INT_MAX,INT_MAX
   },
   {
       3,INT_MAX,2,0,INT_MAX,INT_MAX,INT_MAX,INT_MAX
   },
   {
       INT_MAX,INT_MAX,INT_MAX,1,0,INT_MAX,-2,INT_MAX
   },
   {
       INT_MAX,3,INT_MAX,INT_MAX,-3,0,INT_MAX,INT_MAX
   },
   {
       INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,2,0,2
   },
   {
       INT_MAX,INT_MAX,INT_MAX,INT_MAX,-2,INT_MAX,INT_MAX,0
   }
}
;
Ispisi(f3);
auto s= MODslow(f3);



};

