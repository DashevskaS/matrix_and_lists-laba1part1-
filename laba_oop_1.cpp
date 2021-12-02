#include <iostream>
#include <string>
#include "List.h"
#include "Matrix.h"
#include "Sparse.h"
using namespace std;
int main()
{
    List<sparse> S;
    List<matrix> M;


    int answer;
    int first, second, n, m;
    cout << "Using list-1, using matrix-2 \n";
    cin >> answer;
    switch (answer)
    {
    case 1:
        while (true) {
            cout << " 1. Push back matrix \n";
            cout << " 2. Show matrix \n";
            cout << " 3. Sum matrix \n";
            cout << " 4. Subtract matrix \n";
            cout << " 5. Multipy matrix \n";
            cout << " 6. Delete matrix \n";
            cout << " 7. Get element by id \n";
            cout << " 8. Find element by value \n";
            cout << " 9. Show all \n";
            cin >> answer;
            switch (answer)
            {
            case 1:
                S.push_back(s_create());
                break;
            case 2:
                cout << "Which matrix\n";
                cin >> answer;
                s_show(&S.s_get_link(answer));
                break;
            case 3:
                cout << "Which matrixs you want to summ? \n";
                cin >> first;
                cin >> second;
                S.push_back(s_sum(&S.s_get_link(first), &S.s_get_link(second)));
                s_show(&S.s_get_link(S.size() - 1));
                break;
            case 4:
                cout << "Which matrixs you want to sub? \n";
                cin >> first;
                cin >> second;
                S.push_back(s_sub(&S.s_get_link(first), &S.s_get_link(second)));
                s_show(&S.s_get_link(S.size() - 1));
                break;
            case 5:
                cout << "Which matrixs you want to mult? \n";
                cin >> first;
                cin >> second;
                S.push_back(s_mult(&S.s_get_link(first), &S.s_get_link(second)));
                s_show(&S.s_get_link(S.size() - 1));
                break;
            case 6:
                cout << "Which matrixs you want to del? \n";
                cin >> answer;
                S.del_el(answer);
                break;
            case 7:
                cout << "Which matrixs you want to get by id? \n";
                cin >> answer;
                s_show(&S.s_get_link(answer));
                cout << "Which line?\n";
                cin >> n;
                cout << "Which column?\n";
                cin >> m;
                cout << s_get(&S.s_get_link(answer), n, m);
                break;
            case 8:
                cout << "Which matrixs you want to get element from? \n";
                cin >> answer;
                s_show(&S.s_get_link(answer));
                cout << "Value?\n";
                cin >> n;
                s_find(&S.s_get_link(answer), n);
                break;
            case 9:
                for (int i = 0; i < S.size(); i++) {
                    s_show(&S.s_get_link(i));
                    cout << "\n";
                }
                break;
            }
        }
        break;
    case 2:
        while (true) {
            cout << " 1. Push back matrix \n";
            cout << " 2. Show matrix \n";
            cout << " 3. Sum matrix \n";
            cout << " 4. Subtract matrix \n";
            cout << " 5. Multipy matrix \n";
            cout << " 6. Delete matrix \n";
            cout << " 7. Get element by id \n";
            cout << " 8. Find element by value \n";
            cout << " 9. Show all \n";
            cin >> answer;
            switch (answer)
            {
            case 1:
                M.push_back(m_create());
                break;
            case 2:
                cout << "Which matrix\n";
                cin >> answer;
                m_show(&M.m_get_link(answer));
                break;
            case 3:
                cout << "Which matrixs you want to summ? \n";
                cin >> first;
                cin >> second;
                M.push_back(m_sum(&M.m_get_link(first), &M.m_get_link(second)));
                m_show(&M.m_get_link(M.size() - 1));
                break;
            case 4:
                cout << "Which matrixs you want to sub? \n";
                cin >> first;
                cin >> second;
                M.push_back(m_sub(&M.m_get_link(first), &M.m_get_link(second)));
                m_show(&M.m_get_link(M.size() - 1));
                break;
            case 5:
                cout << "Which matrixs you want to mult? \n";
                cin >> first;
                cin >> second;
                M.push_back(m_mult(&M.m_get_link(first), &M.m_get_link(second)));
                m_show(&M.m_get_link(M.size() - 1));
                break;
            case 6:
                cout << "Which matrixs you want to del? \n";
                cin >> answer;
                M.del_el(answer);
                break;
            case 7:
                cout << "Which matrixs you want to get by id? \n";
                cin >> answer;
                m_show(&M.m_get_link(answer));
                cout << "Which line?\n";
                cin >> n;
                cout << "Which column?\n";
                cin >> m;
                cout << m_get(&M.m_get_link(answer), n, m);
                break;
            case 8:
                cout << "Which matrixs you want to get element from? \n";
                cin >> answer;
                m_show(&M.m_get_link(answer));
                cout << "Value?\n";
                cin >> n;
                m_find(&M.m_get_link(answer), n);
                break;
            case 9:
                for (int i = 0; i < M.size(); i++) {
                    m_show(&M.m_get_link(i));
                    cout << "\n";
                }
                break;
            }

        }

    }
    return 0;
}