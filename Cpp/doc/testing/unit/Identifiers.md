# Unit testing description

# Scenarios

| Scenario          | Description                                                   | File                                                  | Examples      | Success   |
| ----------------- | ------------------------------------------------------------- | ----------------------------------------------------- | ------------- | --------- |
| Letter            | Testing letter identifier                                     | [identifier.cpp](../../../tests/unit/identifier.cpp)  | a             | ✅        |
| Number            | Testing number identifier                                     | [identifier.cpp](../../../tests/unit/identifier.cpp)  | 1             | ❌        |
| Underscore        | Testing underscore identifier                                 | [identifier.cpp](../../../tests/unit/identifier.cpp)  | _             | ✅        |
| Dot               | Testing dot identifier                                        | [identifier.cpp](../../../tests/unit/identifier.cpp)  | .             | ❌        |
| alpha             | Testing an alpha identifier                                   | [identifier.cpp](../../../tests/unit/identifier.cpp)  | identifier    | ✅        |
| first digit       | Testing an identifier with a digit as first character         | [identifier.cpp](../../../tests/unit/identifier.cpp)  | 1identifier   | ❌        |
| first underscore  | Testing an identifier with an underscore as first character   | [identifier.cpp](../../../tests/unit/identifier.cpp)  | _identifier   | ✅        |
| camel case        | Testing an identifier with camel case                         | [identifier.cpp](../../../tests/unit/identifier.cpp)  | camelCase     | ✅        |
| snake case        | Testing an identifier with snake case                         | [identifier.cpp](../../../tests/unit/identifier.cpp)  | snake_case    | ✅        |
| Pascal case       | Testing an identifier with Pascal case                        | [identifier.cpp](../../../tests/unit/identifier.cpp)  | PascalCase    | ✅        |
| Upper case        | Testing an identifier with upper case                         | [identifier.cpp](../../../tests/unit/identifier.cpp)  | UPPER_CASE    | ✅        |
| Lower case        | Testing an identifier with lower case                         | [identifier.cpp](../../../tests/unit/identifier.cpp)  | lower_case    | ✅        |
| Mixed case        | Testing an identifier with mixed case                         | [identifier.cpp](../../../tests/unit/identifier.cpp)  | Mixed_Case    | ✅        |
| Mixed data        | Testing an identifier with mixed data                         | [identifier.cpp](../../../tests/unit/identifier.cpp)  | id3ntifier_   | ✅        |
| Empty             | Testing an empty identifier                                   | [identifier.cpp](../../../tests/unit/identifier.cpp)  |               | ❌        |
