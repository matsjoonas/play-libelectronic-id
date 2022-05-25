#include <iostream>

#include <electronic-id/electronic-id.hpp>

using namespace std;
int main()
{
    using namespace electronic_id;
    auto cardList = availableSupportedCards();
    if (cardList.empty()) {
        throw std::logic_error("test::autoSelectSupportedCard(): No smart cards attached");
    }
}