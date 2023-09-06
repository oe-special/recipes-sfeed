SUMMARY_${PN} = "scam ${PKGV}"
DESCRIPTION_${PN} = "An outdated binary only softcam"

FILESEXTRAPATHS_prepend := "${THISDIR}/../softcams/enigma2-plugin-softcams-scam:"

RDEPENDS_${PN} = "libcrypto-compat-0.9.7 glibc"
RDEPENDS_${PN}_aarch64 = ""

RPROVIDES_${PN} += "enigma2-plugin-softcams-scam-3.60 enigma2-plugin-softcams-scam-3.59"
RREPLACES_${PN} += "enigma2-plugin-softcams-scam-3.60 enigma2-plugin-softcams-scam-3.59"
RCONFLICTS_${PN} += "enigma2-plugin-softcams-scam-3.60 enigma2-plugin-softcams-scam-3.59"
