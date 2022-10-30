#include "ASTAlternateArray.h"
#include "ASTinternal.h"
#include "ASTVisitor.h"

void ASTAlternateArray::accept(ASTVisitor* visitor) {
    if (visitor->visit(this)) {
        getStart()->accept(visitor);
        getEnd()->accept(visitor);
    }
    visitor->endVisit(this);
}

std::vector<std::shared_ptr<ASTNode>> ASTAlternateArray::getChildren() {
    std::vector<std::shared_ptr<ASTNode>> children;
    children.push_back(START);
    children.push_back(END);
    return children;
}

std::ostream& ASTAlternateArray::print(std::ostream &out) const {
    out << "[" << *getStart() << " of " << *getEnd() << "]";
    return out;
}   // LCOV_EXCL_LINE
