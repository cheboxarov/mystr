#include <stdio.h>
#include <stdlib.h>

void my_memcpy(void *dst, const void *src, size_t size) {
    char *d = (char *)dst;
    const char *s = (const char *)src;
    for (size_t i = 0; i < size; i++) {
        d[i] = s[i];
    }
}

void *my_memcpy2(const void *src, size_t size) {
    void *dst = malloc(size);
    my_memcpy(dst, src, size);
    return dst;
}

void *my_memchr(const void *mem, size_t size, char value) {
    const char *m = (const char *)mem;
    for (size_t i = 0; i < size; i++) {
        if (m[i] == value) {
            return (void *)(m + i);
        }
    }
    return NULL;
}

void my_memset(const void *mem, size_t size, char value) {
    char *m = (char *)mem;
    for (size_t i = 0; i < size; i++) {
        m[i] = value;
    }
}

size_t my_strlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int my_strcmp(const char *str1, const char *str2) {
    size_t i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }
    if (str1[i] < str2[i]) {
        return -1;
    } else if (str1[i] > str2[i]) {
        return 1;
    } else {
        return 0;
    }
}

void my_strcpy(char *dst, const char *src) {
    size_t i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

char *my_strcpy2(const char *src) {
    size_t len = my_strlen(src);
    char *dst = malloc((len + 1) * sizeof(char));
    my_strcpy(dst, src);
    return dst;
}

void my_strcat(char *dst, const char *src) {
    size_t dst_len = my_strlen(dst);
    size_t i = 0;
    while (src[i] != '\0') {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';
}

char *my_strcat2(const char *src1, const char *src2) {
    size_t len1 = my_strlen(src1);
    size_t len2 = my_strlen(src2);
    char *dst = malloc((len1 + len2 + 1) * sizeof(char));
    my_strcpy(dst, src1);
    my_strcat(dst, src2);
    return dst;
}

int main() {
    char src[] = "Hello, world!";
    char dst[20];

    my_memcpy(dst, src, sizeof(src));
    printf("my_memcpy: %s\n", dst);

    char *copied = my_memcpy2(src, sizeof(src));
    printf("my_memcpy2: %s\n", copied);
    free(copied);

    char *found = my_memchr(src, sizeof(src), 'o');
    if (found != NULL) {
        printf("my_memchr: Found at index %ld\n", found - src);
    } else {
        printf("my_memchr: Not found\n");
    }

    char str[10] = "123456789";
    my_memset(str, sizeof(str), '0');
    printf("my_memset: %s\n", str);

    printf("my_strlen: %zu\n", my_strlen(src));

    char str1[] = "abc";
    char str2[] = "def";
    printf("my_strcmp: %d\n", my_strcmp(str1, str2));

    char buffer[20];
    my_strcpy(buffer, src);
    printf("my_strcpy: %s\n", buffer);

    char *copied_str = my_strcpy2(src);
    printf("my_strcpy2: %s\n", copied_str);
    free(copied_str);

    char str3[20] = "Hello, ";
    char str4[] = "world!";
    my_strcat(str3, str4);
    printf("my_strcat: %s\n", str3);

    char *concatenated = my_strcat2(str1, str2);
    printf("my_strcat2: %s\n", concatenated);
    free(concatenated);

    return 0;
}