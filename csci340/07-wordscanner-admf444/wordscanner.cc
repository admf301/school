
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <algorithm>

//iterator declaration and printing parameters
typedef std::map<std::string, int>::const_iterator it_type;
const int NO_ITEMS = 4;
const int ITEM_WORD_WIDTH = 14;
const int ITEM_COUNT_WIDTH = 3;

/**
* alpha-numeric helper function
*
* @param c - character to compare
* @returns true/false if character is alpha-numeric
******************************************************************************/
bool alnum(const char& c)
{
	return isalnum(c);
}

/**
* non alpha-numereic helper function
*
* @param c - character to compare
* @returns true/false if a character is not alpha-numeric
******************************************************************************/
bool not_alnum(const char &c)
{
	return !isalnum(c);
}

/**
* convert to lowercase function
*
* @param c - character to be converted to lowercase
******************************************************************************/
void convert_lower(char& c)
{
	c = tolower(c);
	return;
}

/**
* printing words function
*
* prints the number of times a distinct word was found (prints the contents of the map)
* along with the number of words in the input and output streams
*
* @param map - map to be printed
******************************************************************************/
void print_words(const std::map<std::string, int>& map)
{
	int counter = 0;
	int num = 0;

	for(it_type it = map.begin(); it != map.end(); ++it)
	{
		if(counter == NO_ITEMS)
		{
			counter = 0;
			std::cout << std::endl;
		}

		num += (*it).second;

		std::cout << std::setw(ITEM_WORD_WIDTH) << std::left << (*it).first << ":" << std::setw(ITEM_COUNT_WIDTH) << (*it).second;
		counter++;
	}

	std::cout << std::endl;
	std::cout << "number of words in input stream" << std::setw(4) << std::right << ":" << num << std::endl;
	std::cout << "number of words in output stream" << std::setw(3) << std::right << ":" << (int)map.size() << std::endl;
}

/**
* clean entry function
*
* scans input stream until alpha-numeric character is found, marks start of word
* testing if each character from the word is alpha-numeric until a space or punctuation, marks end of word
* extract the entire word from the input stream into the output stream and make the whole word lowercase
*
* @param word1 - input stream  (word to be cleaned)
* @param word2 - output stream (cleaned word to be added to map)
******************************************************************************/
void clean_entry(const std::string& word1, std::string& word2)
{
	int index = 0;
	int index_end = 0;

	bool has_punc = false;
	bool start = false;
	bool end = false;

	for(int count = 0; count < (int)word1.length(); count++)
	{
		if(not_alnum(word1[count]))
		{
			has_punc = true;
		}

		if(alnum(word1[count]) && start == false)
		{
			start = true;
			index = count;
		}

		if(start == true)
		{
			if(not_alnum(word1[count]))
			{
				end = true;
				index_end = count;
			}
		}

		if(end == true)
		{
			break;
		}
	}

	word2 = word1.substr(index, index_end - index);
	for_each(word2.begin(), word2.end(), convert_lower);

	if(has_punc == false)
	{
		word2 = word1;
		for_each(word2.begin(), word2.end(), convert_lower);
	}
}

/**
* get words function
*
* gets words from input stream to add the cleaned words to the map
*
* @param map - map for words to be added to
******************************************************************************/
void get_words(std::map<std::string, int>& map)
{
	std::string to_clean;
	std::string word;

	while(std::cin >> to_clean)
	{
		clean_entry(to_clean, word);

		if(word.length() > 0)
		{
			map[word]++;
		}
	}
}

int main()
{
	std::map<std::string, int> m;

	get_words(m);
	print_words(m);

	return 0;
}




