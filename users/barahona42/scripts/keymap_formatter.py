"""
keyboard symbols from:
    https://gist.github.com/GLMeece/6a2b71c57df228e5a4a35e4b92b0992f
"""

import copy
import io
import json
import re

COLORS = [
    "#332726",  # 0  // base
    "#E0C743",  # 1  //
    "#D67F38",  # 2  // lay2
    "#E0C743",  # 3  //
    "#E0C743",  # 4  //
    "#E0C743",  # 5  //
    "#5C58A1",  # 6  // lay1
    "#E0C743",  # 7  //
    "#57AD7C",  # 8  // nums
    "#E0C743",  # 9  //
    "#4C43E0",  # 10 // navs
    "#E0C743",  # 11 //
    "#E0C743",  # 12 //
    "#E0C743",  # 13 //
    "#E0C743",  # 14 //
    "#E0C743",  # 15 //
]

REPLACEMENTS = {
    "AMPR": "&",
    "ASTR": "*",
    "AT": "@",
    "BSLS": "\\|",
    "BSPC": "⌫",
    "CIRC": "^",
    "COMM": ",<",
    "DEL": "⌦",
    "DLR": "$",
    "DOT": ".>",
    "DOWN": "↓",
    "EQL": "=+",
    "ESC": "⎋",
    "EXLM": "!",
    "GRV": "`~",
    "HASH": "#",
    "LALT_D": "D(⌥)",
    "LALT": "⌥",
    "LAY1_SPC": "␣(lay1)",
    "LAY2_SPC": "␣(lay2)",
    "LBRC": "[",
    "LCA_COM": "(⌃⌥,)",
    "LCA_DOT": "(⌃⌥.)",
    "LCBR": "{",
    "LCTL_S": "S(⌃)",
    "LCTL": "⌃",
    "LEFT": "←",
    "LG_DOWN": "(⌃⌘↓)",
    "LG_LEFT": "(⌃⌘←)",
    "LG_RGHT": "(⌃⌘→)",
    "LG_UP": "(⌃⌘↑)",
    "LGUI_F": "F(⌘)",
    "LGUI": "⌘",
    "LGUI(GRV)": "(⌘`)",
    "LGUI(TAB)": "",
    "LGUI(TAB)": "(⌘⇥)",
    "LPRN": "(",
    "LSFT": "⇧",
    "LSG(GRV)": "(⇧⌘`)",
    "LSG(TAB)": "(⇧⌘⇥)",
    "MINS": "-_",
    "MO(CONF)": "conf",
    "MO(NAVS)": "navs",
    "MO(NUMS)": "nums",
    "PERC": "%",
    "QUOT": "'\"",
    "RALT_K": "K(⌥)",
    "RALT": "⌥",
    "RBRC": "]",
    "RCBR": "}",
    "RCS(TAB)": "(⌃⇧⇥)",
    "RCTL_L": "L(⌃)",
    "RCTL": "⌃",
    "RCTL(TAB)": "(⌃⇥)",
    "RGUI_J": "J(⌘)",
    "RGUI": "⌘",
    "RIGHT": "→",
    "RPRN": ")",
    "RSTF_ENT": "⌤(⇧)",
    "SCLN": ";:",
    "SLSH": "/?",
    "TAB": "⇥",
    "TD(TD_MDIA)": "⏏",
    "UNDS": "_",
    "UP": "↑",
    "RGB_MOD": "rgb mode",
    "RGB_TOG": "rgb tog",
}

KEYMAP_FILE = "/Volumes/development/projects/qmk_firmware/keyboards/splitkb/kyria/keymaps/barahona42/keymap.c"

TEMPLATE = """
["","","","","","",{"x":6},"","","","","",""],
["","","","","","",{"x":6},"","","","","",""],
["","","","","","","","",{"x":2},"","","","","","","",""],
[{"x":3},"","","","","",{"x":2},"","","","",""],
"""


