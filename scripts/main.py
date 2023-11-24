import argparse
import fmt
import io
import yaml

parser = argparse.ArgumentParser()
parser.add_argument("kb")
parser.add_argument("km")

args = parser.parse_args()

with open("layouts.yml", "r") as fin:
    config = yaml.load(fin, yaml.SafeLoader)


def get_keyboard_config():
    if config.get(args.kb) is None:
        print("available layouts:")
        [print(f"- {k}") for k in config.keys()]
        exit(1)
    if config[args.kb].get(args.km) is None:
        print("available layouts:")
        [print(f"- {k}") for k in config[args.kb].keys()]
        exit(1)
    return config[args.kb][args.km]


def main():
    kb = get_keyboard_config()
    w = io.StringIO("")
    for row in kb["rows"]:
        keylen = [float(k) for k in row.split(",") if k != ""]
        for k in keylen:
            w.write(fmt.fmt_key(fmt.NULL_KEY, k))
        w.write("\n")
    print(w.getvalue())


if __name__ == "__main__":
    main()
