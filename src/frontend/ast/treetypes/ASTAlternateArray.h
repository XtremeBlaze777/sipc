#pragma once

#include "ASTExpr.h"
#include <ostream>

/*! \brief Class for an array.
 *
 */
class ASTAlternateArray: public ASTNode {
    std::string name;
    std::shared_ptr<ASTExpr> START;
    std::shared_ptr<ASTExpr> END;
    public:
        std::vector<std::shared_ptr<ASTNode>> getChildren() override;
        ASTAlternateArray(std::unique_ptr<ASTExpr> START, std::unique_ptr<ASTExpr> END)
                        : START(std::move(START)), endExpr(std::move(END)) {}
        std::string getName() const { return name; }
        ASTExpr* getStart() const { return START.get(); }
        ASTExpr* getEnd() const { return END.get(); }
        void accept(ASTVisitor * visitor) override;
        llvm::Value *codegen() override;
    protected:
        std::ostream& print(std::ostream &out) const override;
