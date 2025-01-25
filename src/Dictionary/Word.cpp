//
// Created by Olcay Taner Yıldız on 23.12.2018.
//

#include <regex>
#include <fstream>
#include "Word.h"
#include "StringUtils.h"
#include "../Language/TurkishLanguage.h"

/**
 * An empty constructor of Word class.
 */
Word::Word() = default;

/**
 * A constructor of Word class which gets a String name as an input and assigns to the name variable.
 *
 * @param _name String input.
 */
Word::Word(const string &_name) {
    this->name = _name;
}

/**
 * The overridden to_string method returns the name variable.
 *
 * @return the name variable.
 */
string Word::to_string() {
    return name;
}

/**
 * The charCount method returns the length of name variable.
 *
 * @return the length of name variable.
 */
int Word::charCount() const {
    return Word::size(name);
}

/**
 * The clone method returns new Word as name.
 *
 * @return new Word as name.
 */
Word Word::clone() const {
    return Word(name);
}

/**
 * Getter for the name variable.
 *
 * @return name variable.
 */
string Word::getName() const {
    return name;
}

/**
 * Setter for the name variable.
 *
 * @param _name String input.
 */
void Word::setName(const string &_name) {
    this->name = _name;
}

/**
 * The beforeLastVowel method takes a String stem as an input. It loops through the given stem and returns
 * the second last vowel.
 *
 * @param stem String input.
 * @return the last vowel.
 */
string Word::beforeLastVowel(const string &stem) {
    int before = 1;
    string ch, last = "0";
    string *stemChars = Word::allCharacters(stem);
    for (int i = Word::size(stem) - 1; i >= 0; i--) {
        ch = stemChars[i];
        if (TurkishLanguage::isVowel(ch)) {
            if (before == 1) {
                last = ch;
                before--;
                continue;
            }
            delete[] stemChars;
            return ch;
        }
    }
    delete[] stemChars;
    return last;
}

/**
 * The lastVowel method takes a String stem as an input. It loops through the given stem and returns
 * the last vowel.
 *
 * @param stem String input.
 * @return the last vowel.
 */
string Word::lastVowel(const string &stem) {
    string ch;
    string *stemChars = Word::allCharacters(stem);
    for (int i = Word::size(stem) - 1; i >= 0; i--) {
        ch = stemChars[i];
        if (TurkishLanguage::isVowel(ch)) {
            delete[] stemChars;
            return ch;
        }
    }
    for (int i = Word::size(stem) - 1; i >= 0; i--) {
        ch = stemChars[i];
        if (ch >= "0" && ch <= "9") {
            delete[] stemChars;
            return ch;
        }
    }
    delete[] stemChars;
    return "0";
}

/**
 * The lastPhoneme method takes a String stem as an input. It then returns the last phoneme of the given stem.
 *
 * @param stem String input.
 * @return the last phoneme.
 */
string Word::lastPhoneme(const string &stem) {
    if (stem.empty()) {
        return " ";
    }
    if (Word::lastChar(stem) != "'") {
        return Word::lastChar(stem);
    } else {
        return Word::charAt(stem, Word::size(stem) - 2);
    }
}

/**
 * The isCapital method takes a String surfaceForm as an input and returns true if the character at first index of surfaceForm
 * is a capital letter, false otherwise.
 *
 * @param surfaceForm String input to check the first character.
 * @return true if the character at first index of surfaceForm is a capital letter, false otherwise.
 */
bool Word::isCapital(const string &surfaceForm) {
    string ch = Word::charAt(surfaceForm, 0);
    return TurkishLanguage::UPPERCASE_LETTERS.find(ch) != -1;
}

/**
 * The isPunctuation method takes a String surfaceForm as an input and returns true if it is a punctuation, false otherwise.
 * Grave accent : \u0060
 * Left quotation mark : \u201C
 * Right quotation mark : \u201D
 * Left single quotation mark : \u2018
 *Horizontal ellipsis : \u2026
 *
 * @param surfaceForm String input to check.
 * @return true if it is a punctuation, false otherwise.
 */
