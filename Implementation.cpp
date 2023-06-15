#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"Header.h"

bool Cinema::IsLoggedIn(){
    string username, password, un, pw;
    cout <<"Enter username: "; cin>>username;
    cout <<"Enter password: "; cin>>password;
    
    string fileName = username + ".txt";
    
    ifstream userFile(fileName.c_str());
    if(userFile.is_open()){
        getline(userFile, un);
        getline(userFile, pw);
        if (un==username && pw==password)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else{
        cout << "User not found!" << endl;
        return false;
    }
}
// manager un:admin pw:admin
bool Cinema::IsManager(){
    string username, password;
    
    cout <<"Enter username: "; cin>>username;
    cout <<"Enter password: "; cin>>password;

    if (username=="admin" && password=="admin")
    {
        return true;
    }
    else
    {
        return false;
    }
    cout << endl;
}

void Cinema::selectMovie(){
    int choice;
    
    cout<<"<Movie Selection>\n1. Movie 1: Forrest Gump\n2. Movie 2: The Dark Knight\n3. Movie 3: Inception\n4. Movie 4: Mechamato\nYour choice: "; cin>>choice;
    if (choice == 1)
    {
        movie = "Movie1";
        updateSeats();
    }
    else if (choice == 2)
    {
        movie = "Movie2";
        updateSeats();
    }
    else if (choice == 3)
    {
        movie = "Movie3";
        updateSeats();
    }
    else if (choice == 4)
    {
        movie = "Movie4";
        updateSeats();
    }
    else if (choice == 5)
    {
        movie = "Movie5";
        updateSeats();
    }
}

void Cinema::selectTime(){
    int choice;
    
    cout<<"<Time Selection>\n1. 9:00am\n2. 12:00pm\n3. 3:00pm\n4. 6:00pm\n5. 10:00pm\nYour choice: "; cin>>choice;
    if (choice == 1)
    {
        time = "9:00am";
    }
    else if (choice == 2)
    {
        time = "12:00pm";
    }
    else if (choice == 3)
    {
        time = "3:00pm";
	}
	else if (choice == 4)
    {
        time = "6:00pm";
	}
	else if (choice == 5)
    {
        time = "10:00pm";
	}
	updateSeats();
}

void Cinema::displaySeats(){
	cout << "    \t\t    1  2  3  4  5  6  7  8  9  10" << endl;
	for(int i = 0; i < 10; i++){
		cout << "\t\t" << setw(2) << i + 1 << " ";
		for(int j = 0; j < 10; j++){
			if(seats[i][j] == 0) 
				cout << "[ ]";
			else 
				cout << "[X]";
		}
	cout << endl;
	}
}

void Cinema::bookSeat(){
	int row, col;
	cout << "Enter row: "; cin >> row;
	cout << "Enter col: "; cin >> col;
	if(seats[row - 1][col - 1] == 0){
		seats[row - 1][col - 1] = 1;
		cout << "Booking successful!" << endl;
		cout << "Please pay at the counter to get your ticket." << endl;
		saveSeats();
		printTicket(row,col);
	}
	else{
		cout << "Seat already taken!. Please select another seat." << endl;
	}
	cout << endl;
}

void Cinema::cancelBooking(){
	int row, col;
	cout << "Enter row: "; cin >> row;
	cout << "Enter col: "; cin >> col;
	if(seats[row - 1][col - 1] == 1){
		seats[row - 1][col - 1] = 0;
		cout << "Booking cancelled!" << endl;
		saveSeats();
	}
	else{
		cout << "No booking found at this seat!" << endl;
	}
}

void Cinema::updateSeats(){
	string fileName = movie +"_" + time + ".txt";
	
	ifstream seatFile(fileName.c_str());
	if(seatFile.is_open()){
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				seatFile >> seats[i][j];
			}
		}
		seatFile.close();
	}
	else{
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				seats[i][j] = 0;
			}
		}
	}
}

void Cinema::saveSeats(){
	string fileName = movie + "_" + time + ".txt";
	
	ofstream seatFile(fileName.c_str());
	if(seatFile.is_open()){
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				seatFile << seats[i][j] << " ";
			}
			seatFile << endl;
		}
		seatFile.close();
	}
	else{
		cout << "Error saving seats data for " << movie << "at" << time << endl;
	}
}

void Cinema::printTicket(int a, int b) {
    cout << "Cinema Ticket" << endl;
    cout << "-----------------------------" << endl;
    cout << "Movie: " << movie << endl;
    cout << "Time: " << time << endl;
    cout << "Seat: " << a << "-" << b << endl;
    cout << "Booking Date: " << endl;  //supposedly there is current time but dev version does not support
    cout << "-----------------------------" << endl;
}

void Cinema::registerCustomer(){
	string username, password;
	
	cout << endl;
	cout <<"Select a username: "; cin >> username;
	cout <<"Select a password: "; cin >> password;
	
	string fileName = username + ".txt";
	
	ofstream userFile(fileName.c_str());
	if(userFile.is_open()){
		userFile << username << endl << password;
		userFile.close();
		cout << "Registration Successful" << endl;
	}
	else{
		cout << "Error registering user" << endl;
	}
	cout << endl;
}

void Cinema::displayMenu() {
    int choice;
    bool status;

	cout << endl;
    selectMovie();
    cout << endl;
    selectTime();
    cout << endl;
    cout << "1. Customer Login (Existing Customer)" << endl;
    cout << "2. Manager Login (Staff)" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;

    if (choice == 1) {
        status = IsLoggedIn();
        if(!status) {
            cout << "False Login!" << endl;
            system("PAUSE");
            return;
        }
        else {
            cout << "Successfully logged in!\nWELCOME DEAR CUSTOMER" << endl;
        }
    }
    else if (choice == 2) {
    	status = IsManager();
        if(!status) {
            cout << "False Login!" << endl;
            system("PAUSE");
            return;
        }
        else {
            cout << "Successfully logged in as Manager! \n" << endl;
        }
    }
    while (true) {
        cout << "\n\t\t\tShowtime : Cinema Booking System" << endl;
        cout << "\t\t---------------------------------------------------" << endl;
        cout << "\t\t| Option |            Description                 |" << endl;
        cout << "\t\t---------------------------------------------------" << endl;
        cout << "\t\t|    1   | Display available seats                |" << endl;
        cout << "\t\t---------------------------------------------------" << endl;
        cout << "\t\t|    2   | Book a seat                            |" << endl;
        cout << "\t\t---------------------------------------------------" << endl;
        cout << "\t\t|    3   | Change movie                           |" << endl;
        cout << "\t\t---------------------------------------------------" << endl;
        cout << "\t\t|    4   | Change time                            |" << endl;
        cout << "\t\t---------------------------------------------------" << endl;
        cout << "\t\t|    5   | Cancel a booking  (only manager)       |" << endl;
        cout << "\t\t---------------------------------------------------" << endl;
        cout << "\t\t|    6   | Exit                                   |" << endl;
        cout << "\t\t---------------------------------------------------" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        	case 1:
            	displaySeats();
            	break;
        	case 2:
            	bookSeat();
            	break;
        	case 3:
            	selectMovie();
            	break;
        	case 4:
            	selectTime();
            	break;
        	case 5:
            	if(status == IsManager()){
                	cancelBooking();
            	}
            	else{
                	cout << "Access Denied! Only Manager can cancel booking" << endl;
            	}
            	break;
        	case 6:
            	return;
        }
    }
}

