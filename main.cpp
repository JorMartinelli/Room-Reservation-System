// Arquivo principal contendo testes para todas as funções implementadas

#include <iostream>
#include "ReservationSystem.cpp"
#include "ReservationRequest.cpp"

int main() {
    int room_count = 4;
    int room_capacities[] = {30, 50, 60, 90};
    ReservationSystem system(room_count, room_capacities);

    ReservationRequest request1("Math", "Monday", 9, 11, 60);
    ReservationRequest request2("Physics", "Monday", 10, 12, 40);
    ReservationRequest request3("Chemistry", "Tuesday", 14, 16, 60);
    ReservationRequest request4("Biology", "Wednesday", 8, 10, 20);
    ReservationRequest request5("Computer Science", "Thursday", 13, 15, 80);
    ReservationRequest request6("History", "Monday", 9, 11, 90); 
    ReservationRequest request7_fail("Art", "Friday", 10, 12, 100);
    ReservationRequest request8_fail("Music", "Monday", 9, 11, 70);

    std::cout << "Reserving rooms..." << std::endl;
    std::cout << "Request 1: " << (system.reserve(request1) ? "Success" : "Failed") << std::endl;
    std::cout << "Request 2: " << (system.reserve(request2) ? "Success" : "Failed") << std::endl;
    std::cout << "Request 3: " << (system.reserve(request3) ? "Success" : "Failed") << std::endl;
    std::cout << "Request 4: " << (system.reserve(request4) ? "Success" : "Failed") << std::endl;
    std::cout << "Request 5: " << (system.reserve(request5) ? "Success" : "Failed") << std::endl;
    std::cout << "Request 6: " << (system.reserve(request6) ? "Success" : "Failed") << std::endl;   
    std::cout << "Request 7: " << (system.reserve(request7_fail) ? "Success" : "Failed") << std::endl;
    std::cout << "Request 8: " << (system.reserve(request8_fail) ? "Success" : "Failed") << std::endl;
    std::cout << "\nCurrent Schedule:" << std::endl;
    
    system.printSchedule();

    std::cout << "\nCanceling Physics class..." << std::endl;
    system.cancel("Physics");

    std::cout << "\nUpdated Schedule:" << std::endl;
    system.printSchedule();

    return 0;
}