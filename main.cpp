#include <iostream>
#include <fstream>
using namespace std;

int sBox[16][16];
int sBoxReverse[16][16];
int mul2[16][16];
int mul3[16][16];
int mul9[16][16];
int mul11[16][16];
int mul13[16][16];
int mul14[16][16];

void sBoxLoad() {
	ifstream inFile ; 
	inFile.open("sBox.txt");
	
	while(!inFile) {				 //Checking if the file is open or not
		cout << "Error opening the file" <<endl; 
		cout << "Try again: ";
		
		inFile.open("sBox.txt");
	}
	
	for (int row = 0; row < 16; row++) { 	//initialize the SBOX from a file
		for (int col = 0; col < 16; col ++) {
			inFile >> sBox[row][col]; 
		}
	}
	
	inFile.close();			//Close the opened file
	
}

void sBoxReverseLoad() {
	ifstream inFile ; 
	inFile.open("sBoxReverse.txt");
	
	while(!inFile) {				 //Checking if the file is open or not
		cout << "Error opening the file" <<endl; 
		cout << "Try again: ";
		
		inFile.open("sBoxReverse.txt");
	}
	
	for (int row = 0; row < 16; row++) { 	//initialize the SBOX from a file
		for (int col = 0; col < 16; col ++) {
			inFile >> sBoxReverse[row][col]; 
		}
	}
	
	inFile.close();			//Close the opened file
	
}

void mul2Load() {
	ifstream inFile ; 
	inFile.open("mul2.txt");
	
	while(!inFile) {				 //Checking if the file is open or not
		cout << "Error opening the file 2" <<endl; 
		cout << "Try again: ";
		
		inFile.open("mul2.txt");
	}
	
	for (int row = 0; row < 16; row++) { 	//initialize the SBOX from a file
		for (int col = 0; col < 16; col ++) {
			inFile >> mul2[row][col]; 
		}
	}
	
	inFile.close();			//Close the opened file
	
}

void mul3Load() {
	ifstream inFile ; 
	inFile.open("mul3.txt");
	
	while(!inFile) {				 //Checking if the file is open or not
		cout << "Error opening the file 3" <<endl; 
		cout << "Try again: ";
		
		inFile.open("mul3.txt");
	}
	
	for (int row = 0; row < 16; row++) { 	//initialize the SBOX from a file
		for (int col = 0; col < 16; col ++) {
			inFile >> mul3[row][col]; 
		}
	}
	
	inFile.close();			//Close the opened file
	
}

void mul9Load() {
	ifstream inFile ; 
	inFile.open("mul9.txt");
	
	while(!inFile) {				 //Checking if the file is open or not
		cout << "Error opening the file 9" <<endl; 
		cout << "Try again: ";
		
		inFile.open("mul9.txt");
	}
	
	for (int row = 0; row < 16; row++) { 	//initialize the SBOX from a file
		for (int col = 0; col < 16; col ++) {
			inFile >> mul9[row][col]; 
		}
	}
	
	inFile.close();			//Close the opened file
	
}

void mul11Load() {
	ifstream inFile ; 
	inFile.open("mul11.txt");
	
	while(!inFile) {				 //Checking if the file is open or not
		cout << "Error opening the file 11" <<endl; 
		cout << "Try again: ";
		
		inFile.open("mul11.txt");
	}
	
	for (int row = 0; row < 16; row++) { 	//initialize the SBOX from a file
		for (int col = 0; col < 16; col ++) {
			inFile >> mul11[row][col]; 
		}
	}
	
	inFile.close();			//Close the opened file
	
}

void mul13Load() {
	ifstream inFile ; 
	inFile.open("mul13.txt");
	
	while(!inFile) {				 //Checking if the file is open or not
		cout << "Error opening the file 11" <<endl; 
		cout << "Try again: ";
		
		inFile.open("mul13.txt");
	}
	
	for (int row = 0; row < 16; row++) { 	//initialize the SBOX from a file
		for (int col = 0; col < 16; col ++) {
			inFile >> mul13[row][col]; 
		}
	}
	
	inFile.close();			//Close the opened file
	
}

