// Declaração da classe ReservationRequest

#ifndef RESERVATION_REQUEST_HPP
#define RESERVATION_REQUEST_HPP

#include <iostream>
#include <string>

struct Room { 
    int id;
    int capacity;
};

struct Day{
    int id;
    std::string name;
};
    
struct Alocation{ 
    int id;
    std::string course_name;
    std::string weekday;
    int start_hour;
    int end_hour;
    int student_count;
    int room_id;
};

class ReservationRequest {

private:
    std::string course_name;
    std::string weekday;
    int start_hour;
    int end_hour;
    int student_count;

public:

    //Construtor
    ReservationRequest(std::string course_name, std::string weekday, int start_hour, int end_hour, int student_count);
    //Destrutor
    ~ReservationRequest();

    int getStartHour();
    int getEndHour();
    std::string getCourseName();
    std::string getWeekday();
    int getStudentCount();
};

#endif