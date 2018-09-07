#include <string.h>
#include <iostream>

using namespace std;

template<class T> T min(T A, T B, T C) {
    T D;
    if((A<B)&&(A<C)) {
        D=A;
    } else if((B<A)&&(B<C)) {
        D=B;
    } else {
        D=C;
    }
    return D;
}

const char* min(const char* A, const char* B,const char* C) {
    const char* result;

    if(strcmp(A,B)<0 && strcmp(A,C)<0) {
        result = A;
    } else if(strcmp(B,A)<0 && strcmp(B,C)<0) {
        result=B;
    } else {
        result=C;
    }

    return result;
}

int main() {
    cout << min(9,12,15) << endl;
    cout << min("Anderson", "Washington", "DavidSmith") << endl;
    return 0;
}