void mul14Load() {
	ifstream inFile ; 
	inFile.open("mul14.txt");
	
	while(!inFile) {				 //Checking if the file is open or not
		cout << "Error opening the file 14" <<endl; 
		cout << "Try again: ";
		
		inFile.open("mul14.txt");
	}
	
	for (int row = 0; row < 16; row++) { 	//initialize the SBOX from a file
		for (int col = 0; col < 16; col ++) {
			inFile >> mul14[row][col]; 
		}
	}
	
	inFile.close();			//Close the opened file
	
}

void XOR_ed(int message [4][4], int key[4][4]) {
	
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col ++) {
			message[row][col] = message[row][col] ^ key[row][col];
		}
	}
	
}

void subBytes(int message[4][4]) {
	int a = -1;
	int b = -1; 
	
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			
				a = message[row][col] / 16; 
				b = message[row][col] % 16; 
				message[row][col] = sBox[a][b];
			}
			
			
		}
}


void subBytesReverse(int message[4][4]) {
	int a = -1;
	int b = -1; 
	
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			
				a = message[row][col] / 16; 
				b = message[row][col] % 16; 
				message[row][col] = sBoxReverse[a][b];
			}
			
			
		}
}


void shiftRows (int message[4][4]) {
	int temp = message[1][0];
	message[1][0] = message[1][1];
	message[1][1] = message[1][2];
	message[1][2] = message[1][3];
	message[1][3] = temp;
	
	temp = message[2][0];
	message[2][0] = message[2][1];
	message[2][1] = message[2][2];
	message[2][2] = message[2][3];
	message[2][3] = temp; 
	
	temp = message[2][0];
	message[2][0] = message[2][1];
	message[2][1] = message[2][2];
	message[2][2] = message[2][3];
	message[2][3] = temp; 
	
	temp = message[3][0];
	message[3][0] = message[3][1];
	message[3][1] = message[3][2];
	message[3][2] = message[3][3];
	message[3][3] = temp; 
	
	temp = message[3][0];
	message[3][0] = message[3][1];
	message[3][1] = message[3][2];
	message[3][2] = message[3][3];
	message[3][3] = temp;
	
	temp = message[3][0];
	message[3][0] = message[3][1];
	message[3][1] = message[3][2];
	message[3][2] = message[3][3];
	message[3][3] = temp;
}

void shiftRowsReverse(int message[4][4]) {
	
	int temp = message[1][3];
	message[1][3] = message[1][2];
	message[1][2] = message[1][1];
	message[1][1] = message[1][0];
	message[1][0] = temp;
	
	
	temp = message[2][3];
	message[2][3] = message[2][2];
	message[2][2] = message[2][1];
	message[2][1] = message[2][0];
	message[2][0] = temp; 
	
	temp = message[2][3];
	message[2][3] = message[2][2];
	message[2][2] = message[2][1];
	message[2][1] = message[2][0];
	message[2][0] = temp; 
	
	
	temp = message[3][3];
	message[3][3] = message[3][2];
	message[3][2] = message[3][1];
	message[3][1] = message[3][0];
	message[3][0] = temp;
	
	temp = message[3][3];
	message[3][3] = message[3][2];
	message[3][2] = message[3][1];
	message[3][1] = message[3][0];
	message[3][0] = temp;
	
	temp = message[3][3];
	message[3][3] = message[3][2];
	message[3][2] = message[3][1];
	message[3][1] = message[3][0];
	message[3][0] = temp;
	
}