bool Word::isPunctuation(const string &surfaceForm) {
    return (surfaceForm == "." || surfaceForm == "..." || surfaceForm == "[" || surfaceForm == "]" ||
            surfaceForm == "\u2026" || surfaceForm == "%" || surfaceForm == "&" || surfaceForm == "=" ||
            surfaceForm == "\u0060\u0060" || surfaceForm == "\u0060" || surfaceForm == "''" || surfaceForm == "$" ||
            surfaceForm == "!" || surfaceForm == "?" || surfaceForm == "," || surfaceForm == ":" ||
            surfaceForm == "--" || surfaceForm == ";" || surfaceForm == "(" || surfaceForm == ")" ||
            surfaceForm == "'" || surfaceForm == "\"" || surfaceForm == "\u201C" || surfaceForm == "\u2018" ||
            surfaceForm == "\u201D" || surfaceForm == "…" || surfaceForm == "\u25CF" || surfaceForm == "/" ||
            surfaceForm == "-" || surfaceForm == "+" || surfaceForm == "-LRB-" || surfaceForm == "-RRB-" ||
            surfaceForm == "-LCB-" || surfaceForm == "-RCB-" || surfaceForm == "-LSB-" || surfaceForm == "-RSB-");
}

/**
 * The isHonorific method takes a String surfaceForm as an input and after converting it to lower case it returns true
 * if it equals to "bay" or "bayan", false otherwise.
 *
 * @param surfaceForm String input to check.
 * @return true if it equals to "bay" or "bayan", false otherwise.
 */
bool Word::isHonorific(const string &surfaceForm) {
    string lowercase = surfaceForm;
    std::transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
    return lowercase == "bay" || lowercase == "bayan";
}

/**
 * The isOrganization method takes a String surfaceForm as an input and after converting it to lower case it returns true
 * if it equals to "şirket", "corp", "inc.", or "co.", and false otherwise.
 *
 * @param surfaceForm String input to check.
 * @return true if it equals to "şirket", "corp", "inc.", or "co.", and false otherwise.
 */
bool Word::isOrganization(const string &surfaceForm) {
    string lowercase = surfaceForm;
    std::transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
    return lowercase == "corp" || lowercase == "inc." || lowercase == "co.";
}

/**
 * The isMoney method takes a String surfaceForm as an input and after converting it to lower case it returns true
 * if it equals to one of the dolar, sterlin, paunt, ons, ruble, mark, frank, yan, sent, yen' or $, and false otherwise.
 *
 * @param surfaceForm String input to check.
 * @return true if it equals to one of the dolar, sterlin, paunt, ons, ruble, mark, frank, yan, sent, yen' or $, and false otherwise.
 */
bool Word::isMoney(const string &surfaceForm) {
    string lowercase = surfaceForm;
    std::transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
    return StringUtils::startsWith(lowercase, "dolar") || StringUtils::startsWith(lowercase, "sterlin") || StringUtils::startsWith(lowercase, "paunt") ||
           StringUtils::startsWith(lowercase, "ons") || StringUtils::startsWith(lowercase, "ruble") || StringUtils::startsWith(lowercase, "mark") ||
           StringUtils::startsWith(lowercase, "frank") || lowercase == "yen" || StringUtils::startsWith(lowercase, "sent") ||
           StringUtils::startsWith(lowercase, "cent") || StringUtils::startsWith(lowercase, "yen'") || lowercase.find_first_of('$') != -1;
}

/**
 * isPunctuation method without any argument, it checks name variable whether it is a punctuation or not and
 * returns true if so.
 *
 * @return true if name is a punctuation.
 */
bool Word::isPunctuation() const {
    return name == "," || name == "." || name == "!" || name == "?" || name == ":"
           || name == ";" || name == "\"" || name == "''" || name == "'" || name == "`"
           || name == "``" || name == "..." || name == "-" || name == "--";
}

