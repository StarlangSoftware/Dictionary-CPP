//
// Created by Olcay Taner Yıldız on 23.12.2018.
//

#ifndef DICTIONARY_WORD_H
#define DICTIONARY_WORD_H

#include <string>
using namespace std;

class Word {
protected:
    string name;
public:
    Word();
    virtual ~Word() = default;
    explicit Word(const string& name);
    string to_string();
    int charCount() const;
    Word clone();
    string getName() const;
    void setName(const string& name);
    static string beforeLastVowel(const string& stem);
    static string lastVowel(const string& stem);
    static string lastPhoneme(const string& stem);
    static bool isCapital(const string& surfaceForm);
    static bool isPunctuation(const string& surfaceForm);
    static bool isHonorific(const string& surfaceForm);
    static bool isOrganization(const string& surfaceForm);
    static bool isMoney(const string& surfaceForm);
    static bool startsWith(const string& largeString, const string& smallString);
    static bool endsWith(const string& largeString, const string& smallString);
    static vector<string> split(const string& line, const string& separator);
    static vector<string> split(const string& line);
    static string replaceAll(string str, const string& from, const string& to);
    static string trim(const string& str);
    static int size(const string& surfaceForm);
    static string toLowerCase(const string& surfaceForm);
    static string toUpperCase(const string& surfaceForm);
    static string lastChar(const string& surfaceForm);
    static string charAt(const string& surfaceForm, int index);
    static string* allCharacters(const string& surfaceForm);
    static string substring(const string& surfaceForm, int index, int length);
    static string substring(const string& surfaceForm, int index);
    static string substringExceptLastChar(const string& surfaceForm);
    static string substringExceptLastTwoChars(const string& surfaceForm);
    bool isPunctuation() const;
    static bool isTime(const string& surfaceForm);
    static Word* toWordArray(string* sourceArray, int size);
    vector<Word> toCharacters() const;
    friend istream& operator>> (istream& is, Word& word){
        is >> word.name;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Word& word){
        os << word.getName();
        return os;
    }
    bool operator==(const Word &anotherWord) const{
        return (name == anotherWord.name);
    }
    bool operator<(const Word &anotherWord) const{
        return (name < anotherWord.name);
    }
};


#endif //DICTIONARY_WORD_H
