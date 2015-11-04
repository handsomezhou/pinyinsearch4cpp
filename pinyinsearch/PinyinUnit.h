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

#ifndef PINYINUNIT_H
#define PINYINUNIT_H
#include <QList>
#include "PinyinBaseUnit.h"
class PinyinUnit
{
public:
    PinyinUnit();
    bool isPinyin() const;
    void setPinyin(bool pinyin);

    int getStartPosition() const;
    void setStartPosition(int startPosition);

    QList<PinyinBaseUnit> getPinyinBaseUnitIndex() const;
    void setPinyinBaseUnitIndex(const QList<PinyinBaseUnit> &pinyinBaseUnitIndex);

private:
    bool pinyin;//whether pinyin
    int startPosition;//save starting index position that the variables in the original string.
    /*
     * save the string which single Chinese characters Pinyin(include Multiple Pinyin),or continuous non-kanji characters.
     * if mPinyinBaseUnitIndex.size not more than 1, it means the is not Polyphonic characters.
     */
    QList<PinyinBaseUnit> pinyinBaseUnitIndex;
};
#endif // PINYINUNIT_H
