#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

double function1(double x);
double function2(double x);
double function3(double x);
void printTable(double (*function)(double), double start, double end, double step);
void WriteToFile(double (*function)(double), double x);
double calculate(double (*prtf)(double), double* x, int n);

int main()
{
    setlocale(LC_ALL, "RUS");
    int choice;
    int selectedFunction;
    double x, start, end, step;
    int n;
    do
    {
        printf("����\n");
        printf("1. ��������� ��������\n");
        printf("2. ������������\n");
        printf("3. ��������� ��������\n");
        printf("4. ������������� �������\n");
        printf("5. �����\n");
        printf("�������� �������� (1-4): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("�������� ������� (1, 2 ��� 3): ");
            scanf("%d", &selectedFunction);
            printf("������� �������� x: ");
            scanf("%lf", &x);
            switch (selectedFunction)
            {
            case 1:
                printf("�������� �������: %.6f\n", function1(x));
                break;
            case 2:
                printf("�������� �������: %.6f\n", function2(x));
                break;
            case 3:
                printf("�������� �������: %.6f\n", function3(x));
                break;
            default:
                printf("������������ ����� �������.\n");
            }
            break;
        case 2:
            printf("�������� ������� (1, 2 ��� 3): ");
            scanf("%d", &selectedFunction);
            printf("������� ��������� �������� x: ");
            scanf("%lf", &start);
            printf("������� �������� �������� x: ");
            scanf("%lf", &end);
            printf("������� ���: ");
            scanf("%lf", &step);
            switch (selectedFunction)
            {
            case 1:
                printTable(function1, start, end, step);
                break;
            case 2:
                printTable(function2, start, end, step);
                break;
            case 3:
                printTable(function3, start, end, step);
                break;
            default:
                printf("������������ ����� �������.\n");
            }
            break;
        case 3:
            printf("�������� ������� (1, 2 ��� 3): ");
            scanf("%d", &selectedFunction);
            printf("������� �������� x: ");
            scanf("%lf", &x);
            switch (selectedFunction)
            {
            case 1:
                WriteToFile(function1, x);
                break;
            case 2:
                WriteToFile(function2, x);
                break;
            case 3:
                WriteToFile(function3, x);
                break;
            default:
                printf("������������ ����� �������.\n");
            }
            break;
        case 4:
            printf("�������� ������� (1, 2 ��� 3): ");
            scanf("%d", &selectedFunction);
            printf("������� ���������� ��������� ������� x: ");
            scanf("%d", &n);
            double* array_x = (double*)malloc(n * sizeof(double));
            printf("������� �������� ������� x: ");
            for (int i = 0; i < n; ++i)
            {
                scanf("%lf", &array_x[i]);
            }
            switch (selectedFunction)
            {
            case 1:
                printf("������������ �������� �������: %.6f\n", calculate(function1, array_x, n));
                break;
            case 2:
                printf("������������ �������� �������: %.6f\n", calculate(function2, array_x, n));
                break;
            case 3:
                printf("������������ �������� �������: %.6f\n", calculate(function3, array_x, n));
                break;
            default:
                printf("������������ ����� �������.\n");
            }
            free(array_x);
            break;
        case 5:
            printf("��������� ���������");
            break;
        default:
            printf("������������ �����.\n");
        }
    } while (choice != 5);
}

double function1(double x)
{
    if (x > 0)
    {
        return log(fabs(sqrt(pow(x, 3))));
    }
    else
    {
        return 0;
    }
}

double function2(double x)
{
    if (x > 1)
    {
        return sqrt(tan(pow(x, 2) - 1));
    }
    else if (x >= 0 && x <= 1)
    {
        return -2 * x;
    }
    else if (x < 0)
    {
        return exp(cos(x));
    }
}

double function3(double x)
{
    return (x - 1) / (x + 1) + 1 / 3 * pow((x - 1) / (x + 1), 3) + 1 / 5 * pow((x - 1) / (x + 5), 5) + 1 / 7 * pow((x - 1) / (x + 1), 7);
}

void printTable(double (*function)(double), double start, double end, double step)
{
    printf("x\t|\ty(x)\n");
    printf("-----------------------\n");
    for (double x = start; x <= end; x += step)
    {
        printf("%.2f\t|\t%.6f\n", x, function(x));
    }
}

void WriteToFile(double (*function)(double), double x)
{
    FILE* file = fopen("func.txt", "a");
    if (file != NULL)
    {
        fprintf(file, "%.2f,%.6f\n", x, function(x));
        fclose(file);
        printf("�������� ������� ������� �������� � ���� %s.\n", file);
    }
    else
    {
        printf("������ ��� �������� ����� %s.\n", file);
    }
}

double calculate(double (*prtf)(double), double* x, int n)
{
    double max_value = prtf(x[0]); 
    printf("�������� ��� x[0]: %.6f\n", max_value); 
    for (int i = 1; i < n; ++i)
    {
        double current_value = prtf(x[i]);
        printf("�������� ��� x[%d]: %.6f\n", i, current_value); 
        if (current_value > max_value)
        {
            max_value = current_value; 
        }
    }
    return max_value;
}