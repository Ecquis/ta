with open("base.csv",'r') as fi, open("base100000.csv",'w') as fo:
    for i in range(100000):
        fo.write(fi.readline())
