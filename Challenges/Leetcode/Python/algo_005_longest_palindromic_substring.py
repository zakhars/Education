def is_palindrome(s: str, b: int, e: int) -> bool:
    while b < e:
        if s[b] != s[e]: return False
        b += 1
        e -= 1
    return True

def get_longest_palindrome_substr(s: str) -> str:
    pal = ''
    pal_len = 0
    pal_b = 0
    pal_e = 0
    while pal_len <= len(s):
        for i in range(0, len(s) - pal_len):
            if is_palindrome(s, i, i + pal_len):
                #pal = s[i:i+pal_len+1]
                pal_b = i
                pal_e = i+pal_len
                break
        pal_len += 1
    return s[pal_b:pal_e+1]

def test_get_longest_palindrome_substr(s: str) -> None:
    print(get_longest_palindrome_substr(s))

test_get_longest_palindrome_substr('abacddc')