/**
 * The isTime method takes a String surfaceForm as an input and after converting it to lower case it checks some cases.
 * If it is in the form of 12:23:34 or 12:23 ir returns true.
 * If it starts with name of months; ocak, şubat, mart, nisan, mayıs, haziran, temmuz, ağustos, eylül, ekim, kasım, aralık it returns true.
 * If it equals to the name of days; pazar, pazartesi, salı, çarşamba, perşembe, cuma, cumartesi it returns true.
 *
 * @param surfaceForm String input to check.
 * @return true if it presents time, and false otherwise.
 */
bool Word::isTime(const string &surfaceForm) {
    string lowercase = surfaceForm;
    lowercase = Word::toLowerCase(lowercase);
    if (std::regex_search(lowercase, std::regex("(\\d\\d|\\d):(\\d\\d|\\d):(\\d\\d|\\d)")) ||
        std::regex_search(lowercase, std::regex("(\\d\\d|\\d):(\\d\\d|\\d)"))) {
        return true;
    }
    if (StringUtils::startsWith(lowercase, "ocak") || StringUtils::startsWith(lowercase, "şubat") || StringUtils::startsWith(lowercase, "mart") ||
        StringUtils::startsWith(lowercase, "nisan") || StringUtils::startsWith(lowercase, "mayıs") || StringUtils::startsWith(lowercase, "haziran") ||
        StringUtils::startsWith(lowercase, "temmuz") || StringUtils::startsWith(lowercase, "ağustos") || StringUtils::startsWith(lowercase, "eylül") ||
        StringUtils::startsWith(lowercase, "ekim") || StringUtils::startsWith(lowercase, "kasım") || lowercase == "aralık") {
        return true;
    }
    if (lowercase == "pazar" || lowercase == "salı" || StringUtils::startsWith(lowercase, "çarşamba") ||
        StringUtils::startsWith(lowercase, "perşembe") || lowercase == "cuma" || StringUtils::startsWith(lowercase, "cumartesi") ||
        StringUtils::startsWith(lowercase, "pazartesi")) {
        return true;
    }
    if (lowercase.find_first_of('\'') != -1) {
        lowercase = lowercase.substr(0, lowercase.find_first_of('\''));
    }
    try {
        int time = stoi(lowercase);
        if (time > 1900 && time < 2200) {
            return true;
        }
    } catch (invalid_argument &e) {
    }
    return false;
}

/**
 * The toWordArray method takes a String array sourceArray as an input. First it creates
 * a Word type result array and puts items of input sourceArray to this result array.
 *
 * @param sourceArray String array.
 * @return Word type array.
 */
Word *Word::toWordArray(string *sourceArray, int size) {
    Word *result = new Word[size];
    for (int i = 0; i < size; i++) {
        result[i] = Word(sourceArray[i]);
    }
    return result;
}

/**
 * The toCharacters method creates a Word type characters vector and adds characters of name variable
 * to newly created vector.
 *
 * @return Word type vector.
 */
vector<Word> Word::toCharacters() const {
    vector<Word> characters;
    for (int i = 0; i < Word::size(name); i++) {
        string s;
        s += Word::charAt(name, i);
        characters.emplace_back(Word(s));
    }
    return characters;
}

/**
 * Number of UTF8 characters in a given string.
 * @param surfaceForm Given input string
 * @return Number of UTF8 characters in the input string
 */
int Word::size(const string &surfaceForm) {
    const char *charPtr = surfaceForm.c_str();
    int count = 0;
    while (*charPtr) {
        if ((*charPtr & 0xC0) != 0x80) {
            count++;
        }
        charPtr++;
    }
    return count;
}

/**
 * Converts a given string to its lowercase form.
 * @param surfaceForm Given input string
 * @return Lowercase version of the input string
 */
