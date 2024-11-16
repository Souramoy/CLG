#include <stdio.h>
#include <string.h>

// Function to compute the Longest Prefix Suffix (LPS) array
void computeLPSArray(char *pattern, int m, int *lps) {
    int length = 0; // Length of the previous longest prefix suffix
    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Algorithm to find all occurrences of a pattern in a text
void KMPSearch(char *text, char *pattern) {
    int n = strlen(text);    // Length of the text
    int m = strlen(pattern); // Length of the pattern

    // Create the LPS array
    int lps[m];
    computeLPSArray(pattern, m, lps);

    int i = 0; // Index for text
    int j = 0; // Index for pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

// Main function to test the KMP algorithm
int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    printf("Occurrences of the pattern in the text:\n");
    KMPSearch(text, pattern);

    return 0;
}