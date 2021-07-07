#include <cstring> //strlen, strcpy
#include <iostream> //for operator<<

class String
{
public:
	String(const char* cstr);		        //constructor
    //String(){};                           //note that once user defined constructor overload the default constructor
                                            //the default constructor cannot use unless explictly declare it
    //The Rule of three.
    String(const String& str);				//copy-constructor
	String& operator= (const String& str);	//assignment-operator
    ~String();                              //destructor

    //stream-operator, overload default stream operator, must defined as "friend" of std::ostream
    //because the std::ostream need to visit this class's private member, so must be friend of this class
    friend std::ostream& operator<<(std::ostream& os, const String& str);   
									
    char* get_c_str() const { return m_data; } //member function, return pointer

private:
	char* m_data;   //member data: pointer
};

//initial constructor, cstr: c string.
//if class have pointer, you'd better create buffer of the pointer in constructor
inline String::String(const char* cstr) 
{
    std::cout << "String()" << std::endl; //for debug

	if (cstr != NULL) //not NULL pointer
	{
		m_data = new char[strlen(cstr) + 1];
		strcpy(m_data, cstr);
	}
	else
	{
		m_data = new char[1];
		*m_data = '\0';
	}
}

//copy constructor
//same as constructor, copy-constructor need to create new buffer of the new pointer
inline String::String(const String& str) 
{
    std::cout << "copy String()" << std::endl; //for debug

	if (str.get_c_str()) //not NULL pointer
	{
		m_data = new char[strlen(str.m_data) + 1];
		strcpy(m_data, str.m_data);
	}
	else
	{
		m_data = new char[1];
		*m_data = '\0';
	}
}
//destructor
//if class have pointer, you must remember to delete the buffer in destructor
inline String::~String()
{
    std::cout << "~String()" << std::endl; //for debug
    
    if(m_data != NULL)
	    delete[] m_data;
}

inline String& String::operator=(const String& str)
{
	if (this == &str) //check self assignment.
		return *this;
	
    std::cout << "operator=" << std::endl; //for debug

    //delete buffer then new a buffer
    delete[] m_data;
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);

	return *this;
}
//why need to define operator<<:
//we need to output m_data pointed buffer, it's not typical type that can directly use <<
//so we must implement our own operator<< to overload the common stream operator<<
inline std::ostream& operator<<(std::ostream& os, const String& str)
{
    std::cout << "operator<<" << std::endl; //for debug

	os << str.get_c_str();
	return os;
}

