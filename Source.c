#include <stdio.h>
#include <locale.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

float okruglitel(double chislo, int znaki) {
    double factor = pow(10, znaki);
    double rounded = round(chislo * factor) / factor;
    return rounded;
}

int task1() {
float a = 15.0 / 7;  // a ~ b, c ~ d
float b = 2.14;
float c = sqrt(10);
float d = 3.16;
if (fabs(a - b) > fabs(c - d)) return 2;
else return 1;
}

int task2() {
    float pogresh = 0.0013;
    float chislo = 4.5012;
    float okrug = okruglitel(chislo, 2);
    printf("Округленное число: %f\n", okrug);
    printf("Абсолютная погрешность результата: %f\n\n", fabs(chislo - okrug));
}

int task3() {
float chislo = 1.4229; 
int znaki = 4; 
float one_last_razryada = pow(10, -znaki);
float abspogr = 0.5 * one_last_razryada;
float otnospogr = abspogr / chislo * 100;
printf("Предельная абсолютная погрешность: %f\n", abspogr);
printf("Предельная относительная погрешность (проценты) : % f\n", otnospogr);
return 0;
}

main() {
	setlocale(LC_ALL, "Russian");
	if (task1() == 2) printf("Второе равенство точнее\n\n");
	else printf("Первое равенство точнее\n\n");
    task2();
    task3();
}