void mixColumns(int state[4][4]) {
	
	int temp[4][4];
	
	temp[0][0] = (mul2[state[0][0] / 16][state[0][0] % 16] ^ mul3[state[1][0] / 16][state[1][0] % 16] ^ state[2][0] ^ state[3][0]);
 	temp[1][0] = (state[0][0] ^ mul2[state[1][0] / 16][state[1][0] % 16] ^ mul3[state[2][0]/16][state[2][0]%16] ^ state[3][0]);
 	temp[2][0] = (state[0][0] ^ state[1][0] ^ mul2[state[2][0] / 16][state[2][0] % 16] ^ mul3[state[3][0] / 16][state[3][0] % 16]);
 	temp[3][0] = (mul3[state[0][0] / 16][state[0][0] % 16] ^ state[1][0] ^ state[2][0] ^ mul2[state[3][0] / 16][state[3][0] % 16]);
 	
 	temp[0][1] = (mul2[state[0][1] / 16][state[0][1] % 16] ^ mul3[state[1][1] / 16][state[1][1] % 16] ^ state[2][1] ^ state[3][1]);
 	temp[1][1] = (state[0][1] ^ mul2[state[1][1] / 16][state[1][1] % 16] ^ mul3[state[2][1]/16][state[2][1]%16] ^ state[3][1]);
 	temp[2][1] = (state[0][1] ^ state[1][1] ^ mul2[state[2][1] / 16][state[2][1] % 16] ^ mul3[state[3][1] / 16][state[3][1] % 16]);
 	temp[3][1] = (mul3[state[0][1] / 16][state[0][1] % 16] ^ state[1][1] ^ state[2][1] ^ mul2[state[3][1] / 16][state[3][1] % 16]);
 	
	temp[0][2] = (mul2[state[0][2] / 16][state[0][2] % 16] ^ mul3[state[1][2] / 16][state[1][2] % 16] ^ state[2][2] ^ state[3][2]);
 	temp[1][2] = (state[0][2] ^ mul2[state[1][2] / 16][state[1][2] % 16] ^ mul3[state[2][2]/16][state[2][2]%16] ^ state[3][2]);
 	temp[2][2] = (state[0][2] ^ state[1][2] ^ mul2[state[2][2] / 16][state[2][2] % 16] ^ mul3[state[3][2] / 16][state[3][2] % 16]);
 	temp[3][2] = (mul3[state[0][2] / 16][state[0][2] % 16] ^ state[1][2] ^ state[2][2] ^ mul2[state[3][2] / 16][state[3][2] % 16]);
 	
 	temp[0][3] = (mul2[state[0][3] / 16][state[0][3] % 16] ^ mul3[state[1][3] / 16][state[1][3] % 16] ^ state[2][3] ^ state[3][3]);
 	temp[1][3] = (state[0][3] ^ mul2[state[1][3] / 16][state[1][3] % 16] ^ mul3[state[2][3]/16][state[2][3]%16] ^ state[3][3]);
 	temp[2][3] = (state[0][3] ^ state[1][3] ^ mul2[state[2][3] / 16][state[2][3] % 16] ^ mul3[state[3][3] / 16][state[3][3] % 16]);
 	temp[3][3] = (mul3[state[0][3] / 16][state[0][3] % 16] ^ state[1][3] ^ state[2][3] ^ mul2[state[3][3] / 16][state[3][3] % 16]);
 	
 	for (int row = 0; row < 4; row++) {
 		for (int col = 0; col < 4; col ++) {
 			state[row][col] = temp[row][col]; 
		 }
	}
}

