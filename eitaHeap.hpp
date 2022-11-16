#pragma once
#include "registro.hpp"

class eitaHeap
{
private:
  int capacidade;
int registros;
  Registro *cabeca;
public:
  eitaHeap();
  ~eitaHeap();

  void incluir(int numero, string mensagem);
  Registro* buscarPorNumero(int numero);
  int altura();
  int getTamanho();
int getRegistros();
  void print(Registro *cabeca, int espaco);	
  Registro* getCabeca();
Registro* filhoEsquerda(int pos);
void criarEsquerda(Registro* r, int posicao);
Registro* filhoDireita(int pos);
void criarDireita(Registro* r, int posicao);

  
};