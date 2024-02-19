# Fib sequence
# Write it in recursion format

# n = (n-1) + (n-2)
# n: 1 = 1
# n: 0 = 0

# n: -2
# n is 0 or above
# n: 8 = f(7), f(6)
# 1 f(7) = f(6), f(5)
# 2 f(6) = f(5), f(4)
# 2 f(5) = f(4), f(3)
# 4 f(4) = f(3), f(2)

# (key, value)
# (n, f(n))
prev_stored_fib_nums = {}

def fib(n: int) -> int:
    # Base case
    if n == 1 or n == 0: return n

    # Check my table
    if n in prev_stored_fib_nums: return prev_stored_fib_nums[n]

    n_minus_1 = 0
    n_minus_2 = 0

    if (n-1) in prev_stored_fib_nums: 
        n_minus_1 = prev_stored_fib_nums[n-1]
    else:
        n_minus_1 = fib(n-1)

    if (n-2) in prev_stored_fib_nums:
        n_minus_2 = prev_stored_fib_nums[n-2]
    else:
        n_minus_2 = fib(n-2)
    
    # Use expensive recursion to calculate my number
    result = n_minus_1 + n_minus_2
    prev_stored_fib_nums[n] = result

    return result

print(fib(8)) # Answer 

