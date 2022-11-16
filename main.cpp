/*
Joao Luis Chiarelotto Crema

Esta Recuperação permite que a média dos trabalhos 1, 2, 3, 4, 5, 6, 7, 8 chegue a, no máximo
7,0.
Para obter estes pontos você precisará criar as estruturas de dados especificadas nos itens a e
b, sem esquecer que uma estrutura de dados é composta de uma representação em memória e, no
mínimo três funções (ou métodos) para a sua manipulação. Sendo assim, todas as estruturas de dados
terão, um método para inclusão, um método para exclusão e um método para busca.
a) Usando, C, C++, Python ou Java, crie uma estrutura de dados chamada minhaNovaFila que
deverá usar como representação em memória uma lista linkada. Para testar esta estrutura
você precisará criar uma fila com 100 registros compostos de uma string com até 100
caracteres e um valor numérico do conjunto dos números reais. Para gerar os strings e os
valores números você deverá usar um gerador de números randômicos baseado no
Mersenne Twister.
Durante a criação dos registros você deverá escolher, aleatóriamente dois destes registros
para testar a função de busca.
Uma vez que a lista tenha sido criada você deve contar o tempo necessário para tirar 20%
dos registros desta fila e o tempo necessário para encontrar a posição na fila onde estão
dois dos registros criados. Neste exercício, o tempo gasto em todas as operações com a
estrutura de dados deverá ser registrado.
A saída esperada será feita por meio de um arquivo onde teremos a fila original impressa
na horizontal com comprimento inferior a 5 registros por linha, seguida da fila depois da
exclusão de 20% dos seus registros, também na horizontal.
As últimas linhas do arquivo de saída serão reservadas para o registro dos tempos médios
utilizados para cada uma das operações da estrutura de dados (criação, inclusão, exclusão,
nova inclusão) como estes tempos serão muito pequenos será necessário tirar as médias
com, no mínimo, 50 repetições.
b) Usando, C, C++, Python ou Java, crie uma estrutura de dados chamada eitaHeap que deverá
usar como representação em memória uma lista linkada. Para testar esta estrutura você
precisará criar um heap (min heap) com 100 registros compostos de uma string com até 100
caracteres e um valor numérico do conjunto dos números reais. Para gerar os strings e os
valores números você deverá usar um gerador de números randômicos baseado no
Mersenne Twister.
Durante a criação dos registros você deverá escolher, aleatoriamente dez destes registros
para testar a função de busca.
Uma vez que a heap tenha sido criada você deve contar o tempo necessário para tirar 16%
dos registros deste heap, o tempo necessário para encontrar a posição na fila onde estão os
registros escolhidos para teste e o tempo necessário para inserir 45 registros novos neste
heap. Sem dúvida os testes para a localização dos dezregistrosselecionados para o resgistro
dos tempos de localização deverão ser feitos com o heap originalmente criado, antes da
exclusão de 16% ou da inclusão de novos registros.
Como a estrutura é muito pequena, todos os tempos deverão ser calculados na forma de
média o que implica na repetição dos processos de criação, inserção, remoção, busca e nova
inserção, no mínimo 50 vezes.
A saída esperada será feita por meio de um arquivo onde teremos o heap estruturado em
formato de árvore usando ASCII, seguido do heap com menos 16% dos registros, também
estruturado no formato de uma árvore usando ASCII, seguido do heap após a inclusão de
novos registros, seguido dos tempos médios de inclusão, exclusão, busca e nova inclusão
identificados cada um em sua própria linha.
*/

#include <iostream>
using namespace std;
#include "eitaHeap.hpp"
#include "mt19937.hpp"
#include "randomString.hpp"
#include <cstdlib>
#include <ctime>



int main()
{
  eitaHeap *heap = new eitaHeap();

  MT19937 mt(time(NULL));
  int numero;
  string mensagem;

  srand(time(0));

  int a0 = (rand() % 100);
  int a1 = (rand() % 100);
  int a2 = (rand() % 100);
  int a3 = (rand() % 100);
  int a4 = (rand() % 100);
  int a5 = (rand() % 100);
  int a6 = (rand() % 100);
  int a7 = (rand() % 100);
  int a8 = (rand() % 100);
  int a9 = (rand() % 100);

  Registro *r0 = new Registro();
  Registro *r1 = new Registro();
  Registro *r2 = new Registro();
  Registro *r3 = new Registro();
  Registro *r4 = new Registro();
  Registro *r5 = new Registro();
  Registro *r6 = new Registro();
  Registro *r7 = new Registro();
  Registro *r8 = new Registro();
  Registro *r9 = new Registro();

  /*
  cout << a0 << endl;
  cout << a1 << endl;
  cout << a2 << endl;
  cout << a3 << endl;
  cout << a4 << endl;
  cout << a5 << endl;
  cout << a6 << endl;
  cout << a7 << endl;
  cout << a8 << endl;
  cout << a9 << endl;
  */

  // Looping para gerar os registros
  for (int i = 0; i < 100; i++) {
    // mt.random utiliza o mt implementado por mim.
    numero = mt.random();

    // random_string é baseado no Mersenne Twister, porém,
    // utiliza o mt existente na linguagem c++
    mensagem = random_string(10);

    // Inclui o novo registro na fila
    heap->incluir(numero, mensagem);

    if(i == a1)
      r1 = heap->buscarPorNumero(numero);
    else if(i == a2)
      r2 = heap->buscarPorNumero(numero);
    else if(i == a3)
      r3 = heap->buscarPorNumero(numero);
    else if(i == a4)
      r4 = heap->buscarPorNumero(numero);
    else if(i == a5)
      r5 = heap->buscarPorNumero(numero);
    else if(i == a6)
      r6 = heap->buscarPorNumero(numero);
    else if(i == a7)
      r7 = heap->buscarPorNumero(numero);
    else if(i == a8)
      r8 = heap->buscarPorNumero(numero);
    else if(i == a9)
      r9 = heap->buscarPorNumero(numero);
    else if(i == a0)
      r0 = heap->buscarPorNumero(numero);
    
  }
  cout << heap->getTamanho() << endl;
  cout << heap->altura() << endl;
  cout << heap->getRegistros() << endl;

  
}