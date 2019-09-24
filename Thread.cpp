#include "Thread.h"
//Utilizando a Classe Thread
void Thread::set_value(long int _time, void (*callback)(void), int nivel_priority){
  time2run = _time;
  onrun = callback;
  priority_nv = nivel_priority;
}
//Verifica se pode rodar de acordo com o tempo
bool Thread::canRun(){
  return (millis() - last_time >= time2run) ?  true : false;
}
//Roda
void Thread::run(){
  if(canRun()){
    onrun();
    last_time = millis();
  }
}