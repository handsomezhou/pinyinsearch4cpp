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
#include "T9Util.h"
#include "../../pinyin4cpp/pinyin4cpp/HanyuPinyinCaseType.h"
#include "../../pinyin4cpp/pinyin4cpp/PinyinHelper.h"
#include "../../pinyin4cpp/pinyin4cpp/HanyuPinyinToneType.h"
#include "PinyinBaseUnit.h"
//#include <QDebug>

/**
 * Convert from base data to a series of PinyinUnit
 *
 * @brief PinyinUtil::parse
 * @param pinyinSearchUnit
 */
void PinyinUtil::parse(PinyinSearchUnit &pinyinSearchUnit)
{

    if((pinyinSearchUnit.getBaseData().isEmpty())||(NULL==pinyinSearchUnit.getPinyinUnits())){

       return;
    }

    //qDebug()<<"__FILE__"<<__FILE__<<"; __FUNCTION__"<< __FUNCTION__<<";__LINE__"<<__LINE__<<";["<<pinyinSearchUnit.getBaseData()<<"]";
    QString chineseStr=pinyinSearchUnit.getBaseData().toLower();
    //qDebug()<<"__FILE__"<<__FILE__<<"; __FUNCTION__"<< __FUNCTION__<<";__LINE__"<<__LINE__<<";["<<chineseStr<<"]";

    if(NULL==format){
        format=new HanyuPinyinOutputFormat();
    }

    format->setToneType((HanyuPinyinToneType::WITHOUT_TONE));

    int chineseStringLength=chineseStr.length();
    QString nonPinyinString;
    PinyinUnit *pyUnit=NULL;
    QString originalString;
    QList<QString> *pinyinList=new QList<QString>();
    bool lastChineseCharacters = true;
    int startPosition = -1;
    QChar ch;
    //qDebug()<<"__FILE__"<<__FILE__<<"; __FUNCTION__"<< __FUNCTION__<<";__LINE__"<<__LINE__<<";["<<chineseStringLength<<"]";
    for(int i=0; i<chineseStringLength; i++){
         //qDebug()<<"****************************************";
        ch=chineseStr.at(i);
        pinyinList->clear();
        PinyinHelper::toHanyuPinyinStringArray(ch,format,pinyinList);
        //qDebug()<<"pinyinList->size()"<<pinyinList->size();
        for(int k=0; k<pinyinList->size();k++){
              //qDebug()<<"pinyinList"<<k<<":"<<pinyinList->at(k);
        }
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
                // add continuous non-ChineseCharacter characters to PinyinUnit
                originalString = nonPinyinString;
                QList<QString> *str=new QList<QString>();
                str->append(nonPinyinString);
                //qDebug()<<"originalString111["<<originalString<<"]";
                PinyinUtil::addPinyinUnit(pinyinSearchUnit.getPinyinUnits(), pyUnit, false, originalString,str, startPosition);

                nonPinyinString.clear();
                lastChineseCharacters = true;
            }
            // add single Chinese characters Pinyin(include Multiple Pinyin)
            // to PinyinUnit
            pyUnit = new PinyinUnit();
            startPosition = i;
            originalString =ch;
            //qDebug()<<"originalString222["<<originalString<<"]";
            PinyinUtil::addPinyinUnit(pinyinSearchUnit.getPinyinUnits(), pyUnit, true, originalString,pinyinList, startPosition);

        }
    }

        if (false == lastChineseCharacters) {
            // add continuous non-ChineseCharacter characters to PinyinUnit
            originalString = nonPinyinString;
            QList<QString> *str=new QList<QString>();
            str->append(nonPinyinString);
             //qDebug()<<"originalString333["<<originalString<<"]";
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
    do {

        QList<PinyinUnit*> *pPinyinUnit=pinyinSearchUnit.getPinyinUnits();
        if ((NULL == pPinyinUnit) || (pPinyinUnit->size() <= 0)) {
            break;
        }

        QList<PinyinBaseUnit*> *pPinyinBaseUnit = pPinyinUnit->at(0)->getPinyinBaseUnitIndex();
        if (NULL == pPinyinBaseUnit || pPinyinBaseUnit->size() <= 0) {
            break;
        }

        QString pinyin = pPinyinBaseUnit->at(0)->getPinyin();
        if (NULL == pinyin || pinyin.length() <= 0) {
            break;
        }

        return pinyin.at(0);

    } while (false);


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

    do {


        QList<PinyinUnit*> *pPinyinUnit=pinyinSearchUnit.getPinyinUnits();
        if ((NULL == pPinyinUnit) || (pPinyinUnit->size() <= 0)) {
            break;
        }

        QList<PinyinBaseUnit*> *pPinyinBaseUnit = pPinyinUnit->at(0)->getPinyinBaseUnitIndex();
        if ((NULL == pPinyinBaseUnit) || (pPinyinBaseUnit->size() <= 0)) {
            break;
        }

        QString originalString = pPinyinBaseUnit->at(0)->getOriginalString();
        if (NULL == originalString || originalString.length() <= 0) {
            break;
        }

        return originalString.at(0);

    } while (false);


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
    QString sortKeyStr;
    QString splitSymbol=" ";
    do {

        QList<PinyinUnit*> *pPinyinUnit=pinyinSearchUnit.getPinyinUnits();
        if ((NULL == pPinyinUnit) || (pPinyinUnit->size() <= 0)) {
            break;
        }

        int pinyinUnitSize=pPinyinUnit->size();
        for(int i=0; i<pinyinUnitSize;i++){
            if(pPinyinUnit->at(i)->isPinyin()){
                sortKeyStr.append(pPinyinUnit->at(i)->getPinyinBaseUnitIndex()->at(0)->getPinyin()).append(splitSymbol);
                sortKeyStr.append(pPinyinUnit->at(i)->getPinyinBaseUnitIndex()->at(0)->getOriginalString()).append(splitSymbol);
            }else{
                sortKeyStr.append(pPinyinUnit->at(i)->getPinyinBaseUnitIndex()->at(0)->getOriginalString()).append(splitSymbol);
            }
        }
        return sortKeyStr;
    } while (false);

    return NULL;
}

