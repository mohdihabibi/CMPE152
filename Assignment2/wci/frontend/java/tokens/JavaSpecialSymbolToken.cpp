/**
 * <h1>PascalSpecialSymbolToken</h1>
 *
 * <p> Pascal special symbol tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "../../java/tokens/JavaSpecialSymbolToken.h"

#include <string>

#include "../../java/JavaError.h"

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::java;

JavaSpecialSymbolToken::JavaSpecialSymbolToken(Source *source) throw (string)
    				: JavaToken(source)
{
	extract();
}

void JavaSpecialSymbolToken::extract() throw (string)
				{
	char current_ch = current_char();
	bool good_symbol = true;

	text = current_ch;

	switch (current_ch)
	{
	// Single-character special symbols.

	case '~' : case '@' : case '/' : case ';' : case '?' :
	case '.' : case '\"' : case '\'' : case '(' : case ')' :
	case '[' : case ']' : case '{' : case'}': case ',' :


	{
		next_char();  // consume character
		break;
	}

	// ! , !=
	case '!':
	{
		current_ch = next_char();  // consume ':';

		if (current_ch == '=')
		{
			text += current_ch;
			next_char();  // consume '='
		}

		break;
	}
	// : or ::
	case ':':
	{
		current_ch = next_char();  // consume ':';

		if (current_ch == ':')
		{
			text += current_ch;
			next_char();  // consume '='
		}

		break;
	}

	// < or <= or << or <<=
	case '<':
	{
		current_ch = next_char();  // consume '<';

		if (current_ch == '=')
		{
			text += current_ch;
			next_char();  // consume '='
		}
		else if (current_ch == '<')
		{
			text += current_ch;
			next_char();  // consume '<'

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '<<='
			}
		}

		break;
	}

	// > or >= or >> or >>=
	case '>':
	{
		current_ch = next_char();  // consume '>';

		if (current_ch == '=')
		{
			text += current_ch;
			next_char();  // consume '='
		}
		else if (current_ch == '>')
		{
			text += current_ch;
			next_char();  // consume '>'

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '>>='
			}
		}

		break;
	}

	// =, ==
	case '=':
	{
		current_ch = next_char();  // consume '.';

		if (current_ch == '=')
		{
			text += current_ch;
			next_char();  // consume '.'
		}

		break;
	}

	// &, &=, &&
	case '&':
	{
		current_ch = next_char();  // consume '&';

		if (current_ch == '&')
		{
			text += current_ch;
			next_char();  // consume '='
		}
		else if (current_ch == '=')
		{
			text += current_ch;
			next_char();  // consume '&'
		}

		break;
	}
	// ||, |=, |
	case '|':
	{
		current_ch = next_char();  // consume '|';

		if (current_ch == '=')
		{
			text += current_ch;
			next_char();  // consume '='
		}
		else if (current_ch == '|')
		{
			text += current_ch;
			next_char();  // consume '|'
		}

		break;
	}


	// +, +=, ++
	case '+':
	{
		current_ch = next_char();  // consume '+';

		if (current_ch == '+')
		{
			text += current_ch;
			next_char();  // consume '+'
		}
		else if (current_ch == '=')
		{
			text += current_ch;
			next_char();  // consume '='
		}

		break;
	}

	// -, -=, --
	case '-':
	{
		current_ch = next_char();  // consume '-';

		if (current_ch == '-')
		{
			text += current_ch;
			next_char();  // consume '-'
		}
		else if (current_ch == '=')
		{
			text += current_ch;
			next_char();  // consume '='
		}

		break;
	}

	// *, *=, */
	case '*':
	{
		current_ch = next_char();  // consume '*';

		if (current_ch == '=')
		{
			text += current_ch;
			next_char();  // consume '='
		}
		else if (current_ch == '/')
		{
			text += current_ch;
			next_char();  // consume '/'
		}

		break;
	}

	// /, /=, //
	case '/':
	{
		current_ch = next_char();  // consume '/';

		if (current_ch == '=')
		{
			text += current_ch;
			next_char();  // consume '='
		}
		else if (current_ch == '/')
		{
			text += current_ch;
			next_char();  // consume '/'
		}

		break;
	}

	// %, %=
	case '%':
	{
		current_ch = next_char();  // consume '%';

		if (current_ch == '=')
		{
			text += current_ch;
			next_char();  // consume '='
		}

		break;
	}

	// ^, ^=
	case '^':
	{
		current_ch = next_char();  // consume '/';

		if (current_ch == '=')
		{
			text += current_ch;
			next_char();  // consume '='
		}
		break;
	}


	default:
	{
		next_char();  // consume bad character
		type = (TokenType) (PT_ERROR);
		value = new DataValue((int) INVALID_CHARACTER);
		good_symbol = false;
	}
	}

	// Set the type if it wasn't an error.
	if (good_symbol) {
		type = (TokenType) (JavaToken::SPECIAL_SYMBOLS[text]);
	}
				}

}}}}  // namespace wci::frontend::pascal::tokens
