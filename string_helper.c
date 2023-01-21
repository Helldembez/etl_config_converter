//
// Created by Helldembez on 19-10-2021.
//
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

static inline char *str_cpy(const char *from) {
    char *to = malloc(strlen(from) + 1);
    for (char *p = to; (*p = *from) != '\0'; ++p, ++from) { ;
    }

    return to;
}

static inline void toLower(char *p) {
    for (int i = 0; p[i]; i++) {
        p[i] = tolower(p[i]);
    }
}

static inline char *concat(int count, ...) {
    va_list ap;
    int i;

    // Find required length to store merged string
    int len = 1; // room for NULL
            va_start(ap, count);
    for (i = 0; i < count; i++)
        len += strlen(va_arg(ap, char*));
            va_end(ap);

    // Allocate memory to concat strings
    char *merged = calloc(sizeof(char), len);
    int null_pos = 0;

    // Actually concatenate strings
            va_start(ap, count);
    for (i = 0; i < count; i++) {
        char *s = va_arg(ap, char*);
        strcpy(merged + null_pos, s);
        null_pos += strlen(s);
    }
            va_end(ap);

    return merged;
}

static inline int contains_word(char *line, char *word) {
    char *str;
    if (word[strlen(word) - 1] == '*') {
        char *tmp = str_cpy(word);
        tmp[strlen(tmp) - 1] = '\0';
        return strstr(line, tmp) != NULL;
    } else {
        str = strstr(line, concat(2, " ", word));
    }
    if (str != NULL) {
        char c = str[strlen(word) + 1];
        return isspace(c);
    }
    return 0;
}

static inline int prefix(const char *pre, const char *str) {
    return strncmp(pre, str, strlen(pre)) == 0;
}

static inline char *replaceWord(const char *s, const char *oldW,
                                const char *newW) {
    if (newW == NULL) {
        return "";
    }
    char *result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);

    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], oldW) == &s[i]) {
            cnt++;

            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }

    // Making new string of enough length
    result = (char *) malloc(i + cnt * (newWlen - oldWlen) + 1);

    i = 0;
    while (*s) {
        // compare the substring with the result
        if (strstr(s, oldW) == s) {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        } else
            result[i++] = *s++;
    }

    result[i] = '\0';
    return result;
}

static inline char *substr_of(char *string, char *delimiter) {
    size_t tlen = strstr(string, delimiter) - string;
    char *substr = malloc(tlen + 1);
    if (!substr) {
        perror("malloc-token");
        exit(EXIT_FAILURE);
    }
    memcpy(substr, string, tlen);
    *(substr + tlen) = 0;

    return substr;
}

static inline char *trimwhitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char) *str)) str++;

    if (*str == 0)  // All spaces?
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char) *end)) end--;

    // Write new null terminator character
    end[1] = '\0';

    return str;
}

static inline int string_ends_with(const char *str, const char *suffix) {
    int str_len = strlen(str);
    int suffix_len = strlen(suffix);

    return (str_len >= suffix_len) && (0 == strcmp(str + (str_len - suffix_len), suffix));
}

static inline int str_cmp(const char *left, const char *right) {
    return !(left[0] == '*' || right[0] == '*') || strcmp(left, right);
}