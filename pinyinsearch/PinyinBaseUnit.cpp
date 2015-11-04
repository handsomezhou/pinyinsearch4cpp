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

#include "PinyinBaseUnit.h"

PinyinBaseUnit::PinyinBaseUnit()
{

    return;
}

PinyinBaseUnit::PinyinBaseUnit(QString originalString, QString pinyin, QString number)
{
    this->originalString=originalString;
    this->pinyin = pinyin;
    this->number = number;
}

QString PinyinBaseUnit::getOriginalString() const
{
    return originalString;
}

void PinyinBaseUnit::setOriginalString(const QString &originalString)
{
    this->originalString = originalString;
}

QString PinyinBaseUnit::getPinyin() const
{
    return pinyin;
}

void PinyinBaseUnit::setPinyin(const QString &pinyin)
{
    this->pinyin = pinyin;
}

QString PinyinBaseUnit::getNumber() const
{
    return number;
}

void PinyinBaseUnit::setNumber(const QString &number)
{
    this->number = number;

}
QString PinyinBaseUnit::getOriginalString() const
{
    return originalString;
}

void PinyinBaseUnit::setOriginalString(const QString &value)
{
    originalString = value;
}



