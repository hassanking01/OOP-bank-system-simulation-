#include <iostream>
#include <vector>
using namespace std;
#pragma once
class clsUtil
{
private:



public:
	enum TypeCharacter
	{
		lowrcas = 1,
		upercase = 2,
		digits = 3,
		mix = 4,
		spatiolchars = 5

	};
	static void Srand() {
		srand((unsigned)time(NULL));
	}
	static int randomNumber(int from, int to) {
		int num = rand() % (to - from + 1) + from;
		return num;
	}
	static char GetRandomeCharacter(TypeCharacter c) {
		switch (c)
		{
		case clsUtil::lowrcas:
			return char(randomNumber(97, 122));

			break;
		case clsUtil::upercase:
			return char(randomNumber(65, 90));
			break;
		case clsUtil::digits:
			return char(randomNumber(48, 57));
			break;
		case clsUtil::mix:
			char c[3];
			c[0] = randomNumber(97, 122);
			c[1] = randomNumber(65, 90);
			c[2] = randomNumber(48, 57);
			return c[randomNumber(0, 2)];
			break;
		case clsUtil::spatiolchars:
			char u[4];
			u[0] = randomNumber(33, 47);
			u[1] = randomNumber(58, 64);
			u[2] = randomNumber(91, 96);
			u[3] = randomNumber(123, 126);
			return u[randomNumber(0, 3)];
			break;
		default:
			break;
		}
	}
	static string genaritWord(TypeCharacter c, int length) {
		string str = "";
		for (int i = 0; i < length; i++) {
			str += GetRandomeCharacter(c);
		}
		return str;
	}
	static string genireatKey(TypeCharacter c) {
		string str = "";
		for (int i = 0; i < 5; i++) {
			str += genaritWord(c, 5) + "-";
		}
		str = str.substr(0, str.length() - 1);
		return str;
	}
	static vector <string> GenerateKeys(TypeCharacter c, int numberOfKeys) {
		vector<string> strarr;
		string str;
		for (int i = 0; i < numberOfKeys; i++) {
			str = genireatKey(c);
			strarr.push_back(str);
			str = "";
		}
		return strarr;
	}
	static void fillArrayWithRandomNumbers(int arr[100], int length, int from, int to) {
		int num; 
		for (int i = 0; i < length; i++) {
			num = randomNumber(from, to);
			arr[i] = num;
		}
	}
	static void fillArrayWithRandomWords(string arr[100], int arraylenght, TypeCharacter c, int wordlinght) {
		string str;
		for (int i = 0; i < arraylenght; i++) {
			str = genaritWord(c, wordlinght);
			arr[i] = str;
		}
	}
	static void fillArrayWithRandomKey(string arr[100], int arraylenght, TypeCharacter c) {
		string str;
		for (int i = 0; i < arraylenght; i++) {
			str = genireatKey(c);
			arr[i] = str;
		}
	}
	static void Swap(int& A, int &B) {
		int temp;
		temp = A;
		A = B;
		B = temp;

	}
	static void Swap(string &A, string& B) {
		string temp;
		temp = A;
		A = B;
		B = temp;
	}
	static void shuffelArray(int array[100], int arraylenght) {
		for (int i = 0; i < arraylenght; i++) {
			Swap(array[randomNumber(1, arraylenght) - 1], array[randomNumber(1, arraylenght) - 1] );
		}
	}
	static string  EncryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);

		}

		return Text;

	}

	static string  DecryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);

		}
		return Text;

	}
};