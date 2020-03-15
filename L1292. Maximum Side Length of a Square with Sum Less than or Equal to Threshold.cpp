#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> P(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                P[i][j]=P[i-1][j]+P[i][j-1]-P[i-1][j-1]+mat[i-1][j-1];
            }
        }
        int r=min(m,n),ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;++j)
                for(int c=ans+1;c<=r;++c){
                    if(i+c-1<=m && j+c-1<=n && getRect(P,i,j,i+c-1,j+c-1)<=threshold)
                        ++ans;
                    else break;
                }
        }
        return ans;

    }
    int getRect(const vector<vector<int>>& P,int x1,int y1,int x2,int y2){
        return P[x2][y2]-P[x1-1][y2]-P[x2][y1-1]+p[x1-1][y1-1];
    }
    
};