#include <gtest/gtest.h>
#include "../include/mathTest.hpp"


/*  static method test
    test param->int
*/
TEST(MathTestStatic, AddInt) 
{
    EXPECT_EQ(MathTest<int>::add(5, 3), 8);
    EXPECT_EQ(MathTest<int>::add(-1, 1), 0);
    EXPECT_EQ(MathTest<int>::add(0, 0), 0);
}

TEST(MathTestStatic, SubInt)
{
    EXPECT_EQ(MathTest<int>::sub(5, 3), 2);
    EXPECT_EQ(MathTest<int>::sub(-1, 1),-2);
    EXPECT_EQ(MathTest<int>::sub(0, 0), 0);
}

TEST(MathTestStatic, DivInt)
{
    EXPECT_EQ(MathTest<int>::div(5, 3), 1);
    EXPECT_EQ(MathTest<int>::div(-1, 1),-1);
    EXPECT_EQ(MathTest<int>::div(0, 1), 0);
}


/* test param->double */
TEST(MathTestStatic, AddDouble) {
    EXPECT_DOUBLE_EQ(MathTest<double>::add(2.5, 3.1), 5.6);
}

TEST(MathTestStatic, DivDouble) {
    EXPECT_DOUBLE_EQ(MathTest<double>::div(10.0, 4.0), 2.5);
}

/*
    non static method test
*/
TEST(MathTestPow, IntPow) {
    MathTest<int> obj(2);   // val = 2
    EXPECT_EQ(obj.pow(0), 1);   // 2^0 = 1
    EXPECT_EQ(obj.pow(1), 2);
    EXPECT_EQ(obj.pow(3), 8);
    EXPECT_EQ(obj.pow(5), 32);
}

TEST(MathTestPow, IntPowZeroBase) {
    MathTest<int> obj(0);
    EXPECT_EQ(obj.pow(0), 1);   // 0^0 通常定义为 1（数学上未定义，但编程中常定义为 1）
    EXPECT_EQ(obj.pow(5), 0);
}

TEST(MathTestPow, IntPowNegativeExponent) {
    MathTest<int> obj(2);
    // 如果 pow 支持负数指数，应返回小数或错误。根据你的实现，假设只支持非负。
    // 如果你的实现允许负数，请按实际预期编写。
    // 若未支持，可注释掉或用 EXPECT_THROW 检查异常。
}

// 测试 double 类型 pow
TEST(MathTestPow, DoublePow) {
    MathTest<double> obj(3.0);
    EXPECT_DOUBLE_EQ(obj.pow(0), 1.0);
    EXPECT_DOUBLE_EQ(obj.pow(2), 9.0);
    EXPECT_DOUBLE_EQ(obj.pow(3), 27.0);
}

TEST(MathTestPow, DoublePowFloating) {
    MathTest<double> obj(2.5);
    EXPECT_DOUBLE_EQ(obj.pow(2), 6.25);
    EXPECT_DOUBLE_EQ(obj.pow(3), 15.625);
}

// 测试默认构造（val 应初始化为 0？取决于你的构造函数实现）
TEST(MathTestPow, DefaultConstructor) {
    MathTest<int> obj;  // 假设 val 被初始化为 0
    EXPECT_EQ(obj.pow(0), 1);  // 0^0 = 1
    EXPECT_EQ(obj.pow(3), 0);
}

// 测试 div 除零异常（如果你的实现抛出异常）
TEST(MathTestStatic, DivByZeroThrows) {
    // 假设你的 div 会抛出 std::runtime_error
    EXPECT_THROW(MathTest<int>::div(10, 0), std::runtime_error);
}