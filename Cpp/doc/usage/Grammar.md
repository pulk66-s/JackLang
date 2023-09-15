# Grammar

This file contains the grammar of the language, which is used to parse the code.

## Global structure

```antlr
program: variable_decl*

variable_decl:
    type
    identifier
    '='
    value

value: number | identifier

type:   ('a-z' | 'A-Z')+

identifier:
    ('a-z' | 'A-Z' | '_')
    ('a-z' | 'A-Z' | '0-9' | '_')*

number: sign? digit+

sign: '+' | '-'

digit: [0-9]
```

## Grammar Lexical

| Sign  | Description   |
| ----- | ------------- |
| +     | One or More   |
| *     | Zero or More  |
| ?     | Zero or One   |

