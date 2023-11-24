KEY_LEN = 12
NULL_KEY = "_______"  # usual length of keys seems to be 10


def fmt_key(value, w):
    s = value
    s = s.center(int(w * KEY_LEN))
    return s
