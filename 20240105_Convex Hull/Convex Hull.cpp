#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int MAX = 100000;

// 2D ������ ���� ��Ÿ���� Point Ŭ����
class Graham_Scan
{
public:
    int x, y;
    int p, q;
    Graham_Scan() : Graham_Scan(0, 0, 1, 0) {}
    Graham_Scan(int x, int y) : Graham_Scan(x, y, 1, 0) {}
    Graham_Scan(int x1, int y1, int p1, int q1) : x(x1), y(y1), p(p1), q(q1) {}

    // ������ ���� ����(less than) ������ �����ε�
    bool operator <(const Graham_Scan& O)
    {
        if (1LL * q * O.p != 1LL * p * O.q) return 1LL * q * O.p < 1LL * p * O.q;
        if (y != O.y) return y < O.y;
        return x < O.x;
    }
};

// �� ���� CCW (�ݽð� ����) ũ�ν� ���δ�Ʈ�� ����ϴ� �Լ�
long long ccw(const Graham_Scan& A, const Graham_Scan& B, const Graham_Scan& C)
{
    return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (B.y - A.y) * (C.x - A.x);
}

int main()
{
    int N;
    printf("N: ");
    scanf_s("%d", &N);
    Graham_Scan* p = new Graham_Scan[MAX];

    // ������ �Է¹���
    for (int i = 0; i < N; i++)
    {
        int x, y;
        scanf_s("%d %d", &x, &y);
        p[i] = Graham_Scan(x, y);
    }

    // ������ y ��ǥ�� ����Ͽ� ������ ����
    sort(p + 1, p + N);

    // ���� ���� ���� �������� �� ������ ����ǥ ����
    for (int i = 1; i < N; i++)
    {
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }

    // �ٽ� ����ǥ�� ����Ͽ� ����
    sort(p + 1, p + N);

    stack<int> S;
    S.push(0);
    S.push(1);
    int next = 2;

    // Graham's Scan �˰����� ����Ͽ� ���� ���� ã��
    while (next < N)
    {
        while (S.size() >= 2)
        {
            int first, second;
            first = S.top();
            S.pop();
            second = S.top();
            if (ccw(p[second], p[first], p[next]) > 0)
            {
                S.push(first);
                break;
            }
        }
        S.push(next++);
    }

    // ���� ������ ũ�⸦ ���
    printf("%lld\n", S.size());

    delete[] p;

    return 0;
}