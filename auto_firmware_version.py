import subprocess

Import("env")

def get_firmware_specifier_build_flag():
    #ret = subprocess.run(["git", "describe"], stdout=subprocess.PIPE, text=True) #Uses only annotated tags
    #ret = subprocess.run(["git", "describe", "--tags"], stdout=subprocess.PIPE, text=True) #Uses any tags
    ret = subprocess.run(["git", "rev-parse", "--short", "HEAD"], stdout=subprocess.PIPE, text=True) #show commit point
    #build_version = ret.stdout.strip()
    commit_pt = ret.stdout.strip()
    build_flag = "-D AUTO_COMMITPT=\\\"" + commit_pt + "\\\""
    #print ("Firmware Revision: " + build_version)
    print ("Firmware Commit: " + commit_pt)
    return (build_flag)

env.Append(
    BUILD_FLAGS=[get_firmware_specifier_build_flag()]
)
