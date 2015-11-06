/*
 * Copyright 2015 handsomezhou
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "PinyinUtil.h"
#include "PinyinUnit.h"
#include "../../pinyin4cpp/pinyin4cpp/HanyuPinyinCaseType.h"
#include "../../pinyin4cpp/pinyin4cpp/PinyinHelper.h"

/**
 * Convert from base data to a series of PinyinUnit
 *
 * @brief PinyinUtil::parse
 * @param pinyinSearchUnit
 */
void PinyinUtil::parse(PinyinSearchUnit &pinyinSearchUnit)
{
    if(pinyinSearchUnit.getBaseData().isEmpty()||pinyinSearchUnit.getPinyinUnits().isEmpty()){
       return;
    }

    QString chineseStr=pinyinSearchUnit.getBaseData().toLower();
    if(NULL==format){
        format=new HanyuPinyinOutputFormat();
    }

    format->setToneType(*(HanyuPinyinToneType::WITHOUT_TONE));

    int chineseStringLength=chineseStr.length();
    QString nonPinyinString;
    PinyinUnit *pyUnit=NULL;
    QString originalString;
    QList<QString> *pinyinList=new QList<QString>();
    bool lastChineseCharacters = true;
    int startPosition = -1;
    QChar ch;

    for(int i=0; i<chineseStringLength; i++){
        ch=chineseStr.at(i);
        PinyinHelper::toHanyuPinyinStringArray(ch,format,pinyinList);
        if(0==pinyinList->size()){
            if (true == lastChineseCharacters) {
                pyUnit = new PinyinUnit();
                lastChineseCharacters = false;
                startPosition = i;
                nonPinyinString.clear();
            }
            nonPinyinString.append(ch);
        } else {
            if (false == lastChineseCharacters) {
                // add continuous non-kanji characters to PinyinUnit
                originalString = nonPinyinString;
                QList<QString> *str=new QList<QString>();
                str->append(nonPinyinString);
                PinyinUtil::addPinyinUnit(pinyinSearchUnit.getPinyinUnits(), pyUnit, false, originalString,str, startPosition);
                nonPinyinString.clear();
                lastChineseCharacters = true;
            }
            // add single Chinese characters Pinyin(include Multiple Pinyin)
            // to PinyinUnit
            pyUnit = new PinyinUnit();
            startPosition = i;
            originalString =ch;

            PinyinUtil::addPinyinUnit(pinyinSearchUnit.getPinyinUnits(), pyUnit, true, originalString,pinyinList, startPosition);

        }
    }

        if (false == lastChineseCharacters) {
            // add continuous non-kanji characters to PinyinUnit
            originalString = nonPinyinString;
            QList<QString> *str=new QList<QString>();
            str->append(nonPinyinString);
            PinyinUtil::addPinyinUnit(pinyinSearchUnit.getPinyinUnits(), pyUnit, false, originalString, str,startPosition);
            nonPinyinString.clear();
            lastChineseCharacters = true;
        }

    return;
}

/**
 * get the first letter from original string
 *
 * @brief PinyinUtil::getFirstLetter
 * @param pinyinSearchUnit
 * @return return the first letter of original string,otherwise return null.
 */
QString PinyinUtil::getFirstLetter(PinyinSearchUnit &pinyinSearchUnit)
{
    return NULL;
}

/**
 * get the first character from original string
 *
 * @brief PinyinUtil::getFirstCharacter
 * @param pinyinSearchUnit
 * @return return the first character of original string,otherwise return null.
 */
QString PinyinUtil::getFirstCharacter(PinyinSearchUnit &pinyinSearchUnit)
{

    return NULL;
}

/**
 * get sort key, as sort keyword
 *
 * @brief PinyinUtil::getSortKey
 * @param pinyinSearchUnit
 * @return return sort key,otherwise return null.
 */
QString PinyinUtil::getSortKey(PinyinSearchUnit &pinyinSearchUnit)
{

    return NULL;
}

/**
 * judge chr is kanji
 *
 * @brief PinyinUtil::isKanji
 * @param chr
 * @return Is kanji return true,otherwise return false.
 */
bool PinyinUtil::isKanji(QChar &chr)
{

    return false;
}

void PinyinUtil::addPinyinUnit(QList<PinyinUnit> *pinyinUnit, PinyinUnit *pyUnit, bool pinyin, QString originalString, QList<QString> *string, int startPosition)
{

}


HanyuPinyinOutputFormat* PinyinUtil::format=new HanyuPinyinOutputFormat();
