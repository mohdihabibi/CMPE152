/*
 * JavaSpecialSymbol.h
 *
 *  Created on: Sep 13, 2017
 *      Author: Mohdi
 */

#ifndef WCI_FRONTEND_JAVA_TOKENS_JAVASPECIALSYMBOLTOKEN_H_
#define WCI_FRONTEND_JAVA_TOKENS_JAVASPECIALSYMBOLTOKEN_H_

#include <string>

#include "../../java/JavaToken.h"

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend::java;

class JavaSpecialSymbolToken : public JavaToken
{
public:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    JavaSpecialSymbolToken(Source *source) throw (string);

protected:
    /**
     * Extract a Pascal special symbol token from the source.
     * Override of wci::frontend::Token.
     * @throw a string message if an error occurred.
     */
    void extract() throw (string);
};

}}}}  // namespace wci::frontend::pascal::tokens


#endif /* WCI_FRONTEND_JAVA_TOKENS_JAVASPECIALSYMBOLTOKEN_H_ */
