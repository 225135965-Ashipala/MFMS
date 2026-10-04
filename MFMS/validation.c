#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validation.h"

/* Throw away whatever is left on the current input line. */
static void clearBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        /* discard character */
    }
}

/* Ask for a whole number between min and max. Repeats until valid. */
int getInt(const char *prompt, int min, int max)
{
    int value;
    int result;

    while (1)
    {
        printf("%s", prompt);
        result = scanf("%d", &value);   /* scanf returns 1 if a number was read */

        if (result == EOF)
            exit(1);                    /* input closed, stop the program */

        clearBuffer();

        if (result != 1)
            printf("Invalid input. Please enter a whole number.\n");
        else if (value < min || value > max)
            printf("Please enter a number between %d and %d.\n", min, max);
        else
            return value;
    }
}

/* Ask for a decimal number that is not negative. Repeats until valid. */
double getNonNegativeDouble(const char *prompt)
{
    double value;
    int result;

    while (1)
    {
        printf("%s", prompt);
        result = scanf("%lf", &value);

        if (result == EOF)
            exit(1);

        clearBuffer();

        if (result != 1)
            printf("Invalid input. Please enter a number.\n");
        else if (value < 0)
            printf("Value cannot be negative.\n");
        else
            return value;
    }
}

/* Ask for text that is not empty and fits in dest (size includes '\0'). */
void getString(const char *prompt, char *dest, int size)
{
    char buffer[MAX_TEXT];

    while (1)
    {
        printf("%s", prompt);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            exit(1);

        if (strchr(buffer, '\n') == NULL)   /* line was longer than buffer */
            clearBuffer();

        buffer[strcspn(buffer, "\n")] = '\0';   /* remove the newline */

        if (strlen(buffer) == 0)
            printf("This field cannot be empty.\n");
        else if ((int)strlen(buffer) >= size)
            printf("Too long. Maximum is %d characters.\n", size - 1);
        else
        {
            strcpy(dest, buffer);
            return;
        }
    }
}

/* Email must contain '@' (not first) followed later by a '.', and no spaces. */
int isValidEmail(const char *email)
{
    int i;
    int length = (int)strlen(email);
    int atPos = -1;
    int dotAfterAt = 0;

    for (i = 0; i < length; i++)
    {
        if (email[i] == ' ')
            return 0;
        if (email[i] == '@' && atPos == -1)
            atPos = i;
        else if (email[i] == '.' && atPos != -1 && i > atPos + 1 && i < length - 1)
            dotAfterAt = 1;
    }

    return (atPos > 0 && dotAfterAt);
}

/* Phone: 7 to 15 characters, digits only (a leading '+' is allowed). */
int isValidPhone(const char *phone)
{
    int i;
    int length = (int)strlen(phone);

    if (length < 7 || length > 15)
        return 0;

    for (i = 0; i < length; i++)
    {
        if (i == 0 && phone[i] == '+')
            continue;
        if (phone[i] < '0' || phone[i] > '9')
            return 0;
    }

    return 1;
}

void pauseScreen(void)
{
    printf("\nPress Enter to continue...");
    clearBuffer();
}
