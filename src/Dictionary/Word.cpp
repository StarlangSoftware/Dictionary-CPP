//
// Created by Olcay Taner Yıldız on 23.12.2018.
//

#include <regex>
#include <sstream>
#include "Word.h"
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
Word Word::clone() {
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

bool Word::startsWith(const string &largeString, const string &smallString) {
    return largeString.rfind(smallString, 0) == 0;
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
    return startsWith(lowercase, "dolar") || startsWith(lowercase, "sterlin") || startsWith(lowercase, "paunt") ||
           startsWith(lowercase, "ons") || startsWith(lowercase, "ruble") || startsWith(lowercase, "mark") ||
           startsWith(lowercase, "frank") || lowercase == "yen" || startsWith(lowercase, "sent") ||
           startsWith(lowercase, "cent") || startsWith(lowercase, "yen'") || lowercase.find_first_of('$') != -1;
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
    if (startsWith(lowercase, "ocak") || startsWith(lowercase, "şubat") || startsWith(lowercase, "mart") ||
        startsWith(lowercase, "nisan") || startsWith(lowercase, "mayıs") || startsWith(lowercase, "haziran") ||
        startsWith(lowercase, "temmuz") || startsWith(lowercase, "ağustos") || startsWith(lowercase, "eylül") ||
        startsWith(lowercase, "ekim") || startsWith(lowercase, "kasım") || lowercase == "aralık") {
        return true;
    }
    if (lowercase == "pazar" || lowercase == "salı" || startsWith(lowercase, "çarşamba") ||
        startsWith(lowercase, "perşembe") || lowercase == "cuma" || startsWith(lowercase, "cumartesi") ||
        startsWith(lowercase, "pazartesi")) {
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

vector<string> Word::split(const string &line, const string &separator) {
    size_t current, previous = 0;
    vector<string> tokens;
    current = line.find_first_of(separator);
    while (current != string::npos) {
        tokens.push_back(line.substr(previous, current - previous));
        previous = current + 1;
        current = line.find_first_of(separator, previous);
    }
    tokens.push_back(line.substr(previous, current - previous));
    return tokens;
}

vector<string> Word::split(const string &line) {
    std::istringstream stringStream(line);
    vector<string> tokens{istream_iterator<string>{stringStream}, istream_iterator<string>{}};
    return tokens;
}

bool Word::endsWith(const string &largeString, const string &smallString) {
    if (largeString.size() < smallString.size()) {
        return false;
    }
    return largeString.find(smallString, largeString.size() - smallString.size()) ==
           largeString.size() - smallString.size();
}

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

string Word::toCapital(const string &surfaceForm) {
    return Word::toUpperCase(Word::substring(surfaceForm, 0, 1)) + Word::substring(surfaceForm, 1);
}

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

string Word::lastChar(const string &surfaceForm) {
    int size = surfaceForm.size();
    const char *charPtr = surfaceForm.c_str();
    if ((*(charPtr + size - 1) & 0xC0) != 0x80) {
        return string(1, *(charPtr + size - 1));
    } else {
        return string(charPtr + size - 2);
    }
}

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

string Word::substringExceptLastChar(const string &surfaceForm) {
    int size = surfaceForm.size();
    const char *charPtr = surfaceForm.c_str();
    if ((*(charPtr + size - 1) & 0xC0) != 0x80) {
        return surfaceForm.substr(0, size - 1);
    } else {
        return surfaceForm.substr(0, size - 2);
    }
}

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

string Word::replaceAll(string str, const string &from, const string &to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

string Word::trim(const string &str) {
    int start = -1, end = -1;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            start = i;
            break;
        }
    }
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            end = i;
            break;
        }
    }
    return str.substr(start, end - start + 1);
}
