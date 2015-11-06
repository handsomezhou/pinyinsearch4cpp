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

#ifndef PINYINSEARCHUNIT_H
#define PINYINSEARCHUNIT_H
#include <QString>
#include <QStringBuilder>
#include "PinyinUnit.h"

class PinyinSearchUnit
{
public:
    PinyinSearchUnit();
    PinyinSearchUnit(QString baseData);
    QString getBaseData() const;
    void setBaseData(const QString &baseData);

    QList<PinyinUnit> *getPinyinUnits() const;
    void setPinyinUnits(QList<PinyinUnit> *pinyinUnits);

    QString getMatchKeyWord() const;
    void setMatchKeyWord(const QString &matchKeyWord);



private:
    QString baseData;  //the original string
    QList<PinyinUnit> *pinyinUnits;
    QString matchKeyWord;//the sub string of base data which search by key word;
};
#endif // PINYINSEARCHUNIT_H
