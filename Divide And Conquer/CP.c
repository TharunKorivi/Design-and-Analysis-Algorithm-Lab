#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

struct Point
{
    int x,y;
};

int compareX(const void* a, const void* b)
{
    struct Point* p1 = (struct Point*)a;
    struct Point* p2 = (struct Point*)b;
    return p1->x - p2->x;
}

int compareY(const void* a, const void* b)
{
    struct Point* p1 = (struct Point*)a;
    struct Point* p2 = (struct Point*)b;
    return p1->y - p2->y;
}

double bruteforce(struct Point p[], int start, int end)
{
    double min = INT_MAX;
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            double d = sqrt(pow(p[j].x - p[i].x, 2) + pow(p[j].y - p[i].y, 2));
            if (d < min)
            {
                min = d;
            }
        }
    }
    return min;
}

double cp(struct Point p[], int start, int end)
{
    if (end - start > 2)
    {
        int mid = (start + end) / 2;
        double ld = cp(p, start, mid);
        double rd = cp(p, mid + 1, end);
        double d = ld > rd ? rd : ld;
        struct Point strip[20];
        int k = 0;
        for (int i = start; i <= end; i++)
        {
            if (abs(p[i].x - p[mid].x) < d)
            {
                strip[k++] = p[i];
            }
        }
        qsort(strip, k, sizeof(struct Point), compareY);
        double smin = d;
        for (int i = 0; i < k - 1; i++)
        {
            for (int j = i + 1; j < k && abs(strip[i].y - strip[j].y) < smin; j++)
            {
                double d1 = sqrt(pow(strip[j].x - strip[i].x, 2) + pow(strip[j].y - strip[i].y, 2));
                if (d1 < smin)
                {
                    smin = d1;
                }
            }
        }
        return smin;
    }
    else
    {
        return bruteforce(p, start, end);
    }
}

int main()
{
    int n;
    printf("Enter number of points: ");
    scanf("%d", &n);
    struct Point p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter point %d coordinates: ", i + 1);
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    qsort(p, n, sizeof(struct Point), compareX);
    double min = cp(p, 0, n - 1);
    printf("Min distance: %lf\n", min);
    return 0;
}

