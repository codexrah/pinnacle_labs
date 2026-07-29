#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    char choice;

    srand(time(0));

    do {
        printf("\n############################-NUMBER GUESSING GAME-############################\n");
        printf("Guess the number between 1 to 100\n");

        int randomnumber = (rand() % 100) + 1;
        int no_of_guesses = 0;
        int guessed_number;

        do {
            printf("\nGuess the number =");
            scanf("%d", &guessed_number);

            if (guessed_number > randomnumber) {
                printf("Lower number please!\n");
            }
            else if (guessed_number < randomnumber) {
                printf("Higher number please!\n");
            }
            else {
                printf("Congratulations!........:)\n");
            }

            no_of_guesses++;

        } while (guessed_number != randomnumber);

        printf("You guessed the number in %d guesses.\n", no_of_guesses);

        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &choice);   // Space before %c ignores the newline

    } while (choice == 'Y' || choice == 'y');

    printf("\nThanks for playing!\n");

    return 0;
}