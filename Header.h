//Header File

#ifndef HEADER_H
#define HEADER_H

using namespace std;

class Cinema {
private:
    string movie;
    string time;
    int seats[10][10];
    int row, col;
    bool IsLoggedIn();
    bool IsManager();
    void selectMovie();
    void selectTime();
    void displaySeats();
    void bookSeat();
    void cancelBooking();
    void updateSeats();
    void saveSeats();
    void printTicket(int a, int b);
public:
	void registerCustomer();
    void displayMenu();
};
#endif
