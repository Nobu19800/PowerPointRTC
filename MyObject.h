// -*-C++-*-
/*!
 * @file  MyObject.h
 * @brief ������̑��쓙
 */
#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <vector>
#include <string>
#include <sstream>



/**
*@brief �Z���̔ԍ��𐔒l�ɕϊ�����֐�
* @param m_str �Z���̔ԍ�(�A���t�@�x�b�g)
* @return �Ή����鐔�l
*/
int convertStrToVal(std::string m_str);



/**
*@brief ������u������֐�
* @param String1 �ϊ����̕�����
* @param String2 �u���O�̕���
* @param String3 �u����̕���
* @return �ϊ���̕�����
*/
std::string Replace( std::string String1, std::string String2, std::string String3 );



/**
* @class TreeObject
*@brief RTC�̃f�[�^�|�[�g�̃c���[�̊e�I�u�W�F�N�g�N���X
*/
class TreeObject
{
public:
	/**
	*@brief �R���X�g���N�^
	* @param n �c���[��
	*/
	TreeObject(std::string n)
	{
		name = n;
	};
	std::string name; /**<�@@brief  */
	std::vector<TreeObject*> to; /**<�@@brief  */
};


/**
*@brief System::String��std::string�ɕϊ�����֐�
* @param s �ϊ��O�̕�����
* @return �ϊ���̕�����
*/
std::string MarshalString ( System::String ^ s);


/**
*@brief ����������̕����ŕ�������֐�
* @param str �����O�̕�����
* @param delim �������镶��
* @return
*/
std::vector<std::string> split(const std::string &str, const std::string &delim);


/**
*@brief ������𐔒l�ɕϊ�����֐�
* @param text �ϊ���̕�����
* @param base ��
* @return �ϊ���̐��l
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