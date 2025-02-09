/*A questão pede que, dada uma string contendo apenas os caracteres '(' e ')', seja 
retornado o comprimento da maior substring de parênteses válidos. Uma substring é 
considerada válida quando os parênteses estão balanceados, ou seja, cada abertura de parêntese 
tem um fechamento correspondente e vice-versa. O objetivo é encontrar o tamanho da maior 
sequência de parênteses válidos em toda a string.*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        //Contadores para parênteses
        int countAbertos = 0;
        int countFechados = 0;

        //Variável para armazenar o tamanho máximo da substring válida
        int comprimentoMax = 0;

        //Percorrendo a string s da esquerda para a direita
        for (char caracter : s) {
            if (caracter == '(') countAbertos++; //Incrementa a contagem de parênteses abertos
            else countFechados++; //Incrementa a contagem de parênteses fechados

            if (countAbertos == countFechados) {
                comprimentoMax = max(comprimentoMax, 2*countFechados); //Atualiza o maior comprimento
            }               
            else if (countFechados > countAbertos) {
                countAbertos = countFechados = 0; //Reinicia os contadores se houver mais fechamentos que aberturas
            }  
        }

        //Reiniciando os contadores
        countAbertos = 0;
        countFechados = 0;

        //Percorrendo a string s da direita para a esquerda
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')') countFechados++; //Incrementa a contagem de parênteses fechados
            else countAbertos++; //Incrementa a contagem de parênteses abertos

            if (countAbertos == countFechados) {
                comprimentoMax = max(comprimentoMax, 2*countAbertos); //Atualiza o maior comprimento
            }                               
            else if (countAbertos > countFechados) {
                countAbertos = countFechados = 0; //Reinicia os contadores se houver mais aberturas que fechamentos
            }    
        }

        return comprimentoMax; //Retorna o maior comprimento válido encontrado
    }
};