#include <time.h>
#include <stdio.h>

void test1()
{
    clock_t a;
    a = clock();
    printf("---%lld---\n", a);
    a = clock();
    printf("---%lld---\n", a);
    time_t b;
    b = time(&b);
    __int64 c;
    NULL;
    CLOCKS_PER_SEC;
    struct tm *t;
    t = localtime(&b);
    char *s, *ss;
    s = asctime(t);
    ss = ctime(&b);
    printf("---%s---\n", s);
    printf("---%s---\n", ss);
    printf("---%d---\n", b);
    for (int i = 0; i < 1000000000; i++)
    {
        int ll;
        ll = 1;
        ll = ll + ll;
    }
    a = clock();
    printf("---%d---\n", a);
}

clock_t ts, te;
size_t count;
char sss[1000000];
auto ADD = [](const auto &a, const auto &b)
{
    return a + b;
};
size_t add(const size_t &a, const size_t &b)
{
    return a + b;
}
void test2(size_t cnt)
{
    ts = clock();
    printf("===%lld===\n", ts);

    count = cnt;
    printf("+++%lld+++\n", count);
    for (size_t i = 0; i < count; i++)
    {
        // size_t temporary;//1.257260
        // int temporary;//1.284870,s/10e9op
        // char temporary; //1.288110,s/10e9op
    }

    te = clock();
    printf("===%lld===\n", te);

    printf("---%lf,s/10e9op---\n", ((te - ts) / (CLOCKS_PER_SEC * (double)count)) * 1000000000);
}
void test3(size_t cnt)
{
    ts = clock();
    printf("===%lld===\n", ts);

    count = cnt;
    printf("+++%lld+++\n", count);
    for (size_t i = 0; i < count; i++)
    {
        // ADD(12, 1456);//1.261270,s/10e9op
        // add(12, 1456); //1.254510,s/10e9op
    }

    te = clock();
    printf("===%lld===\n", te);

    printf("---%lf,s/10e9op---\n", ((te - ts) / (CLOCKS_PER_SEC * (double)count)) * 1000000000);
}
void test4(size_t cnt)
{
    FILE *fw;
    fw = fopen("20230704_test_for_timeh.out", "wb");
    ts = clock();
    printf("===%lld===\n", ts);

    count = cnt;
    printf("+++%lld+++\n", count);
    for (size_t i = 0; i < count; i++)
    {
        // ADD(12, 1456);//1.261270,s/10e9op
        // add(12, 1456); //1.254510,s/10e9op
        // fprintf(fw, "%c", 0x23);
        fwrite(sss, 1000000, 1, fw);
    }

    te = clock();
    printf("===%lld===\n", te);

    printf("---%lf,s/10e9op---\n", ((te - ts) / (CLOCKS_PER_SEC * (double)count)) * 1000000000);
    fclose(fw);
}
int main()
{
    for (size_t i = 10; i <= 100000000000; i *= 10)
    {
        test4(i);
    }
    return 0;
}