void mixColumnsReverse(int state[4][4]) {
	
	int temp[4][4];
	
	temp[0][0] = (mul14[state[0][0] / 16][state[0][0] % 16] ^ mul11[state[1][0] / 16][state[1][0] % 16] ^ mul13[state[2][0]/16][state[2][0] % 16] ^ mul9[state[3][0] / 16][state[3][0] % 16]);
 	temp[1][0] = (mul9[state[0][0] / 16][state[0][0] % 16] ^ mul14[state[1][0] / 16][state[1][0] % 16] ^ mul11[state[2][0]/16][state[2][0]%16] ^ mul13[state[3][0] / 16][state[3][0] % 16]);
 	temp[2][0] = (mul13[state[0][0] / 16][state[0][0] % 16] ^ mul9[state[1][0] / 16][state[1][0] % 16] ^ mul14[state[2][0] / 16][state[2][0] % 16] ^ mul11[state[3][0] / 16][state[3][0] % 16]);
 	temp[3][0] = (mul11[state[0][0] / 16][state[0][0] % 16] ^ mul13[state[1][0] / 16][state[1][0] % 16] ^ mul9[state[2][0] /16][state[2][0] % 16]^ mul14[state[3][0] / 16][state[3][0] % 16]);
 	
	temp[0][1] = (mul14[state[0][1] / 16][state[0][1] % 16] ^ mul11[state[1][1] / 16][state[1][1] % 16] ^ mul13[state[2][1] /16][state[2][1] % 16] ^ mul9[state[3][1] / 16][state[3][1] % 16]);
 	temp[1][1] = (mul9[state[0][1] / 16][state[0][1] % 16] ^ mul14[state[1][1] / 16][state[1][1] % 16] ^ mul11[state[2][1] /16][state[2][1] %16] ^ mul13[state[3][1] / 16][state[3][1] % 16]);
 	temp[2][1] = (mul13[state[0][1] / 16][state[0][1] % 16] ^ mul9[state[1][1] /16][state[1][1] % 16] ^ mul14[state[2][1] / 16][state[2][1] % 16] ^ mul11[state[3][1] / 16][state[3][1] % 16]);
 	temp[3][1] = (mul11[state[0][1] / 16][state[0][1] % 16] ^ mul13[state[1][1] / 16][state[1][1] % 16]^ mul9[state[2][1] /16][state[2][1] % 16]^ mul14[state[3][1] / 16][state[3][1] % 16]);

	temp[0][2] = (mul14[state[0][2] / 16][state[0][2] % 16] ^ mul11[state[1][2] / 16][state[1][2] % 16] ^ mul13[state[2][2] /16][state[2][2] % 16] ^ mul9[state[3][2] / 16][state[3][2] % 16]);
 	temp[1][2] = (mul9[state[0][2] / 16][state[0][2] % 16] ^ mul14[state[1][2] / 16][state[1][2] % 16] ^ mul11[state[2][2] /16][state[2][2] %16] ^ mul13[state[3][2] / 16][state[3][2] % 16]);
 	temp[2][2] = (mul13[state[0][2] / 16][state[0][2] % 16] ^ mul9[state[1][2] /16][state[1][2] % 16] ^ mul14[state[2][2] / 16][state[2][2] % 16] ^ mul11[state[3][2] / 16][state[3][2] % 16]);
 	temp[3][2] = (mul11[state[0][2] / 16][state[0][2] % 16] ^ mul13[state[1][2] / 16][state[1][2] % 16]^ mul9[state[2][2] /16][state[2][2] % 16]^ mul14[state[3][2] / 16][state[3][2] % 16]);	
	 
	temp[0][3] = (mul14[state[0][3] / 16][state[0][3] % 16] ^ mul11[state[1][3] / 16][state[1][3] % 16] ^ mul13[state[2][3] / 16][state[2][3] % 16] ^ mul9[state[3][3] / 16][state[3][3] % 16]);
 	temp[1][3] = (mul9[state[0][3] / 16][state[0][3] % 16] ^ mul14[state[1][3] / 16][state[1][3] % 16] ^ mul11[state[2][3] / 16][state[2][3]%16] ^ mul13[state[3][3] / 16][state[3][3] % 16]);
 	temp[2][3] = (mul13[state[0][3] / 16][state[0][3] % 16] ^ mul9[state[1][3] /16][state[1][3] % 16] ^ mul14[state[2][3] / 16][state[2][3] % 16] ^ mul11[state[3][3] / 16][state[3][3] % 16]);
 	temp[3][3] = (mul11[state[0][3] / 16][state[0][3] % 16] ^ mul13[state[1][3] / 16][state[1][3] % 16]^ mul9[state[2][3] / 16][state[2][3] % 16]^ mul14[state[3][3] / 16][state[3][3] % 16]);
	
 	
 	for (int row = 0; row < 4; row++) {
 		for (int col = 0; col < 4; col ++) {

 			state[row][col] = temp[row][col]; 
		 }
	}


}

