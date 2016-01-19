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

#ifndef PINYINBASEUNIT_H
#define PINYINBASEUNIT_H
#include <QString>
/**
 * @brief The PinyinBaseUnit class
 *
 * As a single Pinyin units
 * for example:
 * 	"hao"		===>originalString="hao"; pinyin="hao";number="426";
 *  "???hao" 	===>originalString="???hao"; pinyin="???hao";number="???426";
 *  "周"			===>originalString="周"; pinyin="zhou";number="9468";
 */
class PinyinBaseUnit
{
public:
    PinyinBaseUnit ();
    PinyinBaseUnit(QString originalString,QString pinyin,QString number);

    QString getOriginalString() const;
    void setOriginalString(const QString &originalString);

    QString getPinyin() const;
    void setPinyin(const QString &pinyin);

    QString getNumber() const;
    void setNumber(const QString &number);

private:
    QString mOriginalString;
    QString mPinyin;
    QString mNumber;

};

#endif // PINYINBASEUNIT_H
