#include <bits/stdc++.h>
using namespace std;

/* mercado de ações -> mudança constante nos valores
 * acao[i] == preço da ação de índice i
 * arvore[i] == valor contido no nó i da árvore \
 * assim, arvore[i] == índice da ação mais barata \
 * no intervalo representado pelo nó i
 * 
 * (no) == nó atual da recursão
 * nó atual == segmento [i, j]
 * (atualiza) o valor da ação de ind (pos) para (novo_valor) \
 * e (atualiza) a árvore de acordo com o necessário */

void atualiza( int no, int i, int j, int pos, int novo_valor ) {
    if ( i == j ) { // se pos i == pos j, nó mais baixo da árvore [i, i]

        // fazer alterações
        arvore[no] = i;
        acao[pos] = novo_valor
        return ;
    }

    int no_esq = 2 * no; // indice filho esquerdo
    int no_dir = 2 * no + 1; // indice filho direito

    int meio = (i + j) / 2; // indica o meio do intervalo [i, j]para a recursão

    // decidindo para qual nó descer
    if ( posicao <= meio ) atualiza(no_esq, i, meio, pos, novo_valor);
    else atualiza(no_dir, meio + 1, j, pos, novo_valor);

    // pegando melhor resultado entre os dois nós
    if ( acao[ arvore[no_esq] ] < acao[ arvore[no_dir] ] ) arvore[no] = arvore[no_esq];
    else arvore[no] = arvore[no_dir];
}


// (consulta) -> queremos saber o valor mínimo dentro do intervalo [A, B]
int consulta( int no, int i, int j, int A, int B ) {
    if ( A <= i and j <= B ) { // [i, j] está contido em [A, B]
        return arvore[no];
    }

    if ( i > B or A > j ) // [i, j] e [A, B] são disjuntos -> conjunto inválido
        return -1;

    // chamar recursão nos dois filhos e retornar melhor resposta
    int no_esq = 2 * no;
    int no_dir = 2 * no + 1;
    int meio = (i + j) / 2;

    // resposta para cada filho
    int resp_esq = consulta(no_esq, i, meio, A, B);
    int resp_dir = consulta(no_dir, meio + 1, j, A, B);

    // retornando melhor resposta
    if ( resp_esq == -1 ) return resp_dir;
    if ( resp_dir == -1 ) return resp esq;

    if ( acao[resp_esq] < acao[resp_dir] ) return resp_esq;
    return resp_dir;
}

int main() {



    return 0;
}