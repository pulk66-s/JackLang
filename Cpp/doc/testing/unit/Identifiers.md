# Unit testing description

# Scenarios

| Scenario          | Description                                                   | File                                                  | Examples      | Success   |
| ----------------- | ------------------------------------------------------------- | ----------------------------------------------------- | ------------- | --------- |
| Letter            | Testing letter identifier                                     | [identifier.cpp](../../../tests/unit/identifier.cpp)  | a             | true      |
| Number            | Testing number identifier                                     | [identifier.cpp](../../../tests/unit/identifier.cpp)  | 1             | false     |
| Underscore        | Testing underscore identifier                                 | [identifier.cpp](../../../tests/unit/identifier.cpp)  | _             | true      |
| Dot               | Testing dot identifier                                        | [identifier.cpp](../../../tests/unit/identifier.cpp)  | .             | false     |
| alpha             | Testing an alpha identifier                                   | [identifier.cpp](../../../tests/unit/identifier.cpp)  | identifier    | true      |
| first digit       | Testing an identifier with a digit as first character         | [identifier.cpp](../../../tests/unit/identifier.cpp)  | 1identifier   | false     |
| first underscore  | Testing an identifier with an underscore as first character   | [identifier.cpp](../../../tests/unit/identifier.cpp)  | _identifier   | true      |
| camel case        | Testing an identifier with camel case                         | [identifier.cpp](../../../tests/unit/identifier.cpp)  | camelCase     | true      |
| snake case        | Testing an identifier with snake case                         | [identifier.cpp](../../../tests/unit/identifier.cpp)  | snake_case    | true      |
| Pascal case       | Testing an identifier with Pascal case                        | [identifier.cpp](../../../tests/unit/identifier.cpp)  | PascalCase    | true      |
| Upper case        | Testing an identifier with upper case                         | [identifier.cpp](../../../tests/unit/identifier.cpp)  | UPPER_CASE    | true      |
| Lower case        | Testing an identifier with lower case                         | [identifier.cpp](../../../tests/unit/identifier.cpp)  | lower_case    | true      |
| Mixed case        | Testing an identifier with mixed case                         | [identifier.cpp](../../../tests/unit/identifier.cpp)  | Mixed_Case    | true      |
| Mixed data        | Testing an identifier with mixed data                         | [identifier.cpp](../../../tests/unit/identifier.cpp)  | id3ntifier_   | true      |
| Empty             | Testing an empty identifier                                   | [identifier.cpp](../../../tests/unit/identifier.cpp)  |               | false     |