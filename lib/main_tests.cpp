//
// Created by Nernandez Salas on 28/10/2018.
//

#include <iostream>
#include <cmath>
#include <gtest/gtest.h>

class Calculator{

public:

    int add( int firstNum, int secondNum ){
        return firstNum + secondNum;
    }

    double add( double firstNum, double secondNum ){
        return firstNum + secondNum;
    }

    int subtract( int firstNum, int secondNum ){
        return firstNum - secondNum;
    }

    double subtract( double firstNum, double secondNum ){
        return firstNum - secondNum;
    }

    int multiply( int firstNum, int secondNum ){
        return firstNum * secondNum;
    }

    double multiply( double firstNum, double secondNum ){
        return firstNum * secondNum;
    }

    int divide( int firstNum, int secondNum ){
        try{
            if(secondNum == 0) {
                throw 9999;
            }
            return firstNum / secondNum;
        }catch( int x ){
            return x;
        }
    }

    double divide( double firstNum, double secondNum ){
        try{
            if(secondNum == 0) {
                throw 9999;
            }
            return firstNum / secondNum;
        }catch( int x ){
            return x;
        }
    }

    /* int square( int number ) {   // This function is commented as a 'square' function returns float/double values.
        return sqrt(number);
    } */

    double square( double number ){
        return sqrt( number );
    }
};

// Test 'Add' method
TEST(addTest, addWorks){

    Calculator calculatorHP;

    int result1 = calculatorHP.add( 2, 2 );
    ASSERT_EQ(4, result1);

    double result2 = calculatorHP.add(5.5, 7.6);
    ASSERT_EQ(13.1, result2);
}

// Test 'Subtract' method
TEST(subtractTest, subtractWorks) {
    Calculator calculatorHP;

    int result1 = calculatorHP.subtract(10, 5);
    ASSERT_EQ(5, result1);

    double result2 = calculatorHP.subtract(7.6, 5.3);
    ASSERT_EQ(2.3, result2);
}

// Test 'Multiply' method
TEST(multiplyTest, multiplyWorks){
    Calculator calculatorHP;

    int result1 = calculatorHP.multiply( 2, 2 );
    ASSERT_EQ(4, result1);

    double result2 = calculatorHP.multiply(5.5, 5.5);
    ASSERT_EQ(30.25, result2);

    result2 = calculatorHP.multiply(-2.6, 5.0);
    ASSERT_EQ(-13.0, result2);
}

// Test 'Divide' method
TEST(divideTest, divideWorks){
    Calculator calculatorHP;

    int result1 = calculatorHP.divide( 2, 2 );
    ASSERT_EQ(1, result1);

    double result2 = calculatorHP.divide(12.8, 3.2);
    ASSERT_EQ(4.0, result2);

    result2 = calculatorHP.divide(7, 0);
    ASSERT_TRUE(9999 == result2);
}

// Test 'Square' method
TEST(squareTest, squareWorks){
    Calculator calculatorHP;

    double result1 = calculatorHP.square( 144.0 );
    ASSERT_EQ(12.0, result1);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}