#ifndef VALIDATION_H
#define VALIDATION_H

#define MAX_NAME  50
#define MAX_TEXT 100

/* Read an integer between min and max (re-prompts until valid). */
int    getInt(const char *prompt, int min, int max);

/* Read a decimal number >= 0 (re-prompts until valid). */
double getNonNegativeDouble(const char *prompt);

/* Read a non-empty string of at most size-1 characters. */
void   getString(const char *prompt, char *dest, int size);

/* Return 1 if valid, 0 if not. */
int    isValidEmail(const char *email);
int    isValidPhone(const char *phone);

/* Wait for Enter before returning to a menu. */
void   pauseScreen(void);

#endif
