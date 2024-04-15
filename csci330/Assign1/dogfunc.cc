
#include <cctype>

//performs a caesar cipher on the selected buffer
//@param str buffer to be encrypted
//@param size length of buffer to be encrypted
//@param shift supplied option of how much to be shifted by
void caesarCipher(char str[], int size, int shift)
{
	//if the shift is larger that the alphabet, shrink it down to fit
	shift %= 26;

	//for each character in the buffer
	for(int i = 0; i < size; i++)
	{
		//if the character is in the alphabet, shift it by the amount
		if(isalpha(str[i]))
		{
			str[i] += shift;

			//making sure the char stays a letter in the alphabet
			if(tolower(str[i]) > 'z')
			{
				str[i] -= 26;
			}

			else if(tolower(str[i]) < 'a')
			{
				str[i] += 26;
			}
		}
	}
}

//performs a rotation on the selected buffer
//@param str buffer to be encrypted
//@param size length of buffer to be encrypted
//@param shift supplied option of how much to be shifted
void rotation(char str[], int size, int shift)
{
	for(int i = 0; i < size; i++)
	{
		str[i] = (str[i] + shift) % 255;
	}
}

//translates the selcted buffer to binary
//@param str buffer to be translated
//@param size length of buffer to be translated
//@param binary binary buffer that will store the translated characters
void toBinary(char str[], int size, char binary[])
{
	int num;

	//array of possible values
	char binvals[] = "01";

	//for each character in the buffer
	for(int i = 0; i < size; i++)
	{
		num = str[i];

		//fill the binary[] array with the translated characters
		for(int z = i * 8 + 7; z >= i * 8; z--)
		{
			binary[z] = binvals[num % 2];
			num /= 2;
		}
	}
}

//translates the selected buffer to hex
//@param str buffer to be translated
//@param size length of buffer to be translated
//@param hex hex buffer that will store the translated characters
void toHex(char str[], int size, char hex[])
{
	int num;

	//array of possble hex values
	char hexvals[] = "0123456789abcdefgh";

	//for each character in the buffer
	for(int i = 0; i < size; i++)
	{
		num = str[i];

		//fill the hex[] array with the translated characters
		for(int z = i * 2 + 1; z >= i * 2; z--)
		{
			hex[z] = hexvals[num % 16];
			num /= 16;
		}
	}
}
