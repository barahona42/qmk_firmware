import io

NULL_KEY = "_" * 7
FMT_KEY = " " * 7


def is_line_layer_start(l):
    return l.startswith("[") and l.find("LAYOUT") != -1


def is_line_layer_end(l):
    return l.rfind("),") or l.rfind(")")


def read_input():
    with open("input.txt", "r", encoding="utf-8") as fin:
        lines = [l.strip() for l in fin.readlines()]
        layer_indices = []
        for i, line in enumerate(lines):
            if is_line_layer_start(line):
                layer_indices.append([i + 1, -1])
            elif is_line_layer_end(line):
                layer_indices[-1][1] = i + 1
        return (layer_indices, lines)


def fmt_key(k, l):
    return f"{k},".ljust(l + 4)


def nokey(l):
    return fmt_key(NULL_KEY, l).replace("_", " ").replace(",", " ")


def fmt_row(row, max_key_len):
    buff = io.StringIO("")

    def fmt_row_15():
        for key in row:
            buff.write(fmt_key(key, max_key_len))

    def fmt_row_14():
        for i, key in enumerate(row):
            if i == 13:
                buff.write(nokey(max_key_len))
            buff.write(fmt_key(key, max_key_len))

    def fmt_row_9():
        for i, key in enumerate(row):
            if i == 3:
                buff.write(nokey(max_key_len))
                buff.write(nokey(max_key_len))
                buff.write(fmt_key(key, max_key_len))
                buff.write(nokey(max_key_len))
                buff.write(nokey(max_key_len))
            elif i == 6:
                buff.write(nokey(max_key_len))
                buff.write(nokey(max_key_len))
                buff.write(fmt_key(key, max_key_len))
            else:
                buff.write(fmt_key(key, max_key_len))

    if len(row) == 15:
        fmt_row_15()
    elif len(row) == 14:
        fmt_row_14()
    elif len(row) == 9:
        fmt_row_9()
    else:
        raise ValueError("unexpected row len: %d" % (len(row)))
    return buff.getvalue()


def fmt_layer(layer, max_key_len):
    buff = io.StringIO("")
    for row in layer:
        buff.write(fmt_row(row, max_key_len) + "\n")
    return buff.getvalue()


def parse_layer(layer_startend, lines):
    rows = []
    max_key_len = None
    for line in lines[layer_startend[0] : layer_startend[1]]:
        keys = [k.strip() for k in line.split(",") if k]
        rows.append(keys)
        row_max = max([len(k) for k in keys])
        if max_key_len is None or max_key_len < row_max:
            max_key_len = row_max
    # for row in rows:
    #     print(fmt_row(row, max_key_len))
    return max_key_len, rows


def main():
    layer_indices, lines = read_input()
    global_max_key_len = None
    layers = []
    for layer_startend in layer_indices:
        max_key_len, rows = parse_layer(layer_startend, lines)
        if global_max_key_len is None or global_max_key_len < max_key_len:
            global_max_key_len = max_key_len
        layers.append(rows)
    for layer in layers:
        s = fmt_layer(layer, global_max_key_len)
        print(s)
        print("-" * 150)
        print()


if __name__ == "__main__":
    main()
