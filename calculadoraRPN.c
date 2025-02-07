// Felipe Torres Montoya
// SO
#include <stdio.h>
#include <math.h>

float pi = 3.141592;
float stack[8];

void printStack()
{
    int i;
    for (i = 0; i < 8; i++)
    {
        printf("%d. %f\n", 8 - i, stack[i]);
    }
}

void moveStackUp()
{
    int i;
    for (i = 1; i < 8; i++)
    {
        stack[i - 1] = stack[i];
    }
}

void moveStackDown()
{
    int i;
    for (i = 7; i > 0; i--)
    {
        stack[i] = stack[i - 1];
    }
    stack[0] = 0.0;
}

void printMenu()
{
    printf("Seleccione una opción:\n");
    printf("1. Agregar número  2. Elegir operación  3. Borrar último\n");
    printf("4. Limpiar todo  5. Salir\n");
}

void deleteAll()
{
    int i;
    for (i = 0; i < 8; i++)
    {
        stack[i] = 0.0;
    }
}

void deleteLast()
{
    stack[7] = 0.0;
    moveStackDown();
}

void operations(char n)
{
    double radianes;
    switch (n)
    {
    case '+':
        stack[6] += stack[7];
        moveStackDown();
        printf("\033[2J");
        break;
    case '-':
        stack[6] -= stack[7];
        moveStackDown();
        printf("\033[2J");
        break;
    case '*':
        stack[6] *= stack[7];
        moveStackDown();
        printf("\033[2J");
        break;
    case '/':
        if (stack[7] == 0)
        {
            printf("\033[2JMath Error\n\n");
        }
        else
        {
            stack[6] = stack[6] / stack[7];
            moveStackDown();
            printf("\033[2J");
        }
        break;
    case 'r':
        if (stack[7] >= 0)
        {
            stack[7] = sqrt(stack[7]);
            printf("\033[2J");
        }
        else
        {
            printf("\033[2JMath Error\n\n");
        }
        break;
    case 's':
        radianes = stack[7] * (pi / 180.0);
        stack[7] = sin(radianes);
        printf("\033[2J");
        break;
    case 'c':
        radianes = stack[7] * (pi / 180.0);
        stack[7] = cos(radianes);
        printf("\033[2J");
        break;
    case 't':
        radianes = stack[7] * (pi / 180.0);
        if (fabs(fmod(radianes, pi) - pi / 2) > 1e-10)
        {
            stack[7] = tan(radianes);
            printf("\033[2J");
        }
        else
        {
            printf("\033[2JMath Error\n\n");
        }
        break;
    case 'p':
        stack[6] = pow(stack[6], stack[7]);
        moveStackDown();
        printf("\033[2J");
        break;
    default:
        break;
    }
}

int main()
{
    int opt;
    float num;
    char caracter;

    do
    {
        printStack();
        printMenu();
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("\033[2J");
            printStack();
            printf("Ingrese el número: ");
            scanf("%f", &num);
            moveStackUp();
            stack[7] = num;
            printf("\033[2J");
            break;
        case 2:
            printf("\033[2J");
            printStack();
            printf("+, -, *, /, r(raíz cuadrada), s(seno), c(coseno), t(tangente), p(potencia)\n");
            scanf(" %c", &caracter);
            operations(caracter);
            break;
        case 3:
            printf("\033[2J");
            printStack();
            deleteLast();
            printf("\033[2J");
            break;
        case 4:
            printf("\033[2J");
            printStack();
            deleteAll();
            printf("\033[2J");
            break;
        case 5:
            printf("\033[2J¡Gracias por utilizar la calculadora!\n");
            break;
        default:
            printf("\033[2JOpción no válida\n\n");
            break;
        }

    } while (opt != 5);

    return 0;
}
