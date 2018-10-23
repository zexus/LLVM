#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> INTVECTOR;

int main() {
    INTVECTOR vec1;
    INTVECTOR ver2(10, 6);
    INTVECTOR ver3(ver2.begin(), ver2.begin()+3);
    INTVECTOR::iterator i;

    cout << "vec1.begin()--vec1.end()" << endl;
    for (i=vec1.begin(); i!=vec1.end(); ++i) {
        cout << *i << endl;
    }
}
