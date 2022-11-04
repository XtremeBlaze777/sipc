#pragma once

#include "TipType.h"
#include "TipCons.h"
#include "TipInt.h"
#include <string>
#include <vector>
#include <memory>

/*!
 * \class TipArr 
 *
 * \brief A proper type representing an array 
 */
class TipArr: public TipCons {
public:
    TipArr();
    TipArr(std::vector<std::shared_ptr<TipType>> elems);
    TipArr(std::shared_ptr<TipInt> num, std::shared_ptr<TipType> expr);

    std::vector<std::shared_ptr<TipType>> getElems() const;

    bool operator==(const TipType& other) const override;
    bool operator!=(const TipType& other) const override;

    void accept(TipTypeVisitor *visitor) override;

protected:
    std::ostream& print(std::ostream &out) const override;
};
