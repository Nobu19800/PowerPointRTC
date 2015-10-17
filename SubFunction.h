// -*-C++-*-
/*!
 * @file  SubFunction.h
 * @brief ������̑��쓙
 */
#ifndef SubFunction_H
#define SubFunction_H

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





#endif