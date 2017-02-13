fib_matrix = [[1,1],
              [1,0]]

def matrix_square(A):
    return mat_mult(A,A)


def mat_mult(A,B):
  return [[(A[0][0]*B[0][0] + A[0][1]*B[1][0]), (A[0][0]*B[0][1] + A[0][1]*B[1][1])],
            [(A[1][0]*B[0][0] + A[1][1]*B[1][0]), (A[1][0]*B[0][1] + A[1][1]*B[1][1])]]


def matrix_pow(M, power):
    if power <= 0:
      return M

    powers =  list(reversed([True if i=="1" else False for i in bin(power)[2:]]))

    matrices = [None for _ in powers]
    matrices[0] = M

    for i in range(1,len(powers)):
        matrices[i] = matrix_square(matrices[i-1])


    result = None

    for matrix, power in zip(matrices, powers):
        if power:
            if result is None:
                result = matrix
            else:
                result = mat_mult(result, matrix)

    return result

def fibonacci(n):
  if(n == 0):
    return 0
  else:
    return matrix_pow(fib_matrix, n)[0][1]

print(fibonacci(23922))

# numTests = int(input())

# for tt in range(numTests):
#   hi = 24000
#   lo = 1
#   n = int(input())
#   while(hi != lo):
#     mid = (hi+lo)//2
#     length = len(str(fibonacci(mid)))
#     if(length >= n):
#       hi = mid
#     else:
#       lo = mid+1
#   print(hi)