int expect(int a, int b)
{
    if (!(a == b)) {
        printf("Failed\n");
        printf("  %d expected, but got %d\n", a, b);
        exit(1);
    }
}

int t1()
{
    int a[2][3];
    int *p = a;
    *p = 1;
    expect(1, *p);
}

int t2()
{
    int a[2][3];
    int *p = a + 1;
    *p = 1;
    int *q = a;
    *p = 32;
    expect(32, *(q + 3));
}

int t3()
{
    int a[4][5];
    int *p = a;
    *(*(a + 1) + 2) = 62;
    expect(62, *(p + 7));
}

int t4()
{
    int a[3] = {1, 2, 3};
    expect(1, a[0]);
    expect(2, a[1]);
    expect(3, a[2]);
}

int t5()
{
    int a[2][3];
    a[0][1] = 1;
    a[1][1] = 2;
    int *p = a;
    expect(1, p[1]);
    expect(2, p[4]);
}

int t6a(int e, int x[][3])
{
    expect(e, *(*(x + 1) + 1));
}

int t6()
{
    int a[2][3];
    int *p = a;
    *(p + 4) = 65;
    t6a(65, a);
}

int t7()
{
    int a[3 * 3];  // integer constant expression
    a[8] = 68;
    expect(68, a[8]);
}

int main()
{
    printf("Testing array ... ");

    t1();
    t2();
    t3();
    t4();
    t5();
    t6();
    t7();

    printf("OK\n");
    return 0;
}
