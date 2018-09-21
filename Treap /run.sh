#!/bin/bash

echo "test BST"
time ./wordcount1 < testfile5000.txt > BSTOutput5000.txt 2> structure.txt
time ./wordcount1 < sorted_text_5000.txt > BSTsorted5000.txt 2> structure2.txt

echo "test opt-BST"
time ./wordcountOpt < testfile5000.txt > BSToptOutput5000.txt 2> opt_structure.txt
time ./wordcountOpt < sorted_text_5000.txt > BSToptsorted5000.txt 2> opt_structure2.txt

echo "test Treap"
time ./wordcount2 < testfile5000.txt > TreapOutput5000.txt 2> Treap_structure.txt
time ./wordcount2 < sorted_text_5000.txt > Treapsorted5000.txt 2> Treap_structure2.txt

echo "BST sorted"
time ./wordcount1 < sortedwordcount.txt > BSTsorted_word.txt 2> structure8.txt 
time ./wordcount1 < sorted_text_5000.txt > BSTsorted5000.txt 2> structure4.txt

echo "opt sorted"
time ./wordcountOpt < sortedwordcount.txt > BSToptsortedword.txt 2> opt_structure8.txt
time ./wordcountOpt < sorted_text_5000.txt > BSToptsorted5000.txt 2> opt_sturcture4.txt

echo "treap sorted"
time ./wordcount2 < sortedwordcount.txt > Treapsorted_wordcount.txt 2> Treap_structure8.txt
time ./wordcount2 < sorted_text_5000.txt > Treapsorted5000.txt 2> Treap_structure4.txt
