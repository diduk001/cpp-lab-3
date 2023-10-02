#!/usr/bin/python3

import random

M_I_MIN = 0
M_I_MAX = 10**9

def generate_test(n: int, test_idx: int) -> str:
    random.seed(test_idx)
    array = [random.randint(M_I_MIN, M_I_MAX) for _ in range(n)]
    array_as_str = ' '.join(map(str, array))
    test_as_str = str(n) + '\n' + array_as_str
    return test_as_str

def main():
    for test_idx in range(13):
        n = 20 + test_idx
        test = generate_test(n, test_idx)
        with open(f"tests/TEST_{test_idx:02}.txt", mode='w') as test_file:
            test_file.write(test)

if __name__ == '__main__':
    main()