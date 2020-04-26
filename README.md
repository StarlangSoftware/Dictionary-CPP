# Dictionary

This resource is a dictionary of Modern Turkish, comprised of the definitions of over 50.000 individual entries. Each entry is matched with its corresponding synset (set of synonymous words and expressions) in the Turkish WordNet, KeNet.

For Developers
============
You can also see [Java](https://github.com/olcaytaner/Dictionary), [Python](https://github.com/olcaytaner/Dictionary-Py), or [C#](https://github.com/olcaytaner/Dictionary-CS) repository.

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

	git clone https://github.com/olcaytaner/Dictionary-CPP.git

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

Bir alana özgü veya Türkçe sözlüğü yüklemek için kullanılır. Ayrıca yanlış yazılmış
kelimeler ve yanlış yazılmış kelimelerin doğru formları da yüklenebilir.

Türkçe sözlüğü ve yazım yanlışları sözlüğünü yüklemek için

	a = TxtDictionary()
	
Alana özgü sözlüğü ve yazım yanlışı sözlüğünü yüklemek için

	TxtDictionary(String fileName, WordComparator comparator, String misspelledFileName)

Belirli bir sözcüğün sözlükte olup olmadığı,

	Word getWord(String name)

## TxtWord

Sözlükteki kelimelerin özellikleri TxtWord sınıfının, isim olup olmadıkları

	boolean isNominal()

sıfat olup olmadıkları,

	boolean isAdjective()

bileşik isim olup olmadıkları

	boolean isPortmanteau()

ünlü uyumuna uyup uymadıkları

	notObeysVowelHarmonyDuringAgglutination

ek aldıklarında yumuşayıp yumuşamadıkları

	boolean rootSoftenDuringSuffixation()

## SyllableList

Kelimeyi hecelerine ayırmak için de SyllableList sınıfı kullanılır.

	SyllableList(String word)
