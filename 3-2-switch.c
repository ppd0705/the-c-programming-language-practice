#include <stdio.h>

#define MAX 10

void escape(char s[], char t[]);
void reverse_escape(char s[], char t[]);

int main()
{
    int i = 0;
    char c, s[MAX], t[MAX * 2];
    printf("Input string: ");
    while ((c = getchar()) != EOF && i < MAX -1)
        s[i++] = c;
    printf("s: %s\n", s);
    escape(s, t);
    printf("t: %s\n", t);
    reverse_escape(s, t);
    printf("s: %s\n", s);

}

void escape(char s[], char t[]) {
    int i = 0;
    int k = 0;
    while (i < MAX && s[i] != '\0') {
        switch (s[i]) {
            case '\t':
                t[k++] = '\\';
                t[k++] = 't';
                break;
            case '\n':
                t[k++] = '\\';
                t[k++] = 'n';
                break;
            default:
                t[k++] = s[i];
                break;
        }
        i++;
    t[k]= '\\';
    t[k+1]= '0';
    }
}


void reverse_escape(char s[], char t[]) {
    int i = 0;
    int k = 0;
    while (t[i] != '\\' || t[i+1] != '0') {
        switch (t[i]) {
            case '\\':
                switch (t[i+1]) {
                    case 't':
                       s[k++] = '\t';
                       break;
                    case 'n':
                       s[k++] = '\n';
                       break;
                    default:
                       s[k++] = '\\';
                       s[k++] = t[i+1];
                       break;
                }
                i += 2;
                break;
            default:
                s[k++] = t[i++];
                break;
        }
    s[k]= '\0';
    }
}