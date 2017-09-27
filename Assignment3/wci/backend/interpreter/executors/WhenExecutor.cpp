/**
 * <h1>IfExecutor</h1>
 *
 * <p>Execute an IF statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <vector>
#include "WhenExecutor.h"
#include "StatementExecutor.h"
#include "ExpressionExecutor.h"
#include "../../../DataValue.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

WhenExecutor::WhenExecutor(Executor *parent)
    : StatementExecutor(parent)
{
}

DataValue *WhenExecutor::execute(ICodeNode *node)
{
    // Get the IF node's children.
    vector<ICodeNode *> children = node->get_children();
    for(int i = 0; i < children.size()-2; i = i + 2 )
    {
        ICodeNode *expr_node = children[i];
        ICodeNode *right_arrow_stmt_node = children[i+1];
    }
    //If its odd then we have an otherwise
    ICodeNode *otherwise_stmt_node = !(children.size() % 2) ? children[children.size()-1] : nullptr;

    ExpressionExecutor expression_executor(this);
    StatementExecutor statement_executor(this);

    // Evaluate the expression to determine which statement to execute.
    for( int i = 0; i < (children.size()/2)-1; i = i++)
    {
        DataValue *data_value = expression_executor.execute(expr_node[i]);
        if (data_value->b)
        {
            statement_executor.execute(right_arrow_stmt_node[i]);
        }
        else if (otherwise_stmt_node != nullptr)
        {
            statement_executor.execute(otherwise_stmt_node[i]);
        }

        ++execution_count;  // count the WHEN_BRANCH(technically) statement itself
    }
    return nullptr;
}

}}}}  // namespace wci::backend::interpreter::executors
