#! /bin/bash


# comparing the result between BST and Treap

diff BSTOutput5000.txt TreapOutput5000.txt
diff BSTOutput.txt Treapoutput.txt
diff Treapoutput.txt wordcount_output.txt


sort -u wordcount.txt sortedwordcount.txt

sort -u testfile5000.txt sorted_test_5000.txt


./wordcount2 < sorted_text_5000.txt > Treap_sorted_5000.txt 2> structure1.txt
./wordcount1 < sorted_text_5000.txt > BST_sorted_5000.txt 2> structure2.txt
./wordcountOpt < sorted_text_5000.txt > Opt_BST_sorted_5000.txt 2> structure3.txt

diff Treap_sorted_5000.txt BST_sorted_5000.txt
diff BST_sorted_5000.txt Opt_BST_sorted_5000.txt


