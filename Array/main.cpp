/*
Даны два массива: А[n] и B[m]. Необходимо создать третий массив, в котором нужно собрать:
1.  Элементы обоих массивов;
2.  Общие элементы двух массивов;
3.  Элементы массива A, которые не включаются в B;
4.  Элементы массива B, которые не включаются в A;
5.  Элементы массивов A и B, которые не являются общими для них (то есть объединение результатов двух предыдущих вариантов).
    
    Обязательно используйте синтаксис указателей для решения этой задачи.
*/

#include <iostream>

using::std::cout;
using::std::endl;

void showAr(int*, int);

int main()
{
    srand(time(0));
    const int n = 7, m = 7;
    int A[n], B[m];

    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 20;
        //cout << A[i] << endl;
    }

    for (int j = 0; j < m; j++)
    {
        B[j] = rand() % 20;
        //cout << B[j] << endl;
    }


    char tsk;
    do {
        cout << "\nenter the task: ";
        std::cin >> tsk;
        int C[n + m] = { 0 };
        int* pc = C;
        bool f;

        switch (tsk)
        {
        case'1':
            for (int i = 0; i < n + m; ++i) {

                if (i < n)
                    *(C + i) = *(A + i);
                else
                    *(C + i) = *(B - n + i);
            }
            showAr(C, n + m);
            break;

        case'2':
            for (int j = 0; j < m; j++)
            {
                for (int i = 0; i < n; i++)
                    if (*(B + j) == *(A + i)) {
                        *pc = *(B + j);
                        pc++;
                        break;
                    }
            }
            showAr(C, n + m);
            break;

        case '3':
            for (int i = 0; i < n; i++)
            {
                f = false;

                for (int j = 0; j < m; j++)
                    if (*(A + i) == *(B + j)) {
                        f = true;
                        break;
                    }

                if (!f) {
                    *pc = *(A + i);
                    pc++;
                }
            }
            showAr(C, n + m);
            break;

        case '4':
            for (int i = 0; i < m; i++)
            {
                f = false;

                for (int j = 0; j < m; j++)
                    if (*(B + i) == *(A + j)) {
                        f = true;
                        break;
                    }

                if (!f) {
                    *pc = *(B + i);
                    pc++;
                }
            }
            showAr(C, n + m);
            break;

        case '5':
            for (int i = 0; i < n; i++)
            {
                f = false;

                for (int j = 0; j < m; j++)
                    if (*(A + i) == *(B + j)) {
                        f = true;
                        break;
                    }

                if (!f) {
                    *pc = *(A + i);
                    pc++;
                }
            }

            for (int i = 0; i < m; i++)
            {
                f = false;

                for (int j = 0; j < m; j++)
                    if (*(B + i) == *(A + j)) {
                        f = true;
                        break;
                    }

                if (!f) {
                    *pc = *(B + i);
                    pc++;
                }
            }

            showAr(C, n + m);
            break;

        case '6':
            cout << "the program has exited with code 0\n\n";
            break;

        default:
            cout << "error 400  bad request\n";
        }
    } while (tsk != '6');

    return 0;
}

void showAr(int* a, int length) {
    for (; 0 < length; --length, a++)
        cout << *a << "  ";
}
