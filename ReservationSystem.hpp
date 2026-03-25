// Declaração da classe ReservationSystem

#ifndef RESERVATION_SYSTEM_HPP
#define RESERVATION_SYSTEM_HPP

#include "ReservationRequest.hpp"
#include <iostream>
#include <string>

class ReservationSystem {

private:

    int room_count;
    int* room_capacities;

public:

    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();

    bool reserve(ReservationRequest request);
    bool cancel(std::string course_name);

    void printSchedule();

};

#endif