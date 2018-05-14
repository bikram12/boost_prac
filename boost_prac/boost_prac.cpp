// boost_prac.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <boost\algorithm\string.hpp>
#include <boost\algorithm\string\trim.hpp>
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\xml_parser.hpp>
#include <boost\foreach.hpp>
#include <boost\filesystem.hpp>


using namespace std;
namespace fs = boost::filesystem;

void traverse(const fs::path &dirpath);


int main()
{
	fs::path cwd = fs::current_path();
	cout << cwd << endl;
	cout << cwd.generic_string() << endl;
	cout << cwd.string() << endl;

	for (const auto& dir : cwd)
	{
		cout << '[' << dir.string() << ']' << endl;
	}


	bool searchTextFound = false;

	string path="B:\\c++_prac\\boost_prac\\Cotizaciones-09-05.xml";
	boost::property_tree::ptree pt;
	read_xml(path,pt);

	BOOST_FOREACH(boost::property_tree::ptree::value_type &v,pt.get_child("datoscotizaciones"))
	{
		boost::property_tree::ptree pt1  =	v.second;

		BOOST_FOREACH(boost::property_tree::ptree::value_type &v1,pt1)
		{
			string value = v1.first;

			if (value == "Nombre")
			{
				string value2 = v1.second.data();

				if (value2 == "UNIDAD INDEXADA")
				{
					searchTextFound = true;
				}
			}

			if (value == "TCV" && searchTextFound == true)
			{
				string requiredvalue = v1.second.data();
				cout << "Required value is " << requiredvalue << endl;
			}
		}
	}

	//string m_file = pt.get<string>("debug.filename");

	//string value = pt.get<string>("datoscotizaciones.Fecha");

	/*BOOST_FOREACH(boost::property_tree::ptree::value_type const& node, pt.get_child("Cotiza"))
	{
		ptree subtree = node.second;
	}
	string msg = "  Start:: Hello :: End  ";
	boost::algorithm::trim(msg);
	cout << msg << endl;*/

	string data = "This is a simple string.";
	//convert string to upper case using STL
	for_each(data.begin(), data.end(), [](char& c)
	{
		c = ::toupper(c);
	});

	cout << "In upper case: " << data << std::endl;

	for_each(data.begin(),data.end(),[](char& c)
	{
		c = ::tolower(c);
	});

	cout << "In Lower case: " << data << endl;

	boost::to_upper(data);
	cout << "In upper case: " << data << endl;

    return 0;
}

void traverse(const fs::path& dirpath)
{

}

