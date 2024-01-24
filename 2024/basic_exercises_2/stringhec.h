#ifndef STRINGHEC_H
#define STRINGHEC_H

/**
 * @file stringhec.h
 * @brief This file contains functions for manipulating C-style strings.
 */

/**
 * @brief Prints each character of the given string.
 *
 * This function takes a null-terminated string as input and prints each character of the string on a new line.
 * The function assumes that the input string is not null.
 *
 * @param str The null-terminated string to be printed.
 */
void stampa(const char *str);

/**
 * @brief Calculates the length of a C-style string.
 *
 * This function takes a C-style string as input and returns the number of characters in the string, excluding the null terminator.
 *
 * @param str The C-style string to calculate the length of.
 * @return The length of the string.
 */
unsigned int lunghezza(const char *str);

/**
 * @brief Inverts the characters in a C-style string.
 *
 * This function takes a C-style string as input and reverses the order of its characters.
 * The input string is modified in-place.
 *
 * @param str The C-style string to be inverted.
 */
void inverti(char *str);

/**
 * @brief Clones a C-style string.
 * 
 * This function creates a new dynamically allocated copy of the input string.
 * The caller is responsible for freeing the memory allocated by this function.
 * 
 * @param str The input string to be cloned.
 * @return A pointer to the cloned string.
 */
char *clona(const char *str);

/**
 * @brief Concatenates two strings.
 * 
 * This function takes two strings as input and concatenates them together.
 * The resulting string is returned as a dynamically allocated character array.
 * 
 * @param s1 The first string.
 * @param s2 The second string.
 * @return A dynamically allocated character array containing the concatenated string.
 */
char *concatena(const char *s1, const char *s2);

/**
 * @brief Searches for the first occurrence of a substring within a string.
 * 
 * This function searches for the first occurrence of the substring specified by `st` within the string `s1`.
 * 
 * @param s1 The string to search within.
 * @param st The substring to search for.
 * @return A pointer to the first occurrence of the substring within the string, or nullptr if the substring is not found.
 */
const char *cerca(const char *s1, const char *st);

#endif