#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));  
    int number_to_guess = rand() % 100 + 1;   
    int user_guess;
    bool guessed = false;

    cout << " Challange : Can you guess the no. between 1-100, what it is?" << endl;

    while (!guessed) {
        cout << "Enter your guess: ";
        cin >> user_guess;

        if (user_guess < number_to_guess) {
            cout << "Too low! Try again." << endl;
        } else if (user_guess > number_to_guess) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number." << endl;
            guessed = true;
        }
    }

    return 0;
}
