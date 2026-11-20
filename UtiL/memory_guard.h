#pragma once
#include "stdafx.h"

class memory_protect_guard
{
private:
    LPVOID address_;
    SIZE_T size_;
    DWORD old_protect_;

public:
    /**
     * Constructs a memory_protect_guard object that changes the memory protection of a specified region.
     * If the memory protection change fails, a runtime_error exception is thrown.
     *
     * @param address The starting address of the memory region to protect.
     * @param size The size of the memory region in bytes.
     * @param newProtect The new memory protection level, such as PAGE_EXECUTE_READWRITE.
     */
    memory_protect_guard(LPVOID address, SIZE_T size, DWORD newProtect)
        : address_(address), size_(size), old_protect_(0)
    {
        if (!VirtualProtect(address_, size_, newProtect, &old_protect_))
        {
            throw std::runtime_error("Failed to change memory protection.");
        }
    }

    /**
     * Destructor for the memory_protect_guard class. Restores the original memory protection
     * settings for the managed memory region when the object goes out of scope.
     *
     * This ensures that any changes made to the memory protection during the lifetime
     * of the object are reverted to their original state automatically.
     */
    ~memory_protect_guard()
    {
        // Restore original permissions when going out of scope.
        VirtualProtect(address_, size_, old_protect_, &old_protect_);
    }

    // Prohibit copies
    memory_protect_guard(const memory_protect_guard&);
    memory_protect_guard& operator=(const memory_protect_guard&);
};
