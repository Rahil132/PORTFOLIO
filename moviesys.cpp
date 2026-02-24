#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Base Class - Abstraction of a Media Item
class Media {
public:
    string title;
};

// Derived Class - Specialized for Cinema
class Movie : public Media {
public:
    string genre;
    string rating;    // e.g., PG-13, R
    double price;
    int availableSeats;

    // Constructor to initialize movie details
    Movie() {
        price = 12.50;      // Default ticket price
        availableSeats = 50; // Default theater capacity
    }
};

int main() {
    Movie cinema[100];
    int movieCount = 0;
    int choice;

    // --- PRE-LOADING MOVIES ---
    cinema[movieCount].title = "Inception"; cinema[movieCount].genre = "Sci-Fi"; cinema[movieCount].rating = "PG-13"; movieCount++;
    cinema[movieCount].title = "The Godfather"; cinema[movieCount].genre = "Crime"; cinema[movieCount].rating = "R"; movieCount++;
    cinema[movieCount].title = "Toy Story"; cinema[movieCount].genre = "Animation"; cinema[movieCount].rating = "G"; movieCount++;
    cinema[movieCount].title = "Interstellar"; cinema[movieCount].genre = "Sci-Fi"; cinema[movieCount].rating = "PG-13"; movieCount++;
    cinema[movieCount].title = "The Dark Knight"; cinema[movieCount].genre = "Action"; cinema[movieCount].rating = "PG-13"; movieCount++;

    while (true) {
        cout << "\n========================================================";
        cout << "\n                  CINE-RESERVE BOOKING SYSTEM";
        cout << "\n========================================================";
        cout << "\n1. Add Movie\n2. View Now Showing\n3. Book Tickets\n4. Search by Genre\n5. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (movieCount < 100) {
                cout << "Title: "; getline(cin, cinema[movieCount].title);
                cout << "Genre: "; getline(cin, cinema[movieCount].genre);
                cout << "Rating: "; getline(cin, cinema[movieCount].rating);
                cout << "Price: $"; cin >> cinema[movieCount].price;
                movieCount++;
                cout << "Movie added to the schedule!\n";
            }
        }
        else if (choice == 2) {
            cout << "\n" << left << setw(4) << "ID" << setw(20) << "MOVIE TITLE" << setw(12) << "GENRE" << setw(10) << "RATING" << "SEATS LEFT" << endl;
            cout << "---------------------------------------------------------------------" << endl;
            for (int i = 0; i < movieCount; i++) {
                cout << left << setw(4) << i + 1 << setw(20) << cinema[i].title << setw(12) << cinema[i].genre << setw(10) << cinema[i].rating << cinema[i].availableSeats << endl;
            }
        }
        else if (choice == 3) {
            int id, tickets;
            cout << "Enter Movie ID to book: "; cin >> id;
            if (id > 0 && id <= movieCount) {
                cout << "How many tickets? "; cin >> tickets;
                if(cinema[id-1].availableSeats >= tickets) {
                    cinema[id-1].availableSeats -= tickets;
                    double total = tickets * cinema[id-1].price;
                    cout << "Success! Total Cost: $" << fixed << setprecision(2) << total << endl;
                } else {
                    cout << "Not enough seats available!\n";
                }
            } else cout << "Invalid ID.\n";
        }
        else if (choice == 4) {
            string sGenre;
            cout << "Enter Genre: "; getline(cin, sGenre);
            bool found = false;
            for(int i=0; i<movieCount; i++) {
                if(cinema[i].genre == sGenre) {
                    cout << "- " << cinema[i].title << " (" << cinema[i].rating << ")\n";
                    found = true;
                }
            }
            if(!found) cout << "No movies found in that genre.\n";
        }
        else if (choice == 5) break;
    }
    return 0;
}
