#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>

int scaleRandInt(bool verbose = false) {
    // https://en.cppreference.com/w/cpp/numeric/random/rand
    std::srand(std::time(nullptr)); // use current time as seed for rand()
    int random_variable = std::rand();
    if (verbose) {
        std::cout << "Random variable on [0 " << RAND_MAX << "]: "
                  << random_variable << std::endl;
    }

    double scaledVar = float(random_variable) / RAND_MAX * 99;
    int scaledInt = std::round(scaledVar);
    if (verbose) {
        std::cout << "Scaled on interval [0 99]: " << scaledVar << std::endl;
        std::cout << "Rounded: " << scaledInt << std::endl;
    }
    return scaledInt;
}

//using std::endl;
int main() {
    int randInt = scaleRandInt(true);
    bool youHaveGuessedIt = false;
    int emergency_counter = 0;
    int guess;
    while (!youHaveGuessedIt) {
        std::cout << "Guess: ";
        std::cin >> guess;
        std::cout << std::endl;

        if (guess > randInt) {
            std::cout << "Too high!" << std::endl;
        }
        else if (guess < randInt) {
            std::cout << "Too low!" << std::endl;
        }
        else if (guess == randInt) {
            std::cout << "Just right!" << std::endl;
            youHaveGuessedIt = true;
        }
        emergency_counter += 1;
        if (emergency_counter > 100) {
            youHaveGuessedIt = true;
        }
    }

}
