#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

char* ChangeSim(char* cs)
{
    if (strlen(cs) < 1)
        return cs;
    char* tmp = new char[101];
    char* t = tmp;

    tmp[0] = '\0';
    int i = 0;

    while (cs[i] != 0)
    {
        if (cs[i] == '+' || cs[i] == '-' || cs[i] == '=')
        {
            strcat(t, "**");
            t += 2;
            i += 1;
        }
        else
        {
            *t++ = cs[i++];
            *t = '\0';
        }
    }
    *t++ = cs[i++];
    *t++ = cs[i++];
    *t = '\0';
    strcpy(cs, tmp);

    return tmp;
}

int CountSim(const char* cs, const char* s)
{
    int k = 0;
    for (int i = 0; s[i] != '\0'; i++)
        for (int j = 0; cs[j] != '\0'; j++)
            if (s[i] == cs[j])
                k++;
    return k;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    char cs[101];
    cout << "Ввести:" << endl;
    cin.getline(cs, 100);

    char s[] = "+-=";
    cout << "К-сть: " << CountSim(cs, s) << endl;

    char* dest = new char[75];

    dest = ChangeSim(cs);

    cout << "Вивести: " << cs << endl;
    return 0;
}