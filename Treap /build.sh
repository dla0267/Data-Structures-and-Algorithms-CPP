#!/bin/bash

# commands to compile c++ files using g++

g++ WordCount.cpp -o wordcount1

g++ tree.cpp node.cpp driver.cpp -o wordcount2

g++ -o3 WordCount.cpp -o wordcountOpt


sort wordcount.txt -o sortedwordcount.txt
sort testfile1000.txt -o sorted_test_1000.txt
sort testfile5000.txt -o sorted_test_5000.txt
sort testfile10000.txt -o sorted_test_10000.txt
