
#include <stdio.h>
#include <stdbool.h>

#define InitBalance 1000
#define Lang {{ "English", "\nWelcome to the FSO ATM\n", "\nIndicate operation to do:\n", " 1.Cash Income\n 2.Cash Withdrawal\n 3.Balance Enquiry\n" " 4.Account Activity\n 5.Change PIN\n 6.Exit\n\n", " Operation:", " Cash Income\n", "\n Enter the amount to deposit:", " Successful income\n", " Cash Withdrawal\n", "\n Enter the amount to withdraw:", " Operation does not allowed\n", "   Not enough cash\n", " Balance Enquiry\n", " This operation is not implemented", " EXIT\n", " ERROR: This opertaion does not applied\n", "\n\n Current Balance: %.2f Euros", "\n\n Thanks \n\n"}}
float Balance;

bool saldo();
int idioma();
bool seguridad();
bool movimientos();

int main()
{
    int operation;
    float income, withdraw;

    printf("\nWelcome to the FSO ATM\n");
    if (seguridad())
    {
        Balance = InitBalance;
        operation = 0;
        printf("\nIndicate operation to do:\n");
        printf(" 1.Cash Income\n 2.Cash Withdrawal\n 3.Balance Enquiry\n");
        printf(" 4.Account Activity\n 5.Change PIN\n 6.Exit\n\n");
        printf(" Operation:");
        scanf("%d", &operation);

        if (operation == 1)
        {
            printf(" Cash Income\n");
            printf("\n Enter the amount to deposit:");
            scanf("%f", &income);
            Balance = Balance + income;
            printf(" Successful income\n");
        }
        else if (operation == 2)
        {
            printf(" Cash Withdrawal\n");
            printf("\n Enter the amount to withdraw:");
            scanf("%f", &income);

            if (Balance > income)
            {
                Balance = Balance - income;
            }
            else
            {
                printf(" Operation does not allowed\n");
                printf("   Not enough cash\n");
            }
        }
        else if (operation == 3)
        {
            printf(" Balance Enquiry\n");
        }
        else if ((operation == 4) || (operation == 5))
        {
            printf(" This operation is not implemented");
        }
        else if (operation == 6)
        {
            printf(" EXIT\n");
        }
        else if (operation > 6)
        {
            printf(" ERROR: This opertaion does not applied\n");
        }

        bool consultar = saldo();

        if (consultar)
        {
            printf("\n\n Current Balance: %.2f Euros", Balance);
            printf("\n\n Thanks \n\n");
        }
    }
    else
    {
        printf("Codigo incorrecto");
    }
    return (0);
}

bool saldo()
{
    char consultar;
    printf("Consultar saldo (s/n): ");
    scanf("%s", &consultar);

    return strcmp(consultar, "s") == 0;
}

int idioma()
{
    printf("Eliga idioma");
    int lang;
    const char idiomas[2] = Lang;
    int i = 0;
    for (i = 0; i < sizeof(idiomas); i++)
    {
        printf("%d-%s\n", i, idiomas[i]);
    }
    scanf("%d", &lang);
    return lang;
}

bool seguridad ()
{
    int code;
    int securecode = 123;
    printf("Diga el código de seguridad");
    scanf("%d", &code);
    return code == securecode;
}