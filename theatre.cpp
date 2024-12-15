#include <iostream>
#include <string>
using namespace std;
struct Seat {
    int seatNumber;
    bool isBooked;  
    Seat* next;
    Seat* prev;
};
class Theater {
private:
    Seat* rows[10];  
public:
    Theater() {
        for (int i = 0; i < 10; i++) {
            rows[i] = nullptr; 
        }
        initializeSeats();
    }
    void initializeSeats() {
        for (int i = 0; i < 10; i++) {
            Seat* head = nullptr;
            Seat* last = nullptr;
            for (int j = 1; j <= 7; j++) {
                Seat* newSeat = new Seat{j, false, nullptr, nullptr};  
                if (head == nullptr) {
                    head = newSeat;
                    last = newSeat;
                } else {
                    last->next = newSeat;
                    newSeat->prev = last;
                    last = newSeat;
                }
            }
            if (head) {
                head->prev = last;
                last->next = head;
            }
            rows[i] = head; 
        }
    }
    void displayAvailableSeats(int row) {
        if (row < 0 || row >= 10) {
            cout << "Invalid row number!" << endl;
            return;
        }
        Seat* current = rows[row];
        if (current == nullptr) {
            cout << "No seats available in this row." << endl;
            return;
        }
        cout << "Available seats in row " << row + 1 << ": ";
        for (int i = 0; i < 7; i++) {
            if (!current->isBooked) {
                cout << current->seatNumber << " ";
            }
            current = current->next;
        }
        cout << endl;
    }
    void bookSeat(int row, int seatNumber) {
        if (row < 0 || row >= 10) {
            cout << "Invalid row number!" << endl;
            return;
        }
        Seat* current = rows[row];
        if (current == nullptr) {
            cout << "No seats available in this row." << endl;
            return;
        }
        for (int i = 0; i < 7; i++) {
            if (current->seatNumber == seatNumber) {
                if (current->isBooked) {
                    cout << "Seat " << seatNumber << " is already booked!" << endl;
                } else {
                    current->isBooked = true;
                    cout << "Seat " << seatNumber << " has been successfully booked!" << endl;
                }
                return;
            }
            current = current->next;
        }
        cout << "Invalid seat number!" << endl;
    }
    void cancelBooking(int row, int seatNumber) {
        if (row < 0 || row >= 10) {
            cout << "Invalid row number!" << endl;
            return;
        }
        Seat* current = rows[row];
        if (current == nullptr) {
            cout << "No seats available in this row." << endl;
            return;
        }
        for (int i = 0; i < 7; i++) {
            if (current->seatNumber == seatNumber) {
                if (!current->isBooked) {
                    cout << "Seat " << seatNumber << " is not booked!" << endl;
                } else {
                    current->isBooked = false;
                    cout << "Booking for seat " << seatNumber << " has been cancelled!" << endl;
                }
                return;
            }
            current = current->next;
        }
        cout << "Invalid seat number!" << endl;
    }
    void displayAllAvailableSeats() {
        for (int i = 0; i < 10; i++) {
            displayAvailableSeats(i);
        }
    }
};
int main() {
    Theater theater;
    int choice, row, seat;
    do {
        cout << "\nCinemax Theater Ticket Booking System\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book a Seat\n";
        cout << "3. Cancel a Booking\n";
        cout << "4. Display All Available Seats\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter row number (1-10): ";
                cin >> row;
                theater.displayAvailableSeats(row - 1);  
                break;
            case 2:
                cout << "Enter row number (1-10): ";
                cin >> row;
                cout << "Enter seat number (1-7): ";
                cin >> seat;
                theater.bookSeat(row - 1, seat); 
                break;
            case 3:
                cout << "Enter row number (1-10): ";
                cin >> row;
                cout << "Enter seat number (1-7): ";
                cin >> seat;
                theater.cancelBooking(row - 1, seat);  
                break;
            case 4:
                theater.displayAllAvailableSeats();
                break;
            case 5:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}
