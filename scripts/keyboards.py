import io

NULL_KEY = "_" * 7
FMT_KEY = " " * 7


class Input:
    @staticmethod
    def is_line_layer_start(l):
        return l.startswith("[") and l.find("LAYOUT") != -1

    @staticmethod
    def is_line_layer_end(l):
        return l.rfind("),") or l.rfind(")")

    @staticmethod
    def read_input(filename: str):
        with open(filename, "r", encoding="utf-8") as fin:
            wrapper_lines = [None, None]
            lines = [l.strip() for l in fin.readlines()]
            layer_indices = []
            for i, line in enumerate(lines):
                if line.startswith("const uint16_t"):
                    wrapper_lines[0] = line
                elif line.startswith("};"):
                    wrapper_lines[1] = line
                elif Input.is_line_layer_start(line):
                    layer_indices.append([i + 1, -1])
                elif Input.is_line_layer_end(line):
                    layer_indices[-1][1] = i + 1
            return (layer_indices, lines, wrapper_lines)

    @staticmethod
    def parse_layer(layer_startend, lines):
        rows = []
        max_key_len = None
        for line in lines[layer_startend[0] : layer_startend[1]]:
            keys = [k.strip() for k in line.split(",") if k]
            rows.append(keys)
            row_max = max([len(k) for k in keys])
            if max_key_len is None or max_key_len < row_max:
                max_key_len = row_max
        return max_key_len, rows


class Format:
    @staticmethod
    def fmt_key(k, l):
        return f"{k},".ljust(l + 4)

    @staticmethod
    def nokey(l):
        return Format.fmt_key(NULL_KEY, l).replace("_", " ").replace(",", " ")

    @staticmethod
    def fmt_row(row, max_key_len):
        buff = io.StringIO("")

        def fmt_row_15():
            for key in row:
                buff.write(Format.fmt_key(key, max_key_len))

        def fmt_row_14():
            for i, key in enumerate(row):
                if i == 13:
                    buff.write(Format.nokey(max_key_len))
                buff.write(Format.fmt_key(key, max_key_len))

        def fmt_row_9():
            for i, key in enumerate(row):
                if i == 3:
                    buff.write(Format.nokey(max_key_len))
                    buff.write(Format.nokey(max_key_len))
                    buff.write(Format.fmt_key(key, max_key_len))
                    buff.write(Format.nokey(max_key_len))
                    buff.write(Format.nokey(max_key_len))
                elif i == 6:
                    buff.write(Format.nokey(max_key_len))
                    buff.write(Format.nokey(max_key_len))
                    buff.write(Format.fmt_key(key, max_key_len))
                else:
                    buff.write(Format.fmt_key(key, max_key_len))

        if len(row) == 15:
            fmt_row_15()
        elif len(row) == 14:
            fmt_row_14()
        elif len(row) == 9:
            fmt_row_9()
        else:
            raise ValueError("unexpected row len: %d" % (len(row)))
        return buff.getvalue()

    @staticmethod
    def fmt_layer(layer, max_key_len, row_formatter):
        buff = io.StringIO("")
        for row in layer:
            buff.write(row_formatter(row, max_key_len) + "\n")
        return buff.getvalue()


class Keyboard:
    def fmt_row(self, row, max_key_len: int):
        buff = io.StringIO("")
        f = self.row_fmt_chooser(row)
        buff.write(f(row, max_key_len))
        return buff.getvalue()

    def run(self, filename: str):
        layer_indices, lines, wrapper_lines = Input.read_input(filename)
        global_max_key_len = None
        layers = []
        for layer_startend in layer_indices:
            max_key_len, rows = Input.parse_layer(layer_startend, lines)
            if global_max_key_len is None or global_max_key_len < max_key_len:
                global_max_key_len = max_key_len
            layers.append(rows)
        for layer in layers:
            s = Format.fmt_layer(layer, global_max_key_len, self.fmt_row)
            print(s)
            print()
        print(wrapper_lines[1])


class DSP40(Keyboard):
    pass


class QMMK2(Keyboard):
    def fmt_row_15(self, row, max_key_len):
        buff = io.StringIO("")
        for key in row:
            buff.write(Format.fmt_key(key, max_key_len))
        return buff.getvalue()

    def fmt_row_14(self, row, max_key_len):
        buff = io.StringIO("")
        for i, key in enumerate(row):
            if i == 13:
                buff.write(Format.nokey(max_key_len))
            buff.write(Format.fmt_key(key, max_key_len))
        return buff.getvalue()

    def fmt_row_9(self, row, max_key_len):
        buff = io.StringIO("")
        for i, key in enumerate(row):
            if i == 3:
                buff.write(Format.nokey(max_key_len))
                buff.write(Format.nokey(max_key_len))
                buff.write(Format.fmt_key(key, max_key_len))
                buff.write(Format.nokey(max_key_len))
                buff.write(Format.nokey(max_key_len))
            elif i == 6:
                buff.write(Format.nokey(max_key_len))
                buff.write(Format.nokey(max_key_len))
                buff.write(Format.fmt_key(key, max_key_len))
            else:
                buff.write(Format.fmt_key(key, max_key_len))
        return buff.getvalue()

    def row_fmt_chooser(self, row):
        if len(row) == 15:
            return self.fmt_row_15
        elif len(row) == 14:
            return self.fmt_row_14
        elif len(row) == 9:
            return self.fmt_row_9
        else:
            raise ValueError("unexpected row len: %d" % (len(row)))


class ANC(Keyboard):
    def fmt_row_14(self, row, max_key_len: int):
        buff = io.StringIO("")
        for key in row:
            buff.write(Format.fmt_key(key, max_key_len))
        return buff.getvalue()

    def fmt_row_13(self, row, max_key_len: int):
        buff = io.StringIO("")
        for i, key in enumerate(row):
            if i == 12:
                buff.write(Format.nokey(max_key_len))
            buff.write(Format.fmt_key(key, max_key_len))
        return buff.getvalue()

    def fmt_row_12(self, row, max_key_len: int):
        buff = io.StringIO("")
        for i, key in enumerate(row):
            if i == 10 or i == 11:
                buff.write(Format.nokey(max_key_len))

            buff.write(Format.fmt_key(key, max_key_len))

        return buff.getvalue()

    def fmt_row_8(self, row, max_key_len: int):
        buff = io.StringIO("")
        for i, key in enumerate(row):
            if i == 3:
                buff.write(Format.nokey(max_key_len))
                buff.write(Format.nokey(max_key_len))
                buff.write(Format.nokey(max_key_len))
                buff.write(Format.fmt_key(key, max_key_len))
                buff.write(Format.nokey(max_key_len))
                buff.write(Format.nokey(max_key_len))
                buff.write(Format.nokey(max_key_len))
            # elif i == 6:
            #     buff.write(Format.nokey(max_key_len))
            #     buff.write(Format.nokey(max_key_len))
            #     buff.write(Format.fmt_key(key, max_key_len))
            else:
                buff.write(Format.fmt_key(key, max_key_len))
        return buff.getvalue()

    def row_fmt_chooser(self, row):
        if len(row) == 14:
            return self.fmt_row_14
        elif len(row) == 12:
            return self.fmt_row_12
        elif len(row) == 13:
            return self.fmt_row_13
        elif len(row) == 8:
            return self.fmt_row_8
        else:
            raise ValueError("unexpected row len: %d" % (len(row)))
