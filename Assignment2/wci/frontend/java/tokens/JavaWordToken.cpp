/**
 * <h1>PascalWordToken</h1>
 *
 * <p> Pascal word tokens (identifiers and reserved words).</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "../../java/tokens/JavaWordToken.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

#include "../../java/JavaError.h"

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::java;

JavaWordToken::JavaWordToken(Source *source) throw (string)
    : JavaToken(source)
{
    extract();
}

/**
 * Extract a Pascal word token from the source.
 * @throws Exception if an error occurred.
 */
void JavaWordToken::extract() throw (string)
{
    char current_ch = current_char();

    // Get the word characters (letter or digit). The scanner has
    // already determined that the first character is a letter.
    while (isalnum(current_ch))
    {
        text += current_ch;
        current_ch = next_char();  // consume character
    }

    // Is it a reserved word or an identifier?
    string upper_case(text);
    transform(upper_case.begin(), upper_case.end(),
              upper_case.begin(), ::toupper);
    if (JavaToken::RESERVED_WORDS.find(upper_case)
            != JavaToken::RESERVED_WORDS.end())
    {
        // Reserved word.
        type = (TokenType) JavaToken::RESERVED_WORDS[upper_case];
        value = new DataValue(upper_case);
    }
    else
    {
        // Identifier.
        type = (TokenType) PT_IDENTIFIER;
    }
}

}}}}  // namespace wci::frontend::pascal::tokens
