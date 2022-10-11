#!/usr/bin/env python3
# pps.py
# Glenn G. Chappell
# 2022-10-10
"""Source file for function pretty_print_square"""


def pretty_print_square(n):
    """n -> print square of n in a box of asterisks.

    >>> pretty_print_square(5)
    ******
    *    *
    * 25 *
    *    *
    ******
    >>> pretty_print_square(-1)
    *****
    *   *
    * 1 *
    *   *
    *****
    >>> pretty_print_square(111)
    *********
    *       *
    * 12321 *
    *       *
    *********

    """
    assert isinstance(n, int)

    sq = n*n
    sqlen = len(str(sq))
    print("*" * (sqlen+4))
    print("*" + " " * (sqlen+2) + "*")
    print("* " + str(sq) + " *")
    print("*" + " " * (sqlen+2) + "*")
    print("*" * (sqlen+4))


def run():
    num = 42
    print(f"The square of {num}:")
    print()
    pretty_print_square(num)


def do_tests(verboseflag):
    import doctest
    print("Running doctests (", end="")
    if not verboseflag:
        print("non-", end="")
    print("verbose mode)")
    doctest.testmod(verbose=verboseflag)


if __name__ == "__main__":
    import sys
    import getopt
    testflag = 0
    try:
        opts, args = getopt.getopt(sys.argv[1:], "tT", ["test", "Test"])
        if args:
            print("pps.py: extra command-line argument(s)",
                  file=sys.stderr)
            sys.exit(2)
        for o, a in opts:
            if o in ["-t", "--test"]:
                testflag = 1
            if o in ["-T", "--Test"]:
                testflag = 2
    except getopt.error as err:
        print(f"pps.py: {err}", file=sys.stderr)
        sys.exit(2)

    if testflag == 1:
        do_tests(verboseflag=False)
    elif testflag == 2:
        do_tests(verboseflag=True)
    else:  # testflag == 0
        run()

