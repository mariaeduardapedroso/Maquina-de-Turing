#include <stdio.h>
#define true 1
#define false 0

int main()
{
    int fita[8];
    int cabecote = 0;
    int estado = 0;
    int continua = true;
    int divisivel = false;
    int digitalRead;

    for (int i = 0; i < 8; i++)
    {
        printf("Digite o binario [%d]:", i);
        scanf("%d", &fita[i]);
    }
    printf(" Maquina Turing ");

    scanf("%d", &digitalRead);
    if (digitalRead == 1) // MAQUINA LIGADA
    {
        while (continua) // FITA NÃO ACABOU AINDA
        {
            printf(" EST: %d\n", estado);
            for (int i = 0; i < 8; i++)
            {
                printf("%d", fita[i]);
            }
            printf("\n");

            for (int i = 0; i < 8; i++)
            {
                if (i == cabecote)
                {
                    printf("|");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");

            switch (estado)
            {
            case 0:
                if (fita[cabecote] == 1)
                {
                    estado = 1;
                }
                if (cabecote >= 8)
                {
                    estado = 3;
                    continua = false;
                }
                break;
            case 1:
                if (fita[cabecote] == 1)
                {
                    estado = 0;
                }
                if (fita[cabecote] == 0)
                {
                    estado = 2;
                }
                if (cabecote >= 8)
                {
                    continua = false;
                }
                break;
            case 2:
                if (fita[cabecote] == 0)
                {
                    estado = 1;
                }
                if (cabecote >= 8)
                {
                    continua = false;
                }
                break;
            }
            cabecote += 1;

            if (estado == 3)
            {
                continua = false;
                divisivel = true;
            }
        } // FITA JA ACABOU

        for (int i = 0; i < 8; i++) // COLOCAR VALOR
        {
            printf("%d", fita[i]);
        }
        printf("\n");
        if (divisivel == true) // E DIVISIVEL
        {
            printf("DIVISIVEL");
        }
        else // NAO DIVISIVEL
        {
            printf("NAO DIVISIVEL");
        }
    }
    else // DESLIGADO
    {
        printf("DESLIGADO");
    }

    return 0;
}
