#include <skypat/skypat.h>

#define _Bool bool
extern "C" {
#include <core/Runtime.h>
#include <dataTypes/Value.h>
}
#undef _Bool

SKYPAT_F(Runtime_nop, regular)
{
    Stack* stack = new_Stack((void (*)(void*))free_Value);
    int32_t check_value;

    Value *value_1 = new_i32Value(5);
    Value *value_2 = new_i32Value(4);
    Value *value_3 = new_i32Value(3);
    Value *value_4 = new_i32Value(2);
    Value *value_5 = new_i32Value(1);
    Value *value_6 = new_i32Value(0);
    Value *check = NULL;

    stack->entries->push(stack->entries, value_1);
    stack->entries->push(stack->entries, value_2);
    stack->entries->push(stack->entries, value_3);
    stack->entries->push(stack->entries, value_4);
    stack->entries->push(stack->entries, value_5);
    stack->entries->push(stack->entries, value_6);

    check_value = runtime_select(stack);
    EXPECT_EQ(check_value,0);
    EXPECT_EQ(stack->entries->size, 4);

    stack->entries->pop(stack->entries, (void**)&check);
    EXPECT_EQ(check->value.i32, 1);

    check_value = runtime_select(stack);
    EXPECT_EQ(check_value,0);
    EXPECT_EQ(stack->entries->size, 1);

    stack->entries->pop(stack->entries, (void**)&check);
    EXPECT_EQ(check->value.i32, 5);

    check_value = runtime_select(stack);
    EXPECT_EQ(check_value, -1);

    // clean
    free_Value(check);
    free_Stack(stack);
}
