/*

	dinput_mouse.c - DirectInput Mouse DATAFORMAT

	Written by Filip Navara <xnavara@volny.cz>

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*/

#include "dinput_private.h"

static DIOBJECTDATAFORMAT ATTRIBUTE_TEXT_SECTION c_rgodfDIMouse[] =
{
	{&GUID_XAxis,0x0,DIDFT_ABSAXIS|DIDFT_RELAXIS|DIDFT_ANYINSTANCE,0x0},
	{&GUID_YAxis,0x4,DIDFT_ABSAXIS|DIDFT_RELAXIS|DIDFT_ANYINSTANCE,0x0},
	{&GUID_ZAxis,0x8,DIDFT_ABSAXIS|DIDFT_RELAXIS|DIDFT_ANYINSTANCE|DIDFT_OPTIONAL,0x0},
	{NULL,0xc,DIDFT_BUTTON|DIDFT_ANYINSTANCE,0x0},
	{NULL,0xd,DIDFT_BUTTON|DIDFT_ANYINSTANCE,0x0},
	{NULL,0xe,DIDFT_BUTTON|DIDFT_ANYINSTANCE|DIDFT_OPTIONAL,0x0},
	{NULL,0xf,DIDFT_BUTTON|DIDFT_ANYINSTANCE|DIDFT_OPTIONAL,0x0}
};

const DIDATAFORMAT c_dfDIMouse = {sizeof(DIDATAFORMAT),sizeof(DIOBJECTDATAFORMAT),DIDF_RELAXIS,16,sizeof(c_rgodfDIMouse)/sizeof(c_rgodfDIMouse[0]),c_rgodfDIMouse};
