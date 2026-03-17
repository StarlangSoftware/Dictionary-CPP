Turkish Dictionary
============

This resource is a dictionary of Modern Turkish, comprised of the definitions of over 50.000 individual entries. Each entry is matched with its corresponding synset (set of synonymous words and expressions) in the Turkish WordNet, KeNet.

The bare-forms in the lexicon consists of nouns, adjectives, verbs, adverbs, shortcuts, etc. Each bare-form appears the same in the lexicon except verbs. Since the bare-forms of the verbs in Turkish do not have the infinitive affix ‘mAk’, our lexicon includes all verbs without the infinitive affix. The bare-forms with diacritics are included in two forms, with and without diacritics. For example, noun ‘rüzgar’ appear both as ‘rüzgar’ and ‘rüzgâr’.

Special markers are included as bare-forms such as doc, s, etc.

Some compound words are included in their affixed form. For instance, ‘acemlalesi’ appears as it is, but not as ‘acemlale’.

Foreign words, especially proper noun foreign words, are included, so that the system can easily recognize them as proper nouns. For instance, the words ‘abbott’, ‘abbigail’ are example foreign proper nouns. Including foreign proper nouns, there are 19,000 proper nouns in our lexicon.

From derivational suffixes, we only include words which has taken -lI, -sIz, -CI, -lIk, and -CIlIk derivational affixes. For example, the bare-forms ‘abacı’, ‘abdallık’, ‘abdestli’ and ‘abdestlilik’, are included, since they have taken one or more derivational affixes listed above.

Each bare-form has a set of attributes. For instance, ‘abacı’ is a noun, therefore, it includes CL_ISIM attribute. Similarly, ‘abdestli’ is an adjective, which includes IS_ADJ attribute. If the bare-form has homonyms with different part of speech tags, all corresponding attributes are included.

|Name|Purpose|
|---|---|
|CL ISIM, CL FIIL, IS_OA|Part of speech tag(s)|
|IS_DUP|Part of a duplicate form|
|IS_KIS|Abbreviation, which does not obey vowel harmony while taking suffixes.|
|IS_UU, IS_UUU|Does not obey vowel harmony while taking suffixes.|
|IS_BILES|A portmanteau word in affixed form, such as ‘adamotu’|
|IS_B_SI|A portmanteau word ending with ‘sı’, such as ‘acemlalesi’|
|IS_CA|Already in a plural form, therefore can not take plural suffixes such as ‘ler’ or ‘lar’.|
|IS_ST|The second consonant undergoes a resyllabification.|
|IS_UD, IS_UDD, F_UD|Includes vowel epenthesis.|
|IS_KG|Ends with a ‘k’, and when it is followed by a vowel-initial suffix, the final ‘k’ is replaced with a ‘g’.|
|IS_SD, IS_SDD, F_SD|Final consonant gets devoiced during vowel-initial suffixation.|
|F GUD, F_GUDO|The verb bare-form includes vowel reduction.|
|F1P1, F1P1-NO-REF|A verb, and depending on this attribute, the verb can (or can not) take causative suffix, factitive suffix, passive suffix etc.|

Video Lectures
============

