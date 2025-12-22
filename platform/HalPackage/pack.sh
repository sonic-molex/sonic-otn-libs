#!/bin/bash

####  check execute result
function return_val()
{
    val=`echo $?`
    if test $val -ne 0;then
        echo "#########  `pwd` is ERROR..."
        exit -1
    fi
}

if [ $# -ne 1 ]; then
    echo "Error, platform model is mandatory"
    exit -1
fi

rm -fr build; return_val
mkdir -p build; return_val
cd build; return_val



cmake ..; return_val
make package; return_val

DEB_OLD_NAME=`ls | grep .deb$`
DEB_NEW_NAME=${DEB_OLD_NAME/model/$1}

mv ${DEB_OLD_NAME} ${DEB_NEW_NAME}