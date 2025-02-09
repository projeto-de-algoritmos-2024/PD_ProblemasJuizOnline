/*A questão pede para encontrar o lucro máximo possível ao comprar e vender ações, dado 
um array de preços onde cada elemento representa o preço da ação em um determinado dia. 
O investidor pode realizar no máximo duas transações (comprar e vender duas vezes), mas 
nunca pode ter mais de uma ação ao mesmo tempo. Se não houver oportunidade de lucro, o 
retorno deve ser 0. O objetivo é desenvolver um algoritmo eficiente para encontrar esse 
lucro máximo, considerando que a lista de preços pode ter até 100.000 elementos.*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        //Retorna 0 se não há preços suficientes
        if (prices.empty()) return 0;

        //Menores precos de compra das transações
        int precoDeCompra1 = INT_MAX;
        int precoDeCompra2 = INT_MAX;

        //Lucros das transações
        int primeiroLucro = 0;
        int lucroMax = 0;

        //Percorre cada elemento do vetor prices e atribui o valor atual à variável salva
        for (int salva : prices) {
            //Atribuindo o menor preço para a primeira compra
            precoDeCompra1 = min(precoDeCompra1, salva);

            //Calculando o lucro da primeira venda
            primeiroLucro = max(primeiroLucro, salva-precoDeCompra1);
            
            //Atribuindo o menor preço para a segunda compra (levando em conta o lucro da primeira venda)
            precoDeCompra2 = min(precoDeCompra2, salva-primeiroLucro);

            //Calculando o lucro da segunda venda
            lucroMax = max(lucroMax, salva-precoDeCompra2);
        }
        
        return lucroMax; //Retorna o máximo lucro possível
    }
};