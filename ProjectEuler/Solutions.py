from MathFunctions import *
from itertools import takewhile, combinations
from math import factorial
import datetime
import Data

def Solution1():
    """Add all natural numbers below 1000 that are multiples of 3 or 5"""
    return sum(x for x in xrange(1, 999) if x % 3 == 0 or x % 5 == 0)

def Solution2():
    """Sum even Fibonacci numbers below 4 million"""
    evenFib = (x for x in fibonacci() if x % 2)
    return sum(takewhile(lambda x: x < 4e6, evenFib))

def Solution3():
    """Find largest prime factor of the number below"""
    return max(prime_factors(600851475143))

def Solution4():
    """Largest palindrome made from the product of two 3 digit numbers"""
    candidates = (x*y for x in xrange(110, 1000, 11) for y in xrange(x, 1000))
    return max(x for x in candidates if is_palindrome(x))

def Solution5():
    """LCM of the numbers 1-20"""
    return reduce(lcm, range(1, 21))

def Solution6():
    """Sum of squares minues the squares of sums"""
    sum_of_squares = sum(x*x for x in xrange(1, 101))
    square_of_sums = sum_series(100)**2;
    return square_of_sums - sum_of_squares

def Solution7():
    """The 10001st prime number"""
    return generate_prime(10001)

def Solution8():
    """Find the largest product of 13 adjacent digits in a 1000-digit number"""
    numbers = (int(c) for c in "".join(Data.data8.strip().splitlines()))
    return max(product(nums) for nums in traverse(numbers, 13, 1))

def Solution9():
    """Find the Pythagorean triplet for which a + b + c = 1000"""
    triplet = ((a, b, 1000-a-b) for a in xrange(1, 999) for b in xrange(a+1, 999))
    return first(a*b*c for (a, b, c) in triplet if a*a + b*b == c*c)

def Solution10():
    """Find the sum of all the primes below two million"""
    return sum(get_primes(2000000))

def Solution13():
    """First ten digits of the sum of fifty 100 digit numbers"""
    total = sum(Data.data13)
    n = num_length(total)
    return total / 10**(n - 10)

def Solution16():
    """Sum of the digits of 2**1000"""
    return sum_digits(2**1000)

def Solution19():
    """Number of Sundays from Jan 1, 1901 to Dec 31, 2000"""
    sundays = 0
    for y in xrange(1901, 2001):
        for m in xrange(1, 13):
            if datetime.datetime(y, m, 1).weekday() == 6:
                sundays += 1
    return sundays
    
def Solution20():
    """Sum of the digits of 100!"""
    return sum_digits(factorial(100))

def Solution48():
    """Sum of x**x from 1 to 1000"""
    return sum(x**x for x in range(1, 1001)) % 10000000000

def Solution55():
    """How many Lychrel numbers are there below 10000?"""
    return sum(is_Lychrel(n) for n in range(10000))
    

def Solution56():
    """Maximum digital sum of a^b where a, b < 100."""
    m = 0
    for a in xrange(1, 100):
        for b in xrange(1, 100):
            s = sum_digits(a**b)
            if s> m:
                m = s
    return m

def Solution206():
    """ Find the square with the property of 1_2_3_4_5_6_7_8_9_0"""
    n = 138902663
    while match_206(n*n): n -= 2
    return n*10

def match_206(n):
    s = str(n)
    return not all(int(s[x*2]) == x+1 for x in range(9))

def Solution491():
    arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    solutions = []
    count = 0L
    for p in combinations(arr, 10):
        a = sum(p)
        b = 90 - a
        if (a - b) % 11 == 0 and sorted(p) not in solutions:
            solutions.append(sorted(p))
            count += len([x for x in p if x != 0]) * factorial(len(p) - 1) * factorial(len(p)) / 2**(2*(len(p) - len(set(p))))
            
    return count
