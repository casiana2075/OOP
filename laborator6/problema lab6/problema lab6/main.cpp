#define _CRT_SECURE_NO_WARNINGS
#include "Json.h"
#include <iostream>


int main() {
    auto array_numbers = new ArrayValue();
    array_numbers->add(new NumberValue(5));
    array_numbers->add(new NumberValue(10));
    array_numbers->add(new NumberValue(15));

    auto array_strings = new ArrayValue();
    array_strings->add(new StringValue("abc"));
    array_strings->add(new StringValue("def"));
    array_strings->add(new StringValue("ghi"));

    auto subobject = new ObjectValue();
    subobject->add("email", new StringValue("t@gmail.com"));
    subobject->add("name", new StringValue("T"));
    subobject->add("online", new BoolValue(true));

    auto object = new ObjectValue();
    object->add("n", new NullValue());
    object->add("array_numbers", array_numbers);
    object->add("array_strings", array_strings);
    object->add("info", subobject);

    std::cout << "Top node has " << (unsigned) *object << " subnodes\n";

    object->print(std::cout);
}

//Output should look like this
// {"n": null, "array_numbers": [5, 10, 15], "array_strings": ["abc", "def", "ghi"], "info": {"email": "t@gmail.com", "name": "T", "online": true}}
