#include "util.h"

#include "stdafx.h"
#include "memory_guard.h"

/**
 * Writes a BYTE value to the specified memory offset.
 *
 * This function writes a BYTE value to the given memory offset
 * using the memory_write function.
 *
 * @param offset The memory offset to write to. Must be a valid memory address.
 * @param value The BYTE value to write at the specified memory offset.
 * @return Returns ERROR_SUCCESS on a successful write. If the memory write fails, it
 *         returns the appropriate error code from the memory_write function.
 */
DWORD set_byte(LPVOID offset, BYTE value)
{
    return memory_write(offset, &value, sizeof(BYTE));
}

/**
 * Writes a word (WORD) value to the specified memory offset.
 *
 * This function writes a WORD value to the given memory offset
 * using the memory_write function.
 *
 * @param offset The memory offset to write to. Must be a valid memory address.
 * @param value The WORD value to write at the specified memory offset.
 * @return Returns ERROR_SUCCESS on a successful write. If the memory write fails, it
 *         returns the appropriate error code from the memory_write function.
 */
DWORD set_word(LPVOID offset, WORD value)
{
    return memory_write(offset, &value, sizeof(WORD));
}

/**
 * Writes a double-word (DWORD) value to the specified memory offset.
 *
 * This function writes a DWORD value to the given memory offset
 * using the memory_write function.
 *
 * @param offset The memory offset to write to. Must be a valid memory address.
 * @param value The DWORD value to write at the specified memory offset.
 * @return Returns ERROR_SUCCESS on a successful write. If the memory write fails, it
 *         returns the appropriate error code from the memory_write function.
 */
DWORD set_dword(LPVOID offset, DWORD value)
{
    return memory_write(offset, &value, sizeof(DWORD));
}

/**
 * Writes a single-precision floating-point value to the specified memory offset.
 *
 * This function writes a float value to the given memory offset
 * using the memory_write function.
 *
 * @param offset The memory offset to write to. Must be a valid memory address.
 * @param value The float value to write at the specified memory offset.
 * @return Returns ERROR_SUCCESS on a successful write. If the memory write fails, it
 *         returns the appropriate error code from the memory_write function.
 */
DWORD set_float(LPVOID offset, float value)
{
    return memory_write(offset, &value, sizeof(float));
}

/**
 * Writes a double precision floating-point value to the specified memory offset.
 *
 * This function writes a double value to the given memory offset
 * using the memory_write function.
 *
 * @param offset The memory offset to write to. Must be a valid memory address.
 * @param value The double value to write at the specified memory offset.
 * @return Returns ERROR_SUCCESS on a successful write. If the memory write fails, it
 *         returns the appropriate error code from the memory_write function.
 */
DWORD set_double(LPVOID offset, double value)
{
    return memory_write(offset, &value, sizeof(double));
}

/**
 * Reads a BYTE value from the specified memory offset.
 *
 * This function reads an 8-bit BYTE from the given memory offset
 * and stores the value into the referenced variable.
 *
 * @param offset The memory offset to read from. Must be a valid memory address.
 * @param value A reference to a BYTE where the read value will be stored.
 * @return Returns ERROR_SUCCESS on a successful read. If the memory read fails, it
 *         returns the appropriate error code from the memory_read function.
 */
DWORD get_byte(LPVOID offset, BYTE& value)
{
    return memory_read(offset, &value, sizeof(BYTE));
}

/**
 * Reads a word (WORD) value from the specified memory offset.
 *
 * This function reads a 16-bit WORD from the given memory offset
 * and stores the value into the referenced variable.
 *
 * @param offset The memory offset to read from. Must be a valid memory address.
 * @param value A reference to a WORD where the read value will be stored.
 * @return Returns ERROR_SUCCESS on a successful read. If the memory read fails, it
 *         returns the appropriate error code from the memory_read function.
 */
DWORD get_word(LPVOID offset, WORD& value)
{
    return memory_read(offset, &value, sizeof(WORD));
}

/**
 * Reads a double word (DWORD) value from the specified memory offset.
 *
 * This function reads a 32-bit DWORD from the given memory offset
 * and stores the value into the referenced variable.
 *
 * @param offset The memory offset to read from. Must be a valid memory address.
 * @param value A reference to a DWORD where the read value will be stored.
 * @return Returns ERROR_SUCCESS on a successful read. If the memory read fails, it
 *         returns the appropriate error code from the memory_read function.
 */
DWORD get_dword(LPVOID offset, DWORD& value)
{
    return memory_read(offset, &value, sizeof(DWORD));
}

/**
 * Reads a single-precision floating-point value from the specified memory offset.
 *
 * This function attempts to read a float from the provided memory location
 * into the given reference variable.
 *
 * @param offset The memory offset to read from. Must be a valid memory address.
 * @param value A reference to a float where the read value will be stored.
 * @return Returns ERROR_SUCCESS on a successful read. If the memory read fails, it
 *         returns the appropriate error code from the memory_read function.
 */
DWORD get_float(LPVOID offset, float& value)
{
    return memory_read(offset, &value, sizeof(float));
}

