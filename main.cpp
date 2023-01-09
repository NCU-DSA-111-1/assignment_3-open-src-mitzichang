#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <time.h>
#include <iomanip>
#include "huffman.h"
#include "arithmetic.h"

using namespace std;

int main()
{
    char array[] = {'a', 'b', 'c', 'd', 'e'};
    int freq[] = { 5, 19, 12, 13, 45};
    int size = sizeof(array)/sizeof(array[0]);
    string s = "abcde";
   
    cout<<"\n--------------------------\n";
    cout<<"Start testing Huffman coding.\n";
    double startH,endH;
    startH = clock();
    HuffmanCodes(array, freq, size);
    endH = clock();
    cout << "Time for Huffman coding: " << double(endH-startH)/CLOCKS_PER_SEC << "s" << endl;


    cout<<"\n--------------------------\n";
    cout<<"Start testing Arithmetic coding.\n";

    int n;
	// cout<<"Enter number of characters: ";
	// cin>>n;
	unordered_map<char, node> arr;
	vector<char> ar;
	double range_from= 0;
	// cout<<"Enter frequency of each character:\n";
	for(int i=0; i<n; i++){
		// char ch;
		// cin>>ch;
		ar.push_back(array[i]);
		arr[array[i]].frequency = freq[i];
		arr[array[i]].range_from= range_from;
		arr[array[i]].range_to= range_from + arr[array[i]].frequency;
		range_from= arr[array[i]].range_to;
	}
	// cout<<"Symbol\tFrequency\tRange_from\tRange_to\n";
	// cout<<"----------------------------------------------------\n";
	// for(int i=0; i<ar.size(); i++){
	// 	char ch= ar[i];
	// 	cout<<ch<<"\t"<<arr[ch].frequency<<"\t\t"<<arr[ch].range_from<<"\t\t"<<arr[ch].range_to<<endl;
	// }
	// cout<<endl;
	// string s;
	// cout<<"Enter text: ";
	// cin>>s;
	
    double startA,endA;
    startA = clock();
    double code_word= encoding(arr, s);
    endA = clock();
	// cout<<"Code word for "<<s<<" is: "<<code_word<<endl;
    cout<<"Time for Arithmetic coding: "<<double(endA-startA)/CLOCKS_PER_SEC<<"s"<<endl;
    cout<<"\n--------------------------\n";
    // string text= decoding(arr, code_word, s.size());
	// cout<<"Text for "<<code_word<<" is: "<<text<<endl;
    

}
