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

#ifndef T9UTIL_H
#define T9UTIL_H
#include <QChar>
#include <QString>
#include "PinyinSearchUnit.h"

class PINYINSEARCHSHARED_EXPORT T9Util
{
public:
    static QChar getT9Number(QChar &alphabet);
    static bool match(PinyinSearchUnit &pinyinSearchUnit,QString &search);
private:
    static bool findPinyinUnits(QList<PinyinUnit*> *pPinyinUnits,int pinyinUnitIndex,int t9PinyinUnitIndex,QString &baseData, QString *pSearchString,QString *pKeyWord );
};
#endif // T9UTIL_H
