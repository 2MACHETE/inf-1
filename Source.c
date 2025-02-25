#include <stdio.h>
#include <locale.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

int skolko_znakov_posle(double num) {
    int count = 0;
    while (num != (int)num) {
        num *= 10;
        count++;
    }
    return count;
}

float okruglitel(double chislo, int znaki) {
    double factor = pow(10, znaki);
    double rounded = round(chislo * factor) / factor;
    return rounded;
}

int somnitelniycounter(float a) {
    int c = 0;
    while (a < 1) {
        a *= 10;
        c++;
    }
    return c;
}

int task1() {
    float a = 15.0 / 7;  // a ~ b, c ~ d
    float b = 2.14;
    float c = sqrt(10);
    float d = 3.16;
    float pogr1 = fabs(a - b);
    float pogr2 = fabs(c - d);
    float otnpogr1 = (pogr1 / a) * 100;
    float otnpogr2 = (pogr2 / c) * 100;
    printf("\t\tЗАДАНИЕ А\n");
    printf("Значения выражений с большим количеством десятичных знаков:\n");
    printf("1) 15/7 = %.2f\n", b);
    printf("2) sqrt(10) = %.2f\n", d);
    printf("Предельные абсолютные погрешности, округляя их с избытком:\n");
    printf("1) %f\n", fabs(a - b));
    printf("2) %f\n", fabs(c - d));
    printf("Предельные относительные погрешности составляют (в процентах):\n");
    printf("1) %f\n", otnpogr1);
    printf("2) %f\n", otnpogr2);
    if (otnpogr1 > otnpogr2) printf("Более точное выражение: sqrt(10) = 3.16\n\n");
    else printf("Более точное выражение : 15 / 7 = 2.14\n\n");
}

int task2() {
    float pogresh = 0.0013;
    float chislo = 4.5012;
    float okrug = okruglitel(chislo, somnitelniycounter(pogresh));
    printf("\t\tЗАДАНИЕ Б\n");
    printf("Число: %.4f\n", chislo);
    printf("Погрешность: %.4f\n", pogresh);
    printf("Сомнительный разряд: %.3f\n", pow(10, -somnitelniycounter(pogresh)));
    printf("Округленное число без сомнительных знаков: %.3f\n", okrug);
    printf("Абсолютная погрешность результата: %.4f\n\n", fabs(chislo - okrug));
}

int task3() {
    double chislo = 1.4229;
    int znaki = skolko_znakov_posle(chislo);
    float one_last_razryada = pow(10, -znaki);
    float abspogr = 0.5 * one_last_razryada;
    float otnospogr = abspogr / chislo * 100;
    printf("\t\tЗАДАНИЕ В\n");
    printf("Предельная абсолютная погрешность: %.5f\n", abspogr);
    printf("Предельная относительная погрешность (проценты): %f\n", otnospogr);
    return 0;
}

main() {
    setlocale(LC_ALL, "Russian");
    task1();
    task2();
    task3();
}
