// Implementação da classe ReservationSystem

#include "ReservationSystem.hpp"

ReservationSystem::ReservationSystem(int room_count, int* room_capacities) {
        this -> room_count = room_count;
}

ReservationSystem::~ReservationSystem(){
    
}

bool ReservationSystem::reserve(ReservationRequest request){
        int start_hour = request.getStartHour();
        int end_hour = request.getEndHour();
        int student_count = request.getStudentCount();
        std:: string  weekday = request.getWeekday();
        std:: string course_name  = request.getCourseName();
        
        


};