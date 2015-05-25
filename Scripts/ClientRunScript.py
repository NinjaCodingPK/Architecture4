import os
import time
import subprocess
import sys

cmd = "./aclient " + sys.argv[1] + " " + sys.argv[2]
print cmd

start = time.time()
count = 20
for i in range(count):
    #time.sleep(1/2)
    # print cmd
    PIPE = subprocess.PIPE
    p = subprocess.Popen(cmd, shell=True, stdin=PIPE, stdout=PIPE,
        stderr=subprocess.STDOUT, close_fds=True, cwd=os.path.abspath(os.curdir))
    print "Client", i, "return: ", p.stdout.read()

final = time.time()
print "Time: ", final - start

