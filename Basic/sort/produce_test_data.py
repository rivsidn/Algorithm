#! /usr/bin/python

import os
import sys
import random
import datetime

# 生成数据输出到文件中
def output_data(size, ffname):
    with open(ffname, "w") as file:
        for i in range(size):
            num = random.randint(1, 1000000000)
            file.write(str(num) + "\n")

# 根据数据大小生成文件名(size_date.data)
def filename(size):
    return str(size) + ".data"

def full_filename(dname, fname):
    return dname + "/" + fname

# 每次生成数据在所在目录下记录一下时间戳
def update_time_stamp(dname):
    time = datetime.datetime.now()
    time_stamp_file = dname + "/" + "time.stamp"
    with open(time_stamp_file, "w") as file:
        file.write(str(time)+"\n")

sizes_tuple = (1,2,3,4,5,6,7,8,9,10, 100, 1000, 10000, 100000, 1000000, 10000000)

# 将生成的文件存储到data目录中，后缀为.data
if __name__ == "__main__":
    dname = "data"
    # 生成data目录
    os.makedirs(dname, exist_ok=True)
    # 更新时间戳
    update_time_stamp(dname)
    # 生成测试数据
    for size in sizes_tuple:
        ffname = full_filename(dname, filename(size))
        output_data(size, ffname)
