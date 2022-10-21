#include "ASTMainArray.h"
#include "ASTinternal.h"

ASTMainArray::ASTMainArray(std::vector<std::unique_ptr<ASTExpr>> elements) {
    for(auto &element : elements) {
        std::shared_ptr<ASTExpr> e = std::move(element);
        this->elements.push_back(e);
    }
}

std::vector<ASTExpr*> ASTMainArray::getElements() const {
    return rawRefs(elements);
}

void ASTMainArray::accept(ASTVisitor* visitor) {
    if (visitor->visit(this)) {
        for (auto p : getElements()) {
            p->accept(visitor);
        }
    }
    visitor->endVisit(this);
}

std::vector<std::shared_ptr<ASTNode>> ASTMainArray::getChildren() {
    std::vector<std::shared_ptr<ASTNode>> children;
    for (auto &element : elements) {
        children.push_back(element);
    }
    return children;
}

std::ostream& ASTMainArray::print(std::ostream &out) const {
    auto gotten = getElements();
    auto &last = gotten.back();
    gotten.pop_back();
    out << "[";
    for (auto &element : gotten) {
        out << element << ",";
    }
    out << last << "]";
    return out;
}   // LCOV_EXCL_LINE
