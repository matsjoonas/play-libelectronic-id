#include <electronic-id/electronic-id.hpp>
#include <pcsc-cpp/pcsc-cpp.hpp>
#include "pcsc-cpp/pcsc-cpp-utils.hpp"
#include <iostream>
#include <string>
#include <QApplication>
#include <QByteArray>
#include <QSslCertificate>
#include <QSsl>

using namespace pcsc_cpp;
using namespace electronic_id;
using pcsc_cpp::string_t;

QString getCertificate(const CardInfo::ptr& card,
                       const CertificateType certificateType)
{
    const auto certificateBytes = card->eid().getCertificate(certificateType);

    auto certificateDer = QByteArray(reinterpret_cast<const char*>(certificateBytes.data()),
                                     int(certificateBytes.size()));
    auto certificate = QSslCertificate(certificateDer, QSsl::Der);

    return certificate.toText();
}

int main()
{
    std::cout << "*** START ***" << std::endl;


    auto cardList = electronic_id::availableSupportedCards();
    if (cardList.empty()) {
        throw std::logic_error("test::autoSelectSupportedCard(): No smart cards attached");
    }

    const auto cardInfo = cardList[0];
    const std::wstring reader_name = cardInfo->reader().name;
    const std::string eid_name = cardInfo->eid().name();
    std::wcout << "Reader: " << reader_name << std::endl;
    std::cout << "Card: " << eid_name << std::endl;
    std::cout << std::endl;


    std::cout << "*** Signing cert start ***" << std::endl;
    const QString signingCert = getCertificate(cardInfo, CertificateType::SIGNING);
    std::cout << signingCert.toStdString() << std::endl;
    std::cout << "*** Signing cert end ***" << std::endl;

    std::cout << "*** Auth cert start ***" << std::endl;
    const QString authCert = getCertificate(cardInfo, CertificateType::AUTHENTICATION);
    std::cout << authCert.toStdString() << std::endl;
    std::cout << "*** Auth cert end ***" << std::endl;


    std::cout << "*** END ***" << std::endl;
    return  0;
}