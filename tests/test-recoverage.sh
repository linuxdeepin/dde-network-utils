#!/bin/bash

BUILD_DIR=build
REPORT_DIR=report
#EXTRACT_ARGS="src"

cd ../
rm -rf $BUILD_DIR
mkdir $BUILD_DIR
cd $BUILD_DIR
qmake ../dde-network-utils/
make

cd ../tests/
rm -rf $BUILD_DIR
mkdir $BUILD_DIR
cd $BUILD_DIR
qmake ../dde-network-utils/
TESTARGS="--gtest_output=xml:dde_test_report_network_utils.xml"  make check -j$(nproc)

lcov -d ./ -c -o coverage_all.info
#lcov --extract coverage_all.info $EXTRACT_ARGS --output-file coverage.info
lcov --remove coverage_all.info "*/tests/*" "*/usr/include*" "*build/src*" --output-file coverage.info
cd ..
genhtml -o $REPORT_DIR $BUILD_DIR/coverage.info
#rm -rf $BUILD_DIR
#rm -rf ../$BUILD_DIR
[ -e ./$BUILD_DIR/asan.log* ] && mv ./$BUILD_DIR/asan.log* ./$BUILD_DIR/asan_dde-network-utils.log || touch ./$BUILD_DIR/asan_dde-network-utils.log
#mv ./$BUILD_DIR/asan.log* ./$BUILD_DIR/asan_dde-network-utils.log