class KeymapLayout:
    def __init__(self, t: str):
        self.t = self._prepare_template(t)
        self.layers = {}

    def _prepare_template(self, raw: str):
        rows = []
        for line in map(lambda s: s.strip().removesuffix(","), raw.strip().split("\n")):
            rows.append(json.loads(line))
        return rows

    def _parse_keymap(self, name: str, rows: list[list]):
        self.layers[name] = []
        if len(rows) != len(self.t):
            raise ValueError("length of template and keymap rows do not match")
        for i in range(len(rows)):
            keycodes = copy.deepcopy(rows[i])
            slots = copy.deepcopy(self.t[i])
            row_out = []
            for slot in slots:
                if isinstance(slot, dict):
                    row_out.append(slot)
                else:
                    keycode = keycodes.pop(0).strip("_").replace("KC_", "")
                    if REPLACEMENTS.get(keycode, "") != "":
                        row_out.append(REPLACEMENTS[keycode])
                    else:
                        row_out.append(keycode)
            self.layers[name].append(row_out)

    def _flatten_layers(self):
        for rows in self.layers.values():
            for row in rows:
                pass

    def generate_layout(self, keymaps: dict):
        for k, v in keymaps.items():
            self._parse_keymap(k, v)
        return self.layers


def generate_layout(keymaps: dict):
    template = KeymapLayout(TEMPLATE)
    layout = template.generate_layout(keymaps)
    layer_rows_count = len(list(keymaps.values())[0])
    labels = []
    for i in range(layer_rows_count):
        rows = []
        row_labels = []
        for keymap_name, keymap_rows in layout.items():
            rows.append(keymap_rows[i])
        for row in zip(*rows):
            if isinstance(row[0], dict):
                row_labels.append(row[0])
            else:
                row_labels.append("\n".join(row))
        labels.append(row_labels)
    buff = io.StringIO("")
    for l in labels:
        buff.write(json.dumps(l) + ",\n")
    return buff.getvalue()


def main():
    with open(KEYMAP_FILE, "r") as fin:
        lines = fin.read().split("\n")
    keymaps_start = None
    keymaps_end = None
    for i, line in enumerate(lines):
        if keymaps_start is not None and keymaps_end is not None:
            break
        if (
            keymaps_start is None
            and line.startswith("const")
            and line.find("keymaps[]") != -1
        ):
            keymaps_start = i
        elif keymaps_end is None and line.startswith("};") and i > keymaps_start:
            keymaps_end = i
    if keymaps_start is None or keymaps_end is None:
        print("could not determine keymaps location")
        exit(1)
    cur_keymap = None
    keymaps = {}
    for i, line in enumerate(
        map(lambda l: l.strip(), lines[keymaps_start + 1 : keymaps_end])
    ):
        res = re.match("\[([A-Z0-9_]+)\]=LAYOUT.*\(", line.replace(" ", ""), re.I)
        if res is not None and len(res.groups()) == 1:
            cur_keymap = res.group(1)
            keymaps[cur_keymap] = []
        elif re.match("^\),?", line):
            cur_keymap = None
        else:
            keycodes = list(
                filter(
                    lambda l: len(l) > 0,
                    [l.strip().removesuffix(",") for l in line.split(",")],
                )
            )
            if len(keycodes) > 0:
                keymaps[cur_keymap].append(keycodes)
    keymap_lens = [
        sum([len(row) for row in keymap_rows]) for keymap_rows in keymaps.values()
    ]
    if not all(i == keymap_lens[0] for i in keymap_lens):
        print("inconsistent keymap lengths. does your kemap compile?")
    longest_keycode = max(
        map(
            lambda keymap: max(
                map(lambda row: max(len(keycode) for keycode in row), keymap)
            ),
            keymaps.values(),
        )
    )
    keymap_buffs = []
    for keymap_name, keymap_rows in keymaps.items():
        buff = io.StringIO("")
        buff.write("[%s] = LAYOUT(\n\t\t" % (keymap_name))
        keycodes = []
        for i, keymap_row in enumerate(keymap_rows):
            keycodes.append(
                ",".join(
                    map(lambda keycode: keycode.ljust(longest_keycode), keymap_row)
                )
            )
        buff.write(",\n\t\t".join(keycodes))
        buff.write("\n\t)")
        keymap_buffs.append(buff)
    with open(".keymaps.txt", "w") as fout:
        fout.write(
            ",\n".join(map(lambda b: "\t" + b.getvalue(), [b for b in keymap_buffs]))
        )
    print(generate_layout(keymaps))

    print(generate_styles(COLORS))


def generate_styles(colors):
    classes = {}
    for i in range(len(colors)):
        classes[".keylabel%d>div" % (i)] = {"color": COLORS[i]}
    buff = io.StringIO("")
    for k, v in classes.items():
        buff.write(k)
        buff.write("{\n")
        for sk, sb in v.items():
            buff.write("\t%s: %s;" % (sk, sb))
        buff.write("\n}\n")
    # 0,2,6,8
    return buff.getvalue()


if __name__ == "__main__":
    main()
