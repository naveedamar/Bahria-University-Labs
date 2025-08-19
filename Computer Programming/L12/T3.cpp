#include <iostream>
using namespace std;

void exchangeKeys(int* key1, int* key2) {
    int temp = *key1;
    *key1 = *key2;
    *key2 = temp;
}

int main() {
    int container1Key = 123;
    int container2Key = 456;

    cout << "Before key exchange:\n";
    cout << "Container 1 Key: " << container1Key << endl;
    cout << "Container 2 Key: " << container2Key << endl;

    exchangeKeys(&container1Key, &container2Key);

    cout << "\nKeys exchanged successfully.\n\n";

    cout << "After key exchange:\n";
    cout << "Container 1 Key: " << container1Key << endl;
    cout << "Container 2 Key: " << container2Key << endl;

    return 0;
}
