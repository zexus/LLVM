//extern void myprint(const char *format,...) __attribute__((format(printf,1,2)));
extern void myprint(const char *format,...);
extern void myexit() __attribute__((noreturn));
//extern void myexit();
extern int square(int n) __attribute__((const));

struct S {
    short f[3];
}__attribute__((aligned(8)));
typedef int more_aligned_int __attribute__((aligned(8)));

void test1() {
    myprint("i=%d/n",6);
    myprint("i=%s/n",6);
    myprint("i=%s/n","abc");
    myprint("%s,%d,%d/n",1,2);
}

int test2( int  n ) {
    int i,total=0;
    if ( n > 0 ) {
        myexit();
    } else {
        for (i = 0; i < 100; i++ ) {
            total += square (5) + i;
        }
        return 0;
    }
}

//gcc -Wall -c attribute.c -o attribute
