#import <Foundation/Foundation.h>

#import "WrapperObjectCpp.h"
#include <Wrapper.h>

@implementation ABCpp

-(int)AddTwoNumbersWrapper:(int)inputA toY:(int)inputB
{
    return AddTwoNumbers(10, 20);
}

@end
