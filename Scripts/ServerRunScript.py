import os
import subprocess
import sys
import time

cmd = "./lab4ca " + sys.argv[1]
print cmd
PIPE = subprocess.PIPE
p = subprocess.Popen(cmd, shell=True, stdin=PIPE, stdout=PIPE,
    stderr=subprocess.STDOUT, close_fds=True, cwd=os.path.abspath(os.curdir))
print p.stdout.read()