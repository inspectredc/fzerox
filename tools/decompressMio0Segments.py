import sys
import os
import shutil
from subprocess import run

def main(argv):
    version = argv[0]
    revision = argv[1]
    tools_dir = os.path.dirname(os.path.realpath(__file__))
    mio0 = os.path.join(tools_dir, "mio0")
    root_dir = os.path.join(tools_dir, "..")
    mio0_dir = os.path.join(root_dir, os.path.join("bin", os.path.join(version, os.path.join(revision, "mio0"))))
    out_dir = os.path.join(root_dir, os.path.join("mio0", os.path.join(version, revision)))
    if not os.path.exists(out_dir):
        os.makedirs(out_dir)

    for bin in os.listdir(mio0_dir):
        print("Decompressing: " + bin)
        mio0in = os.path.join(mio0_dir, bin)
        mio0out = os.path.join(out_dir, os.path.splitext(bin)[0] + ".mio0d")
        run([mio0, "-d", mio0in, mio0out])

    sys.exit()

if __name__ == "__main__":
    main(sys.argv[1:])
