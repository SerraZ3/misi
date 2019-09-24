#include "Thread.h"
#include "Misi.h"
//Utilizando a Classe Misi
//Recebe a quantidade de objetos que serão criados - <<constructor>>
Misi::Misi(int numObj = 10){
  //Atribui prioridade máxima a variavel
  priority_tot = numObj;
  //Cria dinamicamente a quantidade de processos
  thread_obj = new Thread[numObj];

  cont = 0;
}
//Adiciona processo ao vetor de objetos
void Misi::add(Thread thread){
  thread_obj[cont] = thread;
  cont++;
}
//Coloca processos em ordem crescente de prioridade
void Misi::set2runner(){
  Thread thread_aux;
  for(int i=0; i<priority_tot; i++){
    for(int j=0; j<priority_tot; j++){
      if(thread_obj[i].priority_nv < thread_obj[j].priority_nv){
        thread_aux = thread_obj[i];
        thread_obj[i] = thread_obj[j];
        thread_obj[j]= thread_aux;       
      }
    }   
  }
}
//Roda sistema de acordo com a prioridade
void Misi::runner(){
  //Controla o nivel de prioridade que está executando
  for(int i=0; i < priority_tot; i++){
    // Serial.print(i);
    // Serial.print(" - "); 
    // Serial.print(millis());
    // Serial.print("\n"); 
    thread_obj[i].run();
  }
}