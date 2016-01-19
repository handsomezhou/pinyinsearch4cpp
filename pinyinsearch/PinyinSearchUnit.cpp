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
//#include <QDebug>

PinyinSearchUnit::PinyinSearchUnit()
{
    this->m_pPinyinUnits=new  QList<PinyinUnit*>();
    this->m_pMatchKeyWord=new QString();
}

PinyinSearchUnit::PinyinSearchUnit(QString baseData)
{
    this->mBaseData=baseData;
    this->m_pPinyinUnits=new  QList<PinyinUnit*>();
}

QString &PinyinSearchUnit::getBaseData()
{
    return this->mBaseData;
}

void PinyinSearchUnit::setBaseData(const QString &baseData)
{
    this->mBaseData = baseData;
}

QList<PinyinUnit*> *PinyinSearchUnit::getPinyinUnits() const
{
    return m_pPinyinUnits;
}

void PinyinSearchUnit::setPinyinUnits(QList<PinyinUnit*> *pPinyinUnits)
{
    this->m_pPinyinUnits = pPinyinUnits;
}

QString *PinyinSearchUnit::getMatchKeyWord() const
{
    return this->m_pMatchKeyWord;
}

void PinyinSearchUnit::setMatchKeyWord(QString *pMatchKeyWord)
{
    this->m_pMatchKeyWord=pMatchKeyWord;
}



void PinyinSearchUnit::show()
{

    /*
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
     */
}





