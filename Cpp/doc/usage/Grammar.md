# Grammar

This file contains the grammar of the language, which is used to parse the code.

## Global structure

```antlr
program: number

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

