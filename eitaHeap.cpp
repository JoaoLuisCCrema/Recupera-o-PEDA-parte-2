#include "eitaHeap.hpp"
#include <cmath>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#define COUNT 10

using namespace std;

eitaHeap::eitaHeap() {
  this->cabeca = NULL;
  this->capacidade = 0;
  this->registros = 0;
}

eitaHeap::~eitaHeap() {
  this->cabeca = NULL;
    this->capacidade = 0;
  this->registros = 0;
}

void eitaHeap::incluir(int numero, string mensagem) {
  Registro *tmp = new Registro();
  Registro *aux = new Registro();
  aux->setNumero(numero);
  aux->setMensagem(mensagem);

  if (!this->cabeca) {
    this->cabeca = aux;
    aux->setProx(new Registro());
    aux->getProx()->setProx(new Registro());
    registros++;
    capacidade = pow(2, registros) + 1;
    return;
  } 
  else 
  {
    tmp = this->cabeca;
    int posicao = 1;

    if (!filhoEsquerda(posicao)) {
      criarEsquerda(aux, posicao);
      registros++;
      capacidade = pow(2, registros) + 1;
      return;
    }
    else
    {
      if (!filhoDireita(posicao)) {
        criarDireita(aux, posicao);
              registros++;
      capacidade = pow(2, registros) + 1;
        return;
      }
      else
      {
        if(filhoEsquerda(posicao)->getNumero() > numero)
        {
          tmp = filhoEsquerda(posicao);
          posicao = posicao * 2;
        }
        else
        {
          tmp = filhoDireita(posicao);
          posicao = (posicao * 2) + 1;
        }
      }
    } 
  }
}

Registro *eitaHeap::buscarPorNumero(int numero) {
  if (getTamanho() == 0)
    return NULL;

  int posicao = 1;

  Registro *tmp = new Registro();
  tmp = this->cabeca;

  if (tmp->getNumero() == numero)
    return tmp;

  while (filhoEsquerda(posicao) != NULL) {
    if (!filhoDireita(posicao)) {
      if (filhoEsquerda(posicao)->getNumero() == numero)
        return tmp;
      return NULL;
    } else {
      if (filhoEsquerda(posicao)->getNumero() <= numero) {
        tmp = filhoEsquerda(posicao);
        posicao = posicao * 2;
      } else {
        tmp = filhoDireita(posicao);
        posicao = (posicao * 2) + 1;
      }
    }
  }

  return NULL;
}

int eitaHeap::altura() { return ceil(log2(registros + 1)); }

int eitaHeap::getTamanho() { return this->capacidade; }
int eitaHeap::getRegistros() { return this->registros; }

Registro *eitaHeap::getCabeca() { return this->cabeca; }

Registro *eitaHeap::filhoEsquerda(int pos) {
  if (pos > getTamanho())
    return NULL;

  Registro *tmp = new Registro();
  tmp = this->cabeca;

  for (int i = 1; i <= getTamanho(); i++) {
    if (i == pos * 2)
      return tmp;
    tmp = tmp->getProx();
  }
}

void eitaHeap::criarEsquerda(Registro *novo, int posicao) {
  Registro *tmp = new Registro();
  tmp = this->cabeca;

  for (int i = 1; i <= getTamanho(); i++) {
    if (i == posicao * 2)
      tmp = novo;
    return;
    tmp = tmp->getProx();
  }
}

Registro *eitaHeap::filhoDireita(int pos) {
  if (pos > getTamanho())
    return NULL;

  Registro *tmp = new Registro();
  tmp = this->cabeca;

  for (int i = 1; i <= getTamanho(); i++) {
    if (i == (pos * 2) + 1)
      return tmp;
    tmp = tmp->getProx();
  }
}

void eitaHeap::criarDireita(Registro *novo, int posicao) {
  Registro *tmp = new Registro();
  tmp = this->cabeca;

  for (int i = 1; i <= getTamanho(); i++) {
    if (i == (posicao * 2) + 1)
      tmp = novo;
    return;
    tmp = tmp->getProx();
  }
}
