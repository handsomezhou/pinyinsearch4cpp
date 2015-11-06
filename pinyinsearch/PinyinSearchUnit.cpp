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

#include "PinyinSearchUnit.h"

PinyinSearchUnit::PinyinSearchUnit()
{
    this->pinyinUnits=new  QList<PinyinUnit>();
}

PinyinSearchUnit::PinyinSearchUnit(QString baseData)
{
    this->baseData=baseData;
    this->pinyinUnits=new  QList<PinyinUnit>();
}

QString PinyinSearchUnit::getBaseData() const
{
    return this->baseData;
}

void PinyinSearchUnit::setBaseData(const QString &baseData)
{
    this->baseData = baseData;
}

QList<PinyinUnit> *PinyinSearchUnit::getPinyinUnits() const
{
    return pinyinUnits;
}

void PinyinSearchUnit::setPinyinUnits(QList<PinyinUnit> *pinyinUnits)
{
    this->pinyinUnits = pinyinUnits;
}

QString PinyinSearchUnit::getMatchKeyWord() const
{
    return this->matchKeyWord;
}

void PinyinSearchUnit::setMatchKeyWord(const QString &matchKeyWord)
{
    this->matchKeyWord = matchKeyWord;
}




