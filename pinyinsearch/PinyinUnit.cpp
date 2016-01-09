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

#include "PinyinUnit.h"


/**
 * PinyinUnit as a base data structure to save the string that Chinese characters  converted to Pinyin characters.
 * for example:
 * Reference: http://www.cnblogs.com/bomo/archive/2012/12/25/2833081.html
 * Chinese characters:"Hi你说了什么git???"
 * Pinyin:
 * 		Hi-Hi					===>pinyin=false, 	pinyinBaseUnitIndex.size=1, startPosition=0
 * 		{[pinyinBaseUnitIndex.get(0).getPinyin()="Hi",pinyinBaseUnitIndex.get(0).getNumber="Hi"];}
 *
 * 		你->ni3					===>pinyin=true, 	pinyinBaseUnitIndex.size=1,	startPosition=2
 * 		{[pinyinBaseUnitIndex.get(0).getPinyin()="ni",pinyinBaseUnitIndex.get(0).getNumber="64"];}
 *
 *     	说->shuo1,shui4,yue4 	===>pinyin=true,	pinyinBaseUnitIndex.size=3,	startPosition=3
 *     	{
 *     	[pinyinBaseUnitIndex.get(0).getPinyin()="shuo",pinyinBaseUnitIndex.get(0).getNumber="7486"];
 *     	[pinyinBaseUnitIndex.get(1).getPinyin()="shui",pinyinBaseUnitIndex.get(1).getNumber="7484"];
 *     	[pinyinBaseUnitIndex.get(2).getPinyin()="yue",pinyinBaseUnitIndex.get(2).getNumber="983"];}
 *
 *      了->le5,liao3,liao4  	===>pinyin=true, 	pinyinBaseUnitIndex.size=2,	startPosition=4
 *     	{
 *     	[pinyinBaseUnitIndex.get(0).getPinyin()="le",pinyinBaseUnitIndex.get(0).getNumber="53"];
 *     	[pinyinBaseUnitIndex.get(1).getPinyin()="liao",pinyinBaseUnitIndex.get(1).getNumber="5426"];}
 *
 * 		什->shen2,shi2,she2		===>pinyin=true, 	pinyinBaseUnitIndex.size=3, startPosition=5
 * 		{
 *     	[pinyinBaseUnitIndex.get(0).getPinyin()="shen",pinyinBaseUnitIndex.get(0).getNumber="7436"];
 *     	[pinyinBaseUnitIndex.get(1).getPinyin()="shi",pinyinBaseUnitIndex.get(1).getNumber="744"];
 *     	[pinyinBaseUnitIndex.get(2).getPinyin()="she",pinyinBaseUnitIndex.get(2).getNumber="743"];}
 *
 * 		么->me5,ma5,yao1			===>pinyin=true,	pinyinBaseUnitIndex.size=3, startPosition=6
 * 		{
 *     	[pinyinBaseUnitIndex.get(0).getPinyin()="me",pinyinBaseUnitIndex.get(0).getNumber="63"];
 *     	[pinyinBaseUnitIndex.get(1).getPinyin()="ma",pinyinBaseUnitIndex.get(1).getNumber="62"];
 *     	[pinyinBaseUnitIndex.get(2).getPinyin()="yao",pinyinBaseUnitIndex.get(2).getNumber="926"];}
 *
 * 		git???->git???				===>pinyin=false, 	pinyinBaseUnitIndex.size=1, startPosition=7
 * 		{[pinyinBaseUnitIndex.get(0).getPinyin()="git???",pinyinBaseUnitIndex.get(0).getNumber="448???"];}
 *
 */
PinyinUnit::PinyinUnit()
{
    this->pinyin=false;
    this->startPosition=-1;
    this->pinyinBaseUnitIndex=new QList<PinyinBaseUnit>();
}

bool PinyinUnit::isPinyin() const
{
    return this->pinyin;
}

void PinyinUnit::setPinyin(bool pinyin)
{
    this->pinyin=pinyin;
}

int PinyinUnit::getStartPosition() const
{
    return this->startPosition;
}

void PinyinUnit::setStartPosition(int startPosition)
{
    this->startPosition=startPosition;
}

QList<PinyinBaseUnit> *PinyinUnit::getPinyinBaseUnitIndex() const
{
    return this->pinyinBaseUnitIndex;
}

void PinyinUnit::setPinyinBaseUnitIndex(QList<PinyinBaseUnit> *pinyinBaseUnitIndex)
{
    this->pinyinBaseUnitIndex = pinyinBaseUnitIndex;
}



