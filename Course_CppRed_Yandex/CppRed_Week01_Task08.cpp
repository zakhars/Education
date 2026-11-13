#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Deque
{
    vector<T> front;
    vector<T> back;
public:
    Deque() = default;
    
    bool Empty() const {
        return front.empty() && back.empty();
    }

    size_t Size() const {
        return front.size() + back.size();
    }

    T& operator[](size_t idx) {
        if (idx < front.size())
        {
            return *(rbegin(front) + idx);
        }
        return *(begin(back) + (idx - front.size()));
    }

    const T& operator[](size_t idx) const {
        if (idx < front.size())
        {
            return *(crbegin(front) + idx);
        }
        return *(cbegin(back) + (idx - front.size()));
    }

    T& At(size_t idx) {
        if (idx >= Size())
        {
            throw out_of_range("at");
        }
        return operator[](idx);
    }

    const T& At(size_t idx) const {
        if (idx >= Size())
        {
            throw out_of_range("const at");
        }
        return operator[](idx);
    }

    T& Front() {
        if (!front.empty())
        {
            return *rbegin(front);
        }
        return back.front();
    }

    const T& Front() const {
        if (!front.empty())
        {
            return *rbegin(front);
        }
        return back.front();
    }

    T& Back() {
        if (!back.empty())
        {
            return back.back();
        }
        return front.front();
    }

    const T& Back() const {
        if (!back.empty())
        {
            return back.back();
        }
        return front.front();
    }

    void PushFront(const T& elem) {
        front.push_back(elem);
    }

    void PushBack(const T& elem) {
        back.push_back(elem);
    }
};


int main_cppr_w1_t8()
{
    /*
    Deque<int> d;
    d.PushFront(1);
    cout << d.Back() << endl;
    d.PushFront(2);
    cout << d.Back() << endl;
    d.PushFront(3);
    cout << d.Back() << endl;
    d.PushFront(4);
    cout << d.Back() << endl;
    d.PushFront(23);
    d.PushBack(34);
    d.PushFront(12);
    cout << d.Back() << endl;
    cout << d.Front() << endl;
    d.Front() = 13;
    d.Back() = 24;
    cout << d.Size() << endl;
    cout << d.Empty() << endl;
    d[1] = 3;
    int elem = d[2];
    d.at(1) = 4;
    try
    {
        int a = d.at(27);
        d.at(42) = 5;
    }
    catch (out_of_range&)
    {
        cout << "out of range caught" << endl;
    }

    try
    {
        d.at(42) = 5;
    }
    catch (out_of_range&)
    {
        cout << "out of range caught" << endl;
    }
    */
    return 0;
}


// Teacher's solution

namespace ts
{
#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

    using namespace std;

    template <typename T>
    class Deque {
    private:
        vector<T> head, tail;

        void CheckIndex(size_t i) const {
            if (i >= Size())
                throw out_of_range("Index is out of range");
        }

    public:
        Deque() = default;

        bool Empty() const {
            return head.empty() && tail.empty();
        }

        size_t Size() const {
            return head.size() + tail.size();
        }

        void Clear() {
            head.clear();
            tail.clear();
        }

        const T& operator [] (size_t i) const {
            return i < head.size() ? head[head.size() - i - 1] : tail[i - head.size()];
        }

        T& operator [] (size_t i) {
            return i < head.size() ? head[head.size() - i - 1] : tail[i - head.size()];
        }

        const T& At(size_t i) const {
            CheckIndex(i);
            return (*this)[i];
        }

        T& At(size_t i) {
            CheckIndex(i);
            return (*this)[i];
        }

        const T& Front() const {
            return head.empty() ? tail.front() : head.back();
        }

        T& Front() {
            return head.empty() ? tail.front() : head.back();
        }

        const T& Back() const {
            return tail.empty() ? head.front() : tail.back();
        }

        T& Back() {
            return tail.empty() ? head.front() : tail.back();
        }

        void PushFront(const T& elem) {
            head.push_back(elem);
        }

        void PushBack(const T& elem) {
            tail.push_back(elem);
        }
    };
}