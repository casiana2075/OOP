#define _CRT_SECURE_NO_WARNINGS
#include "Json.h"

JsonValue::~JsonValue(){};

NullValue::NullValue() {
}

void NullValue::print(std::ostream& out) const {
    out << "null";
}

NumberValue::NumberValue(int value) {
    this->numberValue = value;
}

void NumberValue::print(std::ostream& out) const{
    out << numberValue;
}

BoolValue::BoolValue(int value) {
    this->boolValue = value;
}

void BoolValue::print(std::ostream& out) const {
    if (boolValue == 0)
        out << "false";
    else
        out << "true";
}


StringValue::StringValue(const char* string) {
    strcpy(stringValue, string);
}

void StringValue::print(std::ostream& out) const{ 
    out << "\"" << stringValue << "\""; }

ArrayValue::ArrayValue() {
    count = 0;
}

ArrayValue::~ArrayValue() {
    for (int i = 0; i < count; i++) {
        delete array[i];
    }
}

void ArrayValue::add(JsonValue* value) {
    array[count++] = value;
}

void ArrayValue::print(std::ostream& out) const {
    out << '[';
    for (int i = 0; i < count; ++i) {
        if (i > 0) {
            out << ',';
        }
        if (array[i]) {
            array[i]->print(out);
        } else {
            out << "null";
        }
    }
    out << ']';
}

ObjectValue::ObjectValue() {
    count = 0;
}

ObjectValue::~ObjectValue() {
    for (int i = 0; i < count; i++) {
        delete obj[i].value;
    }
}

void ObjectValue::add(const char* str, JsonValue* val) {
    strcpy(obj[count].name, str);
    obj[count++].value = val;
}

void ObjectValue::print(std::ostream& out) const {

    out << '{';
    for (int i = 0; i < count; ++i) {
        if (i > 0) {
            out << ',';
        }
        out << '"' << obj[i].name << "\":";
        obj[i].value->print(out);
    }
    out << '}';
}
