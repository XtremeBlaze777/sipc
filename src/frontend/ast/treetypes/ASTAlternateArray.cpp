#include "ASTAlternateArray.h"
#include "ASTinternal.h"

void ASTAlternateArray::accept(ASTVisitor* visitor) {
    if (visitor->visit(this)) {
        getStartExpr()->accept(visitor);
        getEndExpr()->accept(visitor);
    }
    visitor->endVisit(this);
}

std::vector<std::shared_ptr<ASTNode>> ASTAlternateArray::getChildren() {
    std::vector<std::shared_ptr<ASTNode>> children;
    children.push_back(startExpr);
    children.push_back(endExpr);
    return children;
}

std::ostream& ASTAlternateArray::print(std::ostream &out) const {
    out << "[" << getStartExpr() << " of " << getEndExpr() << "]";
    return out;
}   // LCOV_EXCL_LINE
