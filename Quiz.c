#include <stdio.h>
#include <string.h>
#include <time.h>

#define QUESTIONS 5
#define TIME_LIMIT 15

struct Quiz {
    char question[100];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    char answer;
};

int main() {
    struct Quiz quiz[QUESTIONS] = {
        {"Which language is used for system programming?",
         "A. Python", "B. Java", "C. C", "D. HTML", 'C'},

        {"Who developed the C language?",
         "A. Dennis Ritchie", "B. James Gosling", "C. Bjarne Stroustrup", "D. Guido van Rossum", 'A'},

        {"Which symbol is used for comments in C?",
         "A. //", "B. ##", "C. <!-- -->", "D. **", 'A'},

        {"Which function is used to print output?",
         "A. scanf()", "B. printf()", "C. input()", "D. print()", 'B'},

        {"What is the extension of a C source file?",
         "A. .cpp", "B. .java", "C. .py", "D. .c", 'D'}
    };

    char playAgain;

    do {
        int score = 0;
        char userAnswer;
        time_t start, end;


        printf("       ====================================ONLINE QUIZ APPLICATION====================================\n");

        printf("You have %d seconds for each question.\n\n", TIME_LIMIT);

        for (int i = 0; i < QUESTIONS; i++) {

            printf("Question %d:\n", i + 1);
            printf("%s\n", quiz[i].question);
            printf("%s\n", quiz[i].optionA);
            printf("%s\n", quiz[i].optionB);
            printf("%s\n", quiz[i].optionC);
            printf("%s\n", quiz[i].optionD);

            time(&start);

            printf("Enter your answer (A/B/C/D): ");
            scanf(" %c", &userAnswer);

            time(&end);

            if (difftime(end, start) > TIME_LIMIT) {
                printf("Time's up! No marks awarded.\n\n");
                continue;
            }

            if (userAnswer >= 'a' && userAnswer <= 'z')
                userAnswer -= 32;

            if (userAnswer == quiz[i].answer) {
                printf("Correct!\n\n");
                score++;
            } else {
                printf("Wrong! Correct Answer: %c\n\n", quiz[i].answer);
            }
        }
        printf("         ==================================== QUIZ COMPLETED====================================\n");
   
        printf("Your Score: %d/%d\n", score, QUESTIONS);

        if (score == QUESTIONS)
            printf("Excellent!\n");
        else if (score >= 3)
            printf("Good Job!\n");
        else
            printf("Keep Practicing!\n");

        printf("\nDo you want to start the quiz again? (Y/N): ");
        scanf(" %c", &playAgain);

        if (playAgain == 'y')
            playAgain = 'Y';

        printf("\n");

    } while (playAgain == 'Y');

    printf("Thank you for playing!\n");

    return 0;
}