#include <iostream>
#include <cmath>

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
                throw 304;
            }

            return firstNum / secondNum;

        }catch( int x ){
            std::cout << "Error in calculating the result. Try Again." << std::endl;
        }
    }

    double divide( double firstNum, double secondNum ){
        try{
            if(secondNum == 0) {
                throw 304;
            }
            return firstNum / secondNum;
        }catch( int x ){
            std::cout << "Error in calculating the result. Try Again." << std::endl;
        }
    }

    /* int square( int number ) {   // This function is commented as a 'square' function returns float/double values.
        return sqrt(number);
    } */

    double square( double number ){
        return sqrt( number );
    }
};



int main() {

    Calculator calculation;

    double number, number1;
    std::string operation;

    std::cout << "Enter the operation that you want to use:\n";
    std::cout << "\"add\" => Addition\n ";
    std::cout << "\"subtract\" => Subtraction\n";
    std::cout << "\"multiply\" => Addition\n ";
    std::cout << "\"divide\" => Divide\n ";
    std::cout << "\"square\" => Square\n";

    std::cin >> operation;

    if( operation != "square" ) {
        std::cout << "Enter the first number\n";
        std::cin >> number;
        std::cout << "Enter the second number\n";
        std::cin >> number1;

        if (operation == "add") {

            std::cout << "The result is:";
            std::cout << calculation.add(number, number1);
        } else if (operation == "subtract") {

            std::cout << "The result is:";
            std::cout << calculation.subtract(number, number1);
        } else if (operation == "multiply") {

            std::cout << "The result is:";
            std::cout << calculation.multiply(number, number1);
        } else if (operation == "divide") {

            std::cout << "The result is:";
            std::cout << calculation.divide(number, number1);
        } else {

            std::cout << "The entered operation was not found.";
            std::cout << "Try again." << std::endl;
        }
    }else{
        std::cout << "Enter number\n";
        std::cin >> number;

        std::cout << "The result is:";
        std::cout << calculation.square(number);
    }

    return 0;
}