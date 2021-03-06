#!/usr/bin/python

import random, sys, string, argparse
from optparse import OptionParser


class randline:
    def __init__(self, filename, lo_hi, arr, stdin_file):
        if lo_hi:
            self.lines = arr
        elif filename == "NA":
            self.lines = stdin_file
            if (len(self.lines) <= 0):
                return 0
        else:
            f = open(filename, 'r')
            self.lines = f.readlines()
            f.close()

    def chooseline(self):
        return random.choice(self.lines)

    def chooseline2(self):
        word = random.choice(self.lines)
        self.lines.remove(word)
        return word


def main():
    version_msg = "%prog 2.0"
    usage_msg = """%prog [OPTION]... [FILE]
  or:  shuf -i LO-HI [OPTION]...
Write a random permutation of the input lines to standard output."""

    parser = OptionParser(version=version_msg,
                          usage=usage_msg)
    # parser.add_option("-n", "--numlines",
    #                   action="store", dest="numlines", default=1,
    #                   help="output NUMLINES lines (default 1)")
    parser.add_option("-i", "--input-range",
                      action="store", dest="lo_hi", default=False,
                      help="treat each number LO through HI as an input line")
    parser.add_option("-r", "--repeat",
                      action="store_true", dest="repeat", default=False,
                      help="output lines can be repeated")
    parser.add_option("-n", "--head-count",
                      action="store", dest="count", default=sys.maxsize,
                      help="output at most COUNT lines")
    options, args = parser.parse_args(sys.argv[1:])
    
    lohiArr = []
    stdin_file = []
    file_count = 0
    
    try:
        count = int(options.count)
    except:
        print("shuf: invalid line count '"+options.count+"'")
        exit(1)
#        parser.error("invalid line count: {0}".
#                     format(options.count))
    if count < 0:
        print("shuf: invalid line count '"+options.count+"'")
        exit(1)
#        parser.error("invalid line count: {0}".
#                     format(count))

    if options.lo_hi:
        try:
            nums = options.lo_hi.split("-")
            num1 = int(nums[0])
            num2 = int(nums[1])
        except:
            print("shuf: invalid input range '" + str(options.lo_hi) + "'")
#            parser.error("invalid input range: '" + str(options.lo_hi) + "'".
#                         format(options.lo_hi))
            exit(1)
        if num2+1 < num1:
            print("shuf: invalid input range '" + str(options.lo_hi) + "'")
            exit(1)
        while num1 <= num2:
            lohiArr.append(str(num1) + '\n')
            num1 += 1
    elif len(args) > 1:
        print("shuf: number of operands not match")
        exit(1)
#        parser.error("Number of operands not match!")

    try:
        input_file = args[0]
    except:
        input_file = "NA"

    if input_file == "-":
        input_file = "NA"

    if options.lo_hi and input_file != "NA":
        print("Segmentation fault")
        exit(139)

    if options.lo_hi:
        file_count = len(lohiArr)
    elif input_file != "NA":
        try:
            with open(input_file, 'r') as file:
                for i in file:
                    file_count += 1
        except IOError as err:
            print("shuf: "+input_file+": No such file or directory")
            exit(1)
    else:
        stdin_file = sys.stdin.readlines()
        for i in stdin_file:
            file_count += 1

    if file_count < count and not options.repeat:
        count = file_count
    
#    if not options.lo_hi and not options.repeat:
#        print("invalid option!")
#        exit(1)

        #parser.error("invalid option!")
        # if len(args) != 1:
        #     parser.error("wrong number of operands")
#    input_file = args[0]

    try:
        generator = randline(input_file, options.lo_hi, lohiArr, stdin_file)
        i = 0
        while i < count:
            if options.repeat:
                sys.stdout.write(generator.chooseline())
            else:
                sys.stdout.write(generator.chooseline2())
            i += 1
    except IOError as err:
        errno, strerror = e.args
        parser.error("I/O error({0}): {1}".
                     format(errno, strerror))

if __name__ == "__main__":
    main()