/**
 * judge chr is Chinese Character
 *
 * @brief PinyinUtil::isChineseCharacter
 * @param chr
 * @return Is Chinese Character return true,otherwise return false.
 */
bool PinyinUtil::isChineseCharacter(QChar &chr)
{

    HanyuPinyinOutputFormat *outputFormat=new HanyuPinyinOutputFormat();
    QList<QString> *pinyinList=new QList<QString>();
    PinyinHelper::toHanyuPinyinStringArray(chr,outputFormat,pinyinList);

    return (pinyinList->size()<=0)?(false):(true);
}

void PinyinUtil::addPinyinUnit(QList<PinyinUnit*> *pPinyinUnit, PinyinUnit *pyUnit, bool pinyin, QString originalString, QList<QString> *string, int startPosition)
{
    if((NULL==pPinyinUnit)||(NULL==pyUnit)||(NULL==originalString)||(NULL==string)){
        return;
    }
    PinyinUtil::initPinyinUnit(pyUnit,pinyin,originalString,string,startPosition);
    pPinyinUnit->append(pyUnit);

    return;
}

void PinyinUtil::initPinyinUnit(PinyinUnit *pyUnit, bool pinyin, QString originalString, QList<QString> *string, int startPosition)
{
     //qDebug()<<"+++++pinyin["<<pinyin<<"]originalString["+originalString<<"]startPosition["<<startPosition<<"]";


    if((NULL==pyUnit)||(NULL==originalString)||(NULL==string)){
        return;
    }

    for(int t=0;t<string->size();t++){
        //qDebug()<<"t="<<t<<":"<<string->at(t);
    }
    int i = 0;
    int j = 0;
    int k = 0;
    int strLength = string->length();
    pyUnit->setPinyin(pinyin);
    pyUnit->setStartPosition(startPosition);

    PinyinBaseUnit *pPinyinBaseUnit=NULL;

    if (false == pinyin || strLength <= 1) {// no more than one pinyin
        for (i = 0; i < strLength; i++) {
            pPinyinBaseUnit = new PinyinBaseUnit();
            PinyinUtil::initPinyinBaseUnit(pPinyinBaseUnit, originalString, string->at(i));
             //qDebug()<<"---"<<pinyinBaseUnit->getPinyin()<<";"<<pinyinBaseUnit->getOriginalString()<<";"<<pinyinBaseUnit->getNumber();
            pyUnit->getPinyinBaseUnitIndex()->append(pPinyinBaseUnit);

        }
           //qDebug()<<"---"<<pyUnit->getPinyinBaseUnitIndex()->size();
    } else { // more than one pinyin.//we must delete the same pinyin
                        // string,because pinyin without tone.

            pPinyinBaseUnit = new PinyinBaseUnit();
            PinyinUtil::initPinyinBaseUnit(pPinyinBaseUnit, originalString, string->at(0));
            pyUnit->getPinyinBaseUnitIndex()->append(pPinyinBaseUnit);
            for (j = 1; j < strLength; j++) {
                int curStringIndexlength = pyUnit->getPinyinBaseUnitIndex()->size();
                for (k = 0; k < curStringIndexlength; k++) {
                    if (pyUnit->getPinyinBaseUnitIndex()->at(k)->getPinyin().compare(string->at(j))==0) {
                        break;
                    }
                }

                if (k == curStringIndexlength) {
                    pPinyinBaseUnit = new PinyinBaseUnit();
                    PinyinUtil::initPinyinBaseUnit(pPinyinBaseUnit, originalString, string->at(j));
                    pyUnit->getPinyinBaseUnitIndex()->append(pPinyinBaseUnit);
                }
            }
    }
    //qDebug()<<"pyUnit->getPinyinBaseUnitIndex().size():"<< pyUnit->getPinyinBaseUnitIndex()->size();
    return;
}

void PinyinUtil::initPinyinBaseUnit(PinyinBaseUnit *pinyinBaseUnit, QString originalString, QString pinyin)
{
    if((NULL==pinyinBaseUnit)||(NULL==originalString)||(NULL==pinyin)){
        return;
    }

    pinyinBaseUnit->setOriginalString( QString(originalString));
    pinyinBaseUnit->setPinyin(QString(pinyin));
    int pinyinLength = pinyin.length();

    QString numberStr;

    for (int i = 0; i < pinyinLength; i++) {
        QChar alphabet=pinyin.at(i);
        QChar ch = T9Util::getT9Number(alphabet);
        numberStr.append(ch);
    }

    pinyinBaseUnit->setNumber(QString(numberStr));

    return;
}


HanyuPinyinOutputFormat* PinyinUtil::format=new HanyuPinyinOutputFormat();