string Word::toLowerCase(const string &surfaceForm) {
    const char *charPtr = surfaceForm.c_str();
    string result;
    string currentChar;
    while (*charPtr) {
        if ((*charPtr & 0xC0) != 0x80) {
            do {
                currentChar += *charPtr;
                charPtr++;
            } while ((*charPtr & 0xC0) == 0x80);
            if (currentChar == "ç" || currentChar == "ö" || currentChar == "ğ" || currentChar == "ü" ||
                currentChar == "ş" || currentChar == "ı" || currentChar == "â" || currentChar == "û" ||
                currentChar == "î") {
                result += currentChar;
            } else {
                if (currentChar == "Ç") {
                    result += "ç";
                } else {
                    if (currentChar == "Ö") {
                        result += "ö";
                    } else {
                        if (currentChar == "Ğ") {
                            result += "ğ";
                        } else {
                            if (currentChar == "Ü") {
                                result += "ü";
                            } else {
                                if (currentChar == "Ş") {
                                    result += "ş";
                                } else {
                                    if (currentChar == "İ") {
                                        result += "i";
                                    } else {
                                        if (currentChar == "I") {
                                            result += "ı";
                                        } else {
                                            if (currentChar == "Â") {
                                                result += "â";
                                            } else {
                                                if (currentChar == "Î") {
                                                    result += "î";
                                                } else {
                                                    if (currentChar == "Û") {
                                                        result += "û";
                                                    } else {
                                                        result += tolower(currentChar[0]);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            currentChar = "";
        } else {
            charPtr++;
        }
    }
    return result;
}

/**
 * Converts a given string to its uppercase form.
 * @param surfaceForm Given input string
 * @return Uppercase version of the input string
 */
string Word::toUpperCase(const string &surfaceForm) {
    const char *charPtr = surfaceForm.c_str();
    string result;
    string currentChar;
    while (*charPtr) {
        if ((*charPtr & 0xC0) != 0x80) {
            do {
                currentChar += *charPtr;
                charPtr++;
            } while ((*charPtr & 0xC0) == 0x80);
            if (currentChar == "Ç" || currentChar == "Ö" || currentChar == "Ğ" || currentChar == "Ü" ||
                currentChar == "Ş" || currentChar == "I" || currentChar == "İ" || currentChar == "Â" ||
                currentChar == "Î" || currentChar == "Û") {
                result += currentChar;
            } else {
                if (currentChar == "ç") {
                    result += "Ç";
                } else {
                    if (currentChar == "ö") {
                        result += "Ö";
                    } else {
                        if (currentChar == "ğ") {
                            result += "Ğ";
                        } else {
                            if (currentChar == "ü") {
                                result += "Ü";
                            } else {
                                if (currentChar == "ş") {
                                    result += "Ş";
                                } else {
                                    if (currentChar == "i") {
                                        result += "İ";
                                    } else {
                                        if (currentChar == "ı") {
                                            result += "I";
                                        } else {
                                            if (currentChar == "â") {
                                                result += "Â";
                                            } else {
                                                if (currentChar == "î") {
                                                    result += "Î";
                                                } else {
                                                    if (currentChar == "û") {
                                                        result += "Û";
                                                    } else {
                                                        result += toupper(currentChar[0]);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            currentChar = "";
        } else {
            charPtr++;
        }
    }
    return result;
}

/**
 * Converts the given string into its capital form
 * @param surfaceForm Given string which will be converted to its capital form
 * @return Capitalized form of the input string.
 */
string Word::toCapital(const string &surfaceForm) {
    return Word::toUpperCase(Word::substring(surfaceForm, 0, 1)) + Word::substring(surfaceForm, 1);
}

/**
 * Returns an array of UTF8 characters of the input string.
 * @param surfaceForm Input string
 * @return An array of UTF8 characters.
 */
string *Word::allCharacters(const string &surfaceForm) {
    auto *result = new string[size(surfaceForm)];
    string ch;
    string *index = result;
    const char *charPtr = surfaceForm.c_str();
    do {
        ch += *charPtr;
        charPtr++;
        if ((*charPtr & 0xC0) != 0x80) {
            *index = ch;
            index++;
            ch = "";
        }
    } while (*charPtr);
    return result;
}

/**
 * Returns the UTF8 character value at the specified index of an input string
 * @param surfaceForm Input string
 * @param index The index of the character
 * @return UTF8 character value at the specified index
 */
string Word::charAt(const string &surfaceForm, int index) {
    const char *charPtr = surfaceForm.c_str();
    string result;
    int current = 0;
    while (*charPtr) {
        if ((*charPtr & 0xC0) != 0x80) {
            if (current == index) {
                do {
                    result += *charPtr;
                    charPtr++;
                } while ((*charPtr & 0xC0) == 0x80);
                return result;
            } else {
                current++;
            }
        }
        charPtr++;
    }
    return "";
}

/**
 * Returns last UTF8 character of an input string
 * @param surfaceForm Input string
 * @return Last UTF8 character
 */
string Word::lastChar(const string &surfaceForm) {
    int size = surfaceForm.size();
    const char *charPtr = surfaceForm.c_str();
    if ((*(charPtr + size - 1) & 0xC0) != 0x80) {
        return string(1, *(charPtr + size - 1));
    } else {
        return string(charPtr + size - 2);
    }
}

/**
 * Returns a string that is a substring of this string. The substring begins at the specified index and extends
 * length characters.
 * @param surfaceForm Input string
 * @param index The beginning index, inclusive.
 * @param length Length of the substring
 * @return Substring of this string starting from index with size length
 */
string Word::substring(const string &surfaceForm, int index, int length) {
    const char *charPtr = surfaceForm.c_str();
    string result;
    int current = 0, currentLength = 0;
    if (length <= 0 || index < 0) {
        return "";
    }
    while (*charPtr) {
        if ((*charPtr & 0xC0) != 0x80) {
            if (current == index) {
                do {
                    result += *charPtr;
                    charPtr++;
                    if ((*charPtr & 0xC0) != 0x80) {
                        currentLength++;
                    }
                } while (currentLength < length && *charPtr);
                return result;
            } else {
                current++;
            }
        }
        charPtr++;
    }
    return "";
}

/**
 * Returns a string that is a substring of this string. The substring begins at the specified index and extends
 * until the end of the input string.
 * @param surfaceForm Input string
 * @param index The beginning index, inclusive.
 * @return Substring of this string starting from index
 */
string Word::substring(const string &surfaceForm, int index) {
    const char *charPtr = surfaceForm.c_str();
    string result;
    int current = 0;
    while (*charPtr) {
        if ((*charPtr & 0xC0) != 0x80) {
            if (current == index) {
                do {
                    result += *charPtr;
                    charPtr++;
                } while (*charPtr);
                return result;
            } else {
                current++;
            }
        }
        charPtr++;
    }
    return "";
}

/**
 * Returns copy of the input string with last character removed.
 * @param surfaceForm Input string
 * @return Copy of the input string with last character removed.
 */
string Word::substringExceptLastChar(const string &surfaceForm) {
    int size = surfaceForm.size();
    const char *charPtr = surfaceForm.c_str();
    if ((*(charPtr + size - 1) & 0xC0) != 0x80) {
        return surfaceForm.substr(0, size - 1);
    } else {
        return surfaceForm.substr(0, size - 2);
    }
}

/**
 * Returns copy of the input string with last two characters removed.
 * @param surfaceForm Input string
 * @return Copy of the input string with last two characters removed.
 */
string Word::substringExceptLastTwoChars(const string &surfaceForm) {
    int size = surfaceForm.size();
    const char *charPtr = surfaceForm.c_str();
    if ((*(charPtr + size - 1) & 0xC0) != 0x80) {
        if (((*(charPtr + size - 2) & 0xC0) != 0x80)) {
            return surfaceForm.substr(0, size - 2);
        } else {
            return surfaceForm.substr(0, size - 3);
        }
    } else {
        if (((*(charPtr + size - 3) & 0xC0) != 0x80)) {
            return surfaceForm.substr(0, size - 3);
        } else {
            return surfaceForm.substr(0, size - 4);
        }
    }
}