[<img src="https://github.com/StarlangSoftware/Dictionary/blob/master/video1.jpg" width="50%">](https://youtu.be/10iAqbfsA2A)[<img src="https://github.com/StarlangSoftware/Dictionary/blob/master/video2.jpg" width="50%">](https://youtu.be/C-_TZDkFwzQ)

For Developers
============
You can also see [Java](https://github.com/starlangsoftware/Dictionary), [Python](https://github.com/starlangsoftware/Dictionary-Py), [Cython](https://github.com/starlangsoftware/Dictionary-Cy), [Swift](https://github.com/starlangsoftware/Dictionary-Swift), [Js](https://github.com/starlangsoftware/Dictionary-Js), [Php](https://github.com/starlangsoftware/Dictionary-Php), or [C#](https://github.com/starlangsoftware/Dictionary-CS) repository.

## Requirements

* [C++ Compiler](#cpp)
* [Git](#git)


### CPP
To check if you have compatible C++ Compiler installed,
* Open CLion IDE 
* Preferences >Build,Execution,Deployment > Toolchain  

### Git

Install the [latest version of Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git).

## Download Code

In order to work on code, create a fork from GitHub page. 
Use Git for cloning the code to your local or below line for Ubuntu:

	git clone <your-fork-git-link>

A directory called Dictionary-CPP will be created. Or you can use below link for exploring the code:

	git clone https://github.com/starlangsoftware/Dictionary-CPP.git

## Open project with CLion IDE

To import projects from Git with version control:

* Open CLion IDE , select Get From Version Control.

* In the Import window, click URL tab and paste github URL.

* Click open as Project.

Result: The imported project is listed in the Project Explorer view and files are loaded.


## Compile

**From IDE**

After being done with the downloading and opening project, select **Build Project** option from **Build** menu. After compilation process, user can run Dictionary-CPP .

Detailed Description
============

+ [TxtDictionary](#txtdictionary)
+ [TxtWord](#txtword)
+ [SyllableList](#syllablelist)

## TxtDictionary

Dictionary is used in order to load Turkish dictionary or a domain specific dictionary. In addition, misspelled words and the true forms of the misspelled words can also be loaded.

To load the Turkish dictionary and the misspelled words dictionary,


	a = TxtDictionary()
	
To load the domain specific dictionary and the misspelled words dictionary,

	TxtDictionary(String fileName, WordComparator comparator, String misspelledFileName)

And to see if the dictionary involves a specific word, getWord is used.

	Word getWord(String name)

## TxtWord

The word features: To see whether the TxtWord class of the dictionary is a noun or not,

	boolean isNominal()

To see whether it is an adjective,

	boolean isAdjective()

To see whether it is a portmanteau word,

	boolean isPortmanteau()

To see whether it obeys vowel harmony,

	notObeysVowelHarmonyDuringAgglutination

And, to see whether it softens when it get affixes, the following is used.

	boolean rootSoftenDuringSuffixation()

## SyllableList

To syllabify the word, SyllableList class is used.

	SyllableList(String word)

# Cite

	@inproceedings{yildiz-etal-2019-open,
    	title = "An Open, Extendible, and Fast {T}urkish Morphological Analyzer",
    	author = {Y{\i}ld{\i}z, Olcay Taner  and
      	Avar, Beg{\"u}m  and
      	Ercan, G{\"o}khan},
    	booktitle = "Proceedings of the International Conference on Recent Advances in Natural Language Processing (RANLP 2019)",
    	month = sep,
    	year = "2019",
    	address = "Varna, Bulgaria",
    	publisher = "INCOMA Ltd.",
    	url = "https://www.aclweb.org/anthology/R19-1156",
    	doi = "10.26615/978-954-452-056-4_156",
    	pages = "1364--1372",
	}

For Contibutors
============

### Conan Setup

1. First install conan.

pip install conan

Instructions are given in the following page:

https://docs.conan.io/2/installation.html

2. Add conan remote 'ozyegin' with IP: 104.247.163.162 with the following command:

conan remote add ozyegin http://104.247.163.162:8081/artifactory/api/conan/conan-local --insert

3. Use the comman conan list to check for installed packages. Probably there are no installed packages.

conan list

### conanfile.py file

1. Put the correct dependencies in the requires part
```
    requires = ["math/1.0.0", "classification/1.0.0"]
```

2. Default settings are:
```
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": True, "fPIC": True}
    exports_sources = "src/*", "Test/*"

    def layout(self):
        cmake_layout(self, src_folder="src")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        copy(conanfile=self, keep_path=False, src=join(self.source_folder), dst=join(self.package_folder, "include"), pattern="*.h")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.a")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.so")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.dylib")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "bin"), pattern="*.dll")

    def package_info(self):
        self.cpp_info.libs = ["ComputationalGraph"]
```

### CMakeLists.txt file
1. Set the C++ standard with compiler flags.
```
	set(CMAKE_CXX_STANDARD 20)
	set(CMAKE_CXX_FLAGS "-O3")
```
2. Dependent packages should be given with find_package.
```
	find_package(util_c REQUIRED)
	find_package(data_structure_c REQUIRED)
```
3. For library part, use add_library and target_link_libraries commands. Use m library for math linker in Linux.
```
	add_library(Math src/Distribution.cpp src/Distribution.h src/DiscreteDistribution.cpp src/DiscreteDistribution.h src/Vector.cpp src/Vector.h src/Eigenvector.cpp src/Eigenvector.h src/Matrix.cpp src/Matrix.h src/Tensor.cpp src/Tensor.h)
	target_link_libraries(Math util_c::util_c data_structure_c::data_structure_c m)
```
4. For executable tests, use add_executable and target_link_libraries commands. Use m library for math linker in Linux.
```
	add_executable(DiscreteDistributionTest src/Distribution.cpp src/Distribution.h src/DiscreteDistribution.cpp src/DiscreteDistribution.h src/Vector.cpp src/Vector.h src/Eigenvector.cpp src/Eigenvector.h src/Matrix.cpp src/Matrix.h src/Tensor.cpp src/Tensor.h Test/DiscreteDistributionTest.cpp)
	target_link_libraries(DiscreteDistributionTest util_c::util_c data_structure_c::data_structure_c m)
```

### Data files
1. Add data files to the cmake-build-debug folder.

### C++ files

1. If needed, comparator operators == and < should be implemented for map and set data structures.
```
    bool operator==(const Word &anotherWord) const{
        return (name == anotherWord.name);
    }
    bool operator<(const Word &anotherWord) const{
        return (name < anotherWord.name);
    }
```
2. Do not forget to comment each function.
```
	/**
 	* A constructor of Word class which gets a String name as an input and assigns to the name variable.
	*
	* @param _name String input.
 	*/
	Word::Word(const string &_name) {
```
3. Function names should follow caml case.
```
	int Word::charCount() const
```
4. Write getter and setter methods.
```
	string Word::getName() const
	void Word::setName(const string &_name)
```
5. Use catch.hpp for testing purposes. Add
```
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
```
line in only one of the test files. Add
```
#include "catch.hpp"
```
line in all test files. Example test file is given below:
```
TEST_CASE("DictionaryTest") {
    TxtDictionary lowerCaseDictionary = TxtDictionary("lowercase.txt", "turkish_misspellings.txt");
    TxtDictionary mixedCaseDictionary = TxtDictionary("mixedcase.txt", "turkish_misspellings.txt");
    TxtDictionary dictionary = TxtDictionary();
    SECTION("testSize"){
        REQUIRE(29 == lowerCaseDictionary.size());
        REQUIRE(58 == mixedCaseDictionary.size());
        REQUIRE(62113 == dictionary.size());
    }
    SECTION("testGetWord"){
        for (int i = 0; i < dictionary.size(); i++){
            REQUIRE_FALSE(nullptr == dictionary.getWord(i));
        }
    }
    SECTION("testLongestWordSize"){
        REQUIRE(1 == lowerCaseDictionary.longestWordSize());
        REQUIRE(1 == mixedCaseDictionary.longestWordSize());
        REQUIRE(21 == dictionary.longestWordSize());
    }
```
6. Enumerated types should be declared with enum class.
```
	enum class Pos {
		ADJECTIVE,
		NOUN,
		VERB,
		ADVERB,
```
7. Every header file should start with
```
	#ifndef MATH_DISTRIBUTION_H
	#define MATH_DISTRIBUTION_H
```
and end with
```
	#endif //MATH_DISTRIBUTION_H
```
8. Do not forget to use const expression for parameters, if they will not be changed in the function.
```
	void Word::setName(const string &_name);
```
9. Do not forget to use const expression for methods, which do not modify any class attribute. Also use [[dodiscard]]
```
	[[nodiscard]] bool isPunctuation() const;
```
10. Use xmlparser package for parsing xml files.
```
    auto* doc = new XmlDocument("test.xml");
    doc->parse();
    XmlElement* root = doc->getFirstChild();
    XmlElement* firstChild = root->getFirstChild();
```
11. Data structures: Use map for hash map, unordered_map for linked hash map, vector for array list, unordered_set for hash set
