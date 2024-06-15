#include "MyString.h"

// 1.���캯��
	// ���캯��0 : Ĭ�Ϲ��캯��(����ͬʱ������Ĭ�Ϲ��캯��)
MyString::MyString()
{
	_str = nullptr;
	_size = _capacity = 0;
}
// ���캯��1 : ʹ���ַ����顢�����ַ�����
MyString::MyString(const char* str)
{
	_size = strlen(str);
	_capacity = _size;
	_str = new char[_capacity + 1](); // +1 : ����'\0'
	strcpy(_str, str); //�����ַ�������strcpy
}
MyString::MyString(const char* s, size_t count)
{
	assert(count <= strlen(s));

	_size = count;
	_capacity = _size;
	_str = new char[_capacity + 1](); // +1 : ����'\0'���ַ������п��ܲ���\0
	size_t slen = strlen(s);
	for (int i = 0; i < count; ++i)
		_str[i] = s[i];
}
// ���캯��2 : ��������(���)
//MyString(const MyString& s)
//{
//	// ���� �ṹ��/�� �����϶�ֻ�����ֳ�Ա�������������͡�ָ�����ͣ��Զ������ͱ�����Ҳ�������������͵�һ�������壩
//	// ������Ĺؼ�����ʵ�ֶ� ָ������ָ��ռ� �Ŀ�����
//	// ������һ���¿ռ䣬�ٰ����ݿ���������¿ռ䡣
//	// �����Զ������ͳ�Ա�Ŀ�������Ҳ���ڰ����� ָ������ָ��ռ� ���п�����
//	
//	_size = s._size; // �����п��Է���ͬ������˽�г�Ա����Ϊ����������ڲ�ʵ�ֵģ������Ƕ���ģ����Բ���Υ����ķ�װ��˼�롣
//	_capacity = s._capacity;
//	_str = new char[_capacity + 1](); // +1 : ����'\0'
//	strcpy(_str, s._str); //�����ַ�������strcpy
//}
void MyString::swap(MyString& s)
{
	std::swap(this->_str, s._str);
	std::swap(this->_size, s._size);
	std::swap(this->_capacity, s._capacity);
}
MyString::MyString(const MyString& s) // ���������ִ�д��(���ù��캯��)
	:_str(nullptr)
	, _size(0)
	, _capacity(0)
{
	MyString tmp(s._str); //���ù��캯������һ����ʱ����
	swap(tmp);   //�����Լ�д�Ľ���������ʹ��std::swap��������
}
MyString::MyString(const MyString& s, size_t start, size_t len)
{
	// ����û�û����len
	if (len == npos)
		len = strlen(s._str) - start;
	else
		assert(((long long)len + start) < strlen(s._str));

	_size = len;
	_capacity = _size;
	_str = new char[_capacity + 1](); // +1 : ����'\0'���ַ������п��ܲ���\0
	size_t slen = strlen(s._str);
	for (int i = 0; i < len; ++i)
	{
		size_t pos = start + i;
		if (pos < slen)
			_str[i] = s._str[pos];
		else
			_str[i] = '\0';
	}
}
// ���캯��3 : ʹ��n���ַ����й���
MyString::MyString(int count, const char c) //��֧��ֱ��ʹ�õ����ַ�������
{
	_size = count;
	_capacity = count;
	_str = new char[count + 1](); // +1 : ����'\0'
	for (int i = 0; i < count; i++)
		_str[i] = c;
}
/* ���캯��4 : �ƶ����� */
// �ƶ����캯���ᡰ��ȡ����һ��std::string������ڲ���Դ�����ַ�����ͳ��ȣ��������Ǹ������ǡ����������������ܣ��ر��ǵ����������ַ���ʱ��
// string (string&& str) noexcept; //STL���ƶ����캯���ĺ���������
//MyString(MyString&& s) noexcept
//{
//	// a.����ȡ��s����Դ
//	_size = s._size;
//	_capacity = s._capacity;
//	_str = s._str;
//	// b.��s�ÿգ�ȷ��s������ԭ������Դ
//	s._size = s._capacity  = 0;
//	s._str = nullptr;
//}
MyString::MyString(MyString&& s) noexcept// �ƶ�������ִ�д��
	: _str(nullptr)
	, _size(0)
	, _capacity(0)
{
	swap(s); // ֱ�ӵ����Լ�д��swap����ȡ��s����Դ
}

// ��������
MyString::~MyString()
{
	if (_str)
		delete[] _str;
	_str = nullptr;
	_size = _capacity = 0;
}

// ��ֵ���������
MyString& MyString::operator= (const MyString& s)
{}
MyString& MyString::operator= (const char* s)
{}
MyString& MyString::operator= (char c)
{}
MyString& MyString::operator= (MyString&& s) noexcept
{}