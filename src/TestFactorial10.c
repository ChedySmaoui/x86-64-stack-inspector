/**
 * TestFactorial10.c
 * 
 * Test file for recusrive implementation and stack outputting of factorial 10!.
*/

#include "Factorial.h"
#include "StackFrame.h"
#include <stdio.h>

#define N_10 10


/**
 * Static (akin to "private") function to this module.
 * This function is only ever called by executeFactorial below.
 * When it has reached the final recursive call, it
 * calls printStackFrames() to print out stack frame data.
 */
static unsigned long factorial(unsigned long n, unsigned long accumulator) {

    if (n <= 1) {
        printStackFrames(N_10 + 1);
        return accumulator;
    }
    return factorial(n - 1, n * accumulator);
}


/**
 * This variant of the provided executeFactorial does the exact same operations but for factorial 10.
 * The ouputted stack should be larger and print out a a total of 11 of stack frames starting from the last factorial call's stack frame.
 * 
 * The result should be: factorial(10) = 3628800.
 * 
 * If the printing is successful, it shows that my implementation is not specification specific and can work for other values than factorial 6.
*/
void executeFactorial10() {
    unsigned long basePointer = getBasePointer();
    printf("executeFactorial: basePointer = %lx\n", basePointer);

    unsigned long returnAddress = getReturnAddress();
    printf("executeFactorial: returnAddress = %lx\n", returnAddress);

    printf("executeFactorial: about to call factorial which should print the stack\n\n");

    unsigned long result = 0l;
    unsigned long number = N_10;
    unsigned long accumulator = 1l;
    result = factorial(number, accumulator);
    printf("executeFactorial: factorial(%lu) = %lu\n", number, result);
}

int main() {
    printf("Program Output For Factorial 10:\n");
    printf("\n");
    executeFactorial10();
    printf("\n");
    return 0;
}