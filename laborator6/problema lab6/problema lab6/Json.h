#pragma once
#include <ostream>

class JsonValue {
  public:
    virtual ~JsonValue() = 0;

    virtual void print(std::ostream& out) const = 0;
};

class NullValue : public JsonValue {
  public:
    NullValue();
    void print(std::ostream& out) const override;
};

class NumberValue : public JsonValue {
    int numberValue;

  public:
    NumberValue(int value);
    void print(std::ostream& out) const override;
};

class BoolValue : public JsonValue {
    bool boolValue;

  public:
    BoolValue(int value);
    void print(std::ostream& out) const override;
};

class StringValue : public JsonValue {
    char stringValue[256];

  public:
    StringValue(const char* string);
    void print(std::ostream& out) const override;
};

class ArrayValue : public JsonValue {
    JsonValue* array[17];
    int count;

  public:
    ArrayValue();
    ~ArrayValue();
    void add(JsonValue* value);
    void print(std::ostream& out) const override;
};

struct pair {
    char name[256];
    JsonValue* value;
};

class ObjectValue : public JsonValue {
    pair obj[16];
    int count;

  public:
    ObjectValue();
    ~ObjectValue();
    void add(const char * str, JsonValue* val);
    void print(std::ostream& out) const override;
};