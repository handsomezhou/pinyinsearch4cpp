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

#include "T9Util.h"
//#include <QDebug>

/**
 * @brief T9Util::getT9Number
 * @param alphabet
 * @return
 */
QChar T9Util::getT9Number(QChar &alphabet)
{
    /**
     * T9 keyboard
     * 1 		2(ABC)	3(DEF)
     * 4(GHI) 	5(JKL) 	6(MNO)
     * 7(PQRS) 	8(TUV) 	9(WXYZ)
     * *		0 		#
     */
    QChar ch = alphabet;

    switch (alphabet.unicode()) {
    case 'A':
    case 'a':
    case 'B':
    case 'b':
    case 'C':
    case 'c':
        ch = '2';
        break;

    case 'D':
    case 'd':
    case 'E':
    case 'e':
    case 'F':
    case 'f':
        ch = '3';
        break;

    case 'G':
    case 'g':
    case 'H':
    case 'h':
    case 'I':
    case 'i':
        ch = '4';
        break;

    case 'J':
    case 'j':
    case 'K':
    case 'k':
    case 'L':
    case 'l':
        ch = '5';
        break;

    case 'M':
    case 'm':
    case 'N':
    case 'n':
    case 'O':
    case 'o':
        ch = '6';
        break;

    case 'P':
    case 'p':
    case 'Q':
    case 'q':
    case 'R':
    case 'r':
    case 'S':
    case 's':
        ch = '7';
        break;

    case 'T':
    case 't':
    case 'U':
    case 'u':
    case 'V':
    case 'v':
        ch = '8';
        break;

    case 'W':
    case 'w':
    case 'X':
    case 'x':
    case 'Y':
    case 'y':
    case 'Z':
    case 'z':
        ch = '9';
        break;

    default:
        break;
    }

    return ch;
}



/**
 * @brief T9Util::match
 * @param pinyinSearchUnit
 * @param search
 * @return true if match success,false otherwise.
 */

bool T9Util::match(PinyinSearchUnit &pinyinSearchUnit, QString &search)
{
    //qDebug()<<"match()111getBaseData["<<pinyinSearchUnit.getBaseData()<<"]";
    //qDebug()<<"match()222getMatchKeyWord["<<*pinyinSearchUnit.getMatchKeyWord()<<"]";
    if((NULL==pinyinSearchUnit.getBaseData())/*||(NULL==pinyinSearchUnit.getMatchKeyWord())*/){
        return false;
    }
    pinyinSearchUnit.getMatchKeyWord()->clear();
    //qDebug()<<"match()333getMatchKeyWord["<<*pinyinSearchUnit.getMatchKeyWord();
    int pinyinUnitsLength=pinyinSearchUnit.getPinyinUnits()->size();
    QString *pSearchString=new QString();
    for(int i=0; i<pinyinUnitsLength; i++){
        int j=0;
        pinyinSearchUnit.getMatchKeyWord()->clear();
        pSearchString->clear();
        pSearchString->append(search);
        bool found= T9Util::findPinyinUnits(pinyinSearchUnit.getPinyinUnits(),i,j,pinyinSearchUnit.getBaseData(),pSearchString,pinyinSearchUnit.getMatchKeyWord());
        if (true == found){
             //qDebug()<<"match()444 true getMatchKeyWord["<<*pinyinSearchUnit.getMatchKeyWord();
            return true;
        }
    }

    //qDebug()<<"match()555 false getMatchKeyWord["<<*pinyinSearchUnit.getMatchKeyWord();

    return false;
}

/**
 * @brief T9Util::findPinyinUnits   match search string with pinyinUnits,if success,save the keyword.
 * @param pinyinUnits       pinyinUnits head node index
 * @param pinyinUnitIndex   pinyinUint Index
 * @param t9PinyinUnitIndex t9PinyinUnit Index
 * @param pBaseData         base data for search.
 * @param pSearchString     search keyword.
 * @param pKeyWord          save the keyword.
 * @return                  true if find,false otherwise.
 */