void roundKey(int message[4][4]) {

	int temp = message[0][3];
	message[0][3] = message[1][3];
	message[1][3] = message[2][3];
	message[2][3] = message[3][3];
	message[3][3] = temp;
	
	
	message[0][3] = sBox[message[0][3] / 16][message[0][3] % 16];
	message[1][3] = sBox[message[1][3] / 16][message[1][3] % 16];
	message[2][3] = sBox[message[2][3] / 16][message[2][3] % 16];
	message[3][3] = sBox[message[3][3] / 16][message[3][3] % 16];
	
	message[0][0] ^= message[0][3] ^ 1; 
	message[1][0] ^= message[1][3] ^ 1;
	message[2][0] ^= message[2][3] ^ 1;
	message[3][0] ^= message[3][3] ^ 1;
	
	message[0][1] ^= message[0][0];
	message[1][1] ^= message[1][0];
	message[2][1] ^= message[2][0];
	message[3][1] ^= message[3][0];
	
	message[0][2] ^= message[0][1];
	message[1][2] ^= message[1][1];
	message[2][2] ^= message[2][1];
	message[3][2] ^= message[3][1];
	
	message[0][3] ^= message[0][2];
	message[1][3] ^= message[1][2];
	message[2][3] ^= message[2][2];
	message[3][3] ^= message[3][2];
	
	
}

void reverseRoundKey(int message[4][4]) {
	
	message[0][3] ^= message[0][2];
	message[1][3] ^= message[1][2];
	message[2][3] ^= message[2][2];
	message[3][3] ^= message[3][2];
	
	message[0][2] ^= message[0][1];
	message[1][2] ^= message[1][1];
	message[2][2] ^= message[2][1];
	message[3][2] ^= message[3][1];
	
	message[0][1] ^= message[0][0];
	message[1][1] ^= message[1][0];
	message[2][1] ^= message[2][0];
	message[3][1] ^= message[3][0];
	
	message[0][0] ^= message[0][3] ^ 1; 
	message[1][0] ^= message[1][3] ^ 1;
	message[2][0] ^= message[2][3] ^ 1;
	message[3][0] ^= message[3][3] ^ 1;
	
	message[0][3] = sBoxReverse[message[0][3] / 16][message[0][3] % 16];
	message[1][3] = sBoxReverse[message[1][3] / 16][message[1][3] % 16];
	message[2][3] = sBoxReverse[message[2][3] / 16][message[2][3] % 16];
	message[3][3] = sBoxReverse[message[3][3] / 16][message[3][3] % 16];
	
	
	int temp = message[3][3];
	message[3][3] = message[2][3];
	message[2][3] = message[1][3];
	message[1][3] = message[0][3];
	message[0][3] = temp; 
	
	
}

void AES_Encrypt(int message[4][4], int key[4][4]) {
	
	//First Round
	XOR_ed(message, key);
	
	//Second - N Rounds
	for (int i = 0; i < 11; i++) {
		subBytes(message);
		shiftRows(message);
		mixColumns(message);
		roundKey(key);
		XOR_ed(message, key);
	}
	
	//Round N + 1
	subBytes(message);
	shiftRows(message);
	roundKey(key);
	XOR_ed(message, key);
}

