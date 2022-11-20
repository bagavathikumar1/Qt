#ifndef MATHCALC_H
#define MATHCALC_H

class MathCalc
{
public:
    MathCalc(int a = 0, int b = 0) : m_nA(a), m_nB(b) { }


    void setData(int a, int b) {
        m_nA = a;
        m_nB = b;
    }

    int getA() { return m_nA; }
    int getB() { return m_nB; }

    int Sum() const { return m_nA + m_nB; }
    int Diff() const { return m_nA - m_nB; }
    int Mult() const { return m_nA * m_nB; }
    int Div() const { return m_nA / m_nB; }

private:
    int m_nA;
    int m_nB;
};

#endif // MATHCALC_H
