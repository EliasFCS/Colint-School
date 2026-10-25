#include "header.h"

int main(int argc, char **argv)
{
char *secret_code = NULL;
int max_attempts = DEFAULT_ATTEMPTS;
int attempt = 0;
int well_placed;
int misplaced;
int i = 1;
char guess[CODE_SIZE + 1];

while (i < argc) {
    if (my_strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
        secret_code = argv[i + 1];
        i += 2;
    } else if (my_strcmp(argv[i], "-t") == 0 && i + 1 < argc) {
        max_attempts = my_atoi(argv[i + 1]);
        i += 2;
    } else {
        i++;
    }
}

if (max_attempts <= 0) {
    return 1;
}

if (!secret_code) {
    secret_code = generate_random_code();
} else if (!is_valid_code(secret_code)) {
    return 1;
}

printf("Will you find the secret code?\n");
printf("Please enter a valid guess\n");

while (attempt < max_attempts) {
    printf("---\nRound %d\n", attempt);
    write(1, ">", 1);

    if (!read_guess(guess)) {
        return 0;
    }

    if (!is_valid_code(guess)) {
        printf("Wrong input!\n");
        continue;
    }

    evaluate_guess(secret_code, guess, &well_placed, &misplaced);

    if (well_placed == CODE_SIZE) {
        printf("Congratz! You did it!\n");
        return 0;
    }

    printf("Well placed pieces: %d\n", well_placed);
    printf("Misplaced pieces: %d\n", misplaced);
    attempt++;
}

return 0;

}