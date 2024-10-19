#! /usr/bin/python

import os
import sys
import random
import datetime

# 生成测试数组，存储到data.cpp中
if __name__ == "__main__":
    try:
        size = int(sys.argv[1])
    except ValueError, IndexError:
        print("usage error")
        sys.exit();

    with open("data.cpp", "w") as file:
        file.write("#include \"data.h\"\n")
        file.write("\n")
        file.write("int array[] = {\n")

        for i in range(size):
            num = random.randint(1, 1000000000)
            file.write("\t" + str(num) + ",\n")

        file.write("};\n")
