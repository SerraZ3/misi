# MISI - MIcro SIstema

Sistema desenvolvido por Henrique Serra e George Lucas

## Exemplo

```C++
#include <Misi.h>
//Funções
void fun_teste0(){
    // Seu código aqui
}
void fun_teste1(){
    // Seu código aqui
}

// Diz quantos processos deseja
Thread thread[2];

// Diz quantos processos o sistema irá lidar
Misi so(2);

void setup() {
  // Configuração das thread
  // 1º parametro(INT): A cada quanto tempo que irá rodar o processo
  // 2º parametro(VOID): A função que será chamada
  // 3º parametro(INT): A prioridade
  thread[0].set_value(1502,fun_teste0,2);
  thread[1].set_value(2003,fun_teste1,3);

  // Adiciona o thread ao sistema
  so.add(thread[0]);
  so.add(thread[1]);

  // Roda as configurações do sistema
  so.set2runner();

}

void loop() {
  // Roda o sistema
  so.runner();
}
```
