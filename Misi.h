#ifndef Misi_h
#define Misi_h

#include "Thread.h"
#include <Arduino.h>

class Misi{
  private: 
    int cont;
    //Valor total de objetos
    int priority_tot;
    //Cria objetos que irão receber processos e armazenar em vetor
    Thread *thread_obj;


  public:
    //Recebe a quantidade de objetos que serão criados
    Misi(int numObj);

    //Adiciona processo ao vetor de objetos
    void add(Thread thread);

    //Coloca processos em ordem crescente de prioridade
    void set2runner();

    //Roda sistema de acordo com a prioridade
    void runner();
};
#endif