#include <iostream>

void testLCSTabulation();
void testPrintShortestSommonSupersequence();
void testLCSRecurrsion();
void testLCSMemoize();
void testLongestCommonSubstring();
void testLongestPalindromicSubsequence();
void testMinimumDeletionToMakePalindrome();
void testMinimumNumberOfInsertionAndDeletion();
void testPrintLCS();
void testShortestCommonSupersequence();
void testLongestRepeatingSubsequence();
void testMinimumNumberOfInsertionsToMakeAStringPalindrome();
void testSequencePatternMatching();

void testLCS() {
	testMinimumNumberOfInsertionsToMakeAStringPalindrome();
	testSequencePatternMatching();

	testLongestRepeatingSubsequence();
	testPrintShortestSommonSupersequence();
	testShortestCommonSupersequence();
	
	testMinimumNumberOfInsertionAndDeletion();
	testMinimumDeletionToMakePalindrome();
	testLongestPalindromicSubsequence();
	testLongestCommonSubstring();
	
	testPrintLCS();
	testLCSTabulation();
	testLCSMemoize();
	testLCSRecurrsion();
}