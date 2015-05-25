import os
import sys
import subprocess


cmd = "./Tests"
PIPE = subprocess.PIPE
p = subprocess.Popen(cmd, shell=True, stdin=PIPE, stdout=PIPE,
    stderr=subprocess.STDOUT, close_fds=True, cwd=os.path.abspath(os.curdir))
print p.stdout.read()

