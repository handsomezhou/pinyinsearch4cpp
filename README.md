pinyinsearch4cpp
===================
    A pinyin search Library base on Qt which provide data parsing methods, 
	data matching method and so on for T9 search and Qwerty search.

    PinyinSearch = T9Search + QwertySearch
	
**If you're looking for other versions search project, you can find all of them at the following links:**

Java(Android):
[PinyinSearch](https://github.com/handsomezhou/PinyinSearchLibrary)
[T9Search](https://github.com/handsomezhou/T9SearchLibrary)
[QwertySearch](https://github.com/handsomezhou/QwertySearchLibrary)

c plus plus(Qt)
[PinyinSearch](https://github.com/handsomezhou/pinyinsearch4cpp)

	
Features
---------------
 * Support T9 search
 * Support Qwerty search
 * Support Chinese character search
 * Support Pinyin search
 * Support English search
 * Support polyphone search
 * Support highlight
 
Depend
---------------
### The library of pinyin4cpp: 
	The [pinyin4cpp](https://github.com/handsomezhou/pinyin4cpphttps://github.com/handsomezhou/pinyin4cpp) is a c plus plus  library supporting convertion between Chinese characters and hanyu pinyin that based on Qt.
	
	reference:[http://pinyin4j.sourceforge.net/](http://pinyin4j.sourceforge.net/)
	

API
---------------
### Data structure:PinyinUnit
	PinyinUnit as a base data structure to save the string that Chinese characters  
	converted to Pinyin characters.
	
### Function:
	static void parse(PinyinSearchUnit &pinyinSearchUnit);
	static bool match(PinyinSearchUnit &pinyinSearchUnit,QString &search);
    static QString getFirstLetter(PinyinSearchUnit &pinyinSearchUnit);
    static QString getFirstCharacter(PinyinSearchUnit &pinyinSearchUnit);
    static QString getSortKey(PinyinSearchUnit &pinyinSearchUnit);
    static bool isKanji(QChar &chr);

### Function call:
	PinyinUtil::parse(...);
	T9Util::match(...);
	QwertyUtil::match(...);
	PinyinUtil::getSortKey(...);
	PinyinUtil::getFirstLetter(...);
	PinyinUtil::getFirstCharacter(...);
	PinyinUtil::isKanji(...);
	
Usage
---------------	
### Function call in detail:
	pinyinsearch4cpp Dependent on pinyin4cpp.
	
	The first step:  Data parsing  (ps:Must init baseData of PinyinSearchUnit before parse)
	    * (PinyinUtil::parse(...))
    The second step: Data matching 
	    * (T9Util::match(...) or QwertyUtil::match(...))
	
	For details, please see project pinyinsearchdemo.	 

Algorithm introduction
---------------
1.[Pinyin search contacts analysis and implementation](http://blog.csdn.net/zjqyjg/article/details/41360769)

2.[T9 search contacts analysis and implementation](http://blog.csdn.net/zjqyjg/article/details/41182911)

3.[Qwerty search contacts analysis and implementation](http://blog.csdn.net/zjqyjg/article/details/41318907)

License 
---------------
	Copyright 2016 handsomezhou

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

		http://www.apache.org/licenses/LICENSE-2.0
		
	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

 