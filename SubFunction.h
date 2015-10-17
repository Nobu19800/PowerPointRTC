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





#endif