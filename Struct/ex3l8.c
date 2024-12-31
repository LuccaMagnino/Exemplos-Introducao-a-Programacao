#include <stdio.h>
#include <string.h>


struct Tradutor
{
    char pais[50];
    char saudacao[50];
};


char* busca(struct Tradutor traduzir[], int n, char *pais)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(traduzir[i].pais, pais) == 0)
        {
            return traduzir[i].saudacao;
        }
    }
    return "-- NOT FOUND --";
}

int main()
{

    struct Tradutor tra[] = 
    {
        {"brasil", "Feliz Natal!"},
        {"alemanha", "Frohliche Weihnachten!"},
        {"austria", "Frohe Weihnacht!"},
        {"coreia", "Chuk Sung Tan!"},
        {"espanha", "Feliz Navidad!"},
        {"grecia", "Kala Christougena!"},
        {"estados-unidos", "Merry Christmas!"},
        {"inglaterra", "Merry Christmas!"},
        {"australia", "Merry Christmas!"},
        {"portugal", "Feliz Natal!"},
        {"suecia", "God Jul!"},
        {"turquia", "Mutlu Noeller"},
        {"argentina", "Feliz Navidad!"},
        {"chile", "Feliz Navidad!"},
        {"mexico", "Feliz Navidad!"},
        {"antardida", "Merry Christmas!"},
        {"canada", "Merry Christmas!"},
        {"irlanda", "Nollaig Shona Dhuit!"},
        {"belgica", "Zalig Kerstfeest!"},
        {"italia", "Buon Natale!"},
        {"libia", "Buon Natale!"},
        {"siria", "Milad Mubarak!"},
        {"marrocos", "Milad Mubarak!"},
        {"japao", "Merii Kurisumasu!"}
    };

    int nt = sizeof(tra) / sizeof(tra[0]);

    char pais[50];

    while (scanf("%s", pais) != EOF)
    {

        char *saudacao = busca(tra, nt, pais);


        printf("%s\n", saudacao);
    }
    return 0;
}
