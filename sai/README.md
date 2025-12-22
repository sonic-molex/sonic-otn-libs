## Description
Build shared libraries in Debian packages for:
- ``libsaiotn-$(version)-amd64.debs``: Vendor implementation of SONiC SAI API for otn-kvm platform.

## Build instruction
```
cd sai
mkdir build
cd build
cmake .. -DSONIC_PATH={SONIC_BUILD_IMAGE_PATH}
make -j4
make package
```

For how to specify sonic build-image path, please refer to the below example:
e.g.
cmake .. -DSONIC_PATH=/home/sonic/sonic/sonic-buildimage
