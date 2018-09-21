#! /bin/bash


echo "BST Performance"
echo "Random 5,000 words: "
time ./wordcount1 < testfile5000.txt > BSTOutput5000.txt

echo "Random 10,000 words: "
time ./wordcount1 < testfile10000.txt > BSTOutput10000.txt

echo "Random 50,000 words: "
time ./wordcount1 < testfile50000.txt > BSTOutput500000.txt

echo "Random 100,000 words: "
time ./wordcount1 < testfile100000.txt > BSTOutput100000.txt

echo "Random 500,000 words: "
time ./wordcount1 < testfile500000.txt > BSTOutput500000.txt

echo "Treap Performance"
echo "Random 5,000 words: "
time ./wordcount2 < testfile5000.txt > TreapOutput5000.txt

echo "Random 10,000 words: "
time ./wordcount2 < testfile10000.txt > TreapOutput10000.txt

echo "Random 50,000 words: "
time ./wordcount2 < testfile50000.txt > TreapOutput50000.txt

echo "Random 100,000 word: "
time ./wordcount2 < testfile100000.txt > TreapOutput100000.txt

echo "Random 500,000 words: "
time ./wordcount2 < testfile500000.txt > TreapOutput500000.txt

# Sorted 

echo "sorted input text filet"
echo "Using BST"
echo "sorted word count"
time ./wordcount1 < sortedwordcount.txt > BSTsorted_wordcount.txt

echo "1000 words:"
time ./wordcount1 < sorted_test_1000.txt > BSTsorted_1000.txt

echo "5000 words:"
time ./wordcount1 < sorted_test_5000.txt > BSTsorted_5000.txt

echo "10000 words:"
time ./wordcount1 < sorted_test_10000.txt > BSTsorted_10000.txt

echo "Using optimized BST"
echo "wordcount.txt"
time ./wordcountOpt < sortedwordcount.txt > Optsorted_wordcount.txt

echo "1000 words"
time ./wordcountOpt < sorted_test_1000.txt > Optsorted_1000.txt

echo "5000 words:"
time ./wordcountOpt < sorted_test_5000.txt > Optsorted_5000.txt

echo "10000 words:"
time ./wordcountOpt < sorted_test_10000.txt > Optsorted_10000.txt

echo "using Treap"

echo "wordcount.txt"
time ./wordcount2 < sortedwordcount.txt > Treap_sorted_wordcount.txt

echo "1000 words"
time ./wordcount2 < sorted_test_1000.txt > Treap_sorted1000.txt

echo "5000 words"
time ./wordcount2 < sorted_test_5000.txt > Treap_sorted5000.txt

echo "10000 words"
time ./wordcount2 < sorted_test_10000.txt > Treap_sorted10000.txt






