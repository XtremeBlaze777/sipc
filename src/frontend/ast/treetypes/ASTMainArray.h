#pragma once

#include "ASTExpr.h"
#include <ostream>

/*! \brief Class for an array.
 *
 */
class ASTMainArray: public ASTExpr {
    std::vector<std::shared_ptr<ASTExpr>> ELEMENTS;
    public:
        std::vector<std::shared_ptr<ASTNode>> getChildren() override;
        ASTMainArray(std::vector<std::unique_ptr<ASTExpr>> ELEMENTS);
        std::vector<ASTExpr*> getElements() const;
        void accept(ASTVisitor * visitor) override;
        llvm::Value *codegen() override;
    protected:
        std::ostream& print(std::ostream &out) const override;
};