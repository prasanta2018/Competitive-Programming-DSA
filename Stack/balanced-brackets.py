#!/bin/python3

# problem: https://www.hackerrank.com/challenges/balanced-brackets/problem

import math
import os
import random
import re
import sys

#
# Complete the 'isBalanced' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def isBalanced(s):
    stack = []
    for b in s:
        if( b == '(' or b == '{' or b == '['):
            stack.append(b)
        else:
            if( len(stack) == 0):
                return 'NO'
            pop_b = stack.pop()
            if( (pop_b == '(' and b == ')') or (pop_b == '{' and b == '}') or (pop_b == '[' and b == ']') ):
                continue
            else:
                return 'NO'
    if(len(stack)):
        return 'NO'
    else:
        return 'YES'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        s = input()

        result = isBalanced(s)

        fptr.write(result + '\n')

    fptr.close()
