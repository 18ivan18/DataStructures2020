#ifndef __PROB4_TESTS_H
#define __PROB4_TESTS_H

const unsigned int N = 100000;

TEST_CASE("Zero rows") 
{

    SparseMatrix<int> m(N, N);

    m.set(0,1000,1);
    m.set(1,15000,0);
    m.set(1,1,0);

    CHECK_FALSE (m.isZeroRow(0));
    CHECK (m.isZeroRow(1));

    m.set (0,1000,0);
    CHECK (m.isZeroRow(0));

}

TEST_CASE("Check assignment and reading") 
{
    SparseMatrix<int> m(N, N);

    m.set(0,1000,1);
    m.set(1,15000,2);
    m.set(1000,1000,3);

    CHECK (m[0][1000] == 1);
    CHECK (m[1][15000] == 2);
    CHECK (m[1000][1000] == 3);

    CHECK (m[9999][9999] == 0);
}

TEST_CASE("Default value at nonexistent position is 0")
{
    SparseMatrix<int> m(N, N);
    CHECK_EQ(m[10][20], 0);
}


template <class T>
unsigned int rowCount (SparseMatrix<T> const &m)
{
    unsigned int c = 0;
    for (unsigned i : m)
    {
        ++c;
    }
    return c;
}

TEST_CASE("Determine non-zero rows") 
{
    SparseMatrix<int> m(N, N);

    m.set(1, 2, 3);
    CHECK (rowCount(m) == 1);

    m.set(5, 10, 10);
    CHECK (rowCount(m) == 2);

    m.set(5, 15, 15);
    CHECK (rowCount(m) == 2);

    m.set(15, 20, 30);
    CHECK (rowCount(m) == 3);
}


TEST_CASE("Iterating rows") 
{
    SparseMatrix<int> m(N, N);

    m.set(5, 10, 20);
    m.set(50, 100, 200);

    unsigned count = 0;
    for (unsigned int i : m)
    {
        CHECK ((i == 5 || i == 50));
        ++count;
    }
    CHECK_EQ(count, 2);
}

#endif
