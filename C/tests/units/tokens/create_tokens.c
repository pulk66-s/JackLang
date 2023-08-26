#include "units/tokens/create_tokens.h"
#include "files.h"

/**
 * @brief           Creates tokens from a file.
 * @param   file    The file to create tokens from.
 * @return          The tokens.
*/
const char ***create_tokens(const char *file)
{
    const char *contents = read_file(file);
    const char ***tokens = parse_content(contents);

    return tokens;
}
