// crypt.cpp

#include "stdafx.h"
#include "crypt.h"
#include <iostream>



const wchar_t * rot13(const wchar_t * source)
{  

	using namespace std;

	std::wstring  src = std::wstring(source);

	const wchar_t* v[] = {  L"АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ",
					L"абвгдежзийклмнопрстуфхцчшщъыьэюя",
					L"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
					L"abcdefghijklmnopqrstuvwxyz",
					L"0123456789",
					 NULL

	};

	wstring out = L"";

	for (auto const & c : src) {

		bool x = false;
		unsigned short i = 0;   // line number in array

		while (v[i] != '\0') {

			wstring str = v[i];
			unsigned short p = 0;            // the position of the cursor in the array row v 
			unsigned short l = str.size();   // string length from array v

			for (auto const & cv : str) {

				if (c == cv) {

					p += l / 2;
					p %= l;

					out += str.at(p);
					x = true; // symbol was found
					break;

				}

				p++;
			}

			if (x) break; // if the character was found, then we finish the search
			i++;
		}

		if (!x) out += c; // if the character was not found, then leave the original character	
	}


	return  out.c_str();

}