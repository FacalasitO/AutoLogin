#pragma once
#include "stdafx.h"

DWORD set_byte(LPVOID offset, BYTE value);
DWORD set_word(LPVOID offset, WORD value);
DWORD set_dword(LPVOID offset, DWORD value);
DWORD set_float(LPVOID offset, float value);
DWORD set_double(LPVOID offset, double value);

DWORD get_byte(LPVOID offset, BYTE& value);
DWORD get_word(LPVOID offset, WORD& value);
DWORD get_dword(LPVOID offset, DWORD& value);
DWORD get_float(LPVOID offset, float& value);
DWORD get_double(LPVOID offset, double& value);

DWORD set_complete_hook(BYTE head, LPVOID offset, LPVOID function_address);
DWORD memory_write(LPVOID offset, LPVOID value, SIZE_T size);
DWORD memory_read(LPVOID offset, LPVOID value, SIZE_T size);
