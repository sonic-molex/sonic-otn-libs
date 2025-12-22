# platform

## Environment
### Install python setuptools with specified version 45.2.0
```
pip install setuptools==45.2.0

pip show setuptools | grep Version
Version: 45.2.0
```

### Install stdeb
```
pip install stdeb
```


## Build
Run build.sh to build depended libraries and debian package.

    ./build.sh
    
The debian package will be released to release folder.

## Description
Build shared libraries in Debian packages for:
- ``libhal-$(model)-$(version)-amd64.deb``: basic hardware driver for OTN kvm platform
- ``libhalplatformclient-otn-$(version)-amd64.deb``: lib called by sonic-platform python classes