bool T9Util::findPinyinUnits(QList<PinyinUnit> *pPinyinUnits, int pinyinUnitIndex, int t9PinyinUnitIndex, QString &baseData, QString *pSearchString, QString *pKeyWord)
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
    if(t9PinyinUnitIndex>=pyUnit.getPinyinBaseUnitIndex()->length()){
         //qDebug()<<"__LINE__"<<__LINE__<<":false";
        return false;
    }

    PinyinBaseUnit pinyinBaseUnit=pyUnit.getPinyinBaseUnitIndex()->at(t9PinyinUnitIndex);
    if(pyUnit.isPinyin()){
        if(searchKeyWord.startsWith(pinyinBaseUnit.getNumber().at(0))){// match pinyin first character
            pSearchString->remove(0,1);//delete the match character
            pKeyWord->append(baseData.at(pyUnit.getStartPosition()));
            bool found=T9Util::findPinyinUnits(pPinyinUnits, pinyinUnitIndex+1, 0, baseData, pSearchString,pKeyWord);
            if(true==found){
                 //qDebug()<<"__LINE__"<<__LINE__<<":true";
                return true;
            }else{
              pSearchString->insert(0, pinyinBaseUnit.getNumber().at(0));
              pKeyWord->remove(pKeyWord->length()-1,1);
            }

        }

        if(pinyinBaseUnit.getNumber().startsWith(searchKeyWord)){
            //The string of "searchKeyWord" is the string of t9PinyinUnit.getNumber() of a subset. means match success.
           pKeyWord->append(baseData.at(pyUnit.getStartPosition()));
           pSearchString->remove(0, pSearchString->length());
            //qDebug()<<"__LINE__"<<__LINE__<<":true";
            return true;

        }else if(searchKeyWord.startsWith(pinyinBaseUnit.getNumber())){ //match quanpin  success
            //The string of t9PinyinUnit.getNumber() is the string of "searchKeyWord" of a subset.
            pSearchString->remove(0, pinyinBaseUnit.getNumber().length());

           pKeyWord->append(baseData.at(pyUnit.getStartPosition()));
            bool found=findPinyinUnits(pPinyinUnits, pinyinUnitIndex+1, 0, baseData, pSearchString,pKeyWord);
            if(true==found){
                 //qDebug()<<"__LINE__"<<__LINE__<<":true";
                return true;
            }else{
               pSearchString->insert(0, pinyinBaseUnit.getNumber());
               pKeyWord->remove(pKeyWord->length()-1,1);

            }
        }else{ //mismatch
            bool found=findPinyinUnits(pPinyinUnits, pinyinUnitIndex, t9PinyinUnitIndex+1, baseData, pSearchString,pKeyWord);
            if(found==true){
                 //qDebug()<<"__LINE__"<<__LINE__<<":true";
                return true;
            }
        }

    }else{ //non-pure Pinyin

        if(pinyinBaseUnit.getNumber().startsWith(searchKeyWord)){
            //The string of "searchKeyWord" is the string of t9PinyinUnit.getNumber() of a subset.
            int startIndex=0;
           //qDebug()<<" searchKeyWord:"<<searchKeyWord;
           //qDebug()<<" before pKeyWord:"<<*pKeyWord;
           //qDebug()<<" baseData:"<<baseData;
           pKeyWord->append(baseData.mid(startIndex+pyUnit.getStartPosition(),/*startIndex+pyUnit.getStartPosition()+ */searchKeyWord.length()));

           pSearchString->remove(0, pSearchString->length());
           //qDebug()<<" after pKeyWord:"<<*pKeyWord;
            //qDebug()<<"__LINE__"<<__LINE__<<":true";
            return true;
        }else if(searchKeyWord.startsWith(pinyinBaseUnit.getNumber())){ //match all non-pure pinyin
            //The string of t9PinyinUnit.getNumber() is the string of "searchKeyWord" of a subset.
            int startIndex=0;

            pSearchString->remove(0, pinyinBaseUnit.getNumber().length());
           pKeyWord->append(baseData.mid(startIndex+pyUnit.getStartPosition(),/*startIndex+pyUnit.getStartPosition()+*/ pinyinBaseUnit.getNumber().length()));
            bool found=findPinyinUnits(pPinyinUnits, pinyinUnitIndex+1, 0, baseData, pSearchString,pKeyWord);
            if(true==found){
                //qDebug()<<"__LINE__"<<__LINE__<<":true";
                return true;
            }else{
                pSearchString->insert(0, pinyinBaseUnit.getNumber());
               pKeyWord->remove(pKeyWord->length()-pinyinBaseUnit.getNumber().length(),pKeyWord->length());
            }
        }else if((pKeyWord->length()<=0)){
            if(pinyinBaseUnit.getNumber().contains(searchKeyWord)){
                int index=pinyinBaseUnit.getNumber().indexOf(searchKeyWord);
               pKeyWord->append(baseData.mid(index+pyUnit.getStartPosition(),/*index+pyUnit.getStartPosition()+*/searchKeyWord.length()));
                pSearchString->remove(0, pSearchString->length());
                 //qDebug()<<"__LINE__"<<__LINE__<<":true";
                return true;
            }else{
                // match case:[Non-Chinese characters]+[Chinese characters]
                //for example:baseData="Tony测试"; match this case:"onycs"<===>"66927"
                //start [Non-Chinese characters]+[Chinese characters]
                int numLength=pinyinBaseUnit.getNumber().length();
                for(int i=0; i<numLength; i++){
                    QString subStr=pinyinBaseUnit.getNumber().mid(i);
                    if(searchKeyWord.startsWith(subStr)){
                        pSearchString->remove(0, subStr.length());
                       pKeyWord->append(baseData.mid(i+pyUnit.getStartPosition(),/* i+pyUnit.getStartPosition()+*/subStr.length()));
                        bool found=findPinyinUnits(pPinyinUnits, pinyinUnitIndex+1, 0, baseData, pSearchString,pKeyWord);
                        if(true==found){
                             //qDebug()<<"__LINE__"<<__LINE__<<":true";
                            return true;
                        }else{
                           pSearchString->insert(0, pinyinBaseUnit.getNumber().mid(i));
                           pKeyWord->remove(pKeyWord->length()-subStr.length(),pKeyWord->length());
                        }

                    }
                }
                //end [Non-Chinese characters]+[Chinese characters]

                //in fact,if pyUnit.isPinyin()==false, pyUnit.getPinyinBaseUnitIndex().size()==1. The function of findPinyinUnits() will return false.
                bool found=findPinyinUnits(pPinyinUnits, pinyinUnitIndex, t9PinyinUnitIndex+1, baseData, pSearchString,pKeyWord);
                if(true==found){
                     //qDebug()<<"__LINE__"<<__LINE__<<":true";
                    return true;
                }
            }
        }else { //mismatch
            //in fact,if pyUnit.isPinyin()==false, pyUnit.getPinyinBaseUnitIndex().size()==1.  The function of findPinyinUnits() will return false.
            bool found=findPinyinUnits(pPinyinUnits, pinyinUnitIndex, t9PinyinUnitIndex+1, baseData, pSearchString,pKeyWord);
            if(true==found){
                 //qDebug()<<"__LINE__"<<__LINE__<<":true";
                return true;
            }
        }
        }
     //qDebug()<<"__LINE__"<<__LINE__<<":false";
    return false;
}
