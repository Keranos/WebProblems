from MathFunctions import *
from itertools import takewhile
import Data

def Solution1():
    return sum(x for x in xrange(1, 999) if x % 3 == 0 or x % 5 == 0)

def Solution2():
    evenFib = (x for x in fibonacci() if x % 2)
    return sum(takewhile(lambda x: x < 4e6, evenFib))

def Solution3():
    return max(prime_factors(600851475143))

def Solution4():
    candidates = (x*y for x in xrange(110, 1000, 11) for y in xrange(x, 1000))
    return max(x for x in candidates if is_palindrome(x))

def Solution5():
    return reduce(lcm, range(1, 21))

def Solution6():
    sum_of_squares = sum(x*x for x in xrange(1, 101))
    square_of_sums = sum_series(100)**2;
    return square_of_sums - sum_of_squares

def Solution7():
    return generate_prime(10001)

def Solution8():
    numbers = (int(c) for c in "".join(Data.data8.strip().splitlines()))
    return max(product(nums) for nums in traverse(numbers, 13, 1))

def Solution9():
    triplet = ((a, b, 1000-a-b) for a in xrange(1, 999) for b in xrange(a+1, 999))
    return first(a*b*c for (a, b, c) in triplet if a*a + b*b == c*c)

def Solution10():
    return sum(get_primes(2000000))

def Solution13():
    total = sum(Data.data13)
    n = num_length(total)
    return total / 10**(n - 10)

def Solution16():
    return sum_digits(2**1000)

def Solution48():
    return sum(x**x for x in range(1, 1001)) % 10000000000
