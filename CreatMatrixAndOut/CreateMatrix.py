import random
import sys


def create_matrix():
    matrix = [[random.random() for col in range(10) ] for row in range(10)]
    return matrix


def create_type_matrix(cmd):
    type, low, high = ''
    if len(cmd) == 1 or len(cmd)==2:
        type, low, high = cmd[0]
    elif len(cmd) == 3:
        type, low, high = cmd
    matrix = [[0 for col in range(10)] for row in range(10)]
    if type == 'int':
        matrix_type = random.random()
    elif type == 'int' and low.isdigit() and high.isdigit():
        matrix_type = random.randint(int(low), int(high))
    elif type == 'double':
        matrix_type = random.uniform(float(low), float(high))
    elif type == 'ones':
        matrix_type = 0
    elif type == 'zeros':
        matrix_type = 0
    else:
        return create_matrix()
    for i in range(10):
        for j in range(10):
            matrix[i][j] = matrix_type
    return matrix


def save_matrix(matrix):
    with open("matrix.txt", 'w+') as f:
        for i in matrix:
            f.write(''.join(str(i)[1:-2]) + '\n')


if __name__ == '__main__':
    cmd = sys.argv[1:]
    if not cmd:
        m = create_matrix()
    else:
        m = create_type_matrix(cmd)
    save_matrix(m)
