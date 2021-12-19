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

#ifndef PINYINUTIL_H
#define PINYINUTIL_H
#include <QChar>
#include <QString>
#include "PinyinSearchUnit.h"
#include "PinyinBaseUnit.h"
#include "../../pinyin4cpp/HanyuPinyinOutputFormat.h"

class PINYINSEARCHSHARED_EXPORT PinyinUtil{
public:
    static void parse(PinyinSearchUnit &pinyinSearchUnit);
    static QString getFirstLetter(PinyinSearchUnit &pinyinSearchUnit);
    static QString getFirstCharacter(PinyinSearchUnit &pinyinSearchUnit);
    static QString getSortKey(PinyinSearchUnit &pinyinSearchUnit);
    static bool isChineseCharacter(QChar &chr);
private:
    static HanyuPinyinOutputFormat *format;
    static void addPinyinUnit(QList<PinyinUnit*> *pinyinUnit,PinyinUnit *pyUnit, bool pinyin, QString originalString,QList<QString> *string, int startPosition);
    static void initPinyinUnit(PinyinUnit *pyUnit, bool pinyin, QString originalString,QList<QString> *string, int startPosition);
    static void initPinyinBaseUnit(PinyinBaseUnit *pinyinBaseUnit, QString originalString, QString pinyin);
};
#endif // PINYINUTIL_H
