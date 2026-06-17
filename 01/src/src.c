#include <stdio.h>
#include <string.h>

static void banner(void)
{
    puts("====================================");
    puts("      IDA Beginner CrackMe v1");
    puts("====================================");
}

static int check_length(const char *input)
{
    return strlen(input) == 13;
}

static int check_prefix(const char *input)
{
    return input[0] == 'I' &&
           input[1] == 'D' &&
           input[2] == 'A' &&
           input[3] == '-';
}

static int check_middle(const char *input)
{
    int sum;

    sum = input[4] + input[5] + input[6];
    if (sum != 249) {
        return 0;
    }

    if (input[4] != 'N') {
        return 0;
    }

    if (input[5] != input[4] + 23) {
        return 0;
    }

    if (input[6] != 'F') {
        return 0;
    }

    return 1;
}

static int check_suffix(const char *input)
{
    char expected[7];

    expected[0] = 'L';
    expected[1] = 'O';
    expected[2] = 'V';
    expected[3] = 'E';
    expected[4] = '!';
    expected[5] = '\0';

    if (input[7] != '-') {
        return 0;
    }

    return strcmp(input + 8, expected) == 0;
}

static int check_password(const char *input)
{
    if (!check_length(input)) {
        return 0;
    }

    if (!check_prefix(input)) {
        return 0;
    }

    if (!check_middle(input)) {
        return 0;
    }

    if (!check_suffix(input)) {
        return 0;
    }

    return 1;
}

static void wait_before_exit(void)
{
    int ch;

    puts("");
    puts("Press Enter to exit...");

    do {
        ch = getchar();
    } while (ch != '\n' && ch != EOF);

    getchar();
}

int main(void)
{
    char input[64];

    banner();
    printf("Password: ");

    if (scanf("%63s", input) != 1) {
        puts("Input error.");
        wait_before_exit();
        return 1;
    }

    if (check_password(input)) {
        puts("Correct! Welcome to reverse engineering.");
    } else {
        puts("Wrong password. Try again.");
    }

    wait_before_exit();
    return 0;
}
