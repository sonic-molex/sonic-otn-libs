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

rm -fr build; return_val
mkdir -p build; return_val
cd build; return_val

cmake ..; return_val
make -j4; return_val
make package; return_val
