# Room Reservation System

Sistema desenvolvido em C++ para gerenciar a alocação de disciplinas em salas de aula ao longo de uma semana. 

## Descrição do Projeto
O sistema avalia a solicitação feita pelo usuário aplicando os seguintes critérios de validação:
1. **Filtro de Capacidade:** Verifica se a sala comporta a quantidade de alunos matriculados.
2. **Filtro de Disponibilidade:** Checa se o intervalo de aula solicitado está livre.

Caso os critérios sejam atendidos, o sistema atribui automaticamente a primeira sala disponível. Caso contrário, a solicitação é negada. O sistema também permite o cancelamento de reservas e a exibição da agenda de aulas.

## Instruções de Compilação
O projeto foi dividido em múltiplos arquivos (`.hpp` e `.cpp`) para separar a declaração das classes de suas implementações. 

Para compilar o projeto inteiro, abra o terminal na pasta raiz do repositório e utilize o compilador GCC (`g++`) com o seguinte comando:

```bash
g++ main.cpp ReservationSystem.cpp ReservationRequest.cpp -o reservation_system