# Grammar Variable Declaration

A Variable Declaration in CL is composed of multiple parts:
- The [type](Type.md) of the variable
- The [name](Identifier.md) of the variable
- The [special char](SpecialChar.md) '='
- The [value](Value.md) of the variable
    - The value can be either a number or an identifier

As you can see in the [language grammar](../../usage/Grammar.md), a variable declaration looks like:

```
variable_decl:
    type
    identifier
    '='
    value
```

## Code

You can find the prototype of the function in the [VariableDecl.hpp](../../../src/CPT/Grammar/VariableDecl.hpp) file and the implementation in the [VariableDecl.cpp](VariableDecl.cpp) file.

Class prototype:
```hpp
namespace CPT::Grammar
{
    class VariableDecl : public Packrat::IExpr
    {
    public:
        VariableDecl();
        VariableDecl(Type *type, std::string identifier, Packrat::IExpr *value);
        enum cpt_type type();
        struct result *parse(Packrat::Parser &p);
        Type *getType();
        std::string get();
        Packrat::IExpr *getValue();

    private:
        Type *t;
        std::string identifier;
        Packrat::IExpr *value;
    };
} // namespace CPT
```

The class inherit from the [Packrat::IExpr](../Packrat/IExpr.md) class that obligate the class to implement the `parse` and `type` methods. The different elements of the variable declaration are stored in the `t`, `identifier` and `value` attributes.
- `t` is the type of the variable
- `identifier` is the name of the variable, it's a string because an identifier is basically a name
- `value` is the value of the variable, it's an IExpr because it can be multiple types of expressions

## Parsing strategy

- First, we are saving the current position
- We are parsing a sequence composed of:
    - [Type](Type.md)
    - [Identifier](Identifier.md)
    - [SpecialChar('=')](SpecialChar.md)
    - [Value](Value.md)
    - If the parsing failed, we are rolling back to the saved position and returning a failure
    - If the parsing succeeded, continue
- We are storing the different elements in the corresponding attributes, commit the position and return a success
