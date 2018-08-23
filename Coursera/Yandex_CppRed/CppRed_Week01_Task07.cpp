#include <vector>

#include "test_runner.h"

using namespace std;

template<typename T>
class Table
{
    vector<vector<T>> m;
public:
    Table(size_t rowcount, size_t colcount) :
        m(rowcount)
    {
        for (auto& row : m)
        {
            row.resize(colcount);
        }
    }

    pair<size_t, size_t> Size() const
    {
        if (m.size() > 0)
        {
            return make_pair(m.size(), m[0].size());
        }
        return make_pair(0, 0);
    }

    void Resize(size_t rows, size_t cols)
    {
        m.resize(rows);
        for (auto& col : m)
        {
            col.resize(cols);
        }
    }

    vector<T>& operator[](size_t i)
    {
        return m[i];
    }

    const vector<T>& operator[](size_t i) const
    {
        return m[i];
    }

};

void TestTable() {
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main_cppr_w1_t7() {
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}

// Teacher's solution

namespace ts
{
    template <typename T>
    class Table {
    private:
        vector<vector<T>> data;

    public:
        Table(size_t rows, size_t columns) {
            Resize(rows, columns);
        }

        const vector<T>& operator [] (size_t idx) const {
            return data[idx];
        }

        vector<T>& operator [] (size_t idx) {
            return data[idx];
        }

        void Resize(size_t rows, size_t columns) {
            data.resize(rows);
            for (auto& item : data) {
                item.resize(columns);
            }
        }

        pair<size_t, size_t> Size() const {
            return { data.size(), (data.empty() ? 0 : data[0].size()) };
        }

    };
}