#ifndef Thread_h
#define Thread_h

#include <Arduino.h>

class Thread{
  private:
    // Last time executed
    long int last_time;
    // Time interval
    long int time2run;
    // Pointer to the function will be call
    void (*onrun)();
      
  public:
    // var to priority
    int priority_nv;
    //1º tempo de execução
    //2º função a ser rodada de acordo com o tempo
    //3º Nivel de prioridade
    void set_value(long int _time, void (*callback)(void), int nivel_priority);

    void set_value(long int _time, void (*callback)(void));

    //Verifica se o intervalo de tempo passou
    bool canRun();

    //Roda a função principal
    void run();
};
#endif