#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

/*
 * 1. Написать программу, которая сравнивает два введённых с клавиатуры числа.
 * Программа должна указать, какое число больше или,
 * если числа равны, вывести соответствующее сообщение.
 */
void ex1() {
    float num1;
    float num2;

    cout << "Enter number 1: ";
    cin >> num1;
    cout << "Enter number 2: ";
    cin >> num2;

    if (num1 > num2) {
        cout << "Value " << num1 << " higher than value " << num2;
    }
    else if (num1 < num2) {
        cout << "Value " << num1 << " lower than value " << num2;
    }
    else {
        cout << "Value " << num1 << " equals to value " << num2;
    }
}


/*
 * 2. Написать программу, которая проверяет является ли год високосным.
 */
void ex2() {
    int year;

    cout << "Enter year : ";
    cin >> year;

    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
    {
        cout << year << " is Leap Year";
    }
    else {
        cout << year << " is NOT a Leap Year";
    }
}


/*
 * 3. Написать программу решения квадратного уравнения.
 * Программа должна проверять правильность исходных данных и в случае,
 * если коэффициент при второй степени неизвестного равен нулю,
 * выводить соответствующее сообщение.
 */
void ex3() {
    float a, b, c;

    cout << "Enter a, b, c for : a*x^2 + b*x + c = 0 " << endl;
    cout << "a : ";
    cin >> a;
    cout << "b : ";
    cin >> b;
    cout << "c : ";
    cin >> c;

    if (a == 0)
    {
        cout << "a must not be zero." << endl;
        ex3();
        return;
    }

    float D = b*b - 4*a*c;
    if (D < 0) {
        cout << "The equation has no real roots.";
        ex3();
        return;
    }
    if (D == 0) {
        cout << "x1 = x2 = " << -b / (2 * a) << endl;
        return;
    }
    cout << "x1 = " << (-b + sqrt(D)) / (2 * a) << ", x2 = " << (-b - sqrt(D)) / (2 * a) << endl;
}


/*
 * 4. Проверить на чётность введённое с клавиатуры число
 */
void ex4() {
    int number;

    cout << "Enter number : ";
    cin >> number;

    if (number % 2 == 0)
    {
        cout << number << " is even number";
    }
    else {
        cout << number << " is NOT even number";
    }
}


/*
 * 5. Написать программу, которая выводит таблицу квадратов десяти первых положительных чисел.
 */
void ex5() {
    for(int i = 1;  i <= 10; i++) {
        cout << i << " : " << i*i << endl;
    }
}

/*
 * 6. Написать программу, которая определяет максимальное число
 * из введённой с клавиатуры последовательности положительных чисел.
 * (длина последовательности неограниченна)
 */
void ex6() {
    float current = 1;
    float max = 0;
    do {
        cout << "Enter number : ";
        cin >> current;

        if (max < current)
        {
            max = current;
        }

        cout << "Total max : " << max << endl;

    }
    while(current > 0);
}

/*
 * 7. Написать программу, которая выводит таблицу значений функции
 * y=-2 * x^2 - 5 * x - 8 в диапазоне от –4 до +4, с шагом 0,5
 */
void ex7() {
    cout << "y=-2 * x^2 - 5 * x - 8" << endl;

    float x = -4;
    while(x <= 4)
    {
        double y = -2 * x * x - 5 * x - 8;
        cout << "( "<< x << " , " << y <<" )" << endl;
        x += 0.5;
    }
}


void print(int matrix[5][5]) {
    int i, j;
    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
void rand(int matrix[5][5]) {
    int i, j, m;
    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j)
            matrix[i][j] = 30 + (rand() % 30);
    }
}
int max(int matrix[5][5]) {
    int i, j, m;
    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j)
            m = max(matrix[i][j], m);
    }

    return m;
}
int min(int matrix[5][5]) {
    int i, j, m;
    m = 100000000;
    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j)
            m = min(matrix[i][j], m);
    }

    return m;
}

