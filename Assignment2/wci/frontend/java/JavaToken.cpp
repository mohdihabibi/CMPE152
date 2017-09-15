/**
 * <h1>PascalToken</h1>
 *
 * <p>Base class for Pascal token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "../java/JavaToken.h"

#include <string>
#include <vector>
#include <map>

namespace wci { namespace frontend { namespace java {

using namespace std;

map<string, JavaTokenType> JavaToken::RESERVED_WORDS;
map<string, JavaTokenType> JavaToken::SPECIAL_SYMBOLS;
map<JavaTokenType, string> JavaToken::SPECIAL_SYMBOL_NAMES;

bool JavaToken::INITIALIZED = false;

void JavaToken::initialize()
{
	if (INITIALIZED) return;

	vector<string> rw_strings =
	{
			"abstract", "double", "break", "else", "case",
			"enum", "char", "extends", "class", "float",
			"const", "for", "continue", "goto","int",
			"long", "native", "return", "short", "package", "protected",
			"static","long", "switch", "super", "this", "throw", "void",
			"volatile", "while", "do", "if"
	};

	vector<JavaTokenType> rw_keys =
	{

			JavaTokenType::ABSTRACT,
			JavaTokenType::DOUBLE,
			JavaTokenType::BREAK,
			JavaTokenType::ENUM,
			JavaTokenType::CHAR,
			JavaTokenType::EXTENDS,
			JavaTokenType::CLASS,
			JavaTokenType::FLOAT,
			JavaTokenType::CONST,
			JavaTokenType::FOR,
			JavaTokenType::CONTINUE,
			JavaTokenType::INT,
			JavaTokenType::NATIVE,
			JavaTokenType::RETURN,
			JavaTokenType::SHORT,
			JavaTokenType::PACKAGE,
			JavaTokenType::PROTECTED,
			JavaTokenType::STATIC,
			JavaTokenType::LONG,
			JavaTokenType::SWITCH,
			JavaTokenType::SUPER,
			JavaTokenType::THIS,
			JavaTokenType::THROW,
			JavaTokenType::VOID,
			JavaTokenType::VOLATILE,

	};

	for (int i = 0; i < rw_strings.size(); i++)
	{
		RESERVED_WORDS[rw_strings[i]] = rw_keys[i];
	}

	vector<string> ss_strings =
	{
			"~","!", "@", "%", "^", "&", "*", "-", "+",
			"=", "|", "/", ":", ";", "?", "<", ">", ".",
			",", "\'", "\"", "(", ")", "[", "]", "{" ,"}", "++", "--",
			"<<", ">>", "<=", ">=", "+=", "-=", "*=", "/=", "==", "|=",
			"%=",  "&=",  "^=", "!=", "<<=", ">>=", "||", "&&", "//", "/*",  "*/"
	};

	vector<JavaTokenType> ss_keys =
	{
			JavaTokenType::TILDA,
			JavaTokenType::EXCLAIM,
			JavaTokenType::AT,
			JavaTokenType::MODULUS,
			JavaTokenType::POWER,
			JavaTokenType::AND,
			JavaTokenType::STAR,
			JavaTokenType::MINUS,
			JavaTokenType::PLUS,
			JavaTokenType::EQUAL,
			JavaTokenType::OR,
			JavaTokenType::F_SLASH,
			JavaTokenType::COLON,
			JavaTokenType::SEMI_COLON,
			JavaTokenType::Q_MARK,
			JavaTokenType::LESS_THAN,
			JavaTokenType::GREATER_THAN,
			JavaTokenType::DOT,
			JavaTokenType::D_QUOTE,
			JavaTokenType::S_QUOTE,
			JavaTokenType::L_PAR,
			JavaTokenType::R_PAR,
			JavaTokenType::L_BRACKET,
			JavaTokenType::R_BRACKET,
			JavaTokenType::L_BRACE,
			JavaTokenType::R_BRACE,
			JavaTokenType::PLUS_PLUS,
			JavaTokenType::MINUS_MINUS,
			JavaTokenType::SHIFT_L,
			JavaTokenType::COMMA,
			JavaTokenType::SHIFT_R,
			JavaTokenType::L_EQUAL,
			JavaTokenType::G_EQUAL,
			JavaTokenType::PLUS_EQUAL,
			JavaTokenType::C_COMMENT,
			JavaTokenType::MINUS_EQUAL,
			JavaTokenType::STAR_EQAUL,
			JavaTokenType::DIVIDE_EQAUL,
			JavaTokenType::EQAUL_EQAUL,
			JavaTokenType::OR_EQAUL,
			JavaTokenType::MODULUS_EQAUL,
			JavaTokenType::AND_EQAUL,
			JavaTokenType::POWER_EQAUL,
			JavaTokenType::NOT_EQUAL,
			JavaTokenType::SL_EQAUL,
			JavaTokenType::SR_EQAUL,
			JavaTokenType::OR_LOGICAL,
			JavaTokenType::AND_AND,
			JavaTokenType::FORWARD_SLASH_SLASH,
			JavaTokenType::O_COMMENT,
	};

	for (int i = 0; i < ss_strings.size(); i++)
	{
		SPECIAL_SYMBOLS[ss_strings[i]] = ss_keys[i];
	}

	vector<string> ss_names =
	{
			"TILDA","EXCLAIM","AT","MODULUS","POWER","AND","STAR","MINUS",
			"PLUS","EQUAL","OR","F_SLASH","COLON","SEMI_COLON","Q_MARK",
			"LESS_THAN","GREATER_THAN","DOT","D_QUOTE","S_QUOTE","L_PAR",
			"R_PAR","L_BRACKET","R_BRACKET","L_BRACE","R_BRACE","PLUS_PLUS",
			"MINUS_MINUS","SHIFT_L","COMMA","SHIFT_R","L_EQUAL","G_EQUAL","PLUS_EQUAL",
			"C_COMMENT","MINUS_EQUAL","STAR_EQAUL","DIVIDE_EQAUL","EQAUL_EQAUL",
			"OR_EQAUL","MODULUS_EQAUL","AND_EQAUL","POWER_EQAUL","NOT_EQUAL","SL_EQAUL",
			"SR_EQAUL","OR_LOGICAL","AND_AND","FORWARD_SLASH_SLASH","O_COMMENT"
	};

	for (int i = 0; i < ss_names.size(); i++)
	{
		SPECIAL_SYMBOL_NAMES[ss_keys[i]] = ss_names[i];
	}

	INITIALIZED = true;
}

JavaToken::JavaToken(Source *source) throw (string)
    		: Token(source)
{
	initialize();
}

}}}  // namespace wci::frontend::pascal
