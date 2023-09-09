#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

const int NUM_ROWS = 5;
const int SEATS_PER_ROW = 10;

// Represents a seat
struct Seat {
    int row;
    int seatNumber;
    bool isBooked;
};

// Represents a movie
struct Movie {
    string title;
    float price;
};

int main() {
    vector<vector<Seat>> seats(NUM_ROWS, vector<Seat>(SEATS_PER_ROW));

    // Initialize seats
    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < SEATS_PER_ROW; ++j) {
            seats[i][j] = {i + 1, j + 1, false};
        }
    }

    // Initialize movies
    map<int, Movie> movies;
    movies[1] = {"Movie A", 10.0};
    movies[2] = {"Movie B", 12.0};
    movies[3] = {"Movie C", 8.0};

    int selectedMovie;
    int selectedRow, selectedSeat;

    cout << "Welcome to the Movie Ticket Booking System!" << endl;

    // Display movie listings
    cout << "Movie Listings:" << endl;
    for (const auto& entry : movies) {
        cout << entry.first << ". " << entry.second.title << " - $" << fixed << setprecision(2) << entry.second.price << endl;
    }

    // Choose a movie
    cout << "Select a movie (enter the number): ";
    cin >> selectedMovie;

    // Check if the selected movie is valid
    if (movies.find(selectedMovie) == movies.end()) {
        cout << "Invalid movie selection." << endl;
        return 1;
    }

    cout << "Selected movie: " << movies[selectedMovie].title << endl;

    // Display seat availability
    cout << "Seat Availability:" << endl;
    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < SEATS_PER_ROW; ++j) {
            cout << (seats[i][j].isBooked ? "X" : "O") << " ";
        }
        cout << endl;
    }

    // Select a seat
    cout << "Select a seat (row and seat number, separated by a space): ";
    cin >> selectedRow >> selectedSeat;

    // Check if the selected seat is valid
    if (selectedRow < 1 || selectedRow > NUM_ROWS || selectedSeat < 1 || selectedSeat > SEATS_PER_ROW || seats[selectedRow - 1][selectedSeat - 1].isBooked) {
        cout << "Invalid seat selection." << endl;
        return 1;
    }

    // Book the selected seat
    seats[selectedRow - 1][selectedSeat - 1].isBooked = true;

    // Calculate total cost
    float totalCost = movies[selectedMovie].price;

    cout << "Booking successful!" << endl;
    cout << "Total cost: $" << fixed << setprecision(2) << totalCost << endl;

    return 0;
}
