#include <iostream>
#define MAXSIZE 1000
using namespace std;

int main(){
	short size = 0;
	int k = 0;
	int array[MAXSIZE];

	bool is_palindrome = true;
	
	do{
		cout << "Enter size of array: ";
		cin >> size;
	}while(size < 5 || size > 100);

	cout << size;

	for(int i=0; i < size; i++){

		cout << "Enter number " << i+1 << ": ";

		int buff[100];
		int buff_num = 0;
		int j = 0;

		cin >> buff_num;

		while(buff_num > 0){

			buff[j++] = buff_num % 10;
			buff_num /= 10;
		}
		
		for(; j > 0; j--){
			array[k++] = buff[j-1];
		}
	}

	for(int i=0; i < k/2; i++){
		// cout << i << " " << k-i-1 << "\n";
		if(array[i] != array[k-i-1]){
			is_palindrome = false;
			break;
		}
	}

	cout << (is_palindrome ? "Is palindrome" : "Is NOT palindrome") << "\n";

	return 0;

}