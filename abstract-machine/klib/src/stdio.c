#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

void reverse(char *out);
char *sprintint(char *out, int d);

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
    out[0] = '\0';
    va_list ap;
    char *s;
    int d;
    char buf[32];
    va_start(ap, fmt);

    int i = 0;
    int j = 0;
    while (fmt[i] != '\0') {
        if (fmt[i] != '%') {
            out[j] = fmt[i];
            out[j + 1] = '\0';
            j++;
            i++;
            continue;
        }
        switch (fmt[i + 1]) {
            case 'd':
                d = va_arg(ap, int);
                char *dd = sprintint(buf, d);
                strcat(out, dd);
                i += 2;
                j += strlen(dd);
                break;
            case 's':
                s = va_arg(ap, char *);
                strcat(out, s);
                j += (int) strlen(s);
                i += 2;
                break;
            default:
                return -1;
        }
    }
    out[j] = '\0';
    va_end(ap);
    return 0;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

char *sprintint(char *out, int d) {
    int i = 0;
    char c;
    if (d < 0) {
        out[0] = '-';
        d *= -1;
        i++;
    }
    while (d != 0) {
        c = '0' + (d % 10);
        out[i] = c;
        d /= 10;
        i++;
    }
    out[i] = '\0';
    if (out[0] == '-') {
        reverse(&out[1]);
    } else {
        reverse(out);
    }
    return out;
}

void reverse(char *s) {
    int n = strlen(s);
    int buf[32];
    for (int i = 0; i < n; ++i) {
        buf[31 - i] = (int) s[i];
    }
    for (int i = 0; i < n; ++i) {
        s[i] = buf[32 + i - n];
    }
}

#endif
