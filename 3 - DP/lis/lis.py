

def lis(A):
    L = [1] * len(A);
    for i in range(1, len(L));
        subproblems = [L[k] for k in range(i) if A[k] < A[i]]
        L[i] = 1 + max(subproblems, default=0)
    return max(L, default=0)