void AES_Decrypt(int message[4][4], int key[4][4]) {
	
	//First Round
	XOR_ed(message, key);
	reverseRoundKey(key);
	shiftRowsReverse(message);
	subBytesReverse(message);
	
	//Second - N Rounds
	for (int i = 0; i < 11; i++) {
		XOR_ed(message, key);
		reverseRoundKey(key);
		mixColumnsReverse(message);
		shiftRowsReverse(message);
		subBytesReverse(message);
	}
	//N+1 Round
	XOR_ed(message, key);
}
int main () {

	string message = ""; 
	string key = ""; 
	ifstream inFile;
	ofstream outFile; 
	int tableMessage[4][4];
	int tableKey [4][4]; 
	int savedCopyKey[4][4]; 
	
	sBoxLoad();  						//loading the sBoxes and mul tables
	sBoxReverseLoad();  
	mul2Load();
	mul3Load();				
	mul9Load();
	mul11Load();
	mul13Load();
	mul14Load();
	
	
	string menu;
	
	cout << "Press 1 to encrypt a message, or anything else to decrypt a message: ";
	getline(cin, menu);
	
	int index = 0; 
	int size = 0; 
	if (menu == "1") {
		
			
			//Prompting the user for message and the key	
			cout << "Please, enter the message you would like to encrypt(18 bytes): "; 				
			getline(cin, message); 
			cout << "Please, enter the key(16 bytes): ";											
			getline(cin, key); 
			
			//Checking the if the key is the right size
			//If the key is larger, only the first 16 bytes will be used
			while (key.size() < 16) {
				cout << "The key is too short, insert another key" <<endl;
				getline(cin, key); 
			}
			
			//Checking if padding is needed for the message
			//16 bytes messages only
			size = message.size() % 16;
			
			char temp = 'z'; 
			if (size != 0) {
				for (size; size < 16; size++) {
					message.push_back(temp);
					temp = temp -1; 
				}
			}
			
			//Opening the file
			outFile.open("ctext.txt");
			
			//Checking if the file is open
			while(!outFile) {				 
				cout << "Error opening the file" <<endl; 
				cout << "Try again: ";
				outFile.open("ctext.txt");
			} 

			index = 0;
			for (int row = 0; row < 4; row++) {
				for (int col = 0; col < 4; col ++) { 
					tableKey[row][col] = key.at(index); 
					index++;
				}
			}
			
			index = 0;
			//Changing the key and message to int
			size = message.size() / 16;
			for (int i = 0; i < size; i++) {
				for (int row = 0; row < 4; row++) {
					for (int col = 0; col < 4; col ++) {  
						tableMessage[row][col] = message.at(index); 
						index++;
					}
				}
				cout << endl;
				
				int k = 0; 
				for (int row = 0; row < 4; row++) {
					for (int col = 0; col < 4; col ++) { 
						tableKey[row][col] = key.at(k); 
						k++;
					}
				}
			
				//Encrypting the message	
				AES_Encrypt(tableMessage, tableKey); 
			
				//Printing the message to the files
				for (int row = 0; row < 4; row++) {
					for (int col = 0; col < 4; col ++) { 
						outFile << tableMessage[row][col] << " "; 
					}
					outFile << endl;
				}
				
				for (int row = 0; row < 4; row++) {
					for (int col = 0; col < 4; col ++) { 
						cout << (char)tableMessage[row][col] << " "; 
					}
				}
			}
			//Closing the file
			outFile.close();
				
					
			//Opening the file key, to store the key
			outFile.open("Key.txt");
		
			//Checking if the file is open or not
			while(!outFile) {				 
				cout << "Error opening the file" <<endl; 
				cout << "Try again: ";
				outFile.open("Key.txt");
			}
			
			outFile << size << " "; 
			//Printing the key to the file
			for (int row = 0; row < 4; row++) {
				for (int col = 0; col < 4; col ++) { 
					outFile << tableKey[row][col] << " "; 
					index++;
				}
			}
			
			//Closing the file
			outFile.close(); 
	}
	else {
			int size = 0; 
			
			//Opening the key file 
			inFile.open("Key.txt");
			
			//Checking if the file is open or not
			while(!inFile) {				 							
				cout << "Error opening the file" <<endl; 
				cout << "Try again: ";
				inFile.open("Key.txt");
			}
			
			inFile >> size; 
			//Getting input from the file 
			for (int row = 0; row < 4; row++) {
				for (int col = 0; col < 4; col ++) { 
					inFile >> tableKey[row][col]; 
				}
			}
			
			//Closing the file
			inFile.close();
			
			for (int row = 0; row < 4; row++) {
				for (int col = 0; col < 4; col ++) { 
					savedCopyKey[row][col] = tableKey[row][col];
				}
			}
			
			//Opening the message file
			inFile.open("ctext.txt");
			
			//Checking if the file is open or not
			while(!inFile) {				 							
				cout << "Error opening the file" <<endl; 
				cout << "Try again: ";
				inFile.open("ctext.txt");
			}
		
			//WHile the end of the file isn't reached, keep getting input
			for (int i = 0; i < size; i++) {
				for (int row = 0; row < 4; row++) {
					for (int col = 0; col < 4; col ++) { 
						inFile >> tableMessage[row][col];
						//delete here
					}
				}
								
				for (int row = 0; row < 4; row++) {
					for (int col = 0; col < 4; col ++) { 
						tableKey[row][col] = savedCopyKey[row][col];
					}
				}
				//Decrypting the message
				AES_Decrypt(tableMessage, tableKey);

				//Printing the message out
				for (int row = 0; row < 4; row++) {
					for (int col = 0; col < 4; col ++) { 
						cout << (char)tableMessage[row][col]; 
					}
				}
			}
			//Closing the file
			inFile.close();
		}			
	return 0;
}
