#include <iostream>
using namespace std;

template <class T>
class MyList {
private:
    T* arr;
    int maxsize;
    int currentsize;

public:
    MyList(int size = 10) {
        maxsize = size;
        currentsize = 0;
        arr = new T[maxsize];
    }

    MyList(const MyList<T>& other) {
        maxsize = other.maxsize;
        currentsize = other.currentsize;
        arr = new T[maxsize];
        for (int i = 0; i < currentsize; i++) {
            arr[i] = other.arr[i];
        }
    }

    ~MyList() {
        delete[] arr;
    }

    bool empty() {
        return currentsize == 0;
    }

    bool full() {
        return currentsize == maxsize;
    }

    int size() {
        return currentsize;
    }

    bool insertAt(int index, T value) {
        if (index < 0 || index > currentsize || currentsize == maxsize) {
            return false;
        }
        for (int i = currentsize; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        currentsize++;
        return true;
    }

    T last() {
        if (currentsize == 0) {
            return T();
        }
        return arr[currentsize - 1];
    }

    bool search(T value) {
        for (int i = 0; i < currentsize; i++) {
            if (arr[i] == value) {
                return true;
            }
        }
        return false;
    }

    void display() {
        if (currentsize == 0) {
            return;
        }
        for (int i = 0; i < currentsize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int choice;
    MyList<int> list;
    int value, index;

    do {
        cout << "\nMenu: \n";
        cout << "1. Add element at index\n";
        cout << "2. Check if list is empty\n";
        cout << "3. Check if list is full\n";
        cout << "4. Get size of list\n";
        cout << "5. Get last element\n";
        cout << "6. Search for an element\n";
        cout << "7. Display list\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter index and value to insert: ";
            cin >> index >> value;
            if (list.insertAt(index, value)) {
                cout << "Element inserted at index " << index << endl;
            }
            else {
                cout << "Insertion failed! Index out of bounds or list full." << endl;
            }
            break;

        case 2:
            if (list.empty()) {
                cout << "List is empty." << endl;
            }
            else {
                cout << "List is not empty." << endl;
            }
            break;

        case 3:
            if (list.full()) {
                cout << "List is full." << endl;
            }
            else {
                cout << "List is not full." << endl;
            }
            break;

        case 4:
            cout << "Current size of the list: " << list.size() << endl;
            break;

        case 5:
            cout << "Last element in the list: " << list.last() << endl;
            break;

        case 6:
            cout << "Enter value to search: ";
            cin >> value;
            if (list.search(value)) {
                cout << "Element found in the list." << endl;
            }
            else {
                cout << "Element not found." << endl;
            }
            break;

        case 7:
            cout << "Elements in the list: ";
            list.display();
            break;

        case 8:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice, please try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
