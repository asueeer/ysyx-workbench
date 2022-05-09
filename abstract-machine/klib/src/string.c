#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

#define MAX_LENGTH 512 * 1024 * 1024

int strncmp(const char *s1, const char *s2, size_t n);

size_t strlen(const char *s) {
    for (int i = 0; i < MAX_LENGTH; ++i) {
        if (s[i] == '\0') {
            return i;
        }
    }
    return -1;
}

char *strcpy(char *dst, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = src[i];
    return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
    for (int i = 0; i < n; ++i) {
        dst[i] = src[i];
    }
    return dst;
}

char *strcat(char *dst, const char *src) {
    char *ptr = dst;
    while (*ptr != '\0') {
        ptr++;
    }
    strcpy(ptr, src);
    return dst;
}

int strcmp(const char *s1, const char *s2) {
    return strncmp(s1, s2, MAX_LENGTH);
}

int strncmp(const char *s1, const char *s2, size_t n) {
    int i = 0;
    while (i < n) {
        if (s1[i] == '\0' || s2[i] == '\0') {
            if (s1[i] == s2[i]) {
                return 0;
            }
            return s1[i] > s2[i] ? 1: -1;
        }
        if (s1[i] == s2[i]) {
            i++;
            continue;
        }
        return s1[i] > s2[i] ? 1: -1;
    }
    return -1;
}

void *memset(void *s, int c, size_t n) {
    char *ptr = (char *) s;
    for (int i = 0; i < n; ++i) {
        *ptr = c;
        ptr++;
    }
    return s;
}

void *memmove(void *dst, const void *src, size_t n) {
    char *cdst = dst;
    const char *csrc = src;
    for (int i = 0; i < n; ++i) {
        *cdst = *csrc;
        cdst++;
        csrc++;
    }
    return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
    return memmove(out, in, n);
}

int memcmp(const void *s1, const void *s2, size_t n) {
    const char * p1 = s1;
    const char * p2 = s2;
    for (int i = 0; i < n; ++i) {
        if (p1[i] == p2[i]) {
            continue;
        }
        return p1[i] < p2[i];
    }
    return 0;
}

#endif
