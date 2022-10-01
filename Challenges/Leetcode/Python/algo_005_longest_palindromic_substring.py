def is_palindrome(s: str, b: int, e: int) -> bool:
    while b < e:
        if s[b] != s[e]: return False
        b += 1
        e -= 1
    return True

def get_longest_palindrome_substr(s: str) -> str:
    pal = ''
    pal_len = 0
    while pal_len <= len(s):
        for i in range(0, len(s) - pal_len):
            if is_palindrome(s, i, i + pal_len):
                pal = s[i:i+pal_len+1]
                break
        pal_len += 1
    return pal

def test_get_longest_palindrome_substr(s: str) -> None:
    print(get_longest_palindrome_substr(s))

test_get_longest_palindrome_substr('aaaaa')

