import argparse
import io
import keyboards

GMMK2 = "gmmk2"
ANC = "anc"

parser = argparse.ArgumentParser()
parser.add_argument("keyboard", choices=[GMMK2, ANC])
parser.add_argument("-i", "--input", type=str, default="input.txt")
args = parser.parse_args()


def main():
    if args.keyboard == GMMK2:
        keyboards.QMMK2().run(args.input)
    if args.keyboard == ANC:
        keyboards.ANC().run(args.input)


if __name__ == "__main__":
    main()
