#include <QtTest>

#include "mathcalc.h"

class TestMathCalc : public QObject
{
    Q_OBJECT

public:
    TestMathCalc();
    ~TestMathCalc();

private slots:
    void test_sum();
    void test_mult();

private:
    MathCalc m_objMathCalc;
};

TestMathCalc::TestMathCalc()
{

}

TestMathCalc::~TestMathCalc()
{

}

void TestMathCalc::test_sum()
{
    // sum default
    QCOMPARE(m_objMathCalc.Sum(), 0 + 0);

    // sum after setting A and B
    const int A = 10;
    const int B = 20;
    m_objMathCalc.setData(A, B);

    QVERIFY2(m_objMathCalc.getA() == 0, "Operand A doesn't match");
    QVERIFY2(m_objMathCalc.getB() == B, "Operand B doesn't match");

    QCOMPARE(m_objMathCalc.Sum(), A + B);
}

void TestMathCalc::test_mult()
{
    const int A = 5;
    const int B = 6;
    m_objMathCalc.setData(A, B);

    QCOMPARE(m_objMathCalc.Sum(), A + B);
}

QTEST_APPLESS_MAIN(TestMathCalc)

#include "tst_testmath.moc"
