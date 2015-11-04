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

#ifndef PINYINUTIL_H
#define PINYINUTIL_H
#include <QChar>
#include <QString>

class PinyinUtil{
public:
    static void parse(PinyinSearchUnit &pinyinSearchUnit);
    static QString getFirstLetter(PinyinSearchUnit &pinyinSearchUnit);
    static QString getFirstCharacter(PinyinSearchUnit &pinyinSearchUnit);
    static QString getSortKey(PinyinSearchUnit &pinyinSearchUnit);
    static bool isKanji(QChar &chr);
}
#endif // PINYINUTIL_H
