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

#include "QwertyUtil.h"
//#include <QDebug>

/**
 * @brief QwertyUtil::match
 * @param pinyinSearchUnit
 * @param search
 * @return
 */
bool QwertyUtil::match(PinyinSearchUnit &pinyinSearchUnit, QString &search)
{
    if((NULL==pinyinSearchUnit.getBaseData())/*||(NULL==pinyinSearchUnit.getMatchKeyWord())*/){
        return false;
    }

    pinyinSearchUnit.getMatchKeyWord()->clear();

    //search by  original string
    QString searchLowerCase=search.toLower();
    int index=pinyinSearchUnit.getBaseData().toLower().indexOf(searchLowerCase);
    if(index>-1){
        pinyinSearchUnit.getMatchKeyWord()->append(pinyinSearchUnit.getBaseData().mid(index, /*index+*/searchLowerCase.length()));
        return true;
    }

    //search by pinyin characters
    int pinyinUnitsLength = pinyinSearchUnit.getPinyinUnits()->size();
    QString *pSearchString=new QString();
    for (int i = 0; i < pinyinUnitsLength; i++) {
        int j = 0;
        pinyinSearchUnit.getMatchKeyWord()->clear();
        pSearchString->clear();
        pSearchString->append(searchLowerCase);

        bool found = findPinyinUnits(pinyinSearchUnit.getPinyinUnits(), i, j, pinyinSearchUnit.getBaseData(),pSearchString, pinyinSearchUnit.getMatchKeyWord());
        if (true == found) {
            return true;
        }
    }

    return false;
}

/**
 * @brief QwertyUtil::findPinyinUnits   match search string with pinyinUnits,if success,save the keyword.
 * @param pPinyinUnits                  pinyinUnits head node index
 * @param pinyinUnitIndex               pinyinUint Index
 * @param qwertyPinyinUnitIndex         pinyinBaseUnit Index
 * @param baseData                      base data for search.
 * @param pSearchString                 search keyword.
 * @param pKeyWord                      save the keyword.
 * @return                              true if find,false otherwise.
 */
