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
#include <QDebug>

PinyinSearchUnit::PinyinSearchUnit()
{
    this->pinyinUnits=new  QList<PinyinUnit>();
}

PinyinSearchUnit::PinyinSearchUnit(QString baseData)
{
    this->baseData=baseData;
    this->pinyinUnits=new  QList<PinyinUnit>();
}

QString &PinyinSearchUnit::getBaseData()
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

QString &PinyinSearchUnit::getMatchKeyWord()
{
    return this->matchKeyWord;
}

void PinyinSearchUnit::setMatchKeyWord(const QString &matchKeyWord)
{
    this->matchKeyWord = matchKeyWord;
}

void PinyinSearchUnit::show()
{
     qDebug()<<"getBaseData["<<this->getBaseData()<<"]this->getPinyinUnits()->size()["<<this->getPinyinUnits()->size()<<"]MatchKeyWord["<<this->getMatchKeyWord()<<"]";
    QList<PinyinUnit> *pinyinUnitList= this->getPinyinUnits();

    for(int i=0; i<pinyinUnitList->length(); i++){
        qDebug()<<"isPinyin["<<pinyinUnitList->at(i).isPinyin()<<"]StartPosition["<<pinyinUnitList->at(i).getStartPosition()<<"]pinyinUnitList->at(i).getPinyinBaseUnitIndex()["<<pinyinUnitList->at(i).getPinyinBaseUnitIndex()->length()<<"]";
        QList<PinyinBaseUnit> *pinyinBaseUnitQList=pinyinUnitList->at(i).getPinyinBaseUnitIndex();
        for(int j=0; j<pinyinBaseUnitQList->length();j++){
            qDebug()<<"originalString["<<pinyinBaseUnitQList->at(j).getOriginalString()<<"]Pinyin["<<pinyinBaseUnitQList->at(j).getPinyin()<<"]Number["<<pinyinBaseUnitQList->at(j).getNumber()<<"]";
        }
    }
     qDebug()<<"****************************************************";
}




