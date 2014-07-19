import operator
from math import sqrt
from fractions import gcd

def isPrime(n):
    for i in range(2, int(sqrt(n))+1):
        if n % i == 0:
            return False            
    return True

def product(nums):
    return reduce(operator.mul, nums, 1)

def factorial(num):
    return product(xrange(2, num))

def fibonacci():
    fib = lambda (a, b), _: (b, a+b)
    return (b for (a, b) in ireduce(fib, count(), (0, 1)))

def first(iterable):
    return iterable.next()

def generate_prime(n):
    if n == 1:
        return 2
    n_primes = 1
    test_num = 1
    while n_primes < n:
        test_num += 2
        if isPrime(test_num):
            n_primes += 1
    return test_num

def get_primes(n):
    sieve = [True] * (n/2)
    for i in xrange(3, int(sqrt(n)) + 1, 2):
        if sieve[i/2]:
            sieve[i*i/2::i] = [False] * ((n-i*i-1)/(2*i)+1)
    return [2] + [2*i + 1 for i in xrange(1, n/2) if sieve[i]]

def nth_prime(n):
    if(n == 1):
        return 2
    n_primes = 1
    test_num = 1
    while n_primes < n:
        test_num += 2
        if isPrime(test_num):
            n_primes += 1
    return test_num

def ireduce(func, iterator, default=None):
    if default is None:
        iterator = iter(iterator)
        curr = iterator.next()
    else:
        curr = init
        yield init
    for x in iterator:
        curr = func(curr, x)
        yield curr

def is_palindrome(num):
    return str(num) == str(num)[::-1]

def lcm(a, b):
    return (a*b) / gcd(a, b)

def prime_factors(num, start=2):
    candidates = xrange(start, int(sqrt(num)) + 1)
    factor = next((x for x in candidates if (num % x == 0)), None)
    return ([factor] + prime_factors(num / factor, factor) if factor else [num])

def reverse_number(num):
    return int(str(num)[::-1])

def sum_series(num):
    return num * (num + 1) / 2

def drop(n, iterable):
    return islice(iterable, n, None)
 
def take_every(n, iterable):
    return islice(iterable, 0, None, n)
 
def traverse(iterable, n, step):
    iter_list = tee(iterable, n)
    one_step_it = izip(*(starmap(drop, enumerate(iter_list))))
    return take_every(step, one_step_it)

def sum_digits(n):
    r = 0
    while n:
        r, n = r + n % 10, n / 10
    return r
