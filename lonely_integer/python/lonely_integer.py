
def findLonelyInt(A):
    if len(A) == 1:
        return A[0]

    s = set()
    for i in A:
        if i in s:
            s.remove(i)
        else:
            s.add(i)

    if len(s) != 1:
        print 'ERROR, too many items in set'
        return -1;

    return s.pop()


if __name__ == '__main__':
    N = input()
    A = [int(i) for i in raw_input().strip().split(" ")]
    li = findLonelyInt(A)
    print li
