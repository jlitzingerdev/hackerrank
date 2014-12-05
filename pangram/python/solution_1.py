
def is_pangram(s):
    if len(s) < 26:
        return 'not pangram'

    letters = set()
    for c in s:
        if not c.isspace():
            letters.add(c.lower())

        if len(letters) == 26:
            return 'pangram'

    return 'not pangram'


if __name__ == '__main__':
    s = raw_input()
    res = is_pangram(s)
    print res
