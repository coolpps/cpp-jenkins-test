#ifndef __MATHTEST_H
#define __MATHTEST_H


template<typename T>
class MathTest{
private:
    T val;

public:
    static T add(const T& a, const T& b);
    static T sub(const T& a, const T& b);
    static T div(const T& a, const T& b);

    MathTest();
    MathTest(T input);
    ~MathTest();


    T pow(const int&);
};

template<typename T>
T MathTest<T>::add(const T& a, const T& b) 
{
    return a + b; 
}

template<typename T>
T MathTest<T>::sub(const T& a, const T& b)
{
    return a - b;
}

template<typename T>
T MathTest<T>::div(const T& a, const T& b)
{
    if(b == 0)
        throw std::runtime_error();
    return a / b;
}

template<typename T>
MathTest<T>::MathTest():val(0) {}

template<typename T>
MathTest<T>::MathTest(T input):val(input) {}

template<typename T>
MathTest<T>::~MathTest() {}


template<typename T>
T MathTest<T>::pow(const int& p)
{
    return [&]() -> T {
        T result = 1;
        for(int i=0; i<p; i++) 
            result *= this->val;  
        return result;
    }();
}


#endif