bool QwertyUtil::findPinyinUnits(QList<PinyinUnit> *pPinyinUnits, int pinyinUnitIndex, int qwertyPinyinUnitIndex, QString &baseData, QString *pSearchString, QString *pKeyWord)
{
    if((NULL==pPinyinUnits)||(NULL==pSearchString)||(NULL==pKeyWord)){
        //qDebug()<<"__LINE__"<<__LINE__<<":false";
        return false;
    }

    QString searchKeyWord=QString(*pSearchString);
    if(searchKeyWord.length()<=0){//match success

        //qDebug()<<"__LINE__"<<__LINE__<<":true";
        return true;
    }

    if(pinyinUnitIndex>=pPinyinUnits->length()){
        //qDebug()<<"__LINE__"<<__LINE__<<":false";
        return false;
     }

     PinyinUnit pyUnit=pPinyinUnits->at(pinyinUnitIndex);
     if(qwertyPinyinUnitIndex>=pyUnit.getPinyinBaseUnitIndex()->length()){
          //qDebug()<<"__LINE__"<<__LINE__<<":false";
          return false;
     }

     PinyinBaseUnit pinyinBaseUnit = pyUnit.getPinyinBaseUnitIndex()->at(qwertyPinyinUnitIndex);

     if (pyUnit.isPinyin()) {

         if (searchKeyWord.startsWith(pinyinBaseUnit.getPinyin().at(0))) {// match pinyin first character
             pSearchString->remove(0, 1);// delete the match character
             pKeyWord->append(baseData.at(pyUnit.getStartPosition()));
             bool found = QwertyUtil::findPinyinUnits(pPinyinUnits,pinyinUnitIndex + 1, 0, baseData, pSearchString,pKeyWord);
             if (true == found) {
                 return true;
             } else {
                 pSearchString->insert(0, pinyinBaseUnit.getPinyin().at(0));
                 pKeyWord->remove(pKeyWord->length() - 1,1);
             }

         }

         if (pinyinBaseUnit.getPinyin().startsWith(searchKeyWord)) {
             // The string of "searchKeyWord" is the string of pinyinBaseUnit.getPinyin() of a subset. means match success.
             pKeyWord->append(baseData.at(pyUnit.getStartPosition()));
             pSearchString->remove(0, pSearchString->length());
             return true;

         } else if (searchKeyWord.startsWith(pinyinBaseUnit.getPinyin())) { // match quanpin success
             // The string of pinyinBaseUnit.getPinyin() is the string of "searchKeyWord" of a subset.
             pSearchString->remove(0, pinyinBaseUnit.getPinyin().length());
             pKeyWord->append(baseData.at(pyUnit.getStartPosition()));
             bool found = findPinyinUnits(pPinyinUnits,pinyinUnitIndex+1, 0, baseData, pSearchString,pKeyWord);
             if (true == found) {
                 return true;
             } else {
                 pSearchString->insert(0, pinyinBaseUnit.getPinyin());
                 pKeyWord->remove(pKeyWord->length()-1,1);
             }
         } else { // mismatch
             bool found = findPinyinUnits(pPinyinUnits, pinyinUnitIndex,qwertyPinyinUnitIndex+1, baseData, pSearchString,pKeyWord);
             if (found == true) {
                 return true;
             }
         }

     } else { // non-pure Pinyin
         if (pinyinBaseUnit.getPinyin().startsWith(searchKeyWord)) {
             // The string of "searchKeyWord" is the string of pinyinBaseUnit.getPinyin() of a subset.
             int startIndex = 0;
             pKeyWord->append(baseData.mid(startIndex+pyUnit.getStartPosition(),/* startIndex+pyUnit.getStartPosition() + */searchKeyWord.length()));
             pSearchString->remove(0, pSearchString->length());
             return true;
         } else if (searchKeyWord.startsWith(pinyinBaseUnit.getPinyin())) { // match all non-pure pinyin
             // The string of pinyinBaseUnit.getPinyin() is the string of "searchKeyWord" of a subset.
             int startIndex = 0;
             pSearchString->remove(0, pinyinBaseUnit.getPinyin().length());
             pKeyWord->append(baseData.mid(startIndex+pyUnit.getStartPosition(),/*startIndex+pyUnit.getStartPosition()+*/pinyinBaseUnit.getPinyin().length()));
             bool found = findPinyinUnits(pPinyinUnits,pinyinUnitIndex+1, 0, baseData, pSearchString,pKeyWord);
             if (true == found) {
                 return true;
             } else {
                 pSearchString->insert(0, pinyinBaseUnit.getPinyin());
                 pKeyWord->remove(pKeyWord->length()-pinyinBaseUnit.getPinyin().length(),pKeyWord->length());
             }
         } else if ((pKeyWord->length() <= 0)) {
             if (pinyinBaseUnit.getPinyin().contains(searchKeyWord)) {
                 int index = pinyinBaseUnit.getPinyin().indexOf(searchKeyWord);
                 pKeyWord->append(baseData.mid(index+pyUnit.getStartPosition(),/*index+pyUnit.getStartPosition()+*/searchKeyWord.length()));
                 pSearchString->remove(0, pSearchString->length());
                 return true;
             } else {
                 // match case:[Non-Chinese characters]+[Chinese characters]
                 // for example:baseData="Tony测试"; match this case:"onycs"
                 // start [Non-Chinese characters]+[Chinese characters]
                 int numLength = pinyinBaseUnit.getPinyin().length();
                 for (int i = 0; i < numLength; i++) {
                     QString subStr = pinyinBaseUnit.getPinyin().mid(i);
                     if (searchKeyWord.startsWith(subStr)) {
                         pSearchString->remove(0, subStr.length());
                         pKeyWord->append(baseData.mid(i+pyUnit.getStartPosition(),/*i+pyUnit.getStartPosition()+*/subStr.length()));
                         bool found = findPinyinUnits(pPinyinUnits,pinyinUnitIndex+1, 0, baseData,pSearchString, pKeyWord);
                         if (true == found) {
                             return true;
                         } else {
                             pSearchString->insert(0, pinyinBaseUnit.getPinyin().mid(i));
                             pKeyWord->remove(pKeyWord->length()-subStr.length(),pKeyWord->length());
                         }

                     }
                 }
                 // end [Non-Chinese characters]+[Chinese characters]

                 // in fact,if pyUnit.isPinyin()==false, pyUnit.getQwertyPinyinUnitIndex().size()==1. The function of findPinyinUnits() will return false.
                 bool found = findPinyinUnits(pPinyinUnits,pinyinUnitIndex, qwertyPinyinUnitIndex + 1, baseData,pSearchString, pKeyWord);
                 if (true == found) {
                     return true;
                 }
             }
         } else { // mismatch
             // in fact,if pyUnit.isPinyin()==false, pyUnit.getQwertyPinyinUnitIndex().size()==1. The function of findPinyinUnits() will return false.
             bool found = findPinyinUnits(pPinyinUnits, pinyinUnitIndex,qwertyPinyinUnitIndex+1, baseData, pSearchString,pKeyWord);
             if (true == found) {
                 return true;
             }
         }
     }
    return false;
}
