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
/*
CardCertificateAndPinInfo getCertificateWithStatusAndInfo(const CardInfo::ptr& card,
                                                          const CertificateType certificateType)
{
    const auto certificateBytes = card->eid().getCertificate(certificateType);

    auto certificateDer = QByteArray(reinterpret_cast<const char*>(certificateBytes.data()),
                                     int(certificateBytes.size()));
    auto certificate = QSslCertificate(certificateDer, QSsl::Der);
    if (certificate.isNull()) {
        THROW(SmartCardChangeRequiredError,
              "Invalid certificate returned by electronic ID " + card->eid().name());
    }

    auto certInfo = CertificateInfo {certificateType,
                                     certificate.expiryDate() < QDateTime::currentDateTimeUtc(),
                                     certificate.effectiveDate() > QDateTime::currentDateTimeUtc(),
                                     certificate.subjectInfo(QSslCertificate::CommonName).join(' '),
                                     certificate.issuerInfo(QSslCertificate::CommonName).join(' '),
                                     certificate.effectiveDate().date().toString(Qt::ISODate),
                                     certificate.expiryDate().date().toString(Qt::ISODate)};
    auto pinInfo =
            PinInfo {certificateType.isAuthentication() ? card->eid().authPinMinMaxLength()
                                                        : card->eid().signingPinMinMaxLength(),
                     certificateType.isAuthentication() ? card->eid().authPinRetriesLeft()
                                                        : card->eid().signingPinRetriesLeft(),
                     card->eid().smartcard().readerHasPinPad()};
    if (pinInfo.pinRetriesCount.first == 0) {
        pinInfo.pinIsBlocked = true;
    }

    return {card};
}
 */

int main()
{
    std::cout << "*** START ***" << std::endl;

    auto certificateDer = QByteArray(1, 1);
    auto certificate = QSslCertificate(certificateDer, QSsl::Der);

    /*
    auto cardList = electronic_id::availableSupportedCards();
    if (cardList.empty()) {
        throw std::logic_error("test::autoSelectSupportedCard(): No smart cards attached");
    }

    const auto cardInfo = cardList[0];
    const std::wstring reader_name = cardInfo->reader().name;
    const std::string eid_name = cardInfo->eid().name();

    std::wcout << "Reader: " << reader_name << std::endl;
    std::cout << "Card: " << eid_name << std::endl;

    const auto certInfo = getCertificateWithStatusAndInfo(cardInfo, CertificateType::AUTHENTICATION);

    std::cout << "*** END ***" << std::endl;
     */
    return  0;
}