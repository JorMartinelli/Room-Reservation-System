// Declaração da classe ReservationSystem

#ifndef RESERVATION_SYSTEM_HPP
#define RESERVATION_SYSTEM_HPP

#include "ReservationRequest.hpp"
#include <iostream>
#include <string>

class ReservationSystem {

private:

    int room_count; // número de salas disponíveis
    int* room_capacities; // ponteiro para um array com a capacidade de alunos por sala
    Room* rooms; // ponteiro para array com todas as salas
    Day* days; // ponteiro para array com os dias da semana
    Alocation* alocations; // ponteiro para array das alocações de salas
    int alocation_count; // quantidade de salas alocadas (reservadas)
    // Room, Day e Alocation são Structs

public:

    ReservationSystem(int room_count, int* room_capacities); // Construtor
    ~ReservationSystem(); // Destrutor

    bool reserve(ReservationRequest request); // Função principal, realiza a reserva de uma sala
    bool cancel(std::string course_name); // função utilizada para cancelar uma reserva

    void printSchedule(); // função para mostrar a agenda de salas

};

#endif