# Unit testing description

# Scenarios

| Scenario              | Description                                   | File                                                      | Examples      | Success   |
| --------------------- | --------------------------------------------- | --------------------------------------------------------- | ------------- | --------- |
| Basic int             | Testing int declaration with default value    | [VariableDecl.cpp](../../../tests/unit/VariableDecl.cpp)  | int a = 42    | ✅        |
| Empty file            | Testing empty file                            | [VariableDecl.cpp](../../../tests/unit/VariableDecl.cpp)  |               | ❌        |
| Unknown type          | Testing un unknown value                      | [VariableDecl.cpp](../../../tests/unit/VariableDecl.cpp)  | fea a = 42    | ✅        |
| Wrong type            | Testing a non alpha value as type             | [VariableDecl.cpp](../../../tests/unit/VariableDecl.cpp)  | 1.2 a = 42    | ❌        |
| Wrong name            | Testing a non alpha value as name             | [VariableDecl.cpp](../../../tests/unit/VariableDecl.cpp)  | int 1.2 = 42  | ❌        |
| No Value              | Testing empty value                           | [VariableDecl.cpp](../../../tests/unit/VariableDecl.cpp)  | int a =       | ❌        |
| No type               | Testing no type                               | [VariableDecl.cpp](../../../tests/unit/VariableDecl.cpp)  | a = 42        | ❌        |
| No name               | Testing no name                               | [VariableDecl.cpp](../../../tests/unit/VariableDecl.cpp)  | int = 42      | ❌        |
| Identifier            | Testing identifier as name                    | [VariableDecl.cpp](../../../tests/unit/VariableDecl.cpp)  | int a = b     | ✅        |
| No Special char       | Testing no '='                                | [VariableDecl.cpp](../../../tests/unit/VariableDecl.cpp)  | int a 42      | ❌        |
| Wrong special char    | Testing wrong special char                    | [VariableDecl.cpp](../../../tests/unit/VariableDecl.cpp)  | int a # 42    | ❌        |