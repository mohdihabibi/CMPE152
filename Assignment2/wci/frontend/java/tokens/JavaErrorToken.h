/*
 * JavaErrorToken.h
 *
 *  Created on: Sep 13, 2017
 *      Author: Mohdi
 */

#ifndef WCI_FRONTEND_JAVA_TOKENS_JAVAERRORTOKEN_H_
#define WCI_FRONTEND_JAVA_TOKENS_JAVAERRORTOKEN_H_


#include <string>

#include "../../java/JavaError.h"
#include "../../java/JavaToken.h"

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend::java;

class JavaErrorToken : public JavaToken
{
public:
    /**
     * Constructor.
     * @param source the source from where to fetch subsequent characters.
     * @param errorCode the error code.
     * @param tokenText the text of the erroneous token.
     * @throw a string message if an error occurred.
     */
    JavaErrorToken(Source *source, JavaErrorCode error_code,
                     string token_text)
        throw (string);

protected:
    /**
     * Do nothing.  Do not consume any source characters.
     * Override of wci::frontend::Token.
     * @throw a string message if an error occurred.
     */
    void extract() throw (string);
};

}}}}  // namespace wci::frontend::pascal::tokens

#endif /* WCI_FRONTEND_JAVA_TOKENS_JAVAERRORTOKEN_H_ */
