#include "header.h"

int my_strlen(const char *str)
{
int len = 0;

while (str && str[len] != '\0') {
    len++;
}
return len;

}

int my_strcmp(const char *s1, const char *s2)
{
int i = 0;

while (s1[i] && s2[i] && s1[i] == s2[i]) {
    i++;
}
return (unsigned char)s1[i] - (unsigned char)s2[i];

}

int my_atoi(const char *str)
{
int res = 0;
int i = 0;

while (str[i] >= '0' && str[i] <= '9') {
    res = res * 10 + (str[i] - '0');
    i++;
}
return res;

}