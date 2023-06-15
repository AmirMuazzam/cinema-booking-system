#include<iostream>
#include"Header.h"

int main(){
    Cinema cinema;
    int choice;
    bool status;
    cout << "\t\t<<ShowTime: Streamlined Cinema Reservation System>>" <<endl;
    cout << "\n1: Register (New Customer)\n2: Login (Existing Customer / Manager)\nYour choice: "; cin>>choice;
    if (choice == 1)
    {
        cinema.registerCustomer();
    }
    else if (choice == 2)
    {
        cinema.displayMenu();
    }
    return 0;
}

