#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cctype>

class Contact
{
	public:
		Contact() {};
		Contact(std::string firstname, std::string lastname, std::string nickname, std::string number, std::string secret)
		{
			m_firstname = firstname;
			m_lastname = lastname;
			m_nickname = nickname;
			m_phonenumber = number;
			m_secret = secret;
		};
		std::string get_firstname()
		{
			return m_firstname;
		}
		std::string get_lastname()
		{
			return m_lastname;
		}
		std::string get_nickname()
		{
			return m_nickname;
		}
		std::string get_phone()
		{
			return m_phonenumber;
		}
		std::string get_secret()
		{
			return m_secret;
		}
		int get_index()
		{
			return n_index;
		}
	private:
		int n_index;
		std::string m_firstname;
		std::string m_lastname;
		std::string m_nickname;
		std::string m_phonenumber;
		std::string m_secret;

};

class Phonebook
{
	private:
		static const int MAX_CONTACTS = 8;
		Contact m_repertoire[MAX_CONTACTS];
		int m_count;
	
	public:
		Phonebook() : m_count(0) {}
		Contact* get_repertoire()
		{
			return m_repertoire;
		};
		int	get_index()
		{
			return m_count;
		}
		void increment()
		{
			m_count++;
		}
};


#endif