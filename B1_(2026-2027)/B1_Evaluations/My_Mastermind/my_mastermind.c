#include "header.h"

int my_strlen(const char *str) {
    int len = 0;
    while (str && str[len] != '\0') {
        len++;
    }
    return len;
}

int my_strcmp(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i]) {
        i++;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}

int my_atoi(const char *str) {
    int res = 0;
    int i = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res;
}

int is_valid_code(const char *code) {
    if (!code || my_strlen(code) != CODE_SIZE) {
        return 0;
    }

    for (int i = 0; i < CODE_SIZE; i++) {
        if (code[i] < '0' || code[i] > '8') {
            return 0;
        }
        for (int j = i + 1; j < CODE_SIZE; j++) {
            if (code[i] == code[j]) {
                return 0;
            }
        }
    }
    return 1;
}

char *generate_random_code(void) {
    static char code[CODE_SIZE + 1];
    int count = 0;

    srand((unsigned int)time(NULL));
    while (count < CODE_SIZE) {
        char digit = '0' + (rand() % 9);
        int exists = 0;
        for (int i = 0; i < count; i++) {
            if (code[i] == digit) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            code[count++] = digit;
        }
    }
    code[CODE_SIZE] = '\0';
    return code;
}

void evaluate_guess(const char *secret, const char *guess, int *well_placed, int *misplaced) {
    *well_placed = 0;
    *misplaced = 0;
    int used_secret[CODE_SIZE] = {0};
    int used_guess[CODE_SIZE] = {0};

    for (int i = 0; i < CODE_SIZE; i++) {
        if (guess[i] == secret[i]) {
            (*well_placed)++;
            used_secret[i] = 1;
            used_guess[i] = 1;
        }
    }

    for (int i = 0; i < CODE_SIZE; i++) {
        if (used_guess[i]) {
            continue;
        }
        for (int j = 0; j < CODE_SIZE; j++) {
            if (!used_secret[j] && guess[i] == secret[j]) {
                (*misplaced)++;
                used_secret[j] = 1;
                break;
            }
        }
    }
}

static int read_guess(char *buffer) {
    int idx = 0;
    char ch;

    while (read(STDIN_FILENO, &ch, 1) > 0) {
        if (ch == '\n') {
            buffer[idx < CODE_SIZE ? idx : CODE_SIZE] = '\0';
            return 1;
        }
        if (idx < CODE_SIZE) {
            buffer[idx] = ch;
        }
        idx++;
    }

    if (idx > 0) {
        buffer[idx < CODE_SIZE ? idx : CODE_SIZE] = '\0';
        return 1;
    }
    return 0;
}

int main(int argc, char **argv) {
    char *secret_code = NULL;
    int max_attempts = DEFAULT_ATTEMPTS;

    for (int i = 1; i < argc; i++) {
        if (my_strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
            secret_code = argv[i + 1];
            i++;
        } else if (my_strcmp(argv[i], "-t") == 0 && i + 1 < argc) {
            max_attempts = my_atoi(argv[i + 1]);
            i++;
        }
    }

    if (!secret_code) {
        secret_code = generate_random_code();
    }

    printf("Will you find the secret code?\nPlease enter a valid guess\n");

    int attempt = 0;
    char guess[CODE_SIZE + 1];

    while (attempt < max_attempts) {
        printf("---\nRound %d\n", attempt);
        write(STDOUT_FILENO, ">", 1);

        if (!read_guess(guess)) {
            return 0;
        }

        if (!is_valid_code(guess)) {
            printf("Wrong input!\n");
            continue;
        }

        int well_placed = 0, misplaced = 0;
        evaluate_guess(secret_code, guess, &well_placed, &misplaced);

        if (well_placed == CODE_SIZE) {
            printf("Congratz! You did it!\n");
            return 0;
        }

        printf("Well placed pieces: %d\nMisplaced pieces: %d\n", well_placed, misplaced);
        attempt++;
    }

    return 0;
}