/*
 * 8. Необходимо создать двумерный массив 5 х 5.
 * Далее написать функцию, которая заполнит его случайными числами от 30 до 60.
 * Создать еще две функции, которые находят максимальный и минимальный элементы этого двумерного массива.
 */
void ex8() {
    srand(time(0)); // to generate pseudo random numbers each time

    int matrix[5][5];

    rand(matrix);
    print(matrix);
    cout << "Min: " << min(matrix) << endl;
    cout << "Max: " << max(matrix) << endl;
}

struct student {
    string common_name;
    string group_number;
    int performance[5]{};
};

/*
 * 9. Создайте структуру с именем student, содержащую поля:
 *  - фамилия и инициалы,
 *  - номер группы,
 *  - успеваемость (массив из пяти элементов).
 *  Создать массив из десяти элементов такого типа,
 *  упорядочить записи по возрастанию среднего балла.
 *  Добавить возможность вывода фамилий и номеров групп студентов,
 *  имеющих оценки, равные только 4 или 5.
 */
void ex9() {
    student students[10];
    for(int i = 0; i < 10; i++)
    {
        students[i] = student { "Student " + std::to_string(i), "Group " + std::to_string(i)};
        for(int & j : students[i].performance)
        {
            if (i >= 8)
            {
                j = 5;
                continue;
            }
            j = 2 + (rand() % 3);
        }
    }

    for(auto & student : students)
    {
        int count = 0;
        for(int & j : student.performance)
        {
            if (j < 4) {
                break;
            }
            count++;
        }
        if (count == 5)
        {
            cout << student.common_name << " - " << student.group_number << endl;
        }
    }
}


struct train {
    string finish_town;
    int number;
    time_t time;
    char* get_time() {
        return ctime(&this->time);
    }
};

bool trains_sorter_by_number(train const& ltr, train const& rtr) {
    return ltr.number < rtr.number;
}

bool trains_sorter_by_town(train const& ltr, train const& rtr) {
    if (ltr.finish_town != rtr.finish_town) {
        return ltr.finish_town < rtr.finish_town;
    }
    return ltr.time < rtr.time;
}

/*
 * 10. Создайте структуру с именем train, содержащую поля:
 *  - название пункта назначения,
 *  - номер поезда,
 *  - время отправления.
 *  Ввести данные в массив из пяти элементов типа train, упорядочить элементы по номерам поездов.
 *  Добавить возможность вывода информации о поезде, номер которого введен пользователем.
 *  Добавить возможность сортировки массив по пункту назначения,
 *  причем поезда с одинаковыми пунктами назначения должны быть упорядочены по времени отправления.
 */
void ex10() {
    int number;
    cout << "Enter train number (1-5): ";
    cin >> number;
    if (number > 5 || number < 1) {
        ex10();
        return;
    }

    train trains[5];
    trains[0] = train { "Moscow", 3, time(0) };
    trains[1] = train { "Moscow", 1, time(0) - 1 };
    trains[2] = train { "New York", 5, time(0) - 2 };
    trains[3] = train { "New York", 4, time(0) - 3 };
    trains[4] = train { "Saratov", 2, time(0) - 4 };

    size_t len = sizeof(trains)/sizeof(trains[0]);
    sort(trains, trains+len, &trains_sorter_by_number);

    train tr = trains[number - 1];
    cout << tr.finish_town << " - " << tr.number << " - " << tr.get_time() << endl;
    cout << "======" << endl;

    sort(trains, trains+len, &trains_sorter_by_town);
    for (int i = 0; i < 5; ++i) {
        train c = trains[i];
        cout << c.finish_town << " - " << c.number << " - " << c.get_time() << endl;
    }
}

int main() {
    ex10();
    //ex9();
    //ex8();
    //ex7();
    //ex6();
    //ex5();
    //ex4();
    //ex3();
    //ex2();
    //ex1();
    return 0;
}
