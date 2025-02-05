#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int recur(string &s,string &t,int i,int j,vector<vector<int>>&dp)
    {
        if(i==0 and j==0) //ambas strings vazias
            return 1;
        if(i==0)  //string s vazia, mas t nao vazia
            return 0;
        if(j==0)  //se t for vazia, tem uma unica possibilidade
            return 1;
        if(dp[i][j]!=-1)  //se ja tem resultado, pega o valor tabelado
            return dp[i][j];
        if(s[i-1]==t[j-1])
            return dp[i][j]=recur(s,t,i-1,j-1,dp)+recur(s,t,i-1,j,dp);
        return dp[i][j]=recur(s,t,i-1,j,dp); //caracteres diferentes, ignora s[i-1]
    }
    int numDistinct(string s, string t) {
        int i=s.size();
        int j=t.size();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));  //matriz pra guardar os ja calculados
        return recur(s,t,i,j,dp);  //funcao recursiva + memoização
    }
};