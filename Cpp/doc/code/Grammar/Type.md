# Grammar Type

A Type in the CL language is an alpha word that reprensents the type of a function
or a variable. As you can see in the [language grammar](../../usage/Grammar.md),
a type looks like:

```
type: ('a-z' | 'A-Z')+
```

## Code

You can find the prototype of the function in the [Type.hpp](../../../src/CPT/Grammar/Type.hpp) file and the implementation in the [Type.cpp](Type.cpp) file.

Class prototype:
```hpp
namespace CPT::Grammar
{
    class Type : public Packrat::IExpr
    {
    public:
        Type();
        Type(std::string name);
        struct result *parse(Packrat::Parser &p) ;
        enum cpt_type type();
        std::string get();

    private:
        std::string name;
    };
} // namespace CPT
```

The class inherit from the [Packrat::IExpr](../Packrat/IExpr.md) class that obligate the class to implement the `parse` and `type` methods. The parsed value is stored in the `name` attribute.

## Parsing strategy

- Save the current position
- Get a [Packrat word](TODO) that's an alpha word
    - If it fails, go back to the saved position and return a failure
    - If it succeeds, continue
- Commit the changes and return the result
