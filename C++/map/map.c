#include <map>
#include <string>
#include <iostream>

using namespace std;

int main() {
    map<int, string> mapStudent;
    map<int, string>::iterator itertor;
    pair<map<int, string>::iterator, bool> insResult;

    // Pair Type
    mapStudent.insert(pair<int, string>(1, "student_one"));
    mapStudent.insert(pair<int, string>(2, "student_two"));
    mapStudent.insert(pair<int, string>(3, "student_three"));

    // Value Type
    mapStudent.insert(map<int, string>::value_type(4, "student_four"));
    mapStudent.insert(map<int, string>::value_type(5, "student_five"));
    mapStudent.insert(map<int, string>::value_type(6, "student_six"));

    // Array Type
    mapStudent[7] = "student_seven";
    mapStudent[8] = "student_eight";
    mapStudent[9] = "student_nine";

    insResult = mapStudent.insert(pair<int, string>(1, "student_one"));
    if (insResult.second == true) {
        cout << "Insert Successfully" << endl;
    } else {
        cout << "Insert Failed" << endl;
        mapStudent[10] = "student_ten";
    }

    // Size
    int size = mapStudent.size();
    cout << "Size: " << size << endl;
    for (itertor = mapStudent.begin(); itertor != mapStudent.end(); itertor++) {
        cout << itertor->first << " " << itertor->second << endl;
    }

    // Find
    map<int, string>::iterator iterator = mapStudent.find(7);
    if (iterator != mapStudent.end()) {
        cout << iterator->first << " " << iterator->second << endl;
    }
}
