#!/bin/python3

#problem: https://www.hackerrank.com/challenges/maximum-element/problem

import math
import os
import random
import re
import sys

#
# Complete the 'getMax' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts STRING_ARRAY operations as parameter.
#

def getMax(operations):
    stack = []
    result =[]
    mx = 0
    for operation in operations:
        operation = operation.split()
        if(int(operation[0]) == 1):
            if(int(operation[1]) > mx):
                mx = int(operation[1])
            stack.append(int(operation[1]))
        elif(int(operation[0]) == 2):
            dlt = stack.pop()
            if(dlt == mx and len(stack)):
                mx = max(stack)
            elif(len(stack) == 0):
                mx = 0
        elif(int(operation[0]) == 3):
            result.append(mx)
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    ops = []

    for _ in range(n):
        ops_item = input()
        ops.append(ops_item)

    res = getMax(ops)

    fptr.write('\n'.join(map(str, res)))
    fptr.write('\n')

    fptr.close()
