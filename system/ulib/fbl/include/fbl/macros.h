
#pragma once

// Macro used to simplify the task of deleting all of the default copy
// constructors and assignment operators.
#define DISALLOW_COPY_ASSIGN_AND_MOVE(_class_name)       \
    _class_name(const _class_name&) = delete;            \
    _class_name(_class_name&&) = delete;                 \
    _class_name& operator=(const _class_name&) = delete; \
    _class_name& operator=(_class_name&&) = delete

// Macro used to simplify the task of deleting the non rvalue reference copy
// constructors and assignment operators.  (IOW - forcing move semantics)
#define DISALLOW_COPY_AND_ASSIGN_ALLOW_MOVE(_class_name) \
    _class_name(const _class_name&) = delete;            \
    _class_name& operator=(const _class_name&) = delete

// Macro used to simplify the task of deleting the new and new[]
// operators. (IOW - disallow heap allocations)
#define DISALLOW_NEW                       \
    static void* operator new(size_t) = delete;   \
    static void* operator new[](size_t) = delete
