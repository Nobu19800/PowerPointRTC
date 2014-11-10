// -*-C++-*-
/*!
 * @file  SubFunction.h
 * @brief 文字列の操作等
 */
#ifndef SubFunction_H
#define SubFunction_H

#include <vector>
#include <string>
#include <sstream>



/**
*@brief セルの番号を数値に変換する関数
* @param m_str セルの番号(アルファベット)
* @return 対応する数値
*/
int convertStrToVal(std::string m_str);



/**
*@brief 文字を置換する関数
* @param String1 変換元の文字列
* @param String2 置換前の文字
* @param String3 置換後の文字
* @return 変換後の文字列
*/
std::string Replace( std::string String1, std::string String2, std::string String3 );



/**
* @class TreeObject
*@brief RTCのデータポートのツリーの各オブジェクトクラス
*/
class TreeObject
{
public:
	/**
	*@brief コンストラクタ
	* @param n ツリー名
	*/
	TreeObject(std::string n)
	{
		name = n;
	};
	std::string name; /**<　@brief  */
	std::vector<TreeObject*> to; /**<　@brief  */
};


/**
*@brief System::Stringをstd::stringに変換する関数
* @param s 変換前の文字列
* @return 変換後の文字列
*/
std::string MarshalString ( System::String ^ s);


/**
*@brief 文字列を特定の文字で分割する関数
* @param str 分割前の文字列
* @param delim 分割する文字
* @return
*/
std::vector<std::string> split(const std::string &str, const std::string &delim);


/**
*@brief 文字列を数値に変換する関数
* @param text 変換後の文字列
* @param base 底
* @return 変換後の数値
*/
template<typename T>
T string2binary(const std::string& text, int base) {
    
    std::istringstream is(text);
    T value;
    switch (base) {
    case 8:
        is >> std::oct >> value;
        break;
    case 10:
        is >> value;
        break;
    case 16:
        is >> std::hex >> value;
        break;
    default:
        ;
    }

    return value;
}

#endif