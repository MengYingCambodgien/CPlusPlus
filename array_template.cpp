#include <iostream>
#include <string>

using namespace std;

template<class T>
class ArrayList {
protected:
    int size;
    T *array;

public:
    // Constructor for empty array
    ArrayList() : size(0), array(nullptr) {}

    // Constructor with single initial element
    ArrayList(T a) {
        size = 1;
        array = new T[size];
        array[0] = a;
    }

    // Destructor to prevent memory leak
    ~ArrayList() {
        delete[] array;
    }

    // Add a single element
    void addElement(T a) {
        // Create a new array with space for 1 more element
        T *tmp = new T[size + 1];

        // Copy existing elements to tmp
        for (int i = 0; i < size; i++) {
            tmp[i] = array[i];
        }

        // Add the new element at the end
        tmp[size] = a;

        // Free old array memory
        delete[] array;

        // Point array to tmp and update size
        array = tmp;
        size++;
    }

    // Add multiple elements from an array
    void addElement(T a[], int n) {
        // Create new array to fit current elements + n new elements
        T *tmp = new T[size + n];

        // Copy existing elements
        for (int i = 0; i < size; i++) {
            tmp[i] = array[i];
        }

        // Append elements from input array
        for (int i = 0; i < n; i++) {
            tmp[size + i] = a[i];
        }

        // Free old memory and reassign
        delete[] array;
        array = tmp;
        size += n;
    }

    // Print array contents
    void print() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << "\t";
        }
        cout << endl;
    }
};

int main() {
    ArrayList<int> a;
    a.addElement(23);
    a.addElement(40);
    a.addElement(12);
    cout << "Integers after individual additions:" << endl;
    a.print();

    int ar[3] = {300, 100, 300};
    a.addElement(ar, 3);
    cout << "Integers after array addition:" << endl;
    a.print();

    cout << "\nStrings:" << endl;
    ArrayList<string> name;
    name.addElement("nara");
    name.addElement("thera");

    string st[2] = {"virak", "sophy"};
    name.addElement(st, 2);
    name.print();

    return 0;
}