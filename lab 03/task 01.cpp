#include <iostream>
using namespace std;

template <class t>
class list {
protected:
public:
    t* arr;
    int maxsize;
    int currentsize;


    virtual void AddAtFirstIndex(t value) = 0;
    virtual void AddAtLastIndex(t value) = 0;
    virtual t RemoveElementFromEnd() = 0;
    virtual void RemoveElementFromStart() = 0;

    virtual ~list() {
        delete[] arr;
    }
};

template <class t>
class page : public list<t> {
public:
    page(int size = 10) {
        this->maxsize = size;
        this->currentsize = 0;
        this->arr = new t[this->maxsize];
    }

    page(const page<t>& other) {
        this->maxsize = other.maxsize;
        this->currentsize = other.currentsize;
        this->arr = new t[this->maxsize];
        for (int i = 0; i < this->currentsize; i++) {
            this->arr[i] = other.arr[i];
        }
    }

    ~page() {
        delete[] this->arr;
    }

    void AddAtFirstIndex(t value) override {
        if (this->currentsize == this->maxsize) {
            return;
        }

        for (int i = this->currentsize; i > 0; i--) {
            this->arr[i] = this->arr[i - 1];
        }
        this->arr[0] = value;
        this->currentsize++;
    }

    void AddAtLastIndex(t value) override {
        if (this->currentsize == this->maxsize) {
            return;
        }
        this->arr[this->currentsize] = value;
        this->currentsize++;
    }

    t RemoveElementFromEnd() override {
        if (this->currentsize == 0) {
            return t();
        }
        this->currentsize--;
        return this->arr[this->currentsize];
    }

    void RemoveElementFromStart() override {
        if (this->currentsize == 0) {
            return;
        }

        for (int i = 0; i < this->currentsize - 1; i++) {
            this->arr[i] = this->arr[i + 1];
        }
        this->currentsize--;
    }

    void PrintArray() {
        for (int i = 0; i < this->currentsize; i++) {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    page<int> obj1(5);
    obj1.AddAtLastIndex(1);
    obj1.AddAtLastIndex(2);
    obj1.AddAtLastIndex(3);
    obj1.AddAtFirstIndex(0);

    cout << "Array after adding elements:" << endl;
    obj1.PrintArray();

    obj1.RemoveElementFromEnd();
    cout << "Array after removing element from the end:" << endl;
    obj1.PrintArray();

    obj1.RemoveElementFromStart();
    cout << "Array after removing element from the start:" << endl;
    obj1.PrintArray();

    page<int> obj2 = obj1;
    cout << "Array after copying:" << endl;
    obj2.PrintArray();

    return 0;
}
