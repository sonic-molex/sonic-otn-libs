#!/bin/bash

python3 setup.py --command-packages=stdeb.command bdist_deb

DEB_OLD_NAME=`ls deb_dist | grep .deb$`
DEB_NEW_NAME=${DEB_OLD_NAME/python3-/}
DEB_NEW_NAME=${DEB_NEW_NAME/1_all/amd64}
DEB_NEW_NAME=${DEB_NEW_NAME//_/-}

cp -f deb_dist/${DEB_OLD_NAME} ./${DEB_NEW_NAME}

rm -rf deb_dist
rm -rf dist
rm -rf *.egg-info
rm -f *.tar.gz