/**
 * Reads a double-precision floating-point value from the specified memory offset.
 *
 * This function attempts to read a double from the provided memory location
 * into the given reference variable.
 *
 * @param offset The memory offset to read from. Must be a valid memory address.
 * @param value A reference to a double where the read value will be stored.
 * @return Returns ERROR_SUCCESS on a successful read. If the memory read fails, it
 *         returns the appropriate error code from the memory_read function.
 */
DWORD get_double(LPVOID offset, double& value)
{
    return memory_read(offset, &value, sizeof(double));
}

/**
 * Sets a complete hook at a specified memory offset, allowing for conditional
 * modification of the first byte and calculation of a relative jump to the provided
 * function address.
 *
 * This function adjusts memory access permissions using RAII, validates inputs,
 * and modifies the memory location with a calculated relative jump address.
 *
 * @param head The byte to be written to the specified memory offset.
 *             If set to 0xFF, no write operation is performed for this byte.
 * @param offset The memory offset where the hook is to be placed. Must be non-zero.
 * @param function_address The address of the function to jump to. Must be non-zero.
 * @return Returns ERROR_SUCCESS on successful hook installation. If the provided
 *         parameters are invalid, it returns ERROR_INVALID_PARAMETER. If an overflow
 *         occurs while calculating the relative address, it returns ERROR_ARITHMETIC_OVERFLOW.
 *         On other failures, it returns the result of GetLastError().
 */
DWORD set_complete_hook(BYTE head, LPVOID offset, LPVOID function_address)
{
    // Validate the arguments
    if (!offset || !function_address)
    {
        return ERROR_INVALID_PARAMETER;
    }

    try
    {
        // Change permissions to PAGE_EXECUTE_READWRITE
        memory_protect_guard guard(offset, 5, PAGE_EXECUTE_READWRITE);


        // Si `head` no es 0xFF, establecer el byte en la posición `offset` con el valor de `head`
        if (head != ASM::CALLD)
        {
            set_byte(offset, head);
        }

        // Calculate the relative displacement of the jump
        const uintptr_t relative_address = reinterpret_cast<uintptr_t>(function_address) -
            (reinterpret_cast<uintptr_t>(offset) + 5);

        if (relative_address > UINT32_MAX)
        {
            return ERROR_ARITHMETIC_OVERFLOW;
        }

        const auto byte_offset = static_cast<BYTE*>(offset);

        // Calculate the relative address of the jump and write it to `offset + 1`
        set_dword(byte_offset + 1, relative_address);
    }
    catch (const std::runtime_error&)
    {
        DWORD error = GetLastError();
        if (error == 0) error = ERROR_ACCESS_DENIED;

        return error;
    }

    return ERROR_SUCCESS;
}

/**
 * Writes data to a specified memory location after temporarily adjusting
 * memory access permissions. Restores the original permissions after the
 * write operation.
 *
 * @param offset The memory address to write to.
 * @param value A pointer to the buffer containing the data to be written.
 * @param size The number of bytes to write from the buffer to the memory address.
 * @return Returns 0 on success. On failure, it returns an error code such as:
 *         ERROR_INVALID_PARAMETER, ERROR_ACCESS_DENIED, or the result of GetLastError().
 */
DWORD memory_write(LPVOID offset, const LPVOID value, const SIZE_T size)
{
    // Basic validation of pointers and parameters
    if (!value || !offset || size == 0)
    {
        return ERROR_INVALID_PARAMETER;
    }

    try
    {
        // Change permissions to PAGE_EXECUTE_READWRITE
        memory_protect_guard guard(offset, size, PAGE_EXECUTE_READWRITE);

        // Copy `size` bytes from `value` to `offset`
        memcpy(offset, value, size);
    }
    catch (const std::runtime_error&)
    {
        DWORD error = GetLastError();
        if (error == 0) error = ERROR_ACCESS_DENIED;

        return error;
    }

    return ERROR_SUCCESS;
}

/**
 * Reads memory from a specified offset and copies it to the provided buffer.
 * The function temporarily adjusts memory access permissions and restores
 * them after the operation is complete.
 *
 * @param offset The memory address (offset) to read from.
 * @param value A pointer to the buffer where the read data will be stored.
 * @param size The number of bytes to read from the memory offset.
 * @return Returns 0 on success. On failure, it returns an error code:
 *         ERROR_INVALID_PARAMETER, ERROR_ACCESS_DENIED, or the result of GetLastError().
 */
DWORD memory_read(const LPVOID offset, LPVOID value, const SIZE_T size)
{
    // Basic validation of pointers and parameters
    if (!value || !offset || size == 0)
    {
        return ERROR_INVALID_PARAMETER;
    }

    try
    {
        // Change permissions to PAGE_EXECUTE_READWRITE
        memory_protect_guard guard(offset, size, PAGE_EXECUTE_READWRITE);

        // Copy `size` bytes from `offset` to `value`
        memcpy(value, offset, size);
    }
    catch (const std::runtime_error&)
    {
        DWORD error = GetLastError();
        if (error == 0) error = ERROR_ACCESS_DENIED;

        return error;
    }

    return ERROR_SUCCESS;
}
