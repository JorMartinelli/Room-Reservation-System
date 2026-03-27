// Implementação da classe ReservationSystem

#include "ReservationSystem.hpp"

std::string days_of_week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"}; // array com os dias da semana

ReservationSystem::ReservationSystem(int room_count, int* room_capacities) {
        this -> room_count = room_count;
        this -> rooms = new Room[room_count]; // alocando o array de salas dinamicamente
        for (int i = 0; i < room_count; i++) {
            rooms[i].id = i + 1; // designando is para cada sala e sua respectiva capacidade
            rooms[i].capacity = room_capacities[i];
        }
        int day_count = 5; 
        this -> days= new Day[day_count]; // criando a semana, com id para cada dia e nome
        for (int i = 0; i < day_count; i++) {
            days[i].id = i + 1;
            days[i].name = days_of_week[i];
        }

        this -> alocations = new Alocation[24*5*room_count]; // criação do array de alocação, para cada hora dos cinco dias da semana há o
        // número de salas que o usuários passou disponíveis para reserva 
        this -> alocation_count = 0; // número de alocações
}

ReservationSystem::~ReservationSystem(){ // tudo que é criado com new deve ser deletado
        delete[] rooms;
        delete[] days;
        delete[] alocations;
}

bool ReservationSystem::reserve(ReservationRequest request){ // função principal do nosso sistema
        // aqui coletamos todos os dados da reserva solicitada
        int start_hour = request.getStartHour();
        int end_hour = request.getEndHour();
        int student_count = request.getStudentCount();
        std:: string  weekday = request.getWeekday();
        std:: string course_name  = request.getCourseName();

        // percorremos cada sala
        for (int i = 0; i < room_count; i++) {
                if (rooms[i].capacity >= student_count) { // verificamos se a sala tem capacidade para o número de alunos
                        bool avaliable = true;
                        for (int j = 0; j < alocation_count; j++) { // percorremos as reservas já aprovadas
                                // verificamos se é a mesma sala e dia que queremos reservar
                                if (alocations[j].room_id == rooms[i].id && alocations[j].weekday == weekday) {
                                        // aqui precisamos verificar se o horário novo entra no meio de um velho,
                                        // se termina no meio de um velho, ou se está no meio de um horário inteiro.
                                        if ((start_hour >= alocations[j].start_hour && start_hour < alocations[j].end_hour) || 
                                            (end_hour > alocations[j].start_hour && end_hour <= alocations[j].end_hour) || 
                                            (start_hour <= alocations[j].start_hour && end_hour >= alocations[j].end_hour)) {
                                                avaliable = false;
                                                break;
                                        }
                                }
                        }
                        if (avaliable) { // realizamos a reserva (alocação)
                                alocations[alocation_count].id = alocation_count + 1;
                                alocations[alocation_count].course_name = course_name;
                                alocations[alocation_count].weekday = weekday;
                                alocations[alocation_count].start_hour = start_hour;
                                alocations[alocation_count].end_hour = end_hour;
                                alocations[alocation_count].student_count = student_count;
                                alocations[alocation_count].room_id = rooms[i].id;
                                alocation_count++;
                                return true;
                        }
                }
        }
        
        return false;
};

bool ReservationSystem::cancel(std::string course_name) {
        for (int i = 0; i < alocation_count; i ++ ) { // percorremos as reservas realizadas
                if (alocations[i].course_name == course_name){
                        for (int j = i; j < alocation_count -1; j++ ){ //selecionamos todas as reservas que estão à frente dessa
                                alocations[j] = alocations[j+1];  // e sobrescrevemos a cancelada.
                        }
                        alocation_count --;
                        return true;
                }
        }
    return false;
}


void ReservationSystem::printSchedule() {
    for (int i = 0; i < alocation_count; i++) { // percorrendo todas as reservas e printando as informações
        std::cout << "Course: " << alocations[i].course_name << ", Weekday: " << alocations[i].weekday << ", Time: " << alocations[i].start_hour << "-" << alocations[i].end_hour << ", Room: " << alocations[i].room_id << std::endl;
    }
}