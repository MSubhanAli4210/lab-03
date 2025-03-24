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

    bool isPrime(T num) {
        if (num <= 1) return false;
        for (T i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    T sum_ofPrime() {
        T sum = 0;
        for (int i = 0; i < currentsize; i++) {
            if (isPrime(arr[i])) {
                sum += arr[i];
            }
        }
        return sum;
    }

    T secondMaxEven() {
        T max = -1, secondMax = -1;
        for (int i = 0; i < currentsize; i++) {
            if (arr[i] % 2 == 0) {
                if (arr[i] > max) {
                    secondMax = max;
                    max = arr[i];
                }
                else if (arr[i] > secondMax && arr[i] != max) {
                    secondMax = arr[i];
                }
            }
        }
        return secondMax;
    }

    T secondMinOdd() {
        T min = -1, secondMin = -1;
        bool foundMin = false, foundSecondMin = false;
        for (int i = 0; i < currentsize; i++) {
            if (arr[i] % 2 != 0) {
                if (!foundMin || arr[i] < min) {
                    secondMin = min;
                    min = arr[i];
                    foundMin = true;
                }
                else if (arr[i] < secondMin && arr[i] != min) {
                    secondMin = arr[i];
                    foundSecondMin = true;
                }
            }
        }
        return foundSecondMin ? secondMin : -1;
    }

    void printDuplicates() {
        for (int i = 0; i < currentsize; i++) {
            for (int j = i + 1; j < currentsize; j++) {
                if (arr[i] == arr[j]) {
                    cout << arr[i] << " ";
                    break;
                }
            }
        }
        cout << endl;
    }

    void rotateClockwise(int r) {
        r %= currentsize;
        if (r < 0) r += currentsize;

        T* tempArr = new T[currentsize];
        for (int i = 0; i < currentsize; i++) {
            tempArr[(i + r) % currentsize] = arr[i];
        }
        for (int i = 0; i < currentsize; i++) {
            arr[i] = tempArr[i];
        }
        delete[] tempArr;
    }

    void rotateAntiClockwise(int r) {
        r %= currentsize;
        if (r < 0) r += currentsize;

        T* tempArr = new T[currentsize];
        for (int i = 0; i < currentsize; i++) {
            tempArr[(i - r + currentsize) % currentsize] = arr[i];
        }
        for (int i = 0; i < currentsize; i++) {
            arr[i] = tempArr[i];
        }
        delete[] tempArr;
    }
};

int main() {
    int choice;
    MyList<int> list;
    int value, index, rotations;

    do {
        cout << "\nMenu: \n";
        cout << "1. Add element at index\n";
        cout << "2. Check if list is empty\n";
        cout << "3. Check if list is full\n";
        cout << "4. Get size of list\n";
        cout << "5. Get last element\n";
        cout << "6. Search for an element\n";
        cout << "7. Sum of prime numbers\n";
        cout << "8. Second maximum even number\n";
        cout << "9. Second minimum odd number\n";
        cout << "10. Print duplicates\n";
        cout << "11. Rotate list clockwise\n";
        cout << "12. Rotate list anti-clockwise\n";
        cout << "13. Display list\n";
        cout << "14. Exit\n";
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
            cout << "Sum of prime numbers in the list: " << list.sum_ofPrime() << endl;
            break;

        case 8:
            cout << "Second maximum even number: " << list.secondMaxEven() << endl;
            break;

        case 9:
            cout << "Second minimum odd number: " << list.secondMinOdd() << endl;
            break;

        case 10:
            cout << "Duplicates in the list: ";
            list.printDuplicates();
            break;

        case 11:
            cout << "Enter number of rotations clockwise: ";
            cin >> rotations;
            list.rotateClockwise(rotations);
            break;

        case 12:
            cout << "Enter number of rotations anti-clockwise: ";
            cin >> rotations;
            list.rotateAntiClockwise(rotations);
            break;

        case 13:
            cout << "Elements in the list: ";
            list.display();
            break;

        case 14:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice, please try again." << endl;
        }

    } while (choice != 14);

    return